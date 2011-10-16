#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct node
{
	ElemType data;
	struct node *lc;	// left child
	struct node *rc;	// right child
} BTree;

void createBT(BTree *&bt, int a[], int n)
{
	BTree *p;
	int i;
	bt = (BTree *)malloc(sizeof(BTree));	
	bt->lc = bt->rc = NULL;
	bt->data = a[0];

	for(i = 1; i < n; i++)
	{
		p = (BTree *)malloc(sizeof(BTree));
		p->data = a[i];
		if(p->)
	}
}

void preOrder(BTree *b)		//recursive preorder traversal
{
	if(b != NULL)
	{
		printf("%c \t", b->data);
		preOrder(b->lc);
		preOrder(b->rc);
	}
}

int main
{
	BTree *bt;
}
