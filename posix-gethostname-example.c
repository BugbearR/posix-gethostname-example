#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

#if !defined HOST_NAME_MAX
size_t getHostNameMax() {
    static size_t s_hostNameMax = 0;

    if (s_hostNameMax == 0) {
        long hostNameMax;
        hostNameMax = sysconf(_SC_HOST_NAME_MAX);
        if (hostNameMax <= 0) {
            // This is usually not possible.
            perror("sysconf");
            exit(EXIT_FAILURE);
        }
        s_hostNameMax = (size_t) hostNameMax;
    }

    return s_hostNameMax;
}
#endif

int main(int argc, char *argv[]) {
    int subRetInt = 0;
#if defined HOST_NAME_MAX
    char nameBuf[HOST_NAME_MAX + 1];
    size_t nameBufLen = sizeof(nameBuf);
#else
    char *nameBuf = NULL;
    size_t nameBufLen = 0;
#endif

#if !defined HOST_NAME_MAX
    nameBufLen = getHostNameMax() + 1;
    nameBuf = malloc(nameBufLen);
    if (!nameBuf) {
        // This is usually not possible.
        perror("malloc");
        return EXIT_FAILURE;
    }
#endif

    subRetInt = gethostname(nameBuf, sizeof(nameBuf));
    if (subRetInt != 0) {
        // This is usually not possible.
        perror("gethostname");
        return EXIT_FAILURE;
    }

    printf("%s\n", nameBuf);

#if !defined HOST_NAME_MAX
    free(nameBuf);
#endif

    return EXIT_SUCCESS;
}
