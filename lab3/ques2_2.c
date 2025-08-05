#include <stdio.h>

int main() {
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);

    char b1 = num & 0xFF;
    char b2 = (num >> 8) & 0xFF;
    char b3 = (num >> 16) & 0xFF;
    char b4 = (num >> 24) & 0xFF;

    printf("Bytes extracted: %d %d %d %d\n", b1, b2, b3, b4);
    return 0;
}

