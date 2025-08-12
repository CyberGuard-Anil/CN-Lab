
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; 
    server_addr.sin_port = htons(8080);

    client_addr.sin_family = AF_INET;
    client_addr.sin_addr.s_addr = INADDR_ANY; 
    client_addr.sin_port = htons(9090);

    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("Server socket creation failed");
        exit(1);
    }
    printf("Server socket created successfully.\n");

    if (bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Server bind failed");
        exit(1);
    }
    printf("Server socket bound to port 8080.\n");

    client_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (client_sock < 0) {
        perror("Client socket creation failed");
        exit(1);
    }
    printf("Client socket created successfully.\n");

    if (bind(client_sock, (struct sockaddr*)&client_addr, sizeof(client_addr)) < 0) {
        perror("Client bind failed");
        exit(1);
    }
    printf("Client socket bound to port 9090.\n");

    close(server_sock);
    close(client_sock);

    return 0;
}

