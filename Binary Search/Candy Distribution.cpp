#include<bits/stdc++.h>
#include<cmath>
#include<climits>
#define test ll t; cin>>t; while(t--)
#define rep0(n) for(ll i=0;i<(n);i++)
#define rep1(n) for(ll i=1;i<=(n);i++)
using namespace std;
typedef long long ll;
ll k,n,*a;
bool canDistribute(ll candies)
{
    ll ki = 0;
  	ll *dummy = new ll[n];
  	rep0(n)
      dummy[i] = a[i];

  	rep0(n)
        if(dummy[i]>=candies)
        {
          	ki+=(dummy[i]/candies);
            if(ki>=k)
                return true;
        }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    test
    {
        cin>>n>>k;
        a= new ll[n];
        rep0(n)
            cin>>a[i];
        ll maximum = *(max_element(a,a+n));
        
        /* binary searching from 0 to maximum */
        ll lo = 0;
        ll hi = maximum;
        while(lo<hi)
        {
            ll mid = ceil((lo+hi)/2.0);
            if(canDistribute(mid))
                lo = mid;
            else
                hi = mid - 1;
            // cout<<mid<<" "<<lo<<" "<<hi<<endl;
        }
        cout<<lo<<endl;
    }
    
    return 0;
}