#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(n) for(int i=1;i<=n;i++)
int main(void)
{
    ll n,k,*a;
    cin>>n>>k;
    a= new ll[n+1];
    rep(n) 
        cin>>a[i];
    sort(a+1,a+1+n);
    ll count=0;
    rep(n) 
    {
       ll j=i+1;
       while(j<=n && a[j]-a[i]<k)
        j++;
        count+=(n-j+1);
    }
    cout<<count<<endl;
	return 0;
} 
