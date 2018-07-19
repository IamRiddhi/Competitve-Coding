#include<bits/stdc++.h>
#include<cmath>
#include<climits>
#define test ll t; cin>>t; while(t--)
#define rep0(n) for(ll i=0;i<(n);i++)
#define rep1(n) for(ll i=1;i<=(n);i++)
using namespace std;
typedef long long ll;
ll mod = 1000000007;
ll fxp(ll base,ll exp)
{
    ll res = 1;
    while(exp>0)
    {
        if(exp%2==1)
            res = (res*base)%mod;
        base=(base*base)%mod;
        exp/=2;
    }
    return res;
}
ll mmi(ll a)
{
    return fxp(a,mod-2);
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s;
    cin>>s;
    ll freq[26]={0};
    ll length = s.length();
    for(ll i=0;i<length;i++)
        freq[s[i]-'a']++;
        
    ll *fact = new ll[length];
    fact[0] = fact[1] = 1;
    for(ll i=2;i<length;i++)
        fact[i] = (fact[i-1]*i)%mod;
    
    for(ll i=0;i<26;i++)
    {
        if(freq[i]==0)
            cout<<"0"<<" ";
        else
        {
            ll ans = fact[length-1];
            for(ll j=0;j<26;j++)
            {
                ll val;
                if(j==i) val = freq[j] - 1;
                else val = freq[j];
                ans = (ans*mmi(fact[val]))%mod;
            }
            cout<<ans<<" ";
        }
    }
    return 0;
}