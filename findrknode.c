#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef int ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode * next; 
} LinkList;

void createListF(LinkList *&list, ElemType a[], int n)
{
	LinkList *p;
	LinkList *tmp;
	int i;
	
	list = (LinkList *)malloc(sizeof(LinkList)); 
	list->next = NULL;

	for(i = 0; i < n; i++)
	{
		p = (LinkList *)malloc(sizeof(LinkList));
		p->data = a[i];
		p->next = list->next;
		list->next = p;
	}
}

int searchrk(LinkList *list, int k)
{
	LinkList *p, *q;
	int count = 0;
	p = q = list->next;

	while(p != NULL && count < k)
	{
		count++;
		p = p->next;
	}
	if (p == NULL && count == k)
	{
                printf("%d\n", q->data);
		return(1);
	}		
	if (p == NULL)
		return(0);

	else
	{
		while (p != NULL)
		{
			q = q->next;
			p = p->next;
		}
		printf("%d\n", q->data);
		return(1);
	}
}

void reversePrintList(LinkList *L)
{
	if (L != NULL)
	{
		reversePrintList(L->next);
		printf("%d\n", L->data);
	}
}

int main(int argc, char *argv[])
{
	int a[6] = {6,5,4,3,2,1}, k;
        LinkList *list;
        createListF(list, a, 6);

#ifdef	FINDK		// Compile with -DFINDK, program will find the backwards k node.
        if(argc != 2)
        {
                printf("Usage: ./command number\n");
                exit(1);
        }

	k = atoi(argv[1]);
	
	if(k < 1 || k > 6)
        {
                printf("number should not less than 0 or greater than 6!!!\n");
                exit(2);
        }

	searchrk(list, k);
#endif
#ifdef REVERSE		// Compile with -DREVERSE, program will print reversed order of the Link list.
	reversePrintList(list);
#endif
	exit(0);
	
}
