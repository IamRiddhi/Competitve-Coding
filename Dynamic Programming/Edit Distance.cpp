#include <iostream>
#include<bits/stdc++.h>
#include<climits>
using namespace std;
typedef long long ll;
#define rep(n) for(ll i=0;i<(n);i++)
#define test ll t; cin>>t; while(t--)
ll n,m;
string src,tgt;
// n- src string , m- tgt string 
/*
*Subproblems*
The idea is process all characters one by one staring from either from left or right sides of both strings.
Let we traverse from right corner, there are two possibilities for every pair of character being traversed.
m: Length of str1 (first string)
n: Length of str2 (second string)
1.	If last characters of two strings are same, nothing much to do. Ignore last characters and get count for remaining strings. So we recur for lengths m-1 and n-1.
2.	Else (If last characters are not same), we consider all operations on ‘str1’, consider all three operations on last character of first string, recursively compute minimum cost for all three operations and take minimum of three values.
a.	Insert: Recur for m and n-1
b.	Remove: Recur for m-1 and n
c.	Replace: Recur for m-1 and n-1
*Edge Case*
// If first string is empty, the only option is to
    // insert all characters of second string into first
    if (m == 0) return n;
 
    // If second string is empty, the only option is to
    // remove all characters of first string
    if (n == 0) return m;

*/
ll editDistance()
{
    ll **dp; 
    dp = new ll*[n+1];
    rep(n+1)
        dp[i]= new ll[m+1];
        
    for(ll i=0;i<=n;i++)
        dp[i][0]= i;
    for(ll j=0;j<=m;j++)
        dp[0][j]= j;
        
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=m;j++)
        {
            if(src[i-1]==tgt[j-1])
                dp[i][j]= dp[i-1][j-1];
            else
            {
                ll replace= dp[i-1][j-1];
                ll insert= dp[i][j-1];
                ll remve= dp[i-1][j];
                dp[i][j]= 1 +  min(replace,min(insert,remve));
            }
        }
    }
    return dp[n][m];    
}
int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    test
    {
        cin>>n>>m;
        cin>>src>>tgt;
        cout<<editDistance()<<endl;
    }
	return 0;
}