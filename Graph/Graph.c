#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
#include  "Graph.h"

#define     Black	2
#define     White	0
#define     Grey	1

int Queue[1024];
int Rear = 0, Front = 0, QueueSize = 0, linkCount;
int GraphSize = 0;

//创建有向图
VertexHead *CreatDirectedGraph(int Nvertex, int Nedge) 
{

	int i, EdgeFrom, EdgeTo;
	VertexHead * Graph;
	Vertex*	Temp;
	
	//建邻接表头节点数组
	Graph = (VertexHead *)malloc((Nvertex + 1) * sizeof(struct VertexNode));
	memset(Graph, 0, (Nvertex + 1)* sizeof(struct VertexNode));
	GraphSize = Nvertex;	
	//读图
	for (i = 1; i <= Nedge; i++) {
		scanf("%d%d", &EdgeFrom, &EdgeTo);
		Temp = (Vertex *)malloc(sizeof(struct EdgeNode));
		Temp->Vertex = EdgeTo;
		//新节点插入到表头
		Temp->Next = Graph[EdgeFrom].Next;
		Graph[EdgeFrom].Next = Temp;
		Graph[EdgeTo].Degree++;
	}
	return Graph;
}

//创建无向图
VertexHead *CreatUndirectedGraph(int Nvertex, int Nedge) 
{

	int i, EdgeFrom, EdgeTo;
	VertexHead * Graph;
	Vertex*	Temp;
	
	//建邻接表头节点数组
	Graph = (VertexHead *)malloc((Nvertex + 1) * sizeof(struct VertexNode));
	memset(Graph, 0, (Nvertex + 1)* sizeof(struct VertexNode));
	GraphSize = Nvertex;
	//读图
	for (i = 1; i <= Nedge; i++) {
		scanf("%d%d", &EdgeFrom, &EdgeTo);
		Temp = (Vertex *)malloc(sizeof(struct EdgeNode));
		Temp->Vertex = EdgeTo;
		//新节点插入到表头
		Temp->Next = Graph[EdgeFrom].Next;
		Graph[EdgeFrom].Next = Temp;
		if (EdgeFrom != EdgeTo) {
			Temp = (Vertex *)malloc(sizeof(struct EdgeNode));
			Temp->Vertex = EdgeFrom;
			//新节点插入到表头
			Temp->Next = Graph[EdgeTo].Next;
			Graph[EdgeTo].Next = Temp;
		}
	}
	return Graph;
}

//入队列
int Enqueue(int value) {
	if(QueueSize >= 1024)
	{
		printf("Queue Full\n");
		return -1;
	}
	else
	{
		Queue[Rear] = value;
	    if((++Rear) == 1024)
		  Rear = 0;
		QueueSize++;
	}
	return 0;
}

//出队列
int Dequeue() {
	int temp;
	if(QueueSize <= 0) {
		printf("Queue Empty\n");
		return -1;
	}
	else
	{
		temp = Queue[Front];
		if((++Front) == 1024)
		  Front = 0;
		QueueSize--;
		return temp;
	}
}

//清空队列

void EmptyQueue() {
	Rear = 0;
	Front = 0;
	QueueSize = 0;
}

//广度优先搜索
void BroadFirstSearch(VertexHead * Graph, int Start) {
	
	int Ver;
	Vertex *temp;
	Graph[Start].Color = Grey;
	Graph[Start].Parent = -1;
	EmptyQueue();
	Enqueue(Start);
	while ((Ver = Dequeue()) != -1) {
		Graph[Ver].Color = Black;
		temp = Graph[Ver].Next;
		while (temp) {
			if (Graph[temp->Vertex].Color == White) {
				Graph[temp->Vertex].Parent = Ver;
				Graph[temp->Vertex].Color = Grey;
				if (Enqueue(temp->Vertex) < 0)
				  return;
			}
			temp = temp->Next;
		}
	}
}

//深度优先搜索
void DepthFirstSearch(VertexHead *Graph, int* link) {
	
	int i;

	//涂白
	for (i = 1; i <= GraphSize; i++) {
		Graph[i].Color = White;
		Graph[i].Parent = 0;
	}
	if (link == NULL)
		link = (int *)malloc(sizeof(int));
	//遍历
	for (i = 1; i <= GGraphSize; i++) {
		if(Graph[i].Color == White)
			DFSVisit(Graph, i, link);
	}
}

void DFSVisit (VertexHead *Graph, int index, int *link) {
	
	static int time = 0;
	Vertex * Temp;
	TopLink *ptr;
	Graph[index].Color = Grey;
	
	Temp = Graph[index].Next;
	while (Temp) {
		
		if (Graph[Temp->Vertex].Color == White) {
			Graph[Temp->Vertex].Parent = index;
			DFSVisit(Graph, Temp->Vertex);
		}
		Temp = Temp->Next;
	}
	Graph[index].Color = Black;
	link[GraphSize - (++time)] = index;
}

//拓扑排序
void TopSort(int* link)
{
	int i;
	for (i = 0; i < GraphSize; i++)
	  printf("%d ", link[i]);
	printf("\n");
}

//转置图
VertexHead * GraphTranspose(VertexHead *Graph)
{
	int i;
	VertexHead *GraphT = (VertexHead *)malloc((GraphSize + 1)* sizeof(struct VertexNode));
	memset(GraphT, 0, GraphSize * sizeof(struct VertexNode));

	Vertex * temp, *ptr;
	for (i = 1; i <= GraphSize; i++) {
		temp = Graph[i].Next;
		while(temp) {
			ptr = (Vertex *)malloc(sizeof(struct EdgeNode));
			ptr->Vertex = i;
			ptr->Next = GraphT[temp->Vertex].Next;
			GraphT[temp->Vertex].Next = ptr;
			temp = temp->Next;
		}
	}

	return GraphT;
}

//强连通分支
void StrongConnectedComponents(VertexHead* Graph)
{
	VertexHead * GraphT;
	TopLink *ptr;		//拓扑链表，用于按f(u)逆序进行深度优先遍历
	//计算转置矩阵
	GraphT = GraphTranspose(Graph);
	//深度优先搜索
	DepthFirstSearch(Graph);
	//对转置矩阵进行深度有限搜索

}
