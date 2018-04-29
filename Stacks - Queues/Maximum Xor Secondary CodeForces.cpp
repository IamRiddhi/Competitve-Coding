#include <iostream>
#include<bits/stdc++.h>
#include<climits>
#include<stack>
using namespace std;
typedef long long ll;
#define rep(n) for(ll i=0;i<(n);i++)
#define test ll t; cin>>t; while(t--)
int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n,*a;
    cin>>n;
    a= new ll[n];
    rep(n)
        cin>>a[i];
    ll maximum=LLONG_MIN;
    stack<ll> s;
    rep(n)
    {
        while(!s.empty())
        {
            maximum= max(maximum,a[i]^s.top());
            if(a[i]<s.top())
                break;
            else
                s.pop();
        }
        s.push(a[i]);
    }
    cout<<maximum<<endl;    
	return 0;
}