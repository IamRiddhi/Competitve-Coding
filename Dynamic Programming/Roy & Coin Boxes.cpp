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
    ll n,m,q;
    cin>>n>>m;
    ll *choc = new ll[n+2];
    ll *ar = new ll[n];
    fill(choc,choc+n+2,0);
    while(m--)
    {
        ll l,r;
        cin>>l>>r;
        choc[l]++;
        choc[r+1]--;
    }
    ar[0] = choc[1] + choc[0];
    for(ll i=2;i<=n;i++)
        ar[i-1] = choc[i] + ar[i-2];
    sort(ar,ar+n);

    cin>>q;
    while(q--)
    {
        ll x; 
        cin>>x;
        ll ind = lower_bound(ar,ar+n,x) - ar;
        cout<<(n-ind)<<endl;
    }
    
    return 0;
}