/*
Overlapping Subproblem: If sum of array is even , we can divide else we cant. Now if sum is even still there is no gurantee that it can be
partitioned into equal sum. Now checking that using dp. If we by some combinations of the array(each element only taken 
once UNLIKE COIN CHANGE we get sum/2 we can say that it can be partitioned into two subsets. Now the overlapping 
subproblem lies here that if by taking some combination we reach a point where sum left and indices or elements
of the array left and has been taken before , and if we see we can get to that sum left using those elements left,
why compute again? also if we cant get , then also, why compute again?
*/
#include <bits/stdc++.h>
#include<climits>
typedef long long ll;
using namespace std;
bool subsetSum(ll n,ll *a, ll k)
{
  	bool *dp = new bool[k+1];
  	dp[0] = true;
  	for(int i=1;i<=k;i++)
      dp[i] = false;
  	for(int i=1;i<=n;i++)
      for(ll j=k;j>=a[i-1];j--)
      {
    	dp[j]|=dp[j-a[i-1]];
        if(dp[k])
          return true;
      }
  	return false;
}
int main()
{
  	ll n,*a,k;
    cin>>n;
  	a = new ll[n];
  	for(ll i=0;i<n;i++)
      cin>>a[i];
 	cin>>k;
  	if(subsetSum(n,a,k))
      cout<<"Yes"<<endl;
  	else
      cout<<"No"<<endl;
    return 0;
}
