/*
Get Path - BFS

Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using BFS and print the shortest path available.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
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
  	int *visited = new int[n];
  	fill(visited,visited+n,INT_MIN);
  
  	int start,end;
  	cin>>start>>end;
  	if(start==end)
      cout<<start;
  	else
    {
      visited[start] = -1; //root
      queue<int> q;
      q.push(start);
      bool flag = false;
      while(!q.empty())
      {
        int popped = q.front(); q.pop();
        for(int i=0;i<n;i++)
        {
          if(adj[popped][i] && visited[i]==INT_MIN)
          {
            visited[i] = popped;
            if(i==end)
            {
              flag = true;
              cout<<end<<" ";
              goto label;
            }
            q.push(i);
          }
        }
      }
      label: if(flag)
            {
				int x = visited[end];
        		while(x!=-1)
                {
                  cout<<x<<" ";
                  x = visited[x];
                }
            }
    }
  return 0;
}
