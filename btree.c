#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 128
typedef int ElemType;

typedef struct node
{
	ElemType data;
	struct node *lc;	// left child
	struct node *rc;	// right child
} BTree;

void createBT(BTree *&bt, int a[], int n)
{
	BTree *p, *q;
	int i;
	bt = (BTree *)malloc(sizeof(BTree));	
	bt->lc = bt->rc = NULL;
	bt->data = a[0];

	for(i = 1; i < n; i++)
	{
		q = bt;
		p = (BTree *)malloc(sizeof(BTree));
		p->data = a[i];
		p->lc = p->rc = NULL;
		while(q != NULL)
		{
			if(p->data <= q->data){
				if(q->lc == NULL)
					break;
				q = q->lc;
			}
			else if(p->data > q->data){
				if(q->rc == NULL)
					break;
				q = q->rc;
			}
		}

		if(p->data <= q->data)
			q->lc = p;
		else if(p->data > q->data)
			q->rc = p;
	}
}

void preOrder(BTree *b)		//recursive preorder traversal
{
	if(b != NULL)
	{
		printf("%d\t", b->data);
		preOrder(b->lc);
		preOrder(b->rc);
	}
}

void inOrder(BTree *b)         //recursive inorder traversal
{
        if(b != NULL)
        {
                inOrder(b->lc);
                printf("%d\t", b->data);
                inOrder(b->rc);
        }
}

void postOrder(BTree *b)         //recursive inorder traversal
{
        if(b != NULL)
        {
                postOrder(b->lc);
                postOrder(b->rc);
                printf("%d\t", b->data);
        }
}

void preOrder1(BTree *b)		 //non-recursive preorder traversal
{
	BTree *btstack[MAXSIZE], *p;	
	int top = -1;

	if(b != NULL)
	{
		top++;
		btstack[top] = b;	//push root node into stack
		while(top > -1)
		{
			p = btstack[top];	//pop root node from stack
			top--;
			printf("%d\t", p->data); //access data of root node
			if(p->rc != NULL)	//if root node has right child, push the right child of root node into stack
			{
				top++;
				btstack[top] = p->rc;
			}
			if(p->lc != NULL)	//if root node has left child, push the left child of root node into stack
			{
				top++;
				btstack[top] = p->lc;
			}
		}
		printf("\n");
	}
}

void inOrder1(BTree *b)                 //non-recursive inorder traversal
{
	BTree *btstack[MAXSIZE], *p;	
	int top = -1;	
	if(b != NULL)
	{
		p = b;
		while(top > -1 || p != NULL)
		{
			while(p != NULL)
			{
				top++;		//把所有的左节点入栈	
				btstack[top] = p;			
				p = p->lc;
			}
			if(top > -1)
			{
				p = btstack[top];	//没有左子树或左子树已经访问过
				top--;
				printf("%d\t", p->data); //访问根节点
				p = p->rc;		 //访问右子树
			}
		}
	printf("\n");
	}
}

void postOrder1(BTree *b)                 //non-recursive postorder traversal
{
	BTree *btstack[MAXSIZE], *p = b, *q;	//q表示栈顶节点的前一个以访问节点		
	int flag, top = -1;

	if(b != NULL)
	{
		do
		{
			while(p != NULL)	//将P的所有左节点入栈
			{
				top++;
				btstack[top] = p;
				p = p->lc;
			}

			q = NULL;
			flag = 1;	//这是flag=1表示需要处理栈顶节点
			while(top > -1 && flag == 1)
			{
				p = btstack[top];	//取出栈顶元素
				if(p->rc == q)	//右孩子不存在或者右孩子已被访问过，访问该节点
				{
				printf("%d\t", p->data);//访问p节点
				top--;				
				q = p;
				}
				else
				{
				p = p->rc;	//p指向右孩子节点
				flag = 0;	//设置flag=0，表示栈顶节点处理完毕
				}
			}
		}while(top > -1);
		printf("\n");
	}
}

int main()
{
	BTree *bt;
	int a[7] = {8,13,2,1,3,10,20};
	createBT(bt, a, 7);
//-------------------------------------------------------
	printf("PreOrder traversal:\n");
	preOrder(bt);
	printf("\n");
	preOrder1(bt);
//-------------------------------------------------------
	printf("InOrder traversal:\n");
	inOrder(bt);
	printf("\n");
	inOrder1(bt);
//-------------------------------------------------------
	printf("PostOrder traversal:\n");
	postOrder(bt);
	printf("\n");
	postOrder1(bt);
//-------------------------------------------------------
	exit(0);
}
