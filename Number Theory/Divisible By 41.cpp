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
        ll n,a0,a1,c;
        cin>>a0>>a1>>c>>n;
      	if(n==1)
        {
        	if(a0==0)
              cout<<"YES"<<endl;
          	else
              cout<<"NO"<<endl;
        }
      	else
        {
        	ll *arr = new ll[n];
            arr[0] = a0;
            arr[1] = a1;
            ll no= a0;
            no = (no*10 + a1)%41;
            for(ll i=2;i<n;i++)
            {
                arr[i] = (arr[i - 1]*c + arr[i - 2])%10;
                no = (no*10+ arr[i])%41;
            }
            if(no==0)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
    return 0;
}
