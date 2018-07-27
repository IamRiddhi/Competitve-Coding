#include <iostream>
#include<bits/stdc++.h>
#include<stack>
using namespace std;
typedef long long ll;
#define rep(n) for(ll i=0;i<n;i++)
int main(void)
{
    ll n,*b;
    cin>>n;
    b= new ll[n];
    rep(n) 
        cin>>b[i];
    stack<ll> s;
    ll max=0,firstNestingDepth,maxSymbols=0,temp=0,start,tstart;
    rep(n)
    {
        if(b[i]==1)
        {
            s.push(i);
            if(temp==0)
                tstart=i;
            temp++;
            if(max<s.size())
            {
                max= s.size();
                firstNestingDepth=i+1;
            }
        }
        else
        {
            s.pop();
            temp++;
            if(s.size()==0)
            {
                if(maxSymbols<temp)
                {
                    maxSymbols=temp;
                    start=tstart+1;
                }
                temp=0;
            }
        }
    }
    cout<<max<<" "<<firstNestingDepth<<" "<<maxSymbols<<" "<<start;
	return 0;
}