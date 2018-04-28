/*
Overlapping subproblem:: Sum Left and no of indices left..It may happen that after checking some previous combinations,
we reach a point where sum left is already matched with indices left before and therefore we know that how many ways we can get that sum with 
the left indices.
*/
#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopb(i,a,b) for(int i=a;i>=b;i--)
#define loopm(i,a,b,step) for(int i=a;i<b;i+=step)
#define loopbm(i,a,b,step) for(int i=a;i>=b;i-=step)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define INF 1000000007
#define MOD 1000000007
#define BINF 1000000000000000001
#define int long long int
#define double long double
 
using namespace std;
 
#undef int
int main()
{
#define int long long int
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
//    t=1; //just for hacker
    while(t--){
    int N,M;
    cin>>M;
    cin>>N;
    int a[N+1];
    for(int i=1;i<=N;i++)
     cin>>a[i];
    int dp[M+1];
    memset(dp,0,sizeof(dp));
   dp[0]=1;
    for(int i=1;i<=N;i++)
    	for(int j=1;j<=M;j++)
    	    if(j>=a[i])
    		 dp[j]+=dp[j-a[i]];
    cout<<dp[M]<<endl;
    }
    return 0;
}
