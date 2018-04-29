#include<bits/stdc++.h>
using namespace std;
void backtrack(int **maze,int n,int i,int j,int **soln)
{
  
      if(i==n-1 && j==n-1 && maze[i][j]==1) //only this final state to be visited more than once.
      {
        soln[i][j] = 1;
        for(int ik=0;ik<n;ik++)
        {
          for(int jk=0;jk<n;jk++)
              cout<<soln[ik][jk]<<" ";
        }
        cout<<endl;
        return;
      }
  
  	  if(i<0 || i>=n || j<0 || j>=n || maze[i][j]==0 || soln[i][j]==1)
      	return;
	
      soln[i][j] = 1;
  	
      backtrack(maze,n,i+1,j,soln);
  	  backtrack(maze,n,i-1,j,soln);
  	  backtrack(maze,n,i,j+1,soln);
      backtrack(maze,n,i,j-1,soln);
	
  	  soln[i][j] = 0;
}

void ratInAMaze(int **maze, int n)
{
  	int **inp = new int*[n];
  	for(int i=0;i<n;i++)
      	inp[i] = new int [n];
  	for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        	inp[i][j] = maze[i][j];
  
  	int **soln = new int*[n];
  	for(int i=0;i<n;i++)
      	soln[i] = new int[n];
  
  for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
        soln[i][j] = 0;
    }
	backtrack(inp,n,0,0,soln);
}
int main()
{
	int n,**a;
	cin>>n;
	a = new int*[n];
	for(int i=0;i<n;i++)
		a[i] = new int[n];
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	
	ratInAMaze(a,n);
	return 0;
}
