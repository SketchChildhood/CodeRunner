#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>

static const char *socket_path = "/var/run/usbmuxd";


int main(int argc, char *argv[]) {
	int listenfd;
	const char* socket_addr = socket_path;
	const char* tcp_port;
	char listen_addr_str[256];
	
	char *listen_addr = "127.0.0.1:27015";

	if (listen_addr) {
		socket_addr = listen_addr;
	}
	tcp_port = strrchr(socket_addr, ':');
	if (tcp_port) {
		tcp_port++;
		size_t nlen = tcp_port - socket_addr;
		
		char* hostname = malloc(nlen);
		strncpy(hostname, socket_addr, nlen-1);
		printf("nlen: %ld", nlen);
		
		struct addrinfo hints;
		struct addrinfo *result, *rp;
		int yes = 1;
		int res;
		
		strncpy(hostname, socket_addr, nlen-1);
		hostname[nlen-1] = '\0';
		
		memset(&hints, '\0', sizeof(struct addrinfo));
		hints.ai_family = AF_UNSPEC;
		hints.ai_socktype = SOCK_STREAM;
		hints.ai_flags = AI_PASSIVE | AI_NUMERICSERV;
		hints.ai_protocol = IPPROTO_TCP;
		
		res = getaddrinfo(hostname, tcp_port, &hints, &result);
		free(hostname);
	}


}