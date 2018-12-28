#include<bits/stdc++.h>
#include<cmath>
#include<climits>
#define test ll t; cin>>t; while(t--)
#define rep0(n) for(ll i=0;i<(n);i++)
#define rep1(n) for(ll i=1;i<=(n);i++)
using namespace std;
typedef long long ll;
ll mod = 1000000007;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    test
    {
        ll n,*a,m;
        cin>>n>>m;
        a= new ll[n];
        rep0(n)
        {
            cin>>a[i];
            a[i] %= m;
        }
        ll *pre = new ll[n];
        pre[0] = a[0];
        for(ll i=1;i<n;i++)
            pre[i] = (pre[i-1] + a[i])%m;
        ll maximum = 0;
        set<ll> set;
        for(ll i=0;i<n;i++)
        {
            auto it = set.lower_bound(pre[i]+1);
            if(it==set.end()) //pre[i]+1 not found
                maximum = max(maximum,pre[i]);
            else //pre[i+1] found
                maximum = max(maximum,(pre[i]-*it+m)%m);
            set.insert(pre[i]);
        }
        cout<<maximum<<endl;
    }
    return 0;
}