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

    string inp,op;
    stack<char> s;
    cin>>inp;

    ll length= inp.length();
    char *minTillNow= new char[length+1];
    minTillNow[length]='z';
    for(ll i=length-1;i>=0;i--)
        minTillNow[i]= min(minTillNow[i+1],inp[i]);
    
    for(ll i=0;i<length;i++)
    {
        while(!s.empty() && s.top()<=minTillNow[i]) // if stack is not empty see whether there exists elements in the stack that were put on hold due to some element present in the string later than it but now has been processed.Hence its time to pop those that were put in hold because the elements that were responsible are now processed. so first pop them and then process the rest.
        {
            op+=s.top();
            s.pop();
        }
        if(inp[i]==minTillNow[i]) //it means either this element has contributed to minTillNow or some element which is present later in the input string has contributed. In the latter case the current element is put on hold by pushing into the stack in the else condition. We will come back to this element after the element contributing to minTillNow[currentelem or i] has been processed.
            op+=inp[i];
        else
            s.push(inp[i]);
    }
    while(!s.empty())  //pop the remaining elements into output after the whole string has been processed.
    {
        op+=(s.top());
        s.pop();
    }
    cout<<op<<endl;
    
	return 0;
} 