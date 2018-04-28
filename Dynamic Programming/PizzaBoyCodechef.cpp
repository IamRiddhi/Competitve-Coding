#include <iostream>
#include<bits/stdc++.h>
#include<climits>
#include<queue> 
using namespace std;
typedef long long ll;
#define rep(n) for(ll i=0;i<(n);i++)
#define test ll t; cin>>t; while(t--)
ll n,*h,*f;
ll minNoOfWaysToGet(ll fuelReqd)
{
    queue<ll> q;
    ll *visited= new ll[fuelReqd];
    fill(visited,visited+fuelReqd+1,-1);
    
    q.push(0); //initally i have nothing( bhikari)
    visited[0]=0;
    while(!q.empty())
    {
        ll popped= q.front(); q.pop();
        for(ll i=1;i<=n;i++)
        {
            if(f[i]+popped<=fuelReqd && visited[f[i]+popped]==-1)
            {
                visited[f[i]+popped]= 1 + visited[popped];
                q.push(f[i]+popped);
            }
        }
    }
    ll count=0;
    for(ll i=1;i<=n;i++)
        count+=visited[h[i]];
    return count; 
}
int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    test
    {
        
        cin>>n;
        h= new ll[n+1];
        f= new ll[n+1];
        for(ll i=1;i<=n;i++){ cin>>h[i]; h[i]*=2;}
        for(ll i=1;i<=n;i++) cin>>f[i];
        
        ll maximum=LLONG_MIN;
        for(ll i=1;i<=n;i++)
            maximum= max(maximum,h[i]);
        maximum= minNoOfWaysToGet(maximum);
        cout<<maximum<<endl;
    }
	return 0;
} 