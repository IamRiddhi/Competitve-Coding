 /*
 Overlapping Subproblem: We may reach a sum of one set again and again by taking different combinations
 and from that sum we know the absolute diff between that sum and totsum-sum. so just like partition problem
 we make a 2d array this time from 1 to totsum because we can acheive the totsum at max. now dp[i][a[i]] is always
 true. and if dp[i-1][j] ie if the sum(j) can be reached using combination of previous (i-1) elements then
 that sum(j) can also be reached using this i as well (excluding i) and we make dp[i][j+a[i]] true as we simply
 add a[i] to all [i-1][j] where [i-1][j] is 1, ie we add a[i] to all possible combinations of (i-1) elements.
 And we update the minimum by taking minimum of previous combinations of i-1 elements and taking a[i] + previous 
 combination of i-1 elements. if a sum(j) can't be reached using previous (i-1) combinations then check if it can
 be reached using combinations of i elements and update the minimum.
 
 PSEUDO CODE:
 sum 0 can always be reached hence dp[i][0] is 1.
 dp[i][a[i]] can always be reached hence always true.
 
 Now 
 IF dp[i][j]= true  && dp[i-1][j]=false ie (either previous j of this ith element has made it true 
 or dp[i][a[i]]= true) and that sum(j) cant be reached without ith element of a[i] then just update the minimum
 as the minimum for this dp[i][j] is not previously checked and no need to add a[i] to previous combinations of 
 (i-1) as we just saw it is not possible to reach sum(j) using previous i-1 combinations dp[i-1][j]=false.
 
 ELSE
 it is entering else loop because of either of 2 cases
 Case 1: dp[i][j]=false ie its not dp[i][a[i]] nor did previous j of same i made it true. 
 so it is sure we cant reach sum(j) using a[i]...therefore we can only reach it if previous combination of 
 (i-1) elements can reach sum(j)
 if previous combination is true then we make dp[i][j+a[i]] true.
 Case 2: if dp[i][j] is true but dp[i-1][j] not false that means minimum till sum(j) was previously checked
 and also we have to add j+a[i] of ith index to make it true(A[i] added with sum reached with (i-1) combinations.
 
 */  
 #include <iostream>
#include<bits/stdc++.h>
#include<climits>
using namespace std;
typedef long long ll;
#define rep(n) for(ll i=1;i<=(n);i++)
#define test ll t; cin>>t;while(t--)
ll n,*a,sum;
ll minSumPartition()
{
    bool **dp;
    ll minimum= sum;
    dp = new bool*[n+1];
    for(ll i=0;i<=n;i++)
    {
        dp[i]= new bool[sum+1];
        memset(dp[i],false,sizeof(dp[i]));
        dp[i][0]= true; //sum 0 can always be reached hence dp[i][0] is 1.
    }
    rep(n)
        dp[i][a[i]]=true; // dp[i][a[i]] can always be reached hence always true.
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=sum;j++)
        {
            if(dp[i][j] && !dp[i-1][j]) 
            {
                if(minimum>abs(sum-2*j))
                    minimum= abs(sum-2*j);
            }
            else
            {
            	dp[i][j]=dp[i-1][j];
            	if(dp[i][j])
            		dp[i][j+a[i]]= true;
			}
        }
    }
    // for(ll i=0;i<=n;i++)
    // {
    //     for(ll j=0;j<=sum;j++)
    //         cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
    return minimum;
}
int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    test
    {
        cin>>n;
        a=new ll[n+1];
        sum=0;
        rep(n)
        {
            cin>>a[i];
            sum+=a[i];
        }
        cout<<minSumPartition()<<endl;
    }
	return 0;
}
