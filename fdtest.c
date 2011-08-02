#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFSIZE 100
int main () {
	int ifd,ofd = 0;
	int n ;
	char *buf[BUFFSIZE];
	ifd = open("calc.c", S_IRUSR|S_IWUSR);
	ofd = open("outcalc.c", O_CREAT|O_WRONLY, S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);
	printf("%d\n", ifd);
	printf("%d\n", ofd);
	while ((n = read(ifd, buf, BUFFSIZE))>0){
		if (write(ofd, buf, n) != n){
			printf("%d\n", n);
			printf("write error\n");
		}
	}
	close(ifd);
	close(ofd);
	 while ((n = read(ifd, buf, BUFFSIZE))>0){
                if (write(ofd, buf, n) != n){
                        printf("%d\n", n);
                        printf("write error\n");
                }
		printf("aaaaaaaaaaa");
        }

	printf("%d\n", ifd);
	return 0;

}
