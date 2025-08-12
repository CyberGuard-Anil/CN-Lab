
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>

int main() {
    int server_sock, client_sock;

    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("Server socket creation failed");
        exit(1);
    }
    printf("Server socket created successfully.\n");


    client_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (client_sock < 0) {
        perror("Client socket creation failed");
        exit(1);
    }
    printf("Client socket created successfully.\n");

    return 0;
}

