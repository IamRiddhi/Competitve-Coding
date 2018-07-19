#include<bits/stdc++.h>
#define MOD 1000000007
typedef long long ll;
using namespace std;
typedef long long ll;
bool primes[50001];
void seive()
{
  fill(primes,primes+50001,true);
  primes[0]= primes[1]= false;
  ll sq= sqrt(50000);
  for(ll i=2;i<=sq;i++)
    if(primes[i])
      for(ll j=i+i;j<=50000;j+=i)
        primes[j]= false;
}
int main()
{
   /* Every number can be expressed as power of primes....
      Therefore no of divisors = (a+1)(b+1).....*/
   
  	seive(); //finding out primes
  	ll t; cin>>t;
 	while(t--)
    {
       ll n,divisors=1,power;
       cin>>n;
       for(ll i=2;i<=n;i++)  //check for every prime less than n as prime factor of n! will be less than n
       {
         if(primes[i])
         {
           	power=0;
           	ll tmp= n;
            while(tmp) //legendre's formula, calculating power = n/p + n/(p^2) + n/(p^3) + ....
            {
              tmp/=i;
              power+=tmp;
            }
          	divisors= (divisors*(power+1))%MOD;  // using the formula (a+1)(b+1)..... where a,b...are powers of prime factors.
         }
       }
      	cout<<divisors<<endl;
    }
	return 0;
}
