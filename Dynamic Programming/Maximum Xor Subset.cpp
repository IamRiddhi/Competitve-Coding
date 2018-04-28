#include <iostream>
#include<bits/stdc++.h>
#include<climits>
using namespace std;
typedef long long ll;
#define rep(n) for(ll i=0;i<(n);i++)
#define test ll t; cin>>t; while(t--)
ll n,k,*a;
ll solve()
{
    bool dp[n+1][1024]; //1023 because maximum xor of 2 10 bit elements will be 1023(10 set bits) as ai is 1000(max)
    rep(n+1)
        fill(dp[i],dp[i]+1024,false);
    
    ll maximum= k;
    
    dp[0][0]=true;
    for(ll i=1;i<=n;i++)
        dp[i][0]=true;
    for(ll j=1;j<=1023;j++)
        dp[0][j]=false;
        
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=1023;j++)
        {
            dp[i][j] = dp[i-1][j];
            dp[i][j]|= dp[i-1][j^a[i]];
            if(dp[i][j]==true)
                maximum=max(k^j,maximum);
        }
    }
    return maximum;
}
int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    test
    {
        cin>>n>>k;
        a= new ll[n+1];
        for(ll i=1;i<=n;i++)
            cin>>a[i];
        cout<<solve()<<endl;
    }
	return 0;
}  