#include <iostream>
#include<bits/stdc++.h>
#include<climits>
using namespace std;
typedef long long ll;
#define rep(n) for(ll i=0;i<(n);i++)
#define test ll t; cin>>t; while(t--)
int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    test
    {
        ll n,*a;
        cin>>n;
        a= new ll[n];
        rep(n)
            cin>>a[i];
        ll *startAtI= new ll[n];
        ll *endAtI= new ll[n];
        ll maximum=a[0];
        
        startAtI[n-1]=a[n-1];
        for(ll i=n-2;i>=0;i--)
            startAtI[i]= max(a[i],a[i]+startAtI[i+1]);
       
        endAtI[0]=a[0];
        for(ll i=1;i<n;i++)
        {
            endAtI[i]= max(a[i],a[i]+endAtI[i-1]);
            maximum= max(maximum,endAtI[i]);
        }
        
        for(ll i=1;i<n-1;i++)
            maximum= max(maximum,endAtI[i-1]+startAtI[i+1]);
        
        cout<<maximum<<endl;
    }
	return 0;
}