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
    ll n,k,x,*a;
    cin>>n>>k>>x;
    a= new ll[n];
    ll val[1024] = {0};
    int temp[1024]={0};
    rep0(n)
    {
        cin>>a[i];
        val[a[i]]++;
    }
    
    for(ll i=1;i<=k;i++)
    {
        int cnt = 0;
        for(ll j=0;j<=1023;j++)
        {
          	if(cnt%2==0)
            {
            	temp[j^x]+=ceil(val[j]/2.0);
              	temp[j]+=(val[j]/2);
            }
            else
            {
              	temp[j]+=ceil(val[j]/2.0);
              	temp[j^x]+=(val[j]/2);
            }            
          	cnt += val[j];
        }
        for(ll j=0;j<=1023;j++)
        {
            val[j] = temp[j];
            temp[j] = 0;
        }
    }
    
    ll minimum,maximum;
    for(ll i=0;i<=1023;i++)
        if(val[i]>0)
        {
            minimum = i;
            break;
        }
    for(ll i=1023;i>=0;i--)
        if(val[i]>0)
        {
            maximum = i;
            break;
        }
    cout<<maximum<<" "<<minimum;
    return 0;
}