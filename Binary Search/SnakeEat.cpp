#include <iostream>
#include<bits/stdc++.h>
#include<climits>
using namespace std;
typedef long long ll;
#define rep(n) for(ll i=0;i<(n);i++)
#define test ll t; cin>>t; while(t--)
ll binarySearch(ll* postfixSum,ll begin,ll end,ll k)
{
    ll req,mid;
    ll indexToStartEating= end;
    while(begin<end)
    {
        mid= (begin+end)/2;
        req= k*(indexToStartEating-mid+1) -(postfixSum[mid]-postfixSum[indexToStartEating+1]); //how many snakes to eat in total for pos....end snakes(jota khete hobe to acheive length k)
        // mid denotes no of snakes left that can be eaten
        if(mid<req)  // ja ache ta requirement er theke choto   
            begin= mid+1; //requirement komabo
        else 
            end= mid;
    }
    if(end==indexToStartEating) //end unmoved
    {
        req= k - (postfixSum[end]-postfixSum[indexToStartEating+1]); //checking explicitly karon end ta je thikache tar ki gurantee bhai?
        if(req>end)
            begin++;
    }
    return begin;
}
int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    test
    {
        ll n,q,*snakes,k;
        cin>>n>>q;
        snakes= new ll[n];
        rep(n)
            cin>>snakes[i];
        sort(snakes,snakes+n);
        ll *postfixSum= new ll[n+1];
        postfixSum[n]=0;
        postfixSum[n-1]= snakes[n-1];
        for(ll i=n-2 ;i>=0;i--)
            postfixSum[i]= postfixSum[i+1]+snakes[i];
        while(q--)
        {
            cin>>k;
            ll pos;
            ll indexToStartEating= (lower_bound(snakes,snakes+n,k)- snakes)-1;
            if(indexToStartEating==-1)
                pos=0;
            else
                pos= binarySearch(postfixSum,0,indexToStartEating,k);
            cout<<(n-pos)<<endl;
        }
    }
	return 0;
} 
 