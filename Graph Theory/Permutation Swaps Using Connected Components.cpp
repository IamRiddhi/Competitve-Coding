#include<bits/stdc++.h>
#include<cmath>
#include<climits>
#define test ll t; cin>>t; while(t--)
#define rep0(n) for(ll i=0;i<(n);i++)
#define rep1(n) for(ll i=1;i<=(n);i++)
using namespace std;
typedef long long ll;

/* swapping can only occur between elements of same connected components. Hence for each connected component ,
elements of p and elements of q must be same though their order maybe different due to swapping. indices which can be swapped
are in same connected component. get the values of p and q from those indices. Now the order of the values maybe be different
but the values must be same as they are in same connected component. Swapping between disconnected components cannot occur
as there are no path between them to swap.*/

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
        ll n,m;
        cin>>n>>m;
        ll *p = new ll[n];
        ll *q = new ll[n];
        rep0(n)
            cin>>p[i];
        rep0(n)
            cin>>q[i];
       vector<int>* edges = new vector<int>[n];
        rep0(m)
        {
            ll j,k;
            cin>>j>>k;
            edges[j - 1].push_back(k - 1);
	    	edges[k - 1].push_back(j - 1);
        }
        
        unordered_set<unordered_set<int>*>* components = getComponents(edges, n);
        
        string ans = "YES";
        unordered_set<unordered_set<int>*>::iterator it1;
        unordered_set<int>::iterator it2;
        for(it1=components->begin();it1!=components->end();it1++)
        {
            unordered_set<int>* component = *it1;
            set<int> s1,s2;
            set<int>::iterator sit;
            for(it2=component->begin();it2!=component->end();it2++)
            {
                ll index = *it2;
                s1.insert(p[index]);
                s2.insert(q[index]);
            }
           for(sit=s1.begin();sit!=s1.end();sit++)
             if(s2.find((*sit))==s2.end())
             {
               ans = "NO";
               goto label;
             }
        }
        
    label:    cout<<ans<<endl;
    }
    return 0;
}