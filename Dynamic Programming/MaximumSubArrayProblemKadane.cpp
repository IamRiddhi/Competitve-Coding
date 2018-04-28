#include <iostream>
#include <bits/stdc++.h>
#define rep(n) for(ll i=0;i<(n);i++)
using namespace std;
typedef long long ll;
/* MY DP METHOD
int main() 
{
    ll t,n,*a;
    cin>>t;
    while(t--)
    {
        cin>>n;
        a= new ll [n];
        rep(n)
            cin>>a[i];
        ll maximum=a[n-1];
        for(ll i=n-2;i>=0;i--)
        {
            a[i]= max(a[i],a[i]+a[i+1]);
            if(maximum<a[i])
                maximum= a[i];
        }
        cout<<maximum<<endl;
        
           
    }
	return 0;
}*/

/*KADANE METHOD*/

#include <iostream>
#include <bits/stdc++.h>
#include<climits>
#define rep(n) for(ll i=0;i<(n);i++)
using namespace std;
typedef long long ll;
int main() 
{
    ll t,n,*a;
    cin>>t;
    while(t--)
    {
        cin>>n;
        a= new ll [n];
        bool isNegative= true;
        ll maximum= LLONG_MIN;
        ll startIndex, endIndex, cur_start, cur_end,cur_max=0;
        rep(n)
        {
            cin>>a[i];
            if(a[i]>0)
                isNegative= false; // atleast one element in the array is positive
            if(maximum<a[i])
            {
                maximum= a[i];
                startIndex=endIndex=i;
            }
        }
        if(!isNegative)
        {
            cur_start=0;
            rep(n)
            {
                cur_max= cur_max + a[i];
                if(cur_max<0)
                {
                    cur_max=0; cur_start=i+1;
                }
                else
                {
                    if(maximum<cur_max)
                    {
                        maximum= cur_max; 
                        endIndex=i; startIndex= cur_start;
                    }
                }
            }
        }
        cout<<maximum<<" from "<<startIndex<<" to "<<endIndex<<endl;
            
    }
	return 0;
}




