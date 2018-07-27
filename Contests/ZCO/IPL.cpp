#include <iostream>
#include<limits.h>
#include<algorithm>
using namespace std;

typedef long long ll;
ll n,*a;
ll func()
{
    if(n==2)
        return a[0]+a[1];
    else if(n==1)
        return a[0];
        
    ll **dp;
    dp= new ll*[n];
    for(ll i=0;i<n;i++)
        dp[i]= new ll[2];
    
    dp[n-1][0]= a[n-1];
    dp[n-1][1]= a[n-1];
    dp[n-2][0]= a[n-2]+a[n-1];
    dp[n-2][1]= a[n-2];
    
    ll maximum1= 0;
    ll maximum0= 0;
    for(ll i=n-3;i>=0;i--)
    {
        maximum1= max(maximum1,dp[i+2][0]);
        maximum0= max(maximum0,max(dp[i+1][1],maximum1));
        
        dp[i][0]= a[i] + maximum0;
        dp[i][1]= a[i]+  maximum1;
        
    }
    // for(ll i=n-1;i>=0;i--)
    //     cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
        
    return max(dp[0][0],dp[1][0]);
}
int main()
{
    
    cin>>n;
    a= new ll[n];
    for(ll i=0;i<n;i++)
        cin>>a[i];
    cout<<func()<<endl;
	return 0;
}
