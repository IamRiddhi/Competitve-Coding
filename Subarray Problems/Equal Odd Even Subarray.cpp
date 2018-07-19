#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n;
    scanf("%lld",&n);
    ll *a;
    a= new ll[n];
    ll even=0,odd=0;
    unordered_map<ll,ll> mp;
    unordered_map<ll,ll>::iterator it;
    for(ll i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        if((a[i]&1)==0)
            even++;
        else 
            odd++;
        mp[odd-even]++;
    }
    ll p=0;
    for(it=mp.begin();it!=mp.end();it++)
    {
        if((it->first)==0)
            p=p+ ((it->second)*((it->second)+1))/2; 
        else
            p=p+ ((it->second)*((it->second)-1))/2; 
    }
    printf("%lld\n",p);       
    return 0;
}