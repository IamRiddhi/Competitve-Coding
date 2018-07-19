#include <iostream>
#include<bits/stdc++.h>
#include<climits>
using namespace std;
typedef long long ll;
#define rep(n) for(ll i=0;i<(n);i++)
#define test ll t; cin>>t; while(t--)
/* https://discuss.codechef.com/questions/60005/tadelive-editorial */
ll n,x,y;
ll *alan,*bob;
bool cmp(ll i, ll j)
{
    return (abs(alan[i]-bob[i]) > abs(alan[j]-bob[j]));
}
ll Greedy()
{
    ll total=0;
    ll* sortedIndices= new ll[n];
    rep(n)
        sortedIndices[i]=i;
    // now sort orders according to decreasing order of tip diff. 
    sort(sortedIndices,sortedIndices+n,cmp);
    
        
    rep(n)
    {
        ll index= sortedIndices[i];
        if(alan[index]>bob[index])
        {
             if(x>0) // no of orders remaining with alan more than 0
             {
                 total+=alan[index];
                 x--;
             }
             else
             {
                total+=bob[index];
                y--;
             }
        }
        else 
        {
            if(y>0) // no of orders remaining with bob more than 0
            {
                total+=bob[index];
                y--;
            }
            else
            {
                total+=alan[index];
                x--;
            }
        }
    }
    
    return total;
}
int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>x>>y;
    alan= new ll[n];
    bob= new ll[n];
    rep(n)
        cin>>alan[i];
    rep(n)
        cin>>bob[i];
    cout<<Greedy()<<endl;
	return 0;
}