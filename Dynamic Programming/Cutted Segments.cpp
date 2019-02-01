#include<bits/stdc++.h>
#include<cmath>
#include<climits>
#define test ll t; cin>>t; while(t--)
#define rep0(n) for(ll i=0;i<(n);i++)
#define rep1(n) for(ll i=1;i<=(n);i++)
using namespace std;
typedef long long ll;
ll mod = 1000000007;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    test
    {
        ll n,x,y,z;
        cin>>n>>x>>y>>z;
        ll *seg = new ll[3];
        seg[0] = x; seg[1] = y; seg[2]= z;
        ll *dp = new ll[n+1];
        dp[0] = 0;
        for(ll j=1;j<=n;j++)
            dp[j] = LLONG_MIN;
        for(ll i=0;i<3;i++)
            for(ll j=seg[i];j<=n;j++)
                if(dp[j-seg[i]]!=LLONG_MIN)
                    dp[j] = max(1+dp[j-seg[i]],dp[j]);
        cout<<dp[n]<<endl;
    }
    return 0;
}