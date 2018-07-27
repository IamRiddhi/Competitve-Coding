#include <iostream>
#include<bits/stdc++.h>
#include<stack>
using namespace std;
typedef long long ll;
#define rep(n) for(ll i=0;i<n;i++)
int main(void)
{
    ll n,k,*a;
    cin>>n>>k;
    a= new ll[n];
    rep(n) 
        cin>>a[i];
    ll count=0;
    sort(a,a+n);
    ll i=0;
    while(i<n)  
    {
        ll j=n-1;
        while(j>i && a[i]+a[j]>=k)
            j--;
        count+=(j-i);
        n=j+1;
        i++;
    }
    cout<<count;
	return 0;
}