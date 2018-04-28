#include <iostream>
#include<bits/stdc++.h>
#include<climits>
using namespace std;
typedef long long ll;
#define rep(n) for(ll i=1;i<=(n);i++)
int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll *a= new ll[n+1];
        memset(a,0,sizeof(a));
        rep(n)
        {
            ll m=sqrt(i);
            ll minimum=LLONG_MAX;
            for(ll j=1;j<=m;j++)
                minimum= min(minimum,1+a[i-j*j]);
            a[i]=minimum;
        }
        cout<<a[n]<<endl;
    }
	return 0;
}