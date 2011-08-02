#include <stdio.h>
#include <stdlib.h>


int main(){
	int s;
	int n;
	printf("Before loop!\n");
test:
	s = 1;
	if(s)
		printf("In loop!\n");
		sleep(3);
	printf("Please input a number: \n");
	scanf("%d", &n);	
	if(n > 5)	
		goto outgo;
	else
		goto test;
outgo:
	printf("The End!\n");	
	exit(0);
}
