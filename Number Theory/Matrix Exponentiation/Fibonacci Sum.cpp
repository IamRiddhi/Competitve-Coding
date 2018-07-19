#include<bits/stdc++.h>
#include<cmath>
#include<climits>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
void matrixMultiply(ll a[2][2], ll b[2][2])
{
    ll f1 = ( (a[0][0]*b[0][0])%(mod) + (a[0][1]*b[1][0])%(mod))%(mod);
    ll f2 = ( (a[0][0]*b[0][1])%(mod) + (a[0][1]*b[1][1])%(mod))%(mod); 
    ll f3 = ( (a[1][0]*b[0][0])%(mod) + (a[1][1]*b[1][0])%(mod))%(mod);
    ll f4 = ( (a[1][0]*b[0][1])%(mod) + (a[1][1]*b[1][1])%(mod))%(mod);
    
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
long long fiboSum(ll n,ll m)
{
	ll fn = fibonacci(n+1); //f(n-1)
   	ll fm = fibonacci(m+2);
    return (fm - fn+mod)%mod;
}
int main()
{
	ll t; cin>>t;
	while(t--)
	{
		ll n,m;
		cin>>n>>m;
		cout<<fiboSum(n,m)<<endl;
	}
	return 0;
}