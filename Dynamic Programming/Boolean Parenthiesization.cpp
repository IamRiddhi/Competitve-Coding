#include<bits/stdc++.h>
#include<cmath>
#include<climits>
#define test ll t; cin>>t; while(t--)
#define rep0(n) for(ll i=0;i<(n);i++)
#define rep1(n) for(ll i=1;i<=(n);i++)
using namespace std;
typedef long long ll;
ll mod = 1003;
ll booleanParenthesis(string operators,string symbols)
{
    ll n = symbols.length();
    ll T[n][n],F[n][n]; // T[i][j] represents no of ways to parenthesize the symbols between i and j such that the expression between i and j represents to be true.
    for(ll i=0;i<n;i++)
    {
        T[i][i] = (symbols[i]=='T') ? 1 : 0;
        F[i][i] = (symbols[i]=='F') ? 1 : 0;
    }
    for(ll j=1;j<n;j++)
        for(ll i=0;i<(n-j);i++)
        {
            T[i][i+j] = F[i][i+j] = 0;
            for(ll k=i;k<(i+j);k++)
            {
                ll total = (((T[i][k]+F[i][k])%mod)*((T[k+1][i+j]+F[k+1][i+j])%mod))%mod;
                if(operators[k]=='&')
                {
                    T[i][i+j] = (T[i][i+j]+(T[i][k]*T[k+1][i+j])%mod)%mod;  
                    F[i][i+j] = (F[i][i+j]+((total-(T[i][k]*T[k+1][i+j])%mod)+mod)%mod)%mod;
                }
                else if(operators[k]=='|')
                {
                    T[i][i+j] = (T[i][i+j]+((total-(F[i][k]*F[k+1][i+j])%mod)+mod)%mod)%mod;  
                    F[i][i+j] = (F[i][i+j]+(F[i][k]*F[k+1][i+j])%mod)%mod;  
                }
                else if(operators[k]=='^')
                {
                    T[i][i+j] = (T[i][i+j]+(((T[i][k]*F[k+1][i+j])%mod)+(F[i][k]*T[k+1][i+j])%mod)%mod)%mod;  
                    F[i][i+j] = (F[i][i+j]+(((T[i][k]*T[k+1][i+j])%mod)+(F[i][k]*F[k+1][i+j])%mod)%mod)%mod;
                }
            }
        }
    return T[0][n-1];
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    test
    {
        ll n;
        cin>>n;
        string s;
        cin>>s;
        string symbols,operators;
        ll len = s.length();
        for(ll i=0;i<len;i++)
            if(s[i]=='&' || s[i]=='|' || s[i]=='^')
                operators += s[i];
            else
                symbols += s[i];
        cout<<booleanParenthesis(operators,symbols)<<endl;
    }
    return 0;
}