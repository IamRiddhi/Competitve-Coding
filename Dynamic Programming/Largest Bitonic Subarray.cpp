#include<bits/stdc++.h>
#include<climits>
using namespace std;
typedef long long ll;
int longestBitonicSubarray(ll *a, ll n) 
{
    ll maximum = 1;
    ll *decreasing = new ll[n];
    ll *increasing = new ll[n];
    decreasing[n-1] = 1;
    increasing[0] = 1;
    for(ll i=1;i<n;i++)
    {
        if(a[i]>a[i-1])
            increasing[i] = increasing[i-1] + 1;
        else
            increasing[i] = 1;
    }
    for(ll i=n-2;i>=0;i--)
    {
        if(a[i]>a[i+1])
            decreasing[i] = decreasing[i+1] + 1;
        else 
            decreasing[i] = 1;
    }
    for(ll i=0;i<n;i++)
        maximum = max(maximum,increasing[i]+decreasing[i]-1);
    return maximum;
}
int main()
{
    ll t; cin>>t;
    while(t--)
    {
        ll n,*a;
        cin>>n;
        a = new ll[n];
        for(ll i=0;i<n;i++)
            cin>>a[i];
        cout<<longestBitonicSubarray(a,n)<<endl;
    }
    return 0;
}
