#include <iostream>
#include<limits.h>
#include<algorithm>
using namespace std;
 
typedef long long ll;
ll n,*a;
ll func()
{
    if(n==2)
        return 0;
    else if(n==1)
        return 0;
        
    ll *dp;
    dp= new ll[n];
    dp[n-1]= a[n-1];
    dp[n-2]= a[n-2];
    dp[n-3]= a[n-3];
    
    for(ll i=n-4;i>=0;i--)
    {
        dp[i]= a[i]+ min(dp[i+1],min(dp[i+2],dp[i+3]));
    }
    return min(dp[0],min(dp[1],dp[2]));
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
