#include <iostream>
#include<bits/stdc++.h>
#include<climits>
using namespace std;
typedef long long ll;
#define rep(n) for(ll i=0;i<(n);i++)
#define test ll t; cin>>t; while(t--)
int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    test
    {
        ll i,popped,n,*a;
        ll maximum=0,area;
        cin>>n;
        a= new ll[n];
        rep(n)
            cin>>a[i];
        
        stack<ll> s;
        s.push(0); //pushing first index into the stack.
        
        for(i=1;i<n;i++)
        {
            if(a[i]>=a[s.top()])
                s.push(i);
            else
            {
                while(!s.empty() && a[i]<a[s.top()])
                {
                    popped= s.top(); //popped is the bar whose area is to be calculated considering it to be the minimum bar.
                    s.pop();
                    if(!s.empty())
                        area= a[popped] * (i-s.top()-1);
                    else
                        area= a[popped] * i;
                    if(maximum<area)
                        maximum=area;
                }
                s.push(i);
            }
        }
        while(!s.empty())
        {
            popped= s.top();
            s.pop();
            if(!s.empty())
                area= a[popped] * (i-s.top()-1);
            else
                area= a[popped] * (i);
            if(maximum<area)
                maximum=area;
        }
        cout<<maximum<<endl;
    }
	return 0;
}