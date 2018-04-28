#include<iostream>
#include<float.h>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    double pr;
    ll n;
    cin>>n>>pr;
    double p= pr/100.0;
    double three=1-p;
    double two=p;
    double *dp= new double[n+1];
    fill(dp,dp+n+1,DBL_MAX);
    dp[n]=0.0;
    dp[n-2]= two;
    dp[n-3]= three;
    for(ll i=n-4;i>=0;i--)
    {
        if(dp[i+2]!=DBL_MAX)
            dp[i]= (two * dp[i+2]);
            
        if(dp[i+3]!=DBL_MAX)
        {
            if(dp[i]==DBL_MAX)
                dp[i]= three * dp[i+3];
            else
                dp[i]= dp[i] + (three * dp[i+3]);
        }
    }
    
    cout<<fixed<<setprecision(6)<<dp[0]<<endl;
}