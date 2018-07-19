#include<bits/stdc++.h>
#include<cmath>
#include<climits>
#define MOD 1000000007
#define test ll t; cin>>t; while(t--)
#define rep0(n) for(ll i=0;i<(n);i++)
#define rep1(n) for(ll i=1;i<=(n);i++)
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll t;
  	cin>>t;
  	while(t--)
    {
        ll n,*a;
      	ll tot=0;
		cin>>n;
      	a= new ll[n];
        ll *ans= new ll[1000001];
        fill(ans,ans+1000001,0);
      	rep0(n)
        {
          	cin>>a[i];
     		ans[a[i]]=1;
        }
      
      	//APPLYING SEIVE
      	for(ll i=1;i<=500000;i++)
        	if(ans[i]) // element present in the input array
            {
              for(ll j=i+i;j<=1000000;j+=i)
                if(ans[j])
                	ans[j] = (ans[i]+ans[j])%MOD;
            }
      	
      	for(ll i=1;i<=1000000;i++)
          tot= (tot+ans[i])%MOD;
      
      	cout<<tot<<endl;
    }
    return 0;
}