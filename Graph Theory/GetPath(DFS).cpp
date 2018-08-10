/*
Get Path - DFS
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using DFS and print the first path that you encountered.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
Note : Save the input fraph in Adjacency Matrix.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
Line (E+2) : Two integers v1 and v2 (separated by space)
Output Format :
Path from v1 to v2 in reverse order (separated by space)
Constraints :
2 <= V <= 1000
1 <= E <= 1000
0 <= v1, v2 <= V-1

Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
3 0 1

Sample Input 2 :
6 3
5 3
0 1
3 4
0 3

Blank Output
*/
#include <bits/stdc++.h>
using namespace std;
int getPath(bool **adj,int n,int start,int end,int *visited)
{
  if(start==end)
  {
    cout<<start<<" ";
    return end;
  }
  for(int i=0;i<n;i++)
  {
    if(adj[start][i] && !visited[i])
    {
      visited[i] = true; 
      int x = getPath(adj,n,i,end,visited);
      if(x>-1)
      {
        cout<<start<<" ";
        return start;
      }
    }
  }
  return -1;
}
int main() {
    int n, e;
    cin >> n >> e;
	
  	bool **adj = new bool*[n];
  	for(int i=0;i<n;i++)
    {
      adj[i] = new bool[n];
      fill(adj[i],adj[i]+n,false);
    }
 	
  	for(int i=0;i<e;i++)
    {
      int x, y; cin>>x>>y;
      adj[x][y] = adj[y][x] = true;
    }
  	bool *visited = new bool[n];
  	fill(visited,visited+n,false);
  
  	int start,end; cin>>start>>end;
  	visited[start] = true;
  	if(start==end)
      cout<<start;
  	else
  		getPath(adj,n,start,end,visited);
  return 0;
}
