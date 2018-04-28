#include<bits/stdc++.h>
#include<cmath>
#include<climits>
#define test ll t; cin>>t; while(t--)
#define rep0(n) for(ll i=0;i<(n);i++)
#define rep1(n) for(ll i=1;i<=(n);i++)
using namespace std;
typedef long long ll;
ll merge(ll *a,ll l1,ll r1,ll l2,ll r2)
{
    ll sum = 0;
    vector<ll> temp;
    ll i = l1;
    ll j = l2;
    while(i<=r1 && j<=r2)
    {
        if(a[i]<a[j])
        {
            temp.push_back(a[i]);
            sum = sum + (a[i]*(r2-j+1));
            i = i + 1;
        }
        else if (a[j]<a[i])
        {
            temp.push_back(a[j]);
            j = j + 1;
        }
        else
        {
            temp.push_back(a[j]);
            j = j + 1;
        }
    }
    while(i<=r1)
    {
        temp.push_back(a[i]);
        i = i + 1;
    }
    while(j<=r2)
    {
        temp.push_back(a[j]);
        j = j + 1;
    }
    
    i=l1;
    vector<ll>::iterator it;
    for(it=temp.begin();it!=temp.end();it++)
        a[i++] = *it;
    
    return sum;
}    
ll mergeSort(ll *a,ll l,ll r)
{
    if (l==r)
        return 0;
    ll mid = (l+r)/2; 
    return mergeSort(a,l,mid) + mergeSort(a,mid+1,r) + merge(a,l,mid,mid+1,r);
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    test
    {
        ll n,*a;
        cin>>n;
        a= new ll[n];
        rep0(n)
            cin>>a[i];
        cout<<mergeSort(a,0,n-1)<<endl;
        // for(ll i=0;i<n;i++)
        //     cout<<a[i]<<" ";
    }
    return 0;
}