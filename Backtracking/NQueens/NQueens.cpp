#include <stdio.h>
#include<stdlib.h>
int * board;
void printboard(int n)
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

int caniplace(int row,int col)
{
     int i;
     for(i=0;i<row;i++)
         if(board[i]==col || abs(board[i]-col)==abs(i-row))
            return 0;
    return 1;
}
void nqueens(int qno,int n)
{
    if(qno==n)
    {
        printboard(n);
        printf("\n\n");
        return;
    }    
    int i;
    for(i=0;i<n;i++)  //checking columns
        if(caniplace(qno,i))
        {
            board[qno]=i;
            nqueens(qno+1,n);
        }
           
}
int main() {
	int n;
	scanf("%d",&n);
	board=(int*)malloc(n*sizeof(int));
	nqueens(0,n);
	return 0;
}
