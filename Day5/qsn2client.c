// udp_client_recv.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAXLINE 1024

int main() {
    int sockfd;
    char buffer[MAXLINE];
    struct sockaddr_in servaddr;

    // Step 1: Socket create karo
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    // Step 2: Server address
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    socklen_t len = sizeof(servaddr);

    // First hello bhejna taki server ko client ka address mile
    char *hello = "Hello Server, I am ready to receive!";
    sendto(sockfd, (const char *)hello, strlen(hello), 0, (const struct sockaddr *)&servaddr, len);

    printf("UDP Client started. Waiting for messages...\n");

    // Continuous receive loop
    while (1) {
        int n = recvfrom(sockfd, (char *)buffer, MAXLINE, 0, (struct sockaddr *)&servaddr, &len);
        buffer[n] = '\0';
        printf("Server: %s\n", buffer);

        if (strncmp("exit", buffer, 4) == 0) {
            printf("Server disconnected.\n");
            break;
        }
    }

    close(sockfd);
    return 0;
}

