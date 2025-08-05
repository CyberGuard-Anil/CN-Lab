#include <stdio.h>

int main() {
    int num;
    printf("Enter a signed integer: ");
    scanf("%d", &num);

    unsigned char b1 = num & 0xFF;
    unsigned char b2 = (num >> 8) & 0xFF;
    unsigned char b3 = (num >> 16) & 0xFF;
    unsigned char b4 = (num >> 24) & 0xFF;

    printf("Bytes in decimal: %u %u %u %u\n", b1, b2, b3, b4);
    return 0;
}

