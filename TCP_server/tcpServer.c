#include "tcpServerTest.h"


int main(int argc, char** argv)
{
	char CWD[PATH_MAX];
	if (getcwd(CWD, sizeof(CWD)) != NULL) {
		printf("CWD : %s", CWD);
	}
	else {
		perror("[*] getcwd() ERROR!");
	}
	
	killer(SERVERPORT);
	int server_socket = setup_server(SERVERPORT, SERVER_BACKLOG);

	while (true)
	{

		
		printf("Waiting for connections...\n");
		int client_socket = accept_new_connection(server_socket);

		handle_connection(client_socket);
	}

	return EXIT_SUCCESS;
}

int setup_server(short port, int backlog)
{
	int
		server_socket, client_socket, addr_size;
	SA_IN server_addr;

	check((server_socket = socket(AF_INET, SOCK_STREAM, 0)),
		"Failed to create socket");

	//init the addr struct:
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = htons(port);

	check(bind(server_socket, (SA*)&server_addr, sizeof(server_addr)),
		"Bind failed!");
	check(listen(server_socket, backlog),
		"Listen failed!");

	return server_socket;
}

void killer(short port) {
	FILE* fp;
	char
		cmd1[1024] = "lsof -i :",
		cmd2[1024] = " | awk '{print $2}' | tail -n1",
		buff[1024],
		sport[8];
	snprintf(sport, 8, "%i", port);
	strcat(cmd1, sport);
	strcat(cmd1, cmd2);
	fp = popen(cmd1, "r");
	if (fp == NULL) perror("Failed to run command.\n");

	while (fgets(buff, sizeof(buff), fp) != NULL) {
		printf("%s\n", buff);
	}
	if (strlen(buff) < 2) {
		printf("Port is free to bind.\n");
	} else {
		char cmd3[1024] = "kill ";
		strcat(cmd3, buff);
		fp = popen(cmd3, "r");
	}
}


int accept_new_connection(int server_socket)
{
	int
		addr_size = sizeof(SA_IN),
		client_socket;
	SA_IN client_addr;
	check(client_socket = accept(server_socket, (SA*)&client_addr, (socklen_t*)&addr_size),
		"Accept failed!");

	return client_socket;
}

int check(int exp, const char* msg)
{
	if (exp == SOCKETERROR) {
		perror(msg);
		exit(1);
	}
	return exp;
}

void* handle_connection(int client_socket)
{
	char buffer[BUFSIZE];
	size_t bytes_read;
	int msgsize = 0;
	char actualpath[PATH_MAX + 1];

	while ((bytes_read = read(client_socket, buffer + msgsize, sizeof(buffer) - msgsize - 1))) {
		msgsize += bytes_read;
		if (msgsize > BUFSIZ - 1 || buffer[msgsize - 1] == '\n') break;
	}
	check(bytes_read, "recv error");
	buffer[msgsize - 1] = 0;
	printf("REQUEST: %s\n", buffer);
	fflush(stdout);

	if (realpath(buffer, actualpath) == NULL) {
		printf("Error(bad path):%s\n", buffer);
		write(client_socket, "[*] Error : bad path\n", strlen(buffer));
		close(client_socket);
		return NULL;
	}

	FILE* fp = fopen(actualpath, "r");
	if (fp == NULL) {
		fprintf(stderr, "%s\n", buffer);
		close(client_socket);
		return NULL;
	}

	while ((bytes_read = fread(buffer, 1, BUFSIZE, fp)) > 0) {
		write(client_socket, buffer, bytes_read);
	}

	close(client_socket);
	fclose(fp);
 	printf("Closing connection\n");
	return NULL;
}

