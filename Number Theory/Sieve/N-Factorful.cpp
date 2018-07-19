#include<bits/stdc++.h>
#include<cmath>
typedef long long ll;
using namespace std;
ll primes[1000001];  // maintains no of prime factors.
ll table[11][1000001];
void seive()
{
  fill(primes,primes+1000001,0);
  for(ll i=2;i<=1000000;i++) // dont do n/2....some prime numbers >n/2 will remain 0-factorful...who will do their +1 if not visited?
    if(primes[i]==0)
    {
    	primes[i]++;
      	for(ll j=i+i;j<=1000000;j+=i)
          primes[j]++;
    }
}
void computeprefixTable()
{
  
  for(ll i=0;i<=10;i++)
    if(i==0)
    	table[0][0]=1;
    else
      	table[i][0]=0;

  for(ll i=0;i<=10;i++)
  {
  	for(ll j=1;j<=1000000;j++)
    {
      table[i][j]= table[i][j-1];
      if(primes[j]==i)
        table[i][j]++;
    }
  }
}
int main()
{
  	seive();
  	computeprefixTable();
  	ll t; 
  	cin>>t;
  	while(t--)
    {
      ll a,b,n;
      cin>>a>>b>>n;
      if(a==0)
        cout<<table[n][b]<<endl;
      else
      	cout<<table[n][b]-table[n][a-1]<<endl;
    }
	return 0;
}
