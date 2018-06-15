#include<bits/stdc++.h>
#include<cmath>
#include<climits>
#define test ll t; cin>>t; while(t--)
#define rep0(n) for(ll i=0;i<(n);i++)
#define rep1(n) for(ll i=1;i<=(n);i++)
using namespace std;
typedef long long ll;
ll *fee,*fun;
ll n,maxBudget;
void dKnapDynamic()
{
    ll **dpFun = new ll*[n+1];
    for(ll i=0;i<=n;i++)
        dpFun[i] = new ll[maxBudget+1];
    dpFun[0][0] = 0;
    for(ll i=0;i<=n;i++)
        dpFun[i][0] = 0;
    for(ll j=0;j<=maxBudget;j++)
        dpFun[0][j] = 0;
        
    for(ll i=1;i<=n;i++)
        for(ll j=0;j<=maxBudget;j++)
          	if(j>=fee[i-1])
            	dpFun[i][j] = max(dpFun[i-1][j],fun[i-1] + dpFun[i-1][j-fee[i-1]]);
  			else
              dpFun[i][j] = dpFun[i-1][j];
    
    ll maxFun = dpFun[n][maxBudget];
    ll minimum = LLONG_MAX;
    for(ll i=0;i<=n;i++)
        for(ll j=0;j<=maxBudget;j++)
            if(dpFun[i][j]==maxFun)
            {
                minimum = min(j,minimum);
            }
 	cout<<minimum<<" "<<maxFun<<endl;
    return;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while(1)
    {
        cin>>maxBudget>>n;
        if(maxBudget==0 && n==0)
            break;
        fee = new ll[n];
        fun = new ll[n];
        rep0(n)
            cin>>fee[i]>>fun[i];
        dKnapDynamic();
    }
    return 0;
}