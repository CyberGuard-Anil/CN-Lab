#include <stdio.h>

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    char b1 = num & 0xFF;
    char b2 = (num >> 8) & 0xFF;
    char b3 = (num >> 16) & 0xFF;
    char b4 = (num >> 24) & 0xFF;
    printf("Byte 1: %d\nByte 2: %d\nByte 3: %d\nByte 4: %d\n", b1, b2, b3, b4);
    return 0;
}

