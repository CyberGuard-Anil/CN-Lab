#include <stdio.h>

unsigned int convertEndian(unsigned int num) {
    return ((num >> 24) & 0xFF) | 
           ((num << 8) & 0xFF0000) | 
           ((num >> 8) & 0xFF00) | 
           ((num << 24) & 0xFF000000);
}

int main() {
    unsigned int num;
    printf("Enter a number to convert endian: ");
    scanf("%u", &num);
    unsigned int converted = convertEndian(num);
    printf("Converted number: %u\n", converted);
    return 0;
}

