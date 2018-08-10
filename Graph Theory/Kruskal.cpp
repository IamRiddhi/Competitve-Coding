#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	int u;
	int v;
	int weight;
}Edge;

int n,**t,*parent,noOfEdges;
Edge *edge; 

int cmpfunc (const void * e1, const void * e2) 
{
   return ( ( (Edge*)e1)->weight - ( (Edge*)e2 )->weight  );
}

void Union(int i, int j)
{
	parent[j]=i;	
}

int Find(int node)
{
	while(parent[node]!=-1)
	{
		node=parent[node];
	}
	return node;
}
int kruskalMST() //returns minimal cost 
{
	int i,u,v,w,edgeTaken;
	int cost=0;
	for(i=1;i<=n;i++)
		parent[i]=-1; // every node is in unique or disjoint parent.
	
	int indexMin=0;
	qsort(edge,noOfEdges,sizeof(Edge),cmpfunc); //analogous to creating the heap and removing the first element(delete_min)
	
	edgeTaken=0;
	
	while( edgeTaken<n-1 && indexMin<noOfEdges )
	{
		u=edge[indexMin].u;
		v=edge[indexMin].v;
		w=edge[indexMin++].weight;
		int a=Find(u);
		int b=Find(v); 
		if(a!=b)  // u and v are not in the same parent.	
		{
		    t[edgeTaken][0]=u;
	   		t[edgeTaken++][1]=v;
			Union(a,b);
			cost+=w;
		}
	}
    
	if(edgeTaken!=n-1)
		return -1;
	else
		return cost;
	
}

int main()
{ 
	int i;
	scanf("%d",&n);
    scanf("%d",&noOfEdges);
	edge=(Edge*)malloc((noOfEdges)*sizeof(Edge)); //starting from index 0.
	 
	t=(int**)malloc((n-1)*sizeof(int*));
	for(i=0;i<n-1;i++)
		t[i]=(int*)malloc(2*sizeof(int));  // t is target/solution array.
	parent=(int*)malloc((n+1)*sizeof(int));
	
    for(i=0;i<noOfEdges;i++)
        scanf("%d%d%d",&(edge[i].u),&(edge[i].v),&(edge[i].weight));
	printf("%d\n",kruskalMST());

	return 0;	
}
