#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAXLINE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <Receiver IP> <Receiver Port>\n", argv[0]);
        return 1;
    }

    char *receiver_ip = argv[1];
    int receiver_port = atoi(argv[2]);

    int sockfd;
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return -1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(receiver_port);
    servaddr.sin_addr.s_addr = inet_addr(receiver_ip);

    char buffer[MAXLINE];
    while (1) {
        printf("Enter message to send: ");
        fgets(buffer, MAXLINE, stdin);
        buffer[strcspn(buffer, "\n")] = 0; 

        sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr*)&servaddr, sizeof(servaddr));

        if (strcmp(buffer, "exit") == 0) {
            printf("Exit message sent. Closing sender.\n");
            break;
        }
    }

    close(sockfd);
    return 0;
}

