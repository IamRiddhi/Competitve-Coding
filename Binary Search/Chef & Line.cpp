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
        ll n,*a,k,b;
        cin>>n>>k>>b;
        a= new ll[n];
        rep0(n)
            cin>>a[i];
        sort(a,a+n);
        ll *ans = new ll[n];
        ans[n-1] = 1;
        ll *maximum = new ll[n]; /* maximum length */
        maximum[n-1] = 1;
        for(ll i=n-2;i>=0;i--)
        {
            ll reachable = k*a[i] + b;
            ll j = lower_bound(a+i+1,a+n,reachable) - a;
            ans[i] = 1 + maximum[j];
            maximum[i] = max(maximum[i+1],ans[i]);
        }
        cout<<maximum[0]<<endl;
    }
    return 0;
}