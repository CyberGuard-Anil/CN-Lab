#include <stdio.h>

void printBytes(int num) {
    unsigned char *b = (unsigned char*)&num;
    for(int i = 0; i < sizeof(num); i++) {
        printf("Byte %d: %u\n", i, b[i]);
    }
}

// Updated convertEndian function with unsigned int to avoid sign-extension
int convertEndian(int num) {
    unsigned int u = (unsigned int)num;
    return ((u >> 24) & 0xFF) | 
           ((u << 8) & 0xFF0000) | 
           ((u >> 8) & 0xFF00) | 
           ((u << 24) & 0xFF000000);
}

int main() {
    int num = 1;
    unsigned char *b = (unsigned char*)&num;
    if (b[0] == 1)
        printf("Little Endian\n");
    else
        printf("Big Endian\n");

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Original bytes:\n");
    printBytes(num);

    int conv = convertEndian(num);

    printf("Converted bytes:\n");
    printBytes(conv);
    
    printf("Converted Value: %u\n", (unsigned int)conv);

    return 0;
}

