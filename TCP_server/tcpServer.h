#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <limits.h>

#define SERVERPORT 9998
#define BUFSIZE 4096
#define SOCKETERROR (-1)
#define SERVER_BACKLOG 128

typedef struct sockaddr_in SA_IN;
typedef struct sockaddr SA;

//protos
void* handle_connection(int);
int check(int exp, const char* msg);
int accept_new_connection(int server_socket);
int setup_server(short port, int backlog);

