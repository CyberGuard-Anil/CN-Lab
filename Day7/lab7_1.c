#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/select.h>
#include <sys/types.h>

#define STDIN 0

int main() {
    fd_set rfds;
    struct timeval tv;
    int retval;
    char buffer[100];

    FD_ZERO(&rfds);
    FD_SET(STDIN, &rfds);

    tv.tv_sec = 5;
    tv.tv_usec = 0;

    retval = select(STDIN + 1, &rfds, NULL, NULL, &tv);

    if (retval == -1) {
        perror("select() error");
        exit(EXIT_FAILURE);
    } else if (retval == 0) {
        printf("Timeout occurred! No input within 5 seconds.\n");
    } else {
        read(STDIN, buffer, sizeof(buffer));
        printf("You entered: %s\n", buffer);
    }
    return 0;
}
