#include<bits/stdc++.h>
#include<cmath>
#include<climits>
#define test ll t; cin>>t; while(t--)
#define rep0(n) for(ll i=0;i<(n);i++)
#define rep1(n) for(ll i=1;i<=(n);i++)
using namespace std;
typedef long long ll;
ll fxp(ll base,ll exp,ll mod)
{
  ll res = 1;
  while(exp>0)
  {
    if(exp%2==1)
      res = (res*base)%mod;
    exp/=2;
    base=(base*base)%mod;
  }
  return res;
}
ll mmi(ll a, ll p)
{
  return fxp(a,p-2,p)%p;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    test
    {
        ll n,p;
      	cin>>n>>p;
      	if(n>=p)
          cout<<"0"<<endl;
     	else if(n<p) //apply wilson theorem
        {
          	ll res = -1;
			for(ll f=n+1;f<=p-1;f++)
              res= (res * mmi(f,p))%p;
          	res+=p;
          cout<<res<<endl;
        }
    }
    return 0;
}
