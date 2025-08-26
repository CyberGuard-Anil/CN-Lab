#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

void sortArray(int arr[], int n) {
    int i, j, temp;
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int sockfd;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t len;
    int arr[50], n;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(1);
    }
    printf("UDP Server started...\n");

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(8080);

    if (bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        perror("Bind failed");
        exit(1);
    }

    len = sizeof(cliaddr);


    recvfrom(sockfd, &n, sizeof(n), 0, (struct sockaddr*)&cliaddr, &len);

    recvfrom(sockfd, arr, sizeof(int)*n, 0, (struct sockaddr*)&cliaddr, &len);

    printf("Received array of %d elements.\n", n);


    sortArray(arr, n);


    sendto(sockfd, arr, sizeof(int)*n, 0, (struct sockaddr*)&cliaddr, len);
    printf("Sent sorted array to client.\n");

    close(sockfd);
    return 0;
}

