#include <iostream>
#include<bits/stdc++.h>
#include<ctype.h>
#include<climits>
using namespace std;
typedef long long ll;
#define rep(n) for(ll i=0;i<(n);i++)
#define test ll t; cin>>t; while(t--)
string src,tgt;
ll srclen,tgtlen;
bool abbreviation()
{
    bool **dp;
    dp= new bool*[srclen+1];
    for(ll i=0;i<=srclen;i++)
        dp[i]= new bool[tgtlen+1];
    
    dp[0][0]= true; 
    
    // target string is of 0 length
    for(ll i=1;i<=srclen;i++)
    {
        if(src[i-1]<97) //if its in capitals it cant be deleted.
            dp[i][0]= false;
        else // it depends on previous state
            dp[i][0]= dp[i-1][0];
    }
    
    //source string is of 0 length
    for(ll j=1;j<=tgtlen;j++)
        dp[0][j]= false;
        
    for(ll i=1;i<=srclen;i++)    
    {
        for(ll j=1;j<=tgtlen;j++)
        {
            if(src[i-1]==tgt[j-1] || src[i-1]-32 == tgt[j-1]) //either both letters are equal or a letter can be casted to upper case to make it equal
            {    
                dp[i][j]= dp[i-1][j-1] & true;
                if(!dp[i][j]) // now ignore this and delete if lowercase
                {
                    if(src[i-1]>=97) //lowercase but not equal , cant be casted hence can be deleted.
                        dp[i][j]= dp[i-1][j];
                    else
                        dp[i][j]=false; //uppercase cant be deleted
                }
            }
            else if(src[i-1]>=97) //lowercase but not equal , cant be casted hence can be deleted.
                dp[i][j]= dp[i-1][j];
            else
                dp[i][j]=false; //uppercase cant be deleted
        }
    }
    
//      for(ll i=0;i<=srclen;i++)    
//     {
//         for(ll j=0;j<=tgtlen;j++)
//             cout<<dp[i][j]<<" ";
//         cout<<endl;
//      }
    
    return dp[srclen][tgtlen];
    
}
int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    test
    {
        cin>>src; 
        cin>>tgt;
        srclen= src.length();
        tgtlen= tgt.length();
        if(abbreviation())
            cout<<"YES"<<endl;
        else 
            cout<<"NO"<<endl;
    }
	return 0;
}