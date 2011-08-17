#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "wordcount.h"
int main(int argc, char *argv[])
{
	int maxchar = 0;
	int wordcount = 0;
	char *wordlist[BUFFSIZE];
	char word[BUFFSIZE];

	if(argc == 1)
	{
		printf("Input a sentence, print \"quit\" if you want quit\n");
		int i;
		for(i = 0; ; i++)
		{
			scanf("%s", word);
			if(strcmp(word, "quit") == 0)
				break;
			wordlist[i] = word;
		}		
		for(i = 0; i <= wordcount; i++) 
			printf("%s\n", wordlist[i]);
	
	}
	else if(argc == 2)
	{

	}
	else
	exit(EINVAL);
	
	exit(0);
}
