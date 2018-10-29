#include<stdio.h>
#include<bits/stdc++.h>
#include<cmath>
#include<climits>
#define test int t; scanf("%d",&t); while(t--)
#define rep0(n) for(ll i=0;i<(n);i++)
#define rep1(n) for(ll i=1;i<=(n);i++)
using namespace std;
typedef long long ll;
ll mod = 1000000007;
static int counter;
vector<int> adjList[100005];
int dfsin[100005];
int dfsout[100005];
int height[100005];
void dfs(ll ht,ll node)
{
    height[node] = ht;
    counter++;
    dfsin[node] = counter;
    vector<int>::iterator it;
    for(it = adjList[node].begin();it!=adjList[node].end();it++)
        dfs(ht+1,*it);
    counter++;
    dfsout[node] = counter;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    test
    {
        int n;
        int x;
        scanf("%d",&n);
        int root = -1;
        for(int i=1;i<=n;i++)
        {
            dfsin[i] = 0;
            dfsout[i] = 0;
            height[i] = 0;
            adjList[i].clear();    
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            if(x==0)
                root = i;
            else
                adjList[x].push_back(i);
        }
        counter = 0;
        dfs(0,root);
        int q;
        scanf("%d",&q);
        while(q--)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            if(dfsin[r]<dfsin[l] && dfsout[r]>dfsout[l]) // r is parent of l
                cout<<height[l]-height[r]-1<<endl;
            else
                cout<<"-1"<<endl;
        }

    }
    return 0;
}