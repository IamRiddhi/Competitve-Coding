#include <iostream>
#include<bits/stdc++.h>
#include<climits>
using namespace std;
typedef long long ll;
#define rep(n) for(ll i=0;i<(n);i++)
#define test ll t; cin>>t; while(t--)
ll la,lb;
string s1,s2;
ll LCS()
{
    ll **lenDP;
    lenDP= new ll*[la+1];

    for(ll i=0;i<=la;i++)
        lenDP[i]= new ll[lb+1];
    
    lenDP[0][0]=0;
    
    for(ll i=1;i<=lb;i++)
        lenDP[0][i]=0;
    for(ll i=1;i<=la;i++)
        lenDP[i][0]=0;
    
    for(ll i=1;i<=la;i++)
    {
        for(ll j=1;j<=lb;j++)
        {
            if(s1[i-1]==s2[j-1])
                lenDP[i][j]= 1 + lenDP[i-1][j-1];
            else
                lenDP[i][j]= max(lenDP[i-1][j],lenDP[i][j-1]);
        }
    }
    
    ll lcs= lenDP[la][lb];
    
    for(ll i = 0 ; i <la; i++ )
            delete[] lenDP[i]; 
        delete[] lenDP;
        
    return lcs;
        
}
int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    test
    {
        cin>>la>>lb;
        cin>>s1>>s2;
        
        cout<<LCS()<<endl;       
        
    }
	return 0;
} 
