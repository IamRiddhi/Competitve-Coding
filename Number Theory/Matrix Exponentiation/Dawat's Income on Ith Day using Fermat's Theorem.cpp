#include<bits/stdc++.h>
#include<cmath>
#include<climits>
#define test ll t; cin>>t; while(t--)
#define rep0(n) for(ll i=0;i<(n);i++)
#define rep1(n) for(ll i=1;i<=(n);i++)
using namespace std;
typedef long long ll;
ll mod = 1000000007;

void matrixMultiply(ll a[2][2], ll b[2][2])
{
    ll f1 = ( (a[0][0]*b[0][0])%(mod-1) + (a[0][1]*b[1][0])%(mod-1))%(mod-1);
    ll f2 = ( (a[0][0]*b[0][1])%(mod-1) + (a[0][1]*b[1][1])%(mod-1))%(mod-1); 
    ll f3 = ( (a[1][0]*b[0][0])%(mod-1) + (a[1][1]*b[1][0])%(mod-1))%(mod-1);
    ll f4 = ( (a[1][0]*b[0][1])%(mod-1) + (a[1][1]*b[1][1])%(mod-1))%(mod-1);
    
    a[0][0] = f1;
    a[0][1] = f2;
    a[1][0] = f3;
    a[1][1] = f4;
}

void power(ll m[2][2],ll n)
{
    if(n==0 || n==1)
        return;
    
    power(m,n/2);
    matrixMultiply(m,m);
    
    if(n%2==1)
    {
        ll temp[2][2] = { {1,1}, {1,0} };
        matrixMultiply(m,temp);
    }
}

ll fibonacci(ll n)
{
    if(n==0)
        return 0;
    
    ll m[2][2] = { {1,1}, {1,0} };
    
    power(m,n-1);
    
    return m[0][0];
}
ll fxp(ll base, ll exp)
{
    ll res = 1;
    while(exp>0)
    {
        if(exp%2==1)
            res= (res*base)%mod;
        exp/=2;
        base=(base*base)%mod;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    test
    {
        ll n,f0,f1;
        cin>>f0>>f1>>n;
      	if(n==0)
          cout<<f0<<endl;
     	else if(n==1)
          	cout<<f1<<endl;
      	else
        {
          ll a = 1 + f0;
          ll b = 1 + f1;
          ll gn = ( fxp(a,fibonacci(n-1)) * fxp(b,fibonacci(n)) )%mod;
          cout<<(gn-1)<<endl;
        }
    }
    return 0;
}
