#include<bits/stdc++.h>
#include<climits>
using namespace std;
typedef long long ll;
#define rep(n) for(ll i=1;i<=(n);i++)
#define test ll t; cin>>t;while(t--)
ll n,*a,sum;
ll minSumPartition()
{
    bool *dp = new bool[sum+1];
    ll mini = LLONG_MAX;
    for(ll i=1;i<=sum;i++)
        dp[i] = false;
    dp[0] = true;
    for(ll i=1;i<=n;i++)
        for(ll j=sum;j>=a[i-1];j--)
        {
            dp[j] |= dp[j-a[i-1]];
            if(dp[j])
                mini = min(abs(2*j-sum),mini);
        }
    return mini;
}
int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    test
    {
        cin>>n;
        a=new ll[n+1];
        sum=0;
        rep(n)
        {
            cin>>a[i];
            sum+=a[i];
        }
        cout<<minSumPartition()<<endl;
    }
	return 0;
}
