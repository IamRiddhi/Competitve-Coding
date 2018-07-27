#include <iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef long long ll;
#define rep(n) for(int i=1;i<=n;i++)
int main(void)
{
    ll n,*a;
    cin>>n;
    a= new ll[n+1];
    rep(n) cin>>a[i];
    sort(a+1,a+1+n);
    ll sum=0;
    rep(n) 
        sum+=( (a[i]*(i-1))-(a[i]*(n-i)) );
    cout<<sum<<endl;
	return 0;
} 
