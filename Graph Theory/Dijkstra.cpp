#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#define MAX 3001
int n,src;
int cost[MAX][MAX];
int distance[MAX],set[MAX];
int findMin()
{
    int index=-1;
    int min= INT_MAX;
    int i;
    for(i=1;i<=n;i++)
    {
        if(set[i]==0 && min>distance[i])
        {
            min=distance[i];
            index=i;
        }
    }
    
    return index;
}
void dijkstra()
{
    int i,j,minNode,minD,w;
    for(i=1;i<=n;i++)
    {
        distance[i]=cost[src][i]; 
    }
    set[src]=1;
    
    for(i=2;i<n;i++)
    {
        minNode= findMin();
        minD= distance[minNode];
        set[minNode]=1;
         for(j=1;j<=n;j++)
        {  
            if(set[j])
                  continue;
            if(minD==INT_MAX || cost[minNode][j]==INT_MAX)
                w=INT_MAX;
            else
                w=minD+cost[minNode][j];
            if(distance[j]>w) //w=minD+cost[minNode][j]
                distance[j]= w;
        }
        
    }
    //printing.
    for(i=1;i<=n;i++)
    {
        if(i==src)
            continue;
        if(distance[i]==INT_MAX)
        printf("-1 ");
        else
        printf("%d ",distance[i]);
    }
    printf("\n");
}
int main(void)
{
    int t,m,x,y,r;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        int i,j;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(i==j)
                    cost[i][i]=0;
                else
                    cost[i][j]=INT_MAX;
            }
        }
        for(i=1;i<=m;i++)
        {
            scanf("%d%d%d",&x,&y,&r);
            cost[x][y]=r;
        }
         scanf("%d",&src);
        for(i=1;i<=n;i++)
        {
            distance[i]=INT_MAX;
            set[i]=0;
        }
        dijkstra();
    }
	return 0;
}


