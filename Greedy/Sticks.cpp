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
       ll n,*a;
       cin>>n;
       a= new ll[n];
       ll freq[1001]={0};
       rep(n)
       {
            cin>>a[i];
            freq[a[i]]++;
       }
       int side1got= -1;
       int side2got= -1;
       for(ll i=1000;i>=1;i--)
       {
           if(side1got==-1)
           {
               if(freq[i]>=4) //square
               {
                   side1got=side2got=i;
                   break;
               }
                else if(freq[i]>=2)
                    side1got=i;
           }
           else
           {
               if(freq[i]>=2)
               {
                    side2got=i;
                    break;
               }
           }
       }
       if(side1got>0 && side2got>0)
            cout<<side1got*side2got<<endl;
        else
            cout<<"-1"<<endl;
    }
	return 0;
}