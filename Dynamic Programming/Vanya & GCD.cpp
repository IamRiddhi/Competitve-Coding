#include<bits/stdc++.h>
#include<cmath>
#include<climits>
#define test ll t; cin>>t; while(t--)
#define rep0(n) for(ll i=0;i<(n);i++)
#define rep1(n) for(ll i=1;i<=(n);i++)
using namespace std;
typedef long long ll;
ll mod=1000000007;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n,*a;
    cin>>n;
    a= new ll[n];
    rep0(n)
        cin>>a[i];
        
    ll **dp = new ll*[n];
    rep0(n)
    {
        dp[i] = new ll[101];
        fill(dp[0],dp[0]+101,0);    
    }
    
    for(ll i=0;i<n;i++)
    {
       dp[i][a[i]]++;
       for(ll k=0;k<i;k++)
           if(a[k]<a[i])
                for(ll gcd=1;gcd<=100;gcd++)
                    dp[i][__gcd(a[i],gcd)] += dp[k][gcd];
    }
    
    ll result = 0;
    for(ll i=0;i<n;i++)
        result = (result+dp[i][1])%mod;
    cout<<result<<endl;
    return 0;
}