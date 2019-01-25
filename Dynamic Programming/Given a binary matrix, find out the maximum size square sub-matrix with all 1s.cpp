#include<bits/stdc++.h>
using namespace std;
int findMaxSquareWithAllOnes(int** arr, int row, int col){
    int concernedNo = 1; 
  	int **dp = new int*[row];
  	int maximum = 0;
  	for(int i=0;i<row;i++)
      dp[i] = new int[col];
  	for(int j=0;j<col;j++)
    	if(arr[0][j]==concernedNo)
        {
          dp[0][j] = 1;
          maximum = 1;
        }
  		else
          dp[0][j] = 0;
  	for(int i=0;i<row;i++)
    	if(arr[i][0]==concernedNo)
        {
          dp[i][0] = 1;
          maximum = 1;
        }  
  		else
          dp[i][0] = 0;
  	
  	for(int i=1;i<row;i++)
      for(int j=1;j<col;j++)
      {
        if(arr[i][j]==concernedNo)
          dp[i][j] = min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j])) + 1;
        else
          dp[i][j] = 0;
        maximum = max(dp[i][j],maximum);
      }
  	return maximum;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r,c;
        int **mat;
        cin>>r>>c;
        mat = new int*[r];
        for(int i=0;i<r;i++)
            mat[i] = new int[c];
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                cin>>mat[i][j];
        cout<<findMaxSquareWithAllOnes(mat,r,c)<<endl;
    }
    return 0;
}


