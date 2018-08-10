/* Code : Has Path
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), check if there exists any path between them or not. Print true or false.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
Line (E+2) : Two integers v1 and v2 (separated by space)
Output Format :
true or false
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
true
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
false*/

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
  	int start,end; cin>>start>>end;
  	if(start==end)cout<<"true"; else{
  	bool fl =false;
  	bool *visited = new bool[n];
  	fill(visited,visited+n,false);
  
  	queue<int> q;
  	q.push(start);
  	visited[start] = true;
  	while(!q.empty())
    {
      int popped = q.front(); q.pop();
      for(int i=0;i<n;i++)
        if(adj[popped][i]==true && visited[i]==false)
        {
          if(i==end){ fl=true; break;}
          visited[i] = true;
          q.push(i);
        }
    }
      if(fl)cout<<"true"; else cout<<"false";
    }
  return 0;
}
