#include <iostream>
#include<bits/stdc++.h>
#include<climits>
using namespace std;
typedef long long ll;
#define rep(n) for(ll i=0;i<(n);i++)
#define test ll t; cin>>t; while(t--)
ll n,l,*PL;
ll **m; 
ll factors[100];
ll noOfFactors;
 
ll dp(ll indexi, ll indexj)
{
    if(m[indexi][indexj]!=LLONG_MIN)
        return m[indexi][indexj];
    
            ll factor= factors[indexj];
            
            for(ll i=0;i<=indexj;i++)
            {
                if(factor%factors[i]==0)
                {
                    ll lside= indexi+factors[i];
                    if(lside<n)
                        m[indexi][indexj]=max(m[indexi][indexj],dp(lside,i)+PL[indexi]);
                    else
                        break;
                }
            }
    return m[indexi][indexj];    
}
int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
    cin>>n>>l;
    PL= new ll[n];
    rep(n)
        cin>>PL[i];
        
    noOfFactors=0;
    factors[noOfFactors++]=1;
    for(ll i=2;i<=l/2;i++)
        if(l%i==0)
            factors[noOfFactors++]=i;
    factors[noOfFactors++]=l;
    
    m= new ll*[n];
    rep(n)
        m[i]=new ll[noOfFactors];
        
    for(ll i=0;i<n;i++)
        for(ll j=0;j<noOfFactors;j++)
            m[i][j]=LLONG_MIN;
    
    for(ll i=0;i<noOfFactors;i++)
        m[n-1][i]= PL[n-1];    
        
    cout<<dp(0,noOfFactors-1)<<endl;
    return 0;
}  