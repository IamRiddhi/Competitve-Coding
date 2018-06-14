#include<bits/stdc++.h>
#include<cmath>
#include<climits>
#define test ll t; cin>>t; while(t--)
#define rep0(n) for(ll i=0;i<(n);i++)
#define rep1(n) for(ll i=1;i<=(n);i++)
using namespace std;
typedef long long ll;
ll compute(string s1,string s2,ll k)
{
    ll len1 = s1.length();
    ll len2 = s2.length();
    
    ll dp[101][101][101];
    
    for(ll i=0;i<=len1;i++)
        for(ll j=0;j<=len2;j++)
            for(ll o=0;o<=k;o++)
            {
                if(o==0)
                    dp[i][j][o] = 0;  // when length is 0, obviously sum will be 0.
              	else if(o>min(i,j))
                  dp[i][j][o] = INT_MIN; //not possible to get subsequence of length k.
                else
                {
                    if(s1[i-1]==s2[j-1])
                    {
                        /* 3 possibilities */
                        ll possibility1 = s1[i-1] + dp[i-1][j-1][o-1]; // take this character
                        ll possibility2 = max(dp[i-1][j][o],dp[i][j-1][o]); //skip this character
                        dp[i][j][o] = max(possibility1,possibility2);
                    }
                    else
                        dp[i][j][o] = max(dp[i-1][j][o],dp[i][j-1][o]) ;
                }
            }
    if(dp[len1][len2][k]<0)
      dp[len1][len2][k] = 0;
    return dp[len1][len2][k];
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    test
    {
        ll k; string s1,s2;
        cin>>s1>>s2;
        cin>>k;
        cout<<compute(s1,s2,k)<<endl;
    }
    return 0;
}