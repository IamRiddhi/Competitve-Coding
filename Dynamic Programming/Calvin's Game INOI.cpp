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
    ll n,*a,k;
    cin>>n>>k;
    a= new ll[n+1];
    rep1(n)
        cin>>a[i];
    ll *backward = new ll[n+1];
    backward[1] = 0;
    if(n>=2)
        backward[2] = a[1];
    for(ll i=3;i<=n;i++)
        backward[i] = max(a[i-1]+backward[i-1],a[i-2]+backward[i-2]);
        
    ll *endElem = new ll[n+1];
    endElem[k] = 0;
    if(k+1<=n)
        endElem[k+1] = a[k+1];
    for(ll i=k+2;i<=n;i++)
        endElem[i] = a[i] + max(endElem[i-1],endElem[i-2]);
    
    ll maximum = LLONG_MIN;
    for(ll i=k;i<=n;i++)
        maximum = max(maximum,endElem[i]+backward[i]);
    cout<<maximum<<endl;
    
    return 0;
}