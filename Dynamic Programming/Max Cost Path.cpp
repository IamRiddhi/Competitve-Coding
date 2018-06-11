#include<bits/stdc++.h>
#include<cmath>
#include<climits>
#define test ll t; cin>>t; while(t--)
#define rep0(n) for(ll i=0;i<(n);i++)
#define rep1(n) for(ll i=1;i<=(n);i++)
using namespace std;
typedef long long ll;
ll maxCostPath(ll **a, ll n)
{
    
    ll **dp = new ll*[n];
    for(ll i=0;i<n;i++)
        dp[i] = new ll[n];
    
    ll maximum = 0;
    
    for(ll i=n-1;i>=0;i--)
        for(ll j=n-1;j>=0;j--)
        {
            if(i==n-1 && j==n-1)
                dp[n-1][n-1] = a[n-1][n-1];
            else
            {
                ll path1,path2,path3;
                path1 = path2 = path3 = 0;
                if(i+1<n && j<n)
                    path1= dp[i+1][j];
                if(i+1<n && j-1<n)
                    path2 = dp[i+1][j-1];
                if(i+1<n && j+1<n)
                    path3 = dp[i+1][j+1];
                    
                dp[i][j] = a[i][j] + max(path1,max(path2,path3));
                maximum = max(maximum,dp[i][j]);
            }
        }
        return maximum;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    test
    {
        ll n,**a;
        cin>>n;
        a= new ll*[n];
        rep0(n)
            a[i] = new ll[n];
        rep0(n)
            for(ll j=0;j<n;j++)
                cin>>a[i][j];
        cout<<maxCostPath(a,n)<<endl;
    }
    return 0;
}