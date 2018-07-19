#include<bits/stdc++.h>
#include<cmath>
#include<climits>
#define test ll t; cin>>t; while(t--)
#define rep0(n) for(ll i=0;i<(n);i++)
#define rep1(n) for(ll i=1;i<=(n);i++)
using namespace std;
typedef long long ll;
vector<ll> primes;
ll R;
void sieve()
{
    bool *a = new bool[R+1];
    fill(a,a+R+1,true);
    a[0] = a[1] = false;
    for(ll i=2;i<=sqrt(R);i++)
        if(a[i])
            for(ll j=i*i;j<=R;j+=i)
                a[j] = false;
  	for(ll i=2;i<=R;i++)
      if(a[i])
      	primes.push_back(i);
}
void segmentedSieve(ll l,ll u)
{
    bool *a = new bool[u-l+1];
    fill(a,a+u-l+1,true);
    vector<ll>::iterator it;
    for(it=primes.begin();it!=primes.end();it++)
    {
        ll primeNo = *it;
      	if(primeNo>sqrt(u))
          	break;
        ll startingNo = (l/primeNo) * primeNo;    
      	if(startingNo<l) 
          startingNo+=primeNo;
     
        for(ll i=startingNo;i<=u;i+=primeNo)
        {
            a[i-l] = false;
          	//special case
      		if(i==primeNo)
        		a[i-l] = true;
        }
    }
    
    //printing primes between l and r
    for(ll i=l;i<=u;i++)
        if(a[i-l] && i!=1)
            cout<<i<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    R = sqrt(INT_MAX);
    sieve();
    test
    {
        ll l,u;
        cin>>l>>u;
        segmentedSieve(l,u);    
    }
    return 0;
}