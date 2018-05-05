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
    test
    {
        string s;
        cin>>s;
        ll len = s.length();
        ll r = 0;
        ll i,k;
        for(i=0;i<len;i++) //first occurence of k
            if(s[i]=='K')
                break;
      	if(i==len) //if no k at all, then len-1 will be answer because atleast 1 R will be replaced.
        {
          cout<<len-1<<endl;
          continue;
        }
        ll maximum = 0;
        ll cur_max = 0;
      	ll R = 0; //total number of Rs
      	for(ll j=0;j<len;j++)
          if(s[j]=='R')
            R++;
        for(ll j = i;j<len;j++)
        {
            if(cur_max==0 && s[j]=='R')
                continue;
            if(s[j]=='K')
                cur_max++;
            else if(s[j]=='R')
                r++;
            if(r>=cur_max) //if no of R's in the current subarray gets greater discard the subarray.
            {
                r = 0;
                cur_max = 0;
            }
          	maximum = max(maximum,cur_max+R-r); //check whether this subarray with k's that would be converte to r + no of remaining r's(R-r 
			  //where r =no of r s in the current subarray) is greater than maximum. 
        }
        cout<<maximum<<endl;
    }
}
