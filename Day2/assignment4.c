#include <stdio.h>

struct pkt {
    char ch1;
    char ch2[2];
    char ch3;
};

int main() {
    int num;
    printf("Enter a 4-digit number: ");
    scanf("%d", &num);

    struct pkt p;
    p.ch1 = num & 0xFF;
    p.ch2[0] = (num >> 8) & 0xFF;
    p.ch2[1] = (num >> 16) & 0xFF;
    p.ch3 = (num >> 24) & 0xFF;

    printf("ch1: %d\nch2[0]: %d\nch2[1]: %d\nch3: %d\n", p.ch1, p.ch2[0], p.ch2[1], p.ch3);

    // Corrected aggregation with unsigned char casting
    int original = ((unsigned char)p.ch3 << 24) |
                   ((unsigned char)p.ch2[1] << 16) |
                   ((unsigned char)p.ch2[0] << 8)  |
                   (unsigned char)p.ch1;

    printf("Aggregated number: %d\n", original);

    return 0;
}

