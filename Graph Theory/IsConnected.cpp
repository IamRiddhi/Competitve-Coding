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
  	
  	bool *visited = new bool[n];
  	fill(visited,visited+n,false);
  	/* running bfs and check whether all nodes are visited. If yes then the graph is a 
    connected graph */
  	queue<int> q;
  	q.push(0);
  	visited[0] = true;
  	while(!q.empty())
    {
      int popped = q.front(); q.pop();
      for(int i=0;i<n;i++)
        if(adj[popped][i]==true && visited[i]==false)
        {
          visited[i] = true;
          q.push(i);
        }
    }
  	bool isConnected = true;
	for(int i=0;i<n;i++)
      if(!visited[i]){ isConnected = false; break;}
  	if(isConnected)
      cout<<"true"<<endl;
  	else 	
      cout<<"false"<<endl;
  return 0;
}
