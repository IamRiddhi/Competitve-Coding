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
    ll n,k,p,a,b;
    ll *inp,*sorted,*forwardIterator,*backwardIterator;
    cin>>n>>k>>p;
    inp= new ll[n]; 
    sorted= new ll[n]; 
    forwardIterator= new ll[n]; 
    backwardIterator= new ll[n];
    rep(n)
    {
        cin>>inp[i];
        sorted[i]=inp[i];
    }
    
    sort(sorted,sorted+n);
    
    /*sorted[i] theke max samne koto jete pri*/
    forwardIterator[n-1]= sorted[n-1];
    for(ll i=n-2;i>=0;i--)
    {
        forwardIterator[i]= sorted[i];
        if(sorted[i+1]-sorted[i]<=k)
            forwardIterator[i]= forwardIterator[i+1];
    }
    
    /* sorted[i] theke max pechone koto jete pri*/
    backwardIterator[0]= sorted[0];
    for(ll i=1;i<n;i++)
    {
        backwardIterator[i]= sorted[i];
        if(sorted[i]-sorted[i-1]<=k)
            backwardIterator[i]= backwardIterator[i-1];
    }
    
    
    while(p--)
    {
        ll a,b;
        cin>>a>>b;
        ll elem1= inp[a-1];
        ll elem2= inp[b-1];
        a= lower_bound(sorted,sorted+n,elem1) - sorted;
        b= lower_bound(sorted,sorted+n,elem2) - sorted;
        if(a==b)
            cout<<"Yes"<<endl;
        else if(a<b) //go forward
        {
            if(elem2<=forwardIterator[a])
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
        else if(a>b) //go backward
        {
            if(elem2>=backwardIterator[a])
                cout<<"Yes"<<endl;  
            else
                cout<<"No"<<endl;
        }
    }
	return 0;
} 