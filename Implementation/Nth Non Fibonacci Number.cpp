#include<bits/stdc++.h>
#include<cmath>
#include<climits>
#define test ll t; cin>>t; while(t--)
#define rep0(n) for(ll i=0;i<(n);i++)
#define rep1(n) for(ll i=1;i<=(n);i++)
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    test{
        int n;
        cin>>n;
        int a = 3;
        int b = 5;
        int c;
        int term = 1;
        int val = 4;
        while(term<n)
        {
            c = a+b;
            int incr = (c-b)-1; 
            if(term+incr<=n)
            {
                term+=incr;
                val = c -1;
            }
            else
            {
                val = b + n - term;
                break;
            }
            a = b;
            b = c;
        }
        cout<<val<<endl; }
    return 0;
}