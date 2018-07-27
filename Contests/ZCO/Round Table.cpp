
#include <iostream>
#include<limits.h>
#include<algorithm>
using namespace std;
 
typedef long long ll;
ll n,*a,*b;
ll func()
{
    if(n==2)
        return min(a[0],a[1]);
    else if(n==1)
        return a[0];
        
    b= a+1;
    ll *dpIfStartFrom1, *dpIfStartFrom2;
    dpIfStartFrom1= new ll[n];
    dpIfStartFrom2= new ll[n-1];
    
    ll sizeOfDpArrayStartingFrom2= n-1;
    
    dpIfStartFrom1[n-1]= a[n-1];
    dpIfStartFrom1[n-2]= a[n-2];
    
    dpIfStartFrom2[sizeOfDpArrayStartingFrom2 - 1]= a[n-1];
    dpIfStartFrom2[sizeOfDpArrayStartingFrom2 -2]= a[n-1]+a[n-2];  
    
    for(ll i=n-3;i>=0;i--)
    { 
        dpIfStartFrom1[i]=  a[i] + min(dpIfStartFrom1[i+ 1],dpIfStartFrom1[i+2]);     
        if(i!=0)
            dpIfStartFrom2[i-1]= b[i-1] + min(dpIfStartFrom2[i],dpIfStartFrom2[i+1]); 
    }
     return min(dpIfStartFrom1[0],dpIfStartFrom2[0]);
}
int main()
{
    
    cin>>n;
    a= new ll[n];
    for(ll i=0;i<n;i++)
        cin>>a[i];
    cout<<func()<<endl;
	return 0;
} 
