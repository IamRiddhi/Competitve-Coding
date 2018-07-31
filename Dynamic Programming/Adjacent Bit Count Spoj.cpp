#include<bits/stdc++.h>
#include<cmath>
#include<climits>
#define test ll t; cin>>t; while(t--)
#define rep0(n) for(ll i=0;i<(n);i++)
#define rep1(n) for(ll i=1;i<=(n);i++)
using namespace std;
typedef long long ll;
ll mod = 1000000007;
ll ***dp;
ll recur(ll i,ll k,ll bit ) //bit can be 0 or 1.
{
    if(i==1)
    {
        if(k==0)
            return 1;
        else 
            return 0;
    }
    if(k<0)
        return 0;
        
    if(dp[i][k][bit]!=INT_MIN) return dp[i][k][bit];
    
    if(bit==1)
        dp[i][k][bit] = (recur(i-1,k,0) + recur(i-1,k-1,1))%mod;
    else
        dp[i][k][bit] = (recur(i-1,k,0) + recur(i-1,k,1))%mod;

    return dp[i][k][bit];
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    test
    {
        ll n,k,tno;
        cin>>tno>>n>>k;
        dp = new ll**[n+1];
        for(ll i=0;i<=n;i++)
        {
            dp[i] = new ll*[k+1];
            for(ll j=0;j<=k;j++)
                dp[i][j] = new ll[2];
        }
        for(ll i=0;i<=n;i++)
            for(ll j=0;j<=k;j++)
                for(ll m=0;m<=1;m++)
                    dp[i][j][m] = INT_MIN;
                    
        cout<<tno<<" "<<(recur(n,k,1) + recur(n,k,0))%mod<<endl;
    }
    return 0;
}