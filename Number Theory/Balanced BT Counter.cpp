#define MOD 1000000007
int balancedBTs(int h) 
{
	long long int* dp= new long long int[h+1];
  	dp[0]=dp[1]=1;
  	for(long long int i=2;i<=h;i++)
      dp[i]= (dp[i-1]*(dp[i-1]+(2*dp[i-2])%MOD)%MOD)%MOD;
  	return dp[h];
}
