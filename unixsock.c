#include <stdio.h>
#include <errno.h>
#include <err.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdlib.h>

#define UNIX_PATH_MAX 108

int main(int argc, char *argv[]) {

        int s = -1;
        struct sockaddr_un una;
        size_t i =0;


//        for (i = 0; i < 65535; i++) {
                s = socket(AF_UNIX, SOCK_STREAM, 0);
                if (s < 0) {
                        warn("socket() failed (i = %zu)", i);
                        exit(1);
                }
                memset(&una, 0, sizeof(struct sockaddr_un));

                una.sun_family = AF_UNIX;
                snprintf(&una.sun_path[0], UNIX_PATH_MAX, "/var/run/acpid.socket");

                if (connect(s, (void *)&una, sizeof(struct sockaddr_un))) {
                        err(1, "connect() failed (i = %zu)", i);
                }
                printf("%d\n", i);
  //      }

        exit(0);
}

