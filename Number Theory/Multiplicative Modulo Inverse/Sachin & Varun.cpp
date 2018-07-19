#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class Triplet
{
    public: ll x,y,gcd;
};
Triplet ExtendedEuclid(ll a, ll b)
{
    Triplet t;
    if(b==0)
    {
        t.gcd=a;
        t.x= 1;
        t.y= 0;
    }
    else
    {
        Triplet smallAns= ExtendedEuclid(b,a%b);
        t.gcd= smallAns.gcd;
        t.x= smallAns.y;
        t.y= smallAns.x- ((a/b)*smallAns.y);
    }
    return t;
}
int main()
{
  	ll t; cin>>t;
  	while(t--)
    {
      ll a,b,d;
      cin>>a>>b>>d;
      ll g = (ExtendedEuclid(a,b)).gcd;
      if(d%g!=0)
      {
        cout<<"0"<<endl;
        continue;
      }
      if(d==0)
      {
        cout<<"1"<<endl;
        continue;
      }
      a/=g;
      b/=g;
      d/=g;
      Triplet t= ExtendedEuclid(b,a);
      while(((t.x)+a)%a <0 )
        t.x= t.x+a;
      ll y1=  (d%a * ((t.x)%a+a)%a)%a;
      if(y1>d/b)
      {
        cout<<"0"<<endl; 
        continue;
      }
      ll n= (d/b-y1)/a;
      cout<<n+1<<endl;
    }
	return 0;
}
