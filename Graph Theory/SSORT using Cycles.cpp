#include<bits/stdc++.h>
#include<cmath>
#include<climits>
#define test ll t; cin>>t; for(ll tq=1;tq<=t;tq++)
#define rep0(n) for(ll i=0;i<(n);i++)
#define rep1(n) for(ll i=1;i<=(n);i++)
using namespace std;
typedef long long ll;
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
    int tq = 1;
    while(true)
    {
        int n,*a,*sorted;
        cin>>n;
        if(n==0)
            break;
        unordered_map<int,int> freq;
        a= new int[n];
        sorted = new int[n];
        int minElem = INT_MAX;
        int minInd = -1;
        rep0(n)
        {
            cin>>a[i];
            freq[a[i]]++;
            sorted[i] = a[i];
            if(minElem>a[i])
            {
                minElem = a[i];
                minInd = i;
            }
        }
        sort(sorted,sorted+n);
        vector<int>* edges = new vector<int>[n];
        for(int i=0;i<n;i++)
        {
            edges[i].push_back((lower_bound(sorted,sorted+n,a[i])-sorted)+freq[a[i]]-1);    
            freq[a[i]]--;
        }
        unordered_set<unordered_set<int>*>* components = getComponents(edges, n);    
        unordered_set<unordered_set<int>*>::iterator it1;
        unordered_set<int>::iterator it2;
        ll ans = 0;
        for(it1=components->begin();it1!=components->end();it1++)
        {
            unordered_set<int>* component = *it1;
            ll sum = 0;
            int k = component->size();
            if(k==1)
                continue;
            int minimum = INT_MAX;
            int minimumIndex = -1;
            for(it2=component->begin();it2!=component->end();it2++)
            {
                int index = *it2;
                if(minimum>a[index])
                {
                    minimumIndex = index;
                    minimum = a[index];
                }
            }
            if(minInd!=minimumIndex)
                sum += 2*(a[minInd]+a[minimumIndex]);
            for(it2=component->begin();it2!=component->end();it2++)
            {
                int index = *it2;
                sum  += a[index];
            }
            if(minInd!=minimumIndex)
            {
                sum -= minimum;
                sum += (minElem*(k-1));
            }
            else
                sum += minimum*(k-2);
                
           ll sum1 = 0;    
            for(it2=component->begin();it2!=component->end();it2++)
            {
                 int index = *it2;
                sum1  += a[index];
            }
            sum1 += minimum*(k-2);
            sum = min(sum1,sum);
            ans += sum;
        }    
        
        cout<<"Case "<<tq<<": "<<ans<<endl<<endl;
        tq++;
    }
    return 0;
}