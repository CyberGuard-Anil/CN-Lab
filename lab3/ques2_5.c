#include <stdio.h>

int main() {
    int num = 0x01020304;
    char *c = (char*)&num;
    printf("Memory content bytes: %02x %02x %02x %02x\n", (unsigned char)c[0], (unsigned char)c[1], (unsigned char)c[2], (unsigned char)c[3]);

    if (c[0] == 0x04 && c[3] == 0x01) {
        printf("Little Endian\n");
    } else if (c[0] == 0x01 && c[3] == 0x04) {
        printf("Big Endian\n");
    } else {
        printf("Unknown Endianness\n");
    }

    return 0;
}

