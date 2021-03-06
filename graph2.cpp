#include <bits/stdc++.h>
using namespace std;
#define long long int ll

typedef struct 
{
	int src,dest;
}Edge;

typedef struct
{
	int V,E;
	Edge *edge;
}Graph;

Graph* createGraph(int V,int E)
{
	Graph *graph = (Graph *)malloc(sizeof(Graph));
	graph->E = E;
	graph->V = V;
	graph->edge = (Edge *)malloc(sizeof(Edge)*graph->E);
	return graph;
}

int find(int parent[],int i)
{
	if(parent[i]==-1)
	return i;
	return find(parent,parent[i]);
}

void Union(int parent[],int x,int y)
{
	int xset = find(parent,x);
	int yset = find(parent,y);
	parent[xset]=yset;
}

int isCycle(Graph* graph)
{
	int *parent = new int[graph->V];
	memset(parent,-1,sizeof(parent));
	for(int i=0;i<graph->E;i++)
	{
		int x = find(parent,graph->edge[i].src);
		int y = find(parent,graph->edge[i].dest);
		if(x==y)
		return 1;
		Union(parent,x,y);	
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int V = 3, E = 3;
    Graph* graph = createGraph(V, E);
 
    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
 
    // add edge 1-2
    graph->edge[1].src = 1;
    graph->edge[1].dest = 2;
 
    // add edge 0-2
    graph->edge[2].src = 0;
    graph->edge[2].dest = 2;
 
    if (isCycle(graph))
        printf( "graph contains cycle" );
    else
        printf( "graph doesn't contain cycle" );
 
return 0;
}

