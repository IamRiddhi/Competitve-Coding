#include<bits/stdc++.h>
#include<cmath>
#include<climits>
#define test ll t; cin>>t; while(t--)
#define rep0(n) for(ll i=0;i<(n);i++)
#define rep1(n) for(ll i=1;i<=(n);i++)
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    test
    {
        ll k,n,*a;
        cin>>n>>k;
        a= new ll[n];
        rep0(n)
            cin>>a[i];
        unordered_map<ll,ll> mp;
        unordered_map<ll,ll>::iterator it;
        ll sum=0;
        rep0(n)
        {
            sum+=a[i];
            mp[(sum%k)]++; 
        }
        ll count=0;
        for(it=mp.begin();it!=mp.end();it++)
        {
            ll value= it->second;
            if(it->first==0)
                count+=(value*(value+1))/2;
            else
                count+=(value*(value-1))/2;
        }
        cout<<count<<endl;
    }
    return 0;
}
