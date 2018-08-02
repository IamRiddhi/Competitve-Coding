#include<bits/stdc++.h>
#include<cmath>
#include<climits>
#define test ll t; cin>>t; while(t--)
#define rep0(n) for(ll i=0;i<(n);i++)
#define rep1(n) for(ll i=1;i<=(n);i++)
using namespace std;
typedef long long ll;
ll *util;
int noOfDigits(ll n)
{
    if(n==0)
        return 1;
    int c = 0;
    while(n>0)
    {
        n/=10;
        c++;
    }
    return c;
}
ll sumRes(ll n)
{
    if(n==0)
        return 0;
    ll d = noOfDigits(n);
    
    ll x = pow(10,d-1);
    ll firstDigit = n/x;
    ll rem = n%(firstDigit*x);
    
    ll sum = 0;
    for(ll i=0;i<firstDigit;i++)
        sum+=(i*x+util[d-1]);
        
    return (sum + firstDigit*(rem+1) + sumRes(rem));
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while(1)
    {
        ll a,b;
        cin>>a>>b;
        if(a==-1 && b==-1)
            break;
        int d = noOfDigits(b);
        util = new ll[d];
        util[0] = 0;
        for(ll digits=1;digits<d;digits++)
        {
            ll sum = 0;
            for(ll i=0;i<=9;i++)
                sum+=(i*pow(10,digits-1)+util[digits-1]);
            util[digits] = sum;
        }
        cout<<sumRes(b)-sumRes(a-1)<<endl;
    }
    return 0;
}