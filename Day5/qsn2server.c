// udp_server_send.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAXLINE 1024

int main() {
    int sockfd;
    char msg[MAXLINE];
    struct sockaddr_in servaddr, cliaddr;

    // Step 1: Socket create karo
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    // Step 2: Server address
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    // Step 3: Bind karo
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("UDP Server started on port %d...\n", PORT);

    socklen_t len = sizeof(cliaddr);

    // First dummy recvfrom -> client ka address lena
    char buffer[MAXLINE];
    int n = recvfrom(sockfd, buffer, MAXLINE, 0, (struct sockaddr *)&cliaddr, &len);
    buffer[n] = '\0';
    printf("Client connected: %s\n", buffer);

    // Now continuous sending
    while (1) {
        printf("Server: ");
        fgets(msg, MAXLINE, stdin);

        sendto(sockfd, (const char *)msg, strlen(msg), 0, (const struct sockaddr *)&cliaddr, len);

        if (strncmp("exit", msg, 4) == 0) {
            printf("Server exiting...\n");
            break;
        }
    }

    close(sockfd);
    return 0;
}

