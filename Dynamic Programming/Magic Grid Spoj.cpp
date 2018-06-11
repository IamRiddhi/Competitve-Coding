#include<bits/stdc++.h>
#include<cmath>
#include<climits>
#define test ll t; cin>>t; while(t--)
#define rep0(n) for(ll i=0;i<(n);i++)
#define rep1(n) for(ll i=1;i<=(n);i++)
using namespace std;
typedef long long ll;
ll magrid(ll **a, ll r, ll c)
{
    
    ll** dp= new ll*[r];
    for(ll i=0;i<r;i++)
        dp[i] = new ll[c];
    
    for(ll i=r-1;i>=0;i--)
        for(ll j=c-1;j>=0;j--)
        {
            if(i==r-1 && j==c-1)
                dp[i][j] = 1;
            else
            {
                ll path1,path2;
                path1 = path2 = LLONG_MAX;
                if(i+1<r && j<c)
                {
                    path1 = dp[i+1][j] - a[i][j];
                    if(path1<=0) path1 = 1;
                }    
                if(i<r && j+1<c)
                {
                    path2 = dp[i][j+1] - a[i][j];
                    if(path2<=0) path2 = 1;
                }
                
                dp[i][j] = min(path1,path2);
                
            }
        }

    // for(ll i=0;i<r;i++)
    // {
    //     for(ll j=0;j<c;j++)
    //         cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
    return dp[0][0];
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    test
    {
        ll r,c,**a;
        cin>>r>>c;
        a= new ll*[r];
        rep0(r)
            a[i] = new ll[c];
        rep0(r)
            for(ll j=0;j<c;j++)
                cin>>a[i][j];
        cout<<magrid(a,r,c)<<endl;
    }
    return 0;
}