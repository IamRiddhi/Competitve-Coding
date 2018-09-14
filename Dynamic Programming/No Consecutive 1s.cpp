#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
int main() 
{
	ll t;
	cin>>t;
	while(t--)
	{
	    ll n;
	    cin>>n;
	    ll prev0,prev1; //starting with 'i' = prev'i'(0/1)
	    prev0 = prev1 = 1;
	    for(ll i=2;i<=n;i++)
	    {
	        ll cur0 = (prev0 + prev1)%mod;
	        ll cur1 = prev0;
	        prev0 = cur0;
	        prev1 = cur1;
	    }
	    cout<<(prev0+prev1)%mod<<endl;
	}
	return 0;
}