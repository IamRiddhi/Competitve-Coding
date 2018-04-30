#include<bits/stdc++.h>
#include<cmath>
#include<climits>
#define test ll t; cin>>t; for(ll T=1;T<=t;T++)
#define rep0(n) for(ll i=0;i<(n);i++)
#define rep1(n) for(ll i=1;i<=(n);i++)
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    test
    {
        ll n,*a;
        cin>>n;
        a= new ll[n];
        rep0(n)
            cin>>a[i];
        if(n>=2)
            a[n-2] = max(a[n-2],a[n-1]);
        for(ll i=n-3;i>=0;i--)
            a[i] = max(a[i]+a[i+2],a[i+1]);
    
        cout<<"Case "<<T<<": "<<a[0]<<endl;
    }
    return 0;
}