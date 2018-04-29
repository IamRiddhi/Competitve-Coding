/*
Johnny, a computer science student from the Bytelandian Technological University (BTU), has finally managed to write a program to solve the N queens problem. However, his version of the N queens problem is not really all that similar to the classical one.

Recall that in the N queens problem, there is a square chessboard of size NxN. The goal is to put N queens on the chessboard so that no two queens would be able to attack each other.

In Johnny's version of the problem (which he states to be "much harder" than the original one), there are K "blocked" squares given on the chessboard. The goal is still the same: to put N queens on the chessboard such that no two queens would be able to attack each other. However, there are some differences due to the existence of blocked squares. First, a queen cannot be put on a blocked square. Secondly, two queens are considered to be able to attack each other only if there is no blocked square between them. Finally, there must be exactly one queen on every column of the board.

Johnny claims that his program solves the above problem very effectively. He generates some test cases (which his program can solve within minutes) to challenge you. You know the method Johnny used to generate the test case. For a given N, Johnny randomly picks a number K between 1 and N2/2 with equal probability. After that, Johnny picks K blocked squares on the chess board. Any combinations of K squares can be picked with equal probability.

Write a program that can solve Johnny's test cases within seconds.

Input
The first line contains t, the number of test cases (about 5). Then t test cases follow. Each test case has the following form:

The first line contains two integers N and K (8 <= N <= 500, 1 <= K <= N2/2)
Each line in the next K lines contains two integers i, j which are the row and the column number of a blocked square (1 <= i, j <= N)
Each test case's input is separated by a blank line. The rows and the columns of the chessboard are numbered from 1 to N. There is always a solution for each test case.

Output
For each test case, print a single line containing N integers a1, a2, ..., aN in which ai is the row number of the queen in column i. Any correct solution will be accepted.

Example
Input
1

8 15
7 7
3 1
7 1
4 8
8 3
6 5
4 4
2 1
8 2
6 3
3 7
7 6
2 3
1 2
6 4

Output
4 2 7 5 2 4 6 8 */

#include<stdio.h> //board[j]=i where j is column and i is row.
#include<stdlib.h>
int *board,**blocked; 
void print(int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",board[i]);
}
int caniplace(int qno,int n)
{
    int row,col ;
    for(row=0;row<n;row++)
    {
        if(blocked[row][qno]==1 )
            return 0;
        else
        {
            for(col=0;col<n;col++)
            
        }
    }
}
int main()
{
    int t,i,j,n,k,bi,bj;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        board=(int*)malloc(n*sizeof(int));
        blocked=(int**)malloc(n*sizeof(int*));
        for(i=0;i<n;i++)
            blocked[i]=(int*)calloc(n,sizeof(int));
        for(i=1;i<=k;i++)
        {
            scanf("%d%d",&bi,&bj);
            blocked[bi-1][bj-1]=1;
        }
        
        
        
    }
    return 0;
}

