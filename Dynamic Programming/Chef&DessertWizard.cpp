#include <iostream>
#include<bits/stdc++.h>
#include<climits>
using namespace std;
typedef long long ll;
#define rep(n) for(ll i=0;i<(n);i++)
#define test ll t; cin>>t; while(t--)
ll n,*a;
int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    test
    {
        cin>>n;
        a= new ll[n];
        rep(n)
            cin>>a[i];
        
        ll *dpMaxSubarray= new ll[n];
        ll *dpMinSubarray= new ll[n];
        ll *dpMax= new ll[n];
        ll *dpMin= new ll[n];
        
        ll ansMax= LLONG_MIN;
        
        //min-max(min from front max from back)
        
        dpMaxSubarray[n-1]=a[n-1];
        dpMax[n-1]= a[n-1];
        for(ll i=n-2;i>=0;i--)
        {
            dpMaxSubarray[i]= max(a[i],a[i]+dpMaxSubarray[i+1]);
            dpMax[i]= max(dpMaxSubarray[i],dpMax[i+1]);
        }
        
        dpMinSubarray[0]= a[0];
        dpMin[0]= a[0];
        for(ll i=1;i<n;i++)
        {
            dpMinSubarray[i]= min(a[i],a[i]+dpMinSubarray[i-1]);
            dpMin[i]= min(dpMinSubarray[i],dpMin[i-1]);
        }
        //calculate abs-diff
        for(ll i=0;i<n-1;i++)
        {
            ll val= abs(dpMin[i]-dpMax[i+1]);
            ansMax= max(val,ansMax);
        }
        
        //max-min(max from front min from back)
        
        dpMinSubarray[n-1]=a[n-1];
        dpMin[n-1]= a[n-1];
        for(ll i=n-2;i>=0;i--)
        {
            dpMinSubarray[i]= min(a[i],a[i]+dpMinSubarray[i+1]);
            dpMin[i]= min(dpMinSubarray[i],dpMin[i+1]);
        }
        
        dpMaxSubarray[0]= a[0];
        dpMax[0]= a[0];
        for(ll i=1;i<n;i++)
        {
            dpMaxSubarray[i]= max(a[i],a[i]+dpMaxSubarray[i-1]);
            dpMax[i]= max(dpMaxSubarray[i],dpMax[i-1]);
        }
        
        // for(ll i=0;i<n;i++)
        //     cout<<dpMaxSubarray[i]<<" "; cout<<endl;
            
        //calculate abs-diff
        for(ll i=0;i<n-1;i++)
        {
            ll val= abs(dpMax[i]-dpMin[i+1]);
            ansMax= max(val,ansMax);
        }
        
        
        cout<<ansMax<<endl;
    }
	return 0;
}