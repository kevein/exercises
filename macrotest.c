#include <stdio.h>

#define cat(x,y) x ## y

int main(){
	int result;
	result = cat(1,2);
	printf("%d\n",result);	
	result = cat(cat(1,2),3);
	printf("%d\n",result);	
	return 0;
}
