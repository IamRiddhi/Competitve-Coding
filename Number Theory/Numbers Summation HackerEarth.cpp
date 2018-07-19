#include<bits/stdc++.h>
#include<climits>
#define mod 1000000007
typedef long long ll;
using namespace std;
ll fxp(ll base,ll exp)
{
	ll res = 1;
  	while(exp>0)
    {
    	if(exp%2==1)
        	res = (res*base)%mod;
      	exp/=2;
      	base = (base*base)%mod;
    }
  	return res;
}
ll mmi(ll p, ll m)
{
	return fxp(p,m-2)%m;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n; cin>>n;
  	//ll modInverse2 = mmi(2,mod); //mod Inverse of 2
  	ll modInverse2 = 500000004;
    ll sum = 0;
  	for(ll i=1;i<=n;)
    {
    	ll x = n/i;
      	ll j = n/x;
      	ll summationx = ( (x%mod*(x%mod+1))%mod * modInverse2)%mod;
		ll y;
      	if(i!=j)
        {
        	/*summation Repeating is suppose 9 to 12 it will 9*summation(2) + 10*summation(2)...
        	12*summation(2). we take summation(2) common which is summation(x)
        	so summation(x)*(summation(9) + summation(10) + summation(11) + summation(12) )
        	= summation(x)*(summation(12) - summation(8) ) */
 
        	  ll summationRepeating = ( ((((j%mod)*(j%mod+1))%mod * modInverse2)%mod) - 
                                       (((((i-1)%mod)*((i-1)%mod+1))%mod * modInverse2)%mod) +mod )%mod;
          	  y = (summationRepeating*summationx)%mod;
        }
      	else
			y = (i%mod * summationx)%mod;      	
      	sum = (sum+y)%mod;
      	i = j+1;
    }
  	cout<<sum<<endl;
    return 0;
}
