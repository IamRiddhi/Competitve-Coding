#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll getMin(ll *a,ll n)
{
    ll *dp = new ll[n];
      fill(dp,dp+n,1);
      for(ll i=n-2;i>=0;i--)
    {
        if(a[i]>a[i+1])
          dp[i] = dp[i+1] + 1;
    }
    ll sum = dp[0];
    ll k = dp[0];
    for(ll i=1;i<n;i++)
    {
        if(a[i]>a[i-1])
        {
            k = max(k+1,dp[i]);
            sum +=k;
        }
        else
        {
            k = dp[i];
            sum += k;
        }
    }
    return sum;
}

int main()
{
    ll n;
    ll *a;
    cin>>n;
    a = new ll[n];
    for(ll i=0;i<n;i++)
        cin>>a[i];
    cout<<getMin(a,n);
    return 0;
}