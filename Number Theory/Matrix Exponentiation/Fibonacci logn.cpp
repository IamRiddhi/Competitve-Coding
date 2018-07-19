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

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n;
    cin>>n;
    cout<<fibonacci(n)<<endl;
    return 0;
}