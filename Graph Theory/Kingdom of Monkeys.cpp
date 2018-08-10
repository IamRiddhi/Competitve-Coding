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
    test
    {
        int n,m;
        cin>>n>>m;
        vector<int>* edges = new vector<int>[n];
        while(m--)
        {
            int x,y; cin>>x>>y; x--; y--;
            edges[x].push_back(y);
            edges[y].push_back(x);
        }
        ll *a = new ll[n];
        rep0(n)
            cin>>a[i];
            
        unordered_set<unordered_set<int>*>* components = getComponents(edges, n);
        unordered_set<unordered_set<int>*>::iterator it1;
        unordered_set<int>::iterator it2;
        ll maximum = 0;
        for(it1=components->begin();it1!=components->end();it1++)
        {
            unordered_set<int>* component = *it1;
            ll sum = 0;
            for(it2=component->begin();it2!=component->end();it2++)
            {
                int index = *it2;
                sum  += a[index]; 
            }
            maximum = max(sum,maximum);
        }
        cout<<maximum<<endl;
    }
}