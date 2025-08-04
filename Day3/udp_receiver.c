#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAXLINE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <Port to listen>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);

    int sockfd;
    struct sockaddr_in servaddr, cliaddr;

    socklen_t len;
    char buffer[MAXLINE];

    // Create UDP socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return -1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(port);

    // Bind socket to port
    if (bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        perror("Bind failed");
        return -1;
    }

    printf("Receiver started on port %d\n", port);

    while (1) {
        len = sizeof(cliaddr);
        int n = recvfrom(sockfd, buffer, MAXLINE, 0, (struct sockaddr*)&cliaddr, &len);
        buffer[n] = '\0';
        printf("Received: %s\n", buffer);

        if (strcmp(buffer, "exit") == 0) {
            printf("Exit message received. Closing receiver.\n");
            break;
        }
    }

    close(sockfd);
    return 0;
}


