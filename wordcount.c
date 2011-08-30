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

	/* if no argument, we will accept a single sentence.
 	**/
	if(argc == 1)
	{
		int i = 0;
		char s = '\0';
		int wordsize = 0;
	/* buffer for storing input
 	**/
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
		int nr_of_word = 1;
		for(i = 0; i < wordsize; i++)
		{
			if(buff[i] == 0x20)
				nr_of_word++;
		}
		

	}
	else if(argc == 2)
	{
		printf("Not implement yet!\n");
	}
	else
	exit(EINVAL);
	
	exit(0);
}
