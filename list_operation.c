#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list_node 
{
	struct list_node  *next, *prev;
	char *str;
};      


void get_list_tail(struct list_node *head, struct list_node *tail)
{
	struct list_node *temp = head;
//	printf("%d, tail: %p\n", __LINE__, tail);
        for(; head->next != head; head = head->next) 
	{
		printf("%s\n", head->str);
	}
	*tail = *head;
	head = temp;

//	printf("%d, tail: %p\n", __LINE__, tail);
	printf("Tail's string is %s\n", tail->str);

	
}
          

int main()
{
	struct list_node t1;
	struct list_node t2;
	struct list_node t3;
	struct list_node t4;
	
	t1.prev = &t1;
	t1.next = &t2;
	t2.prev = &t1;
	t2.next = &t3;
	t3.prev = &t2;
	t3.next = &t4;
	t4.prev = &t3;
	t4.next = &t4;
	
	t1.str = "str1";
	t2.str = "str2";
	t3.str = "str3";
	t4.str = "str4";

	struct list_node tail;
//	printf("%d, tail: %p\n", __LINE__, &tail);
	get_list_tail(&t1, &tail);

	printf("Tail's string is %s\n", tail.str);
}
