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
    string s; 
    stack<ll> st;
    cin>>s;
    ll len,max=0,count=1;
    ll stringLength= s.length();
    st.push(-1);
    rep(stringLength)
    {
        if(s[i]=='(')
            st.push(i);
        else
        {
            st.pop();
            if(!st.empty())
            {
                    len= i - st.top();
                    if(max<len)
                    {
                        max=len;
                        count=1;
                    }
                    else if(max==len)
                        count++;
            }
            else
                st.push(i);
        }
    }
     
    cout<<max<<" "<<count<<endl;
    
	return 0;
}