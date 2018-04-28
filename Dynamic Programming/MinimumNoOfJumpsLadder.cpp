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
        
    ll *dp;
    dp= new ll[n];
    
    dp[n-1]= a[n-1];
    dp[n-2]= a[n-2]+a[n-1];
    dp[n-3]= max( (a[n-3]+dp[n-1]), max(dp[n-2], (a[n-3]+a[n-2]) ) );
    
    ll ajThekeKhelboArPorerDinKhelbo, ajThekeKhelboAr3rdDayKhelbo, kalThekeKhelbo;
    
    for(ll i=n-4;i>=0;i--)
    {
        ajThekeKhelboAr3rdDayKhelbo= a[i]+dp[i+2];  //1,3
        kalThekeKhelbo= dp[i+1];    //2,3
        ajThekeKhelboArPorerDinKhelbo= a[i]+a[i+1] + dp[i+3];   //1,2
        
        dp[i]= max(ajThekeKhelboAr3rdDayKhelbo,max(ajThekeKhelboArPorerDinKhelbo,kalThekeKhelbo));        
    }
    // for(ll i=n-1;i>=0;i--)
    //     cout<<dp[i]<<endl;
        
    return dp[0];
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
 
