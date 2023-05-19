#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>

// Function to execute the netstat command
int netstat() {
    return system("netstat -an");
}

// Function to perform a ping to a given host
int ping(const char* host) {
    char command[256];
    snprintf(command, sizeof(command), "ping -c 5 %s", host);
    return system(command);
}

// Function to test if a port is open on a given host
int test_port(const char* host, int port) {
    struct sockaddr_in server;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return -1;
    }

    server.sin_addr.s_addr = inet_addr(host);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    int result = connect(sock, (struct sockaddr *)&server, sizeof(server));
    close(sock);
    return result;
}
