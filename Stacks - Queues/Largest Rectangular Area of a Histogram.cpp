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
        ll n,*a;
        cin>>n;
        a= new ll[n];
        rep0(n)
            cin>>a[i];
        stack<ll> s;
        ll maxi = 0;
        for(ll i=0;i<n;i++)
        {
            while(!s.empty() && a[i]<a[s.top()])
            {
                ll ind = s.top(); s.pop();
                ll left = -1;
                if(!s.empty())
                    left = s.top();
                maxi = max(maxi,a[ind]*(i-left-1));
            }
            s.push(i);
        }
        while(!s.empty())
        {
            ll ind = s.top(); s.pop();
            if(s.empty())
                maxi = max(maxi,a[ind]*n);
            else
                maxi = max(maxi,a[ind]*(n-s.top()-1));
        }
        cout<<maxi<<endl;    
    }
    return 0;
}
