#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <errno.h>
#include <netinet/in.h>
#include <unistd.h>




int main()
{
    int 
        srvr_sock = socket(AF_INET, SOCK_STREAM, 0),
        port = 9998;
    char 
        srvr_msg[1024] = "You have reached the server.";

    //define the server address:
    struct sockaddr_in srvr_addr;
    srvr_addr.sin_family = AF_INET;
    srvr_addr.sin_port = htons(port);
    srvr_addr.sin_addr.s_addr = INADDR_ANY;

    bind(srvr_sock, (struct sockaddr *)&srvr_addr, sizeof(srvr_addr));

    listen(srvr_sock, 5);printf("Server listening on %i\n", port);

    int client_sock = accept(srvr_sock, NULL, 0);

    send(client_sock, srvr_msg, sizeof(srvr_msg), 0);

    close(srvr_sock);

    return 0;

}
