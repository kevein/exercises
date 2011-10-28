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

typedef ElemType SqTree[MAXSIZE];

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

void postOrder(BTree *b)         //recursive postorder traversal
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

BTree *binsearch(BTree *b, int k)
{
	if(b == NULL)
		return NULL;
	else if(b->data == k){
		printf("\nFind it: \t");
		return b;
	}
	else if(k < b->data){
		printf("%d ---> ", b->data);
		binsearch(b->lc, k);
	}
	else { 
		printf("%d ---> ", b->data);
		binsearch(b->rc, k);
	}
}

void levelOrder(BTree *b)
{
	BTree *p;
	BTree *qu[MAXSIZE];	//环形队列
	int front, rear;	//定义队头和队尾
	front = rear =0;	//置空队列

	if(b == NULL)
	{
		printf("The tree is null!\n");
		return;
	}
	rear++;
	qu[rear] = b;		//根节点入队列
	while(rear != front)
	{
		front = (front+1)%MAXSIZE;
		p = qu[front];
		printf("%d\t", p->data);
		if(p->lc != NULL)
		{
			rear = (rear + 1)%MAXSIZE;
			qu[rear] = p->lc;
		}
		if(p->rc != NULL)
		{
			rear = (rear + 1)%MAXSIZE;
			qu[rear] = p->rc;
		}
	}
	
	printf("\n");
}
void printLeaf(BTree *b)
{
	if(b != NULL)
	{
		if(b->lc == NULL && b->rc == NULL)
			printf("%d\t", b->data);
		printLeaf(b->lc);
		printLeaf(b->rc);
	}
}
void printLeaf1(BTree *b)
{
        BTree *btstack[MAXSIZE], *p;
        int top = -1;

        if(b != NULL)
        {
                p = b;
                while(p != NULL)
                {
                        if(p->rc != NULL)
                        {
                                top++;
                                btstack[top] = p->rc;
                        }
                        if(p->lc != NULL)
                                p = p->lc;
                        if(p->lc == NULL && p->rc == NULL)
                        {
                                printf("%d\t", p->data);
                                if(top > -1){
                                        p = btstack[top];
                                        top--;
                                }
                                else 
                                        break;
                        }
                }
        printf("\n");
        }
}

BTree *findparent(BTree *root, BTree *node)
{
        BTree *btstack[MAXSIZE], *p;
	//BTree *parent;
        int top = -1;

        if(root != NULL)
        {
                top++;
                btstack[top] = root;       //push root node into stack
                while(top > -1)
                {
                        p = btstack[top];       //pop root node from stack
                        top--;
			if(p->lc == node || p->rc ==node)
			{
//			printf("The parent of %d is %d\n", node->data, p->data);
//			parent = (BTree *) malloc(sizeof(BTree));
//			parent->data = p->data;
//			parent->lc = p->lc;
//			parent->rc = p->rc;
//			return parent;
				return p;
			}
                        if(p->rc != NULL)       //if root node has right child, push the right child of root node into stack
                        {
                                top++;
                                btstack[top] = p->rc;
                        }
                        if(p->lc != NULL)       //if root node has left child, push the left child of root node into stack
                        {
                                top++;
                                btstack[top] = p->lc;
                        }
                }
        }

	return NULL;	
}
void delnode(BTree *&b, ElemType k)
{
	if(b == NULL)
		return;
	BTree *p = b, *parent;
	if(p->data == k)
	{
		parent = findparent(b, p);
		if(parent->lc == p) parent->lc = NULL;	//if p is the left child of it's parent, set the parent's lc to NULL
		if(parent->rc == p) parent->rc = NULL;	//if p is the right child of it's parent, set the parent's rc to NULL
		free(p);
	}
}

void copytree(BTree *b, BTree *&t)
{
	if(b == NULL)
		t = NULL;
	else
	{
		t = (BTree *)malloc(sizeof(BTree));
		t->data = b->data;
		copytree(b->lc, t->lc);
		copytree(b->rc, t->rc);
	}
}

int like(BTree *a, BTree *b)		//判断两棵树是否相似
{
	if(a == NULL && b == NULL)
		return 1;
	if(a == NULL && b != NULL || a != NULL && b == NULL)
		return 0;
	else
	{
		return (like(a->lc, b->lc) && like(a->rc, b->rc));
	}

}

void trans2seq(SqTree a, BTree *b, int i)	//将链式存储编程顺序存储
{
	if(b != NULL)
	{
		a[i] = b->data;
		trans2seq(a, b->lc, 2*i);
		trans2seq(a, b->rc, 2*i+1);
	}
}

int main()
{
	BTree *bt, *node;
	int a[15] = {10,5,15,2,7,12,18,1,3,6,8,11,13,16,19};
	createBT(bt, a, 15);
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
	printf("levelOrder traversal:\n");
	levelOrder(bt);
//-------------------------------------------------------
	printf("Print leaves: \n");
	printLeaf1(bt);
	printLeaf(bt);
	printf("\n");
//-------------------------------------------------------
	node = binsearch(bt,3);	
	printf("%d\n", node->data);
//-------------------------------------------------------
	BTree *t;
	copytree(bt, t);
	printf("Tree t copied from tree bt: \n");
	levelOrder(t);	
//-------------------------------------------------------
	BTree *bt2;
	int b[15] = {20,15,25,12,17,22,28,11,13,16,18,21,23,26,29};
	int result;
	createBT(bt2, b, 15);
	result = like(bt, bt2);
	if(result == 1)	
		printf("bt is like bt2\n");
	else
		printf("bt is not like bt2\n");
	BTree *bt3;
	int c[14] = {20,15,25,12,17,22,28,11,13,16,18,21,23,26};
	createBT(bt3, c, 14);
	result = -1;
	result = like(bt, bt3);
	if(result)	
		printf("bt is like bt3\n");
	else if(result == 0)
		printf("bt is not like bt3\n");
//-------------------------------------------------------
	SqTree st;	//把链式存储的二叉树bt变为顺序存储的二叉树st
	int i;
	for (i = 0; i<MAXSIZE; i++)
		st[i] = '#';
	trans2seq(st, bt, 1);
	for (i = 0; i<30; i++)
	{
		if(st[i] == 35)
			printf("# ");
		else
		printf("%d ", st[i]);
	}
	printf("\n");
//-------------------------------------------------------
	exit(0);
}
