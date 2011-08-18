#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list_node 
{
	struct list_node  *next, *prev;
	char *str;
};      


struct list_node* get_list_tail(struct list_node  *head)
{
        struct list_node  *temp;
        for(temp = head; temp->next != temp; temp = temp->next)
	{
		printf("%s\n", temp->str);
	}
        return temp;
}
          

int main()
{
	struct list_node* t1;
	struct list_node* t2;
	struct list_node* t3;
	struct list_node* t4;
	
	printf("%d\n", sizeof(struct list_node));
	
	memset(&t1, 0, sizeof(struct list_node));
	memset(&t2, 0, sizeof(struct list_node));
	memset(&t3, 0, sizeof(struct list_node));
	memset(&t4, 0, sizeof(struct list_node));

	t1->prev = t1;
	t1->next = t2;
	t2->prev = t1;
	t2->next = t3;
	t3->prev = t2;
	t3->next = t4;
	t4->prev = t3;
	t4->next = t4;
	
	t1->str = malloc(20 * sizeof(char));
	t2->str = malloc(20 * sizeof(char));
	t3->str = malloc(20 * sizeof(char));
	t4->str = malloc(20 * sizeof(char));

	struct list_node* tail;
	tail = get_list_tail(t1);

	printf("Tail's string is %s\n", tail->str);
}
