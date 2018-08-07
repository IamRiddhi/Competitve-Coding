#include<bits/stdc++.h>
#include<cmath>
#include<climits>
#define test int t; cin>>t; while(t--)
#define rep0(n) for(int i=0;i<(n);i++)
#define rep1(n) for(int i=1;i<=(n);i++)
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    test
    {
        int n,*a;
        cin>>n;
        a= new int[n];
        rep0(n)
            cin>>a[i];
            
        int dp[1001][2000]={0};
        for(int i=0;i<=n;i++)
            dp[i][0] = 1;
            
        for(int i=1;i<=n;i++)
            for(int j=i-1;j>=1;j--)
            {
                int  d = a[i-1] - a[j-1];
                if(d>0)
                  d+=999;
                else
                  d = -d;
                	if(d==0)
                  	dp[i][d] = (dp[j][d]+dp[i][d]);
              	else
                	dp[i][d] = (dp[j][d] + dp[i][d] + 1);
            }
        int sum = 0;
        for(int i=0;i<=n;i++)
            for(int j=0;j<2000;j++)
                sum = (sum + dp[i][j]);
        cout<<sum<<endl;
    }
    return 0;
}