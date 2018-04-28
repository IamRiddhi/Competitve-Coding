#include<bits/stdc++.h>
#include<cmath>
#include<climits>
#define test ll t; cin>>t; while(t--)
#define rep0(n) for(ll i=0;i<(n);i++)
#define rep1(n) for(ll i=1;i<=(n);i++)
using namespace std;
typedef long long ll;
ll n,c,*stalls;
bool checkCondition(ll minDistance) //c cows can be placed
{
  	ll cowsPlaced=1; 
  	ll lastPlaced = 0;
  	while(cowsPlaced<c)
    {
    	ll i = lastPlaced + 1;
      	while(i<n && stalls[i]-stalls[lastPlaced]<minDistance)
      	    i++;
      	if(i==n) // no stalls left
      	    return false;
      	 lastPlaced=i;
      	 cowsPlaced++;
    }
  	return true;
}
ll myBsearch(ll low, ll high)
{
  	while(low<high)
    {
      ll mid = ceil((low+high)/2.0);
      if(checkCondition(mid))
        low = mid;
      else
        high = mid-1;
    }
  	return low;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    test
    {
        cin>>n>>c;
        stalls= new ll[n];
        rep0(n)
            cin>>stalls[i];
      	sort(stalls,stalls+n);
      	ll maxDist = stalls[n-1] - stalls[0];
      	cout<<myBsearch(0,maxDist)<<endl;
    }
    return 0;
}