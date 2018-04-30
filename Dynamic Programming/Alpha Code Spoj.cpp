#include <bits/stdc++.h>
#include<climits>
using namespace std;
typedef long long ll;
#define mod LLONG_MAX
ll solve(string s,ll length)
{
  	ll len = s.length();
  	ll *dp = new ll[len];
  	
  	if(s[len-1]-'0'==0)
		dp[len-1] = 0;
 	else
      dp[len-1] = 1;
  	
  	if(len>=2)
    {
      	if(s[len-2]-'0'==0)
          dp[len-2] = 0;
      	else if(s[len-2]-'0'==1)
          dp[len-2] = 1 + dp[len-1];
      	else if(s[len-2]-'0'==2)
        {
        	if(s[len-1]-'0'<=6)
              dp[len-2] = 1 + dp[len-1];
          	else
              dp[len-2] = 1;
        }
      	else
          dp[len-2] = dp[len-1];
      	
      	for(ll i=len-3;i>=0;i--)
        {
          	if(s[i]-'0'==0)
              dp[i] = 0;
          	else if(s[i]-'0'==1)
            	dp[i] = (dp[i+1] + dp[i+2])%mod;
        	else if(s[i]-'0'==2)
            {
              if(s[i+1]-'0'<=6)
              	dp[i] = (dp[i+1] + dp[i+2])%mod;
          	  else
              	dp[i] = dp[i+1];
            }
          	else
              dp[i] = dp[i+1];
        }
    }
    return dp[0];	
}
int main()
{
  	while(1)
    {
  		string s;
  		cin>>s;
      	if(s[0]-'0'==0)
          break;
  		cout<<solve(s,s.length())<<endl;
    }
    return 0;
}

