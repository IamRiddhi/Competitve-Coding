#include<stdio.h>
#include<stdlib.h>
int main()
{
	int t,n, **graph,i,j,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		graph=(int**)malloc(n*sizeof(int*));
		for(i=0;i<n;i++)
			graph[i]= (int*)malloc(n*sizeof(int));
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%d",&graph[i][j]);
			}
		}
		
		for(k=0;k<n;k++) //traversing through kth node or traversing through no other node greater than k(that node or direct distance)  in algorithmic terms
		{
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					if(graph[i][k]+graph[k][j]<graph[i][j])
						graph[i][j]= graph[i][k] + graph[k][j];
				}
			}
		}
		
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				printf("%d ",graph[i][j]);
			}
		}
		printf("\n");
	}
	return 0;
}
