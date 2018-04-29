#include <stdio.h>
#include<stdlib.h>
int * board,*col,*lr,*rl,n;
void printboard()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            if(board[i]==j)
                printf("Q%d\t",i+1);
            else
                printf("*\t");
        printf("\n");
    }
}
int caniplace(int qno,int c)
{
    if(col[c]==1 || lr[n-1+c-qno]==1 || rl[qno+c]==1)
        return 0;
    return 1;
}
int updateBoard(int r, int c)
{
    board[r]=c;
    lr[n-1+c-r]=rl[c+r]=col[c]=1;
    return c;
}
void undoMove(int r,int c)
{
    lr[n-1+c-r]=rl[c+r]=col[c]=0;
}

void nqueens(int qno)
{
	static int count = 0;
    if(qno==n)
    {
        printboard();
        printf("\n");
        count++;
        return ;
    }
    int c,colUpdated;
    for(c=0;c<n;c++)
    {
        if(caniplace(qno,c))
        {                   
            colUpdated=updateBoard(qno,c);
           	nqueens(qno+1);
           	undoMove(qno,colUpdated);
        }
    }
    if(qno==0)
    	printf("the count is %d",count);
}
int main()
{
    scanf("%d",&n);
	board=(int*)malloc(n*sizeof(int));
	col=(int*)calloc(n,sizeof(int));
	lr=(int*)calloc(2*n-1,sizeof(int));  //NW TO SE DIAGONAL  C-R VALUE, WITH C<R VALUES AS STARTING INDEX..CAN BE ACCESSED BY LR[N-1+C-R]
	rl=(int*)calloc(2*n-1,sizeof(int)); // NE TO SW DIAGONAL C+R VALUE IS STARTING INDEX
	nqueens(0);
    return 0;
}
