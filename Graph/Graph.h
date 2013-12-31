//邻接表中的节点
typedef struct EdgeNode {
	
	int		Vertex;
	struct	EdgeNode *Next;

} Vertex;

//邻接表头节点
typedef struct VertexNode{
	
	int		Degree;
	int 	Parent;
	int 	Color;
	int		Time;
	struct	EdgeNode *Next;

} VertexHead;

//图信息结构体
typedef struct Graph{
	
	int numOfVertex;
	int numOfEdge;
	int *Timed;
	int *Timef;

}

VertexHead * CreatUndirectedGraph(int Nvertex, int Nedge);
VertexHead * CreatDirectedGraph(int Nvertex, int Nedge);
void BroadFirstSearch(VertexHead * Graph, int Start);
void DepthFirstSearch(VertexHead *Graph, int *link);
void DFSVisit (VertexHead *Graph, int index);
void TopSort(VertexHead* Graph);
VertexHead * GraphTranspose(VertexHead *Graph, int Nvertex);
		
