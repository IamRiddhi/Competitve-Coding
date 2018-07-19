#include<bits/stdc++.h>
#include<cmath>
#include<climits>
#define test ll t; cin>>t; while(t--)
#define rep0(n) for(ll i=0;i<(n);i++)
#define rep1(n) for(ll i=1;i<=(n);i++)
using namespace std;
typedef long long ll;
ll lpf[2000001];
void leastPrimeSeive()
{
	for(ll i=0;i<=2000000;i++)
      lpf[i] = i;
 
  	for(ll i=2;i<=2000000;i++)
    {
      if(lpf[i]==i) //prime factor
      {
        for(ll j=i+i;j<=2000000;j+=i)
          lpf[j] = i;
      }
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n;
  	leastPrimeSeive();
    cin>>n;
    bool *ar = new bool[n+1];
    for(ll i=0;i<=n;i++)
        ar[i] = false;
 
    for(ll i=n;i>=1;i--)
    {
        if(!ar[i]) //not yet been removed.
        {
            cout<<i<<" "; //adding the maximum to the list.
            ar[i] = true;
            unordered_set<ll> pf;
           vector<ll> prnt;
            unordered_set<ll>::iterator it;
 
          /* ----- Finding out prime factors --------*/
          ll no = i;
          while(no>1)
          {
          		pf.insert(lpf[no]);
            	no/=lpf[no];
          }
 
            for(it=pf.begin();it!=pf.end();it++)
            {
                for(ll j=(i-(*it));j>=1;j-=(*it))
                    if(ar[j]==false)
                    {
                        ar[j]= true;
                      	prnt.push_back(j);
                    }
            }
          
          sort(prnt.begin(),prnt.end(),greater<int>());
          
          for(int k=0;k<prnt.size();k++)
          {
            cout<<prnt[k]<<" ";
          }
        }
    }
    return 0;
}
