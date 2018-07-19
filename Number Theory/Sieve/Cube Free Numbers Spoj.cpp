#include<bits/stdc++.h>
#include<cmath>
using namespace std;
typedef long long ll;
#define test  ll t; cin>>t; for(ll rid=1;rid<=t;rid++)
bool ans[1000001];
ll cnt[1000001];
void compute()
{
  fill(ans,ans+1000001,true);
  for(ll i=2;(i*i*i)<=1000000;i++) //seggregating the cube numbers
    ans[i*i*i]= false;
  
  for(ll i=2;i<=500000;i++)
  	  if(!ans[i])
        for(ll j=i+i;j<=1000000;j+=i)
          ans[j]= false;
  
  ll count =0;
  cnt[0]=0;
  for(ll i=1;i<=1000000;i++)
  {
    if(ans[i])
  		count++;
  	cnt[i]= count;
  }
}

int main()
{
  compute();
  test
  {
    ll n; 
    cin>>n;
    cout<<"Case "<<rid<<":"<<" ";
    if(ans[n]) //cube free
      cout<<cnt[n]<<endl;
    else
      cout<<"Not Cube Free"<<endl;
  }
  return 0;
}