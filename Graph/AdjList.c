#include  <stdio.h>
#include  <string.h>
#include  "Graph.h"

void PrintGraph(VertexHead *Graph, int Nvertex);
void PrintPath(VertexHead* Graph, int From, int To);

extern int *Timef;
extern int *Timed;

int main(void) 
{
	int Nvertex, Nedge,i;
	VertexHead *dGraph, *unGraph, *GraphT;
	int Start, To;
	printf("the Number of Vertex and Edge: \n");
	scanf("%d%d", &Nvertex, &Nedge);
	
	unGraph = CreatUndirectedGraph(Nvertex, Nedge);
	dGraph = CreatDirectedGraph(Nvertex, Nedge);
	PrintGraph(dGraph, Nvertex);
	PrintGraph(unGraph, Nvertex);
	

	printf("input the Starting and Ending: \n");
	scanf("%d%d", &Start, &To);
	BroadFirstSearch(dGraph, Start);
	BroadFirstSearch(unGraph, Start);
	PrintPath(dGraph, Start, To);
	printf("\n");
	PrintPath(unGraph, Start, To);
	printf("\n");
	
	DepthFirstSearch(dGraph, Nvertex);
	for (i = 0; i <= Nvertex; i++) {
		printf("%d ", Timed[i]);
	}
	printf("\n");
	for (i = 0; i <= Nvertex; i++) {
		printf("%d ", Timef[i]);
	}
	printf("\n");

	TopSort(dGraph, Nvertex);

	GraphT = GraphTranspose(dGraph, Nvertex);
	PrintGraph(GraphT, Nvertex);
	return 0;
}

void PrintGraph(VertexHead *Graph, int Nvertex) {
	int i;
	Vertex *ptr;
	for (i = 1; i <= Nvertex; i++) {
		printf("Vertex %d: ", i);
		ptr = Graph[i].Next;
		while (ptr) {
			printf(" %d", ptr->Vertex);
			ptr = ptr->Next;
		}
		printf("\n");
	}
}

void PrintPath(VertexHead* Graph, int From, int To)
{
	if(From == To)
		printf("%d ", From);
	else if(Graph[To].Parent == 0)
		printf("no path from %d to %d\n", From, To);
	else
	{
		PrintPath(Graph, From, Graph[To].Parent);
		printf("%d ", To);
	}
}
