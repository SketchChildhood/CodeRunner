#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    int i;
    for (i = 1; i <= 10; i++) {
        printf("%d", i);
    }

    // create a socket  (IPv4, TCP)
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }
    // set the socket to be reusable
    int optval = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0) {
        perror("setsockopt");
        return 1;
    }
    // bind the socket to a port
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(12345);
    addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        return 1;
    }
    // listen for connections
    if (listen(sockfd, 10) < 0) {
        perror("listen");
        return 1;
    }
    // accept a connection
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int clientfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
    if (clientfd < 0) {
        perror("accept");
        return 1;
    }
    // read from the client
    char buf[1024];
    int n = read(clientfd, buf, sizeof(buf));
    if (n < 0) {
        perror("read");
        return 1;
    }
    // write to the client
    if (write(clientfd, buf, n) < 0) {
        perror("write");
        return 1;
    }
    // close the client socket
    if (close(clientfd) < 0) {
        perror("close");
        return 1;
    }
    // close the server socket
    if (close(sockfd) < 0) {
        perror("close");
        return 1;
    }

    return 0;
}