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
        ll n;
        cin>>n;
        char **mat;
        mat= new char*[n];
        rep(n)
            mat[i]= new char[n];
        rep(n)
            for(ll j=0;j<n;j++)
                cin>>mat[i][j];
        bool *dp= new bool[n];
        bool **rockToEast= new bool*[n];
        rep(n)
            rockToEast[i]=new bool[n];
        fill(dp,dp+n,true);
        
        for(ll i=n-1;i>=0;i--)
        {
            rockToEast[i][n-1]= (mat[i][n-1]=='#')?true:false;
            for(ll j=n-2;j>=0;j--)
            {
                rockToEast[i][j]=rockToEast[i][j+1];
                if(!rockToEast[i][j] && mat[i][j]=='#')
                    rockToEast[i][j]=true;
            }
        }
        
        ll count=0;
        
        for(ll i=n-1;i>=0;i--)
        {
            for(ll j=n-1;j>=0;j--)
            {
                if(mat[i][j]=='#')
                    dp[j]=false;
                else if(dp[j] && !rockToEast[i][j])
                    count++;
            }
        }
        
        cout<<count<<endl;
        
    }
	return 0;
}