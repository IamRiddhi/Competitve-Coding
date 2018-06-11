#include<bits/stdc++.h>
#include<cmath>
#include<climits>
#define test ll t; cin>>t; while(t--)
#define rep0(n) for(ll i=0;i<(n);i++)
#define rep1(n) for(ll i=1;i<=(n);i++)
using namespace std;
typedef long long ll;
ll kadane(ll *temp, ll n)
{
    ll max_so_far = 0;
    ll maximum = 0;
    
    for(ll i=0;i<n;i++)
    {
        max_so_far+=temp[i];
        if(max_so_far<0)
            max_so_far=0;
        maximum = max(maximum,max_so_far);
    }
    
    return maximum;
}
ll maxSumRectangle(ll **a,ll r,ll c)
{
    ll maximum = 0;
    
    ll *temp = new ll[r];
    
    for(ll i=0;i<c;i++) //fixing left boundary
    {
        for(ll j=i;j<c;j++) //fixing right boundary
        {
            for(ll k=0;k<r;k++) //setting the 1d array for kadane (row wise addition from left to right)
            {
                if(j>i)
                    temp[k]+=a[k][j];
                else
                    temp[k] = a[k][j];
            }
            
            maximum = max(maximum,kadane(temp,r)); //setting the top and bottom of rectangle and updating maximum value.
        }
    }
    return maximum;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    test
    {
        ll r,c,**a;
        cin>>r>>c;
        a= new ll*[r];
        rep0(r)
            a[i] = new ll[c];
  		bool allNeg = true;
        rep0(r)
        for(ll j=0;j<c;j++)
        {
            cin>>a[i][j];
  			if(a[i][j]>=0)
              allNeg = false;
        }
  		if(allNeg)
        {
           ll maximum = LLONG_MIN;
           rep0(r)
            for(ll j=0;j<c;j++)
              maximum = max(maximum,a[i][j]);
          cout<<maximum<<endl;
        }
        else
        	cout<<maxSumRectangle(a,r,c)<<endl;
    }
    return 0;
}