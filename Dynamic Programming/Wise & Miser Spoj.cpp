#include<bits/stdc++.h>
#include<cmath>
#include<climits>
#define test ll t; cin>>t; while(t--)
#define rep0(n) for(ll i=0;i<(n);i++)
#define rep1(n) for(ll i=1;i<=(n);i++)
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n,m;
    cin>>n>>m;
    ll **mat = new ll*[n];
    ll **dp = new ll*[n];
    rep0(n)
    {
        mat[i] = new ll[m];
        dp[i] = new ll[m];
    }
    rep0(n)
        for(ll j=0;j<m;j++)
            cin>>mat[i][j];

    rep0(m)
        dp[n-1][i] = mat[n-1][i];
        
    for(ll i=n-2;i>=0;i--)
    {
        for(ll j=0;j<m;j++)
        {
            ll less,equal,more;
            less = equal = more = INT_MAX;
            if(j>=1) less = dp[i+1][j-1];
            equal = dp[i+1][j];
            if(j+1<m) more = dp[i+1][j+1];
            dp[i][j] = mat[i][j] + min(less,min(equal,more));
        }
    }
    
    ll minimum = INT_MAX;
    for(ll i=0;i<m;i++)
        minimum = min(dp[0][i],minimum);
        
    cout<<minimum<<endl;
    
    return 0;
}