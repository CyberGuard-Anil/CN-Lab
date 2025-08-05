#include <stdio.h>

int main() {
    unsigned int num;
    int attempts = 0;

    while (1) {
        printf("Enter an unsigned integer: ");
        scanf("%u", &num);
        attempts++;

        unsigned char first_byte = num & 0xFF;
        unsigned char last_byte = (num >> 24) & 0xFF;

        if (first_byte != last_byte) {
            printf("Succeeded with %d attempts\n", attempts);
            break;
        } else {
            printf("First and last byte are same, try again.\n");
        }
    }
    return 0;
}

