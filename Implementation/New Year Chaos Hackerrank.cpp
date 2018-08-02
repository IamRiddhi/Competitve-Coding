#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
int main()
{ 
    ll t,n,*tgt,*src;
    cin>>t;
    while(t--)
    {
        cin>>n;
        tgt= new ll[n+1];
        src= new ll[n+1];
        for(int i=1;i<=n;i++){
            cin>>tgt[i]; src[i]=i;}
        ll moves=0,swap,temp,flag=1;
        for(int i=1;i<n;i++)
        {
            if(tgt[i]==src[i])
                continue;
            if(tgt[i]==src[i+1])
            {
                temp=src[i];
                src[i]=src[i+1];
                src[i+1]=temp; 
                moves+=1;
            }
            else if(tgt[i]==src[i+2])
            {
                temp=src[i+2];
                src[i+2]=src[i+1];
                src[i+1]=src[i];
                src[i]=temp;
                moves+=2;
            }
            else
            {
                flag=0; break;
            }
        }
        if(flag)
            cout<<moves<<endl;
        else
            cout<<"Too chaotic"<<endl;
    }
    return 0;
}
