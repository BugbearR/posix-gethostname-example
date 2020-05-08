#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int main(int argc, char *argv) {
    char nameBuf[HOST_NAME_MAX + 1];
    int subRetInt = 0;

    subRetInt = gethostname(nameBuf, sizeof(nameBuf));
    if (subRetInt != 0) {
        perror("gethostname");
        return EXIT_FAILURE;
    }

    printf("%s\n", nameBuf);

    return EXIT_SUCCESS;
}
