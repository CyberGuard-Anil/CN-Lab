// udp_client.c
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
    char msg[MAXLINE];
    struct sockaddr_in servaddr;

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    socklen_t len = sizeof(servaddr);

    printf("UDP Chat Client started...\n");

    while (1) {
        printf("Client: ");
        fgets(msg, MAXLINE, stdin);

        sendto(sockfd, (const char *)msg, strlen(msg), 0, (const struct sockaddr *)&servaddr, len);

        if (strncmp("exit", msg, 4) == 0) {
            printf("Client exiting...\n");
            break;
        }

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

