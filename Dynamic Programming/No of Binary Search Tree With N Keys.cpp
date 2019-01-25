#include <iostream>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
int countBST(int n)
{
	ll *dp = new ll[n+1];
	dp[0] = 1;
	dp[1] = 1;
	for(ll i=2;i<=n;i++)
	{
	    dp[i] = 0;
	    for(ll k=1;k<=i;k++) 
	        dp[i] = (dp[i] + (dp[k-1]*dp[i-k])%mod)%mod;
	}
	return (int)dp[n];
}
int main() {
	ll t;
	cin>>t;
	while(t--)
	{
	   int n;
	   cin>>n;
	   cout<<countBST(n)<<endl;
	}
	return 0;
}