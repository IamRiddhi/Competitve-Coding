#include<bits/stdc++.h>
#include<cmath>
#include<climits>
#define test ll t; cin>>t; while(t--)
#define rep0(n) for(ll i=0;i<(n);i++)
#define rep1(n) for(ll i=1;i<=(n);i++)
using namespace std;
typedef long long ll;
ll mod = 1000000007;
ll fxp(ll base,ll exp,ll m)
{
    ll res = 1;
    while(exp>0)
    {
        if(exp%2==1)
            res = (res*base)%m;
        base = (base*base)%m;
        exp/=2;
    }
    return res;
}
int C[5001][5001];
void nCrModp()
{
    int i, j;
    for (i = 0; i <= 5000; i++)
        for (j = 0; j <= min(i, 5000); j++)
        {
            // Base Cases
            if (j == 0 || j == i)
                C[i][j] = 1;
 
            // Calculate value using previosly stored values
            else
                C[i][j] = (C[i-1][j-1] + C[i-1][j])%(mod-1);
        }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    nCrModp();
    test
    {
        ll n,k,*a;
        cin>>n>>k;
        a= new ll[n];
        rep0(n)
            cin>>a[i];
        sort(a,a+n);
        ll product = 1;
        for(ll i=0;i<n;i++)
        {
            // count the no of subsequences in which a[i] will be appearing.
            ll allSubsequences = C[n-1][k-1];
            // count the no of subsequences in which a[i] will start as minimum 
            ll minStart = C[n-i-1][k-1];
            // count the no of subsequences in which a[i] will start as maximum
            ll maxStart = C[i][k-1];
            
            /*no of subsequences in which a[i] will not be as minimum or maximum = 
            no of subsequences in which a[i] will be appearing - 
            no of subsequences in which a[i] will start as minimum-
            no of subsequences in which a[i] will start as maximum
            */
            /* finding out notMaxMin as mod of (mod-1) as (a^b)mod m = (a^(b mod (m-1)))mod m*/
            /* Note that we cant apply Fermat's Theorem over here as we used mod-1 here and mod-1 is not 
            prime.*/
            
            ll notMaxMin = (allSubsequences - minStart - maxStart)%(mod-1);
            if(notMaxMin<0)
                notMaxMin+=(mod-1);
            product = (product * fxp(a[i],notMaxMin,mod))%mod;
        }
        
        cout<<product<<endl;
    }
    return 0;
}