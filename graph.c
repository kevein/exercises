#include <stdlib.h>
#include <stdio.h>

#define MAXV 10

typedef char ElemType;
typedef struct
{
	int no;		//顶点编号
	ElemType info;	//顶点其他信息
} VertexType;		//顶点类型定义

typedef struct
{
	int edges[MAXV][MAXV];	//邻接矩阵数组
	int n, e;		//顶点数和边数
	VertexType vexs[MAXV];	//存放顶点信息
} MGraph;			//图的邻接矩阵类型定义


typedef int InfoType;
typedef struct ANode		//边表节点类型
{
	int adjvex;		//该边终点的编号
	struct ANode *nextarc;	//指向下一个邻接点
	InfoType info;		//该边的相关信息
} ArcNode;

typedef struct Vnode		//顶点表节点类型
{
	ElemType data;		//顶点信息
	ArcNode *firstarc;	//指向第一个邻接点
} Vnode;

typedef Vonde AdjList[MAXV];	//AdjList是邻接表类型

typedef struct
{
	AdjList adjlist;	//邻接表
	int n, e;		//顶点数和边数
} AGraph;

int visited[MAXV];
void DFS(AGraph *G, int v)	//以邻接表为存储结构的深度优先遍历
{       //G表示以邻接表存储的图，v表示起始顶点
	ArcNode *p;		//边节点的指针
	visited[v] = 1;
	printf("%d: %c,", v, G->adjlist[v]->data);
	p = G->adjlist[v]->firstarc; 
	while(p != NULL)
	{
		if(visited[p->adjvex] == 0)//若p->adjvex顶点未被访问，递归访问之
			DFS(G, p->adjvex);
		p = p->nextarc;		//若p->adjvex被访问过，则跳到下一个邻接点
	}

}
