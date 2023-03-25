#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "socket.h"

#define BUFFER_SIZE 1024
int main(int argc, char *argv[]) {
	
	int server_fd;
	uint16_t port = 9999;
	
	server_fd = socket_create("127.0.0.1", port);
	if (server_fd < 0) {
		fprintf(stderr, "Could not create socket\n");
		return -1;
	}
	
	while (1) {
		int client_fd = socket_accept(server_fd, port);
		if (client_fd < 0) {
			continue;
		}
		
		printf("Handling new client connection...\n");
		
		
		char msg[] = "Hello world from C language server.";
		size_t length = sizeof(msg);
		socket_send(client_fd, (void *)&msg, length);
		
		char *data = (char *)malloc(BUFFER_SIZE);
		int res = socket_receive(client_fd, data, BUFFER_SIZE);
		printf("C Server receive: %s, res: %d\n", data, res);
		
		free(data);
	}
	
	
	return 0;
}