#include<bits/stdc++.h>
#include<climits>
using namespace std;
typedef long long ll;
ll longestBitonicSubarray(ll *a, ll n) 
{
    ll maximum = LLONG_MIN;
    
    /* increasing sequence as end and decreasing sequence as start*/
    ll *increasing,*decreasing;
    increasing = new ll[n];
    decreasing = new ll[n];
    
    /* find out length of increasing sequence ending at i */
    increasing[0] = 1;
    for(ll i=1;i<n;i++)
        increasing[i] = (a[i]>a[i-1]? increasing[i-1] + 1: 1);
        
    /* find out the length of decreasing sequence starting at i*/
    decreasing[n-1] = 1;
    for(ll i=n-2;i>=0;i--)
        decreasing[i] = (a[i+1]<a[i]? decreasing[i+1] + 1: 1);
    
    for(ll i=0;i<n;i++)
        maximum = max(increasing[i]+decreasing[i]-1,maximum);
    
    return maximum;
}
ll longestBitonicSubSequence(ll *a, ll n)
{
    ll maximum = LLONG_MIN;
    
    /* increasing sequence as end and decreasing sequence as start*/
    ll *increasing,*decreasing,*lis;
    increasing = new ll[n];
    decreasing = new ll[n];
    lis = new ll[n];
    fill(lis,lis+n,LLONG_MAX);
    
    /* find out length of increasing sequence ending at i */
    for(ll i=0;i<n;i++)
    {
        ll pos = lower_bound(lis,lis+n,a[i]) - lis;
        lis[pos] = a[i];
        increasing[i] = pos + 1;
    }
    
    /* find out the length of decreasing sequence starting at i*/
    fill(lis,lis+n,LLONG_MAX);
    for(ll i=n-1;i>=0;i--)
    {
        ll pos = lower_bound(lis,lis+n,a[i]) - lis;
        lis[pos] = a[i];
        decreasing[i] = pos + 1;
    }
    
    for(ll i=0;i<n;i++)
        maximum = max(increasing[i]+decreasing[i]-1,maximum);
    
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
        //cout<<longestBitonicSubarray(a,n)<<endl;
        //cout<<longestBitonicSubSequence(a,n)<<endl;
    }
    return 0;
}