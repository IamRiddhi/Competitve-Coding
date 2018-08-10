#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int **cost,n, noOfEdges, *near, **solution,Mincost,minInitialEdgeWeight,*set,node1,node2,nodesTaken;

void printSolution()
{
    int i;
    for(i=0;i<n-1;i++)
        printf("%d\t%d\t%d\n",solution[i][0],solution[i][1],solution[i][2]);
}

int existsinSet(int node)
{
	int i;
	for(i=0;i<n;i++)
		if(set[i]==node)
			return 1;
	return 0;
}
void updateNear(int enteringNode)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(!existsinSet(i))
		{
			if(cost[i][near[i]]>cost[enteringNode][i])
				near[i]=enteringNode;
		}
	}
}
int WhichNodeToInsertIntoSetFromNear()
{
	int i;
	int node=-1,min= INT_MAX;
	for(i=1;i<=n;i++)
		if(!existsinSet(i)&& min>cost[i][near[i]])
		{
			min=cost[i][near[i]];
			node=i;
		}
	return node;
}

int prim()
{
	int edgeTaken=0,i, nodeEnteringIntoSet;
	nodesTaken=0;
	
	solution[edgeTaken][0]=node1;
	solution[edgeTaken][1]=node2;
	solution[edgeTaken++][2]=minInitialEdgeWeight;
	
	set[nodesTaken++]=node1;
	set[nodesTaken++]=node2;
	
	updateNear(node2);
	
	Mincost+= minInitialEdgeWeight;
	
	while(edgeTaken<n-1)
	{
		nodeEnteringIntoSet= WhichNodeToInsertIntoSetFromNear();
		set[nodesTaken++]= nodeEnteringIntoSet;
		
		solution[edgeTaken][0]= nodeEnteringIntoSet;
		solution[edgeTaken][1]= near[nodeEnteringIntoSet];
		solution[edgeTaken++][2]=  cost[nodeEnteringIntoSet][near[nodeEnteringIntoSet]];
		
		Mincost+=  cost[nodeEnteringIntoSet][near[nodeEnteringIntoSet]];
		
		updateNear(nodeEnteringIntoSet);
	}
	printSolution();
	return Mincost;
}

int main()
{
	int i,j,u,v,w;
	Mincost=0;
	scanf("%d",&n);
	scanf("%d",&noOfEdges);
	
	cost = (int**)malloc((n+1)*sizeof(int*));
	for(i=0;i<=n;i++)
		cost[i]=(int*)malloc( (n+1)*sizeof(int));
	
	//initialisng the cost matrix .
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i==j)
				cost[i][i]=0;
			else 
				cost[i][j]= INT_MAX; // node i and node j are not connected.
		}
	}
	minInitialEdgeWeight=INT_MAX;
	//take input of edges .
	for(i=1;i<=noOfEdges;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		cost[u][v]=w;
		cost[v][u]=w;
		if(minInitialEdgeWeight>w)
		{
			minInitialEdgeWeight=w;	
			node1=u; node2=v;
		}
	} 
		

	near= (int*)malloc((n+1)*sizeof(int)); //maintain the nearest node of each node from current set.	
	for(i=1;i<=n;i++)
		near[i]=node1;
	
	set= (int*)malloc(n*sizeof(int));
	solution= (int**)malloc((n-1)*sizeof(int*));
	for(i=0;i<n-1;i++)
		solution[i]=(int*)malloc(3*sizeof(int));
	
	printf("%d\n",prim());	
	return 0;
}
