#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "wordcount.h"

int main(int argc, char *argv[])
{
	int maxchar = 0;
	struct list_head *list;
	struct list_head headnode;
	list = &headnode;
	INIT_LIST_HEAD(list);

	if(argc == 1)
	{
		int i = 0;
		char s = '\0';
		int wordsize = 0;
		char buff[WORDSIZE];
		printf("Input a sentence, blank line means quit:\n");	
		while((s = getchar()) != '\n')
		{
			if (wordsize == WORDSIZE-1)
			{
				printf("Too many words!!!\n");
				break;
			}
				
			buff[wordsize] = s;
			wordsize++;
		}
		buff[wordsize] = '\0';	
		printf("%d\n", wordsize);
		printf("%s\n", buff);

	}
	else if(argc == 2)
	{

	}
	else
	exit(EINVAL);
	
	exit(0);
}
