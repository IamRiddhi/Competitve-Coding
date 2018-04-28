#include <iostream>
#include<bits/stdc++.h>
#include<climits>
using namespace std;
typedef long long ll;
#define rep(n) for(ll i=0;i<(n);i++)
#define test ll t; cin>>t; while(t--)
int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    test
    {
        ll n,*a,*dp;
        bool *sign; //negative means false, positive means true
        cin>>n;
        a= new ll[n];
        dp= new ll[n];
        sign= new bool[n];
        rep(n)
            cin>>a[i];
        dp[n-1]=1;
        sign[n-1]= a[n-1]<0?false:true;
        for(ll i=n-2;i>=0;i--)
        {
            sign[i]= a[i]<0?false:true;
            if(sign[i]==sign[i+1]) //same sign
                dp[i]= 1;
            else
                dp[i]= 1 + dp[i+1];
        }
        rep(n)
            cout<<dp[i]<<" ";
        cout<<endl;
    }
	return 0;
}