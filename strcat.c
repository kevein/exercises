#include <stdio.h>
#include <stdlib.h>

char * _strcat(char *, const char *);
void _strcp(char *, char *);

int main(){

	char *str1 = "hello", *str2 = "world";
	char *str = malloc(sizeof(char)*100);
//	_strcp(str, str1);
//	printf("%s\n", str);
	str = _strcat(str1, str2);
	printf("%s\n", str);
	return 0;

}

char * _strcat(char * dst, const char * src){

	char *temp = dst;
	
	while(*dst)
		dst++;
	dst = src;
	while(*dst++ = *src++)
		;

	return temp;
}

void _strcp(char *s, char *t) {
	while (*s++ = *t++)
	;
}
