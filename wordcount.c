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
		int i;
		char buff[WORDSIZE];
		printf("Input a sentence, blank line means quit:\n");	
		while(fgets(buff, WORDSIZE, stdin) != NULL)
		{
			if((str[0] == '\n') || (str[0] == '\0'))
			{
				printf("Bye\n");
				exit(0);
			}
		}
	}
	else if(argc == 2)
	{

	}
	else
	exit(EINVAL);
	
	exit(0);
}
