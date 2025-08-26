#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int sockfd;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t len;
    int nums[2], result;


    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(1);
    }
    printf(" UDP Server started...\n");


    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(8080);


    if (bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        perror("Bind failed");
        exit(1);
    }

    len = sizeof(cliaddr);


    recvfrom(sockfd, nums, sizeof(nums), 0, (struct sockaddr*)&cliaddr, &len);
    printf("Received numbers: %d and %d\n", nums[0], nums[1]);


    result = nums[0] + nums[1];
    printf(" Sum = %d\n", result);

    sendto(sockfd, &result, sizeof(result), 0, (struct sockaddr*)&cliaddr, len);
    printf("Sent result to client.\n");

    close(sockfd);
    return 0;
}

