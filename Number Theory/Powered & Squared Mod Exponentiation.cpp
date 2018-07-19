#include<bits/stdc++.h>
#include<cmath>
#include<climits>
#define test ll t; cin>>t; while(t--)
#define rep0(n) for(ll i=0;i<(n);i++)
#define rep1(n) for(ll i=1;i<=(n);i++)
using namespace std;
typedef long long ll;
ll fxp(ll base, string exp, ll m)
{
    ll length = exp.length() - 1;
    ll res = 1;
    while(length>=0)
    {
        ll ivalue = exp[length] - '0';
        if(ivalue==2)
            res = (((res*base)%m)*base)%m;
        else if(ivalue==1)
            res = (res*base)%m;
        length--; //decreasing the exponent
        base = (((base*base)%m)*base)%m; // increasing the base.
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    test
    {
        ll a,m;
        string b;
        cin>>a>>b>>m;
        cout<<fxp(a,b,m)<<endl;
    }
    return 0;
}