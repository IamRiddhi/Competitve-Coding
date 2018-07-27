#include <iostream>
#include<queue>
#include<bits/stdc++.h>
#include<climits>
using namespace std;
typedef long long ll;
#define test ll t; cin>>t; while(t--)
#define rep(n) for(ll i=1;i<=(n);i++)
ll n,*f;
ll minNoOfWaysToGet(ll SumToReach)
{
    ll *dp= new ll[SumToReach+1];
    for(ll i=0;i<=n;i++)
    {
        for(ll j=0;j<=SumToReach;j++)
        {
            if(j==0)
                dp[j]=0;
            else if(i==0 && j!=0)
                dp[j]= LLONG_MAX; //infinty means unreachable.
            else if(j>=f[i] && dp[j-f[i]]!=LLONG_MAX)
                    dp[j]= min(dp[j],1+dp[j-f[i]]);    
        }
    }
    if(dp[SumToReach]==LLONG_MAX)
        dp[SumToReach]=-1;
    return dp[SumToReach]; 
}
int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    test
    {
        ll v;
        cin>>v>>n;
        f= new ll[n+1];
        for(ll i=1;i<=n;i++)
            cin>>f[i]; 
        cout<<minNoOfWaysToGet(v)<<endl;
        
    }
	return 0;
}
