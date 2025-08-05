#include <stdio.h>

int main() {
    unsigned int num;
    printf("Enter an unsigned integer: ");
    scanf("%u", &num);

    unsigned char first_byte = num & 0xFF;             
    unsigned char last_byte = (num >> 24) & 0xFF;       

    printf("First byte = %u\n", first_byte);
    printf("Last byte = %u\n", last_byte);
    return 0;
}

