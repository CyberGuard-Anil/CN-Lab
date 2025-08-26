#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int sockfd;
    struct sockaddr_in servaddr;
    socklen_t len;
    int arr[50], n, i;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8080);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    printf("Enter size of array: ");
    scanf("%d", &n);
    printf("Enter array elements: ");
    for(i = 0; i < n; i++) scanf("%d", &arr[i]);


    sendto(sockfd, &n, sizeof(n), 0, (struct sockaddr*)&servaddr, sizeof(servaddr));
    sendto(sockfd, arr, sizeof(int)*n, 0, (struct sockaddr*)&servaddr, sizeof(servaddr));


    len = sizeof(servaddr);
    recvfrom(sockfd, arr, sizeof(int)*n, 0, (struct sockaddr*)&servaddr, &len);

    printf("Sorted array from server: ");
    for(i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    close(sockfd);
    return 0;
}

