#include<bits/stdc++.h>
#include<cmath>
#include<climits>
#define test ll t; cin>>t; while(t--)
#define rep0(n) for(ll i=0;i<(n);i++)
#define rep1(n) for(ll i=1;i<=(n);i++)
using namespace std;
typedef long long ll;
ll mod = 1000000007;

/* Code for Connected Components*/
void dfs(int start, vector<int>* edges, int n, unordered_set<int>& visited, unordered_set<int> * component) {
	visited.insert(start);
	component->insert(start);
	vector<int>::iterator it = edges[start].begin();
	for (;it != edges[start].end(); it++) {
		int i = *it;
		if (visited.count(i) > 0) {
			continue;
		}
		dfs(i, edges,n, visited, component);
	}
}

unordered_set<unordered_set<int>*>* getComponents(vector<int>* edges, int n) {
	unordered_set<int> visited;
	unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();
	for (int i = 0; i < n; i++) {
		if (visited.count(i) == 0) {
			unordered_set<int> * component = new unordered_set<int>();
			dfs(i, edges,n, visited, component);
			output->insert(component);
		}
	}
	return output;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll fact[1000001];
    fact[0] = 1;
    for(ll i=1;i<1000001;i++)
        fact[i] = (fact[i-1]*i)%mod;
    test
    {
        int n,m,q;
        cin>>n>>m>>q;
        vector<int>* edges = new vector<int>[q];
        int adj[1001][1001];
        for(int i=0;i<1001;i++)
            for(int j=0;j<1001;j++)
                adj[i][j] = -1;
                
        int i = 0;
        int q1 = q;
        while(q1--)
        {
            ll x,y;
            cin>>x>>y;
            x--; y--;
            adj[x][y] = i;
            if(x-1>=0 && y-2>=0 && adj[x-1][y-2]>-1)
            {
                int z = adj[x-1][y-2];
                edges[i].push_back(z);
                edges[z].push_back(i);
            }
            if(x-1>=0 && y+2<m && adj[x-1][y+2]>-1)
            {
                int z = adj[x-1][y+2];
                edges[i].push_back(z);
                edges[z].push_back(i);
            }
            if(x+1<n && y-2>=0 && adj[x+1][y-2]>-1)
            {
                int z = adj[x+1][y-2];
                edges[i].push_back(z);
                edges[z].push_back(i);
            }
            if(x+1<n && y+2<m && adj[x+1][y+2]>-1)
            {
                int z = adj[x+1][y+2];
                edges[i].push_back(z);
                edges[z].push_back(i);
            }
            if(x-2>=0 && y+1<m && adj[x-2][y+1]>-1)
            {
                int z = adj[x-2][y+1];
                edges[i].push_back(z);
                edges[z].push_back(i);
            }
            if(x-2>=0 && y-1>=0 && adj[x-2][y-1]>-1)
            {
                int z = adj[x-2][y-1];
                edges[i].push_back(z);
                edges[z].push_back(i);
            }
            if(x+2<n && y+1<m && adj[x+2][y+1]>-1)
            {
                int z = adj[x+2][y+1];
                edges[i].push_back(z);
                edges[z].push_back(i);
            }
             if(x+2<n && y-1>=0 && adj[x+2][y-1]>-1)
            {
                int z = adj[x+2][y-1];
                edges[i].push_back(z);
                edges[z].push_back(i);
            }
            i++;
        }
        
        unordered_set<unordered_set<int>*>* components = getComponents(edges, q);
        unordered_set<unordered_set<int>*>::iterator it1;
        ll product = 1;
        for(it1=components->begin();it1!=components->end();it1++)
        {
            unordered_set<int>* component = *it1;
            product = (product * fact[component->size()])%mod;
        }
        cout<<product<<endl;
    }
}















