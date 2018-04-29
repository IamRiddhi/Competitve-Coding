#include<stdio.h>
#include<stdlib.h>
#define n 4
#define m 3
int *node;
int adj[4][4]={{0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0},
    };
void printSoln()
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("Node %d is colored with color %d.\n",(i+1),node[i]);
	}
	printf("\n");
}
int canicolor(int k, int color ) // checking whether kth node can be colored with a particular color.
{
	int j;
	for(j=0;j<n;j++)
		if(adj[k][j]==1 && color==node[j])
			return 0;
	return 1;
}

void ncoloring(int k)
{
	if(k==n)
	{
		printSoln();
		return;
	}
	int i;
	for(i=1;i<=m;i++)   //running through all the colors as i was running through all columns in nqueens.
	{
		if(canicolor(k,i))
		{  
			node[k]=i;
			ncoloring(k+1);	
		}	
	}		
}

int main()
{
	int i;
	
	node= (int*)calloc(n,sizeof(int)); // all nodes filled with 0 color i.e invalid color or no colour.
// 	adj=(int**)malloc(n*sizeof(int*));
// 	for(i=0;i<n;i++)
// 		adj[i]=(int*)malloc(n*sizeof(int));
	

	ncoloring(0);	
	return 0;
}



