#include <iostream>
#include<bits/stdc++.h>
#include<climits>
#include<algorithm>
using namespace std;
typedef long long ll;
#define rep(n) for(ll i=0;i<(n);i++)
#define test ll t; cin>>t ; while(t--)
ll n,*a;
ll LIS()
{
    if(n==0)
        return 0;
    ll *endElems= new ll[n];
    fill(endElems,endElems+n,LLONG_MAX);
    ll *parent= new ll[n];
    fill(parent,parent+n,-1);
    ll maximum=0;
    rep(n)
    {
        ll index= lower_bound(endElems,endElems,a[i]) - endElems;
        endElems[index]= a[i];
        parent[i]= index-1;
        maximum= max(index,maximum);
    }
    return maximum+1;
    
}
int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    test
    {
        cin>>n;
        a= new ll[n];
        rep(n)
            cin>>a[i];
        cout<<LIS()<<endl;
    }
	return 0;
}