#include <iostream>
using namespace std;
typedef long long ll;
#define rep(n) for(ll i=0;i<(n);i++)


ll n,*wt,*val,maxWeight;

// ll dKnap(ll index,ll availableWeight)
// {
//      if(availableWeight==0 || index==n )
//         return 0;
    
//     if(wt[index]>availableWeight)
//         return dKnap(index+1,availableWeight); 

//     ll take,dontTake;
    
//     dontTake= dKnap(index+1,availableWeight); //skipping current item
//     take= val[index]+ dKnap(index+1,availableWeight-wt[index]); //taking current item
    
//     return max(take,dontTake);
// }

// ll dKnapDynamic()
// {
//     ll **dp;
//     dp= new ll*[n];
//     rep(n)
//         dp[i]= new ll[maxWeight+1];
    
//     rep(n)
//     {
//         dp[i][0]=0;
//     }
    
//     for(ll j=1;j<=maxWeight;j++)
//         dp[0][j]= wt[0]<=j ? val[0]:0;
    
//     for(ll i=1;i<n;i++)
//     {
//         for(ll j=1;j<=maxWeight;j++)
//         {
//             if(weights[i]>j)
//                 dp[i][j]= dp[i-1][j];
//             else 
//               dp[i][j]= max( values[i] + dp[i-1][j-wt[i]] //take
//                                  ,    dp[i-1][j] ); // dont take
//         }
//     }
//     return dp[n-1][maxWeight];
// }
int knapsack(int* weights, int* values, int n, int maxWeight){

     int *dp = new int[maxWeight+1];
  	
  	for(int i=0;i<=maxWeight;i++)
      dp[i] = 0;
  
  	for(int i=1;i<=n;i++)
      for(int j=maxWeight;j>=weights[i-1];j--)    
      		dp[j] = max(dp[j-weights[i-1]]+values[i-1],dp[j]);  
	
  	return dp[maxWeight];
}


int main() 
{  
    ll t;
    cin>>t;
    while(t--)
    {
        cin>>n>>maxWeight;
        wt= new ll[n];
        val= new ll[n];
        rep(n)
            cin>>val[i];
        rep(n)
            cin>>wt[i];
        //cout<<dKnap(0,maxWeight)<<endl;
        cout<<dKnapDynamic()<<endl;
    }

	return 0;
}
