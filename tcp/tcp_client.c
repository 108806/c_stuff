#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <errno.h>
#include <netdb.h>
#include <unistd.h>

int main()
{
    int net_sock;
    net_sock = socket(AF_INET, SOCK_STREAM, 0);

    //specify an addr:
    struct sockaddr_in srver;
    srver.sin_family = AF_INET;
    srver.sin_port = htons(9998);
    srver.sin_addr.s_addr = INADDR_ANY;

    int conn_status = connect(net_sock, (struct sockaddr *)&srver, sizeof(srver));
    //check for errs:
    if (conn_status == -1) { printf("connection failed: %d\n", conn_status); return -1; }

    //recv data from server:
    char buffer[256];
    recv(net_sock, &buffer, sizeof(buffer), 0);

    //print received data:
    printf("Data received: %s\n", buffer);

    close(net_sock);
    return 0;
}
