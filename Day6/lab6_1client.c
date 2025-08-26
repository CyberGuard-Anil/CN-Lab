#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int sockfd;
    struct sockaddr_in servaddr;
    socklen_t len;
    int nums[2], result;


    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8080);
    servaddr.sin_addr.s_addr = INADDR_ANY;


    printf("Enter two numbers: ");
    scanf("%d %d", &nums[0], &nums[1]);


    sendto(sockfd, nums, sizeof(nums), 0, (struct sockaddr*)&servaddr, sizeof(servaddr));


    len = sizeof(servaddr);
    recvfrom(sockfd, &result, sizeof(result), 0, (struct sockaddr*)&servaddr, &len);

    printf("Sum from server = %d\n", result);

    close(sockfd);
    return 0;
}

