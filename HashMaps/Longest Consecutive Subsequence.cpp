#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() 
{
    ll t; cin>>t;
    while(t--)
    {
        ll n,*a;
        cin>>n;
        a= new ll[n];
        unordered_set<ll> s;
        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
            s.insert(a[i]);
        }
        ll maximum=1;
        for(ll i=0;i<n;i++)
        {
            if(s.find(a[i]-1)==s.end()) //a[i] is the starting element of a consecutive sequence
            {
                ll cur= a[i]+1;
                while(s.find(cur)!=s.end())
                    cur++;
                maximum= max(maximum,cur-a[i]);
            }
        }
        cout<<maximum<<endl;
    }
	return 0;
}
