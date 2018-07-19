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
    ll n,inp;
    cin>>n;
    vector<ll> a;
    rep(n)
    {
       cin>>inp;
       a.push_back(inp);
    }
    sort(a.begin(),a.end());
    ll minimum=LLONG_MAX;
    rep(n-1)
       minimum= min(a[i+1]-a[i],minimum);
    
    cout<<minimum<<endl;
	return 0;
}