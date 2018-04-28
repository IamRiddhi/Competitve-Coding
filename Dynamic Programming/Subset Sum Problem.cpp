/*
Overlapping Subproblem: If sum of array is even , we can divide else we cant. Now if sum is even still there is no gurantee that it can be
partitioned into equal sum. Now checking that using dp. If we by some combinations of the array(each element only taken 
once UNLIKE COIN CHANGE we get sum/2 we can say that it can be partitioned into two subsets. Now the overlapping 
subproblem lies here that if by taking some combination we reach a point where sum left and indices or elements
of the array left and has been taken before , and if we see we can get to that sum left using those elements left,
why compute again? also if we cant get , then also, why compute again?
*/
#include <iostream>
#include<bits/stdc++.h>
#include<climits>
using namespace std;
typedef long long ll;
#define rep(n) for(ll i=1;i<=(n);i++)
ll t,n,*a,sum;

bool subsetSum()
{
    
   bool **dp;
   dp=new bool*[n+1];
   for(ll i=0;i<=n;i++)
   {
       dp[i]= new bool[sum+1];
       memset(dp[i],false,sizeof(dp[i]));
   }
   
   
   for(ll i=1;i<=n;i++)
   {
       for(ll j=1;j<=sum;j++)
       {
           if(j==a[i])
                dp[i][j]=true;
            
           else if(j<a[i])
                dp[i][j]=dp[i-1][j];
            
           else if(j>a[i])
                dp[i][j]= dp[i-1][j] | dp[i-1][j-a[i]];    
       }
   }
   return dp[n][sum];
}

int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        sum=0;
        cin>>n;
        a= new ll[n+1];
        rep(n)
        {
            cin>>a[i];
            sum+=a[i];
        }
        if(sum%2==1)
        {
            cout<<"NO"<<"\n";
            continue;
        }
        sum>>=1;
        if(sum==0 || subsetSum())
            cout<<"YES"<<"\n";
        else 
            cout<<"NO"<<"\n";
    }
	return 0;
}
