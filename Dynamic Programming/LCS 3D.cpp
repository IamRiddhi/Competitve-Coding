#include <iostream>
#include<bits/stdc++.h>
#include<climits>
using namespace std;
typedef long long ll;
#define repF(startOFi,n) for(ll i=startOFi;i<=(n);i++)
#define repB(n,endOFi) for(ll i=n;i<=(endOFi);i--)
#define test ll t; cin>>t; while(t--)
ll n,m,k;
string s1,s2,s3;
ll LCS3D()
{
    ll dp[n+1][m+1][k+1];
   
    for(ll i=0;i<=n;i++)
    {
        for(ll j=0;j<=m;j++)
        {
            for(ll o=0;o<=k;o++)
            {
                if(i==0 || j==0 || o==0)
                    dp[i][j][o]=0;
                    
                else if(s1[i-1]==s2[j-1] && s2[j-1]==s3[o-1])
                    dp[i][j][o]= 1 + dp[i-1][j-1][o-1];
                
                else 
                    dp[i][j][o]= max(dp[i][j][o-1], max(dp[i-1][j][o],dp[i][j-1][o]));
            }
        }
    }
    return dp[n][m][k];
}
int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    test
    {
        cin>>n>>m>>k;
        cin>>s1>>s2>>s3;
        cout<<LCS3D()<<endl;
    }
	return 0;
}