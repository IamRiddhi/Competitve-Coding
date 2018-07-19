#include <bits/stdc++.h>
#include<utility>
typedef long long ll;
using namespace std;
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
    // cout<<a<<" "<<b<<" "<<t.x<<" "<<t.y<<endl;
    return t;
}
int main() 
{
    ll t; cin>>t;
    while(t--)
    {
        ll a,m;
        cin>>a>>m;
        Triplet ans= ExtendedEuclid(a,m);
        if(ans.gcd==1)
            cout<<(ans.x%m+m)%m<<endl; //handle negative
        else
            cout<<"-1"<<endl;
    }
	return 0;
}
