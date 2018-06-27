#include<bits/stdc++.h>
#include<cmath>
#include<climits>
#define test ll t; cin>>t; while(t--)
#define rep0(n) for(ll i=0;i<(n);i++)
#define rep1(n) for(ll i=1;i<=(n);i++)
using namespace std;
typedef long long ll;
ll n,m,*ecap,*wt,*no,*sortedIndex;

bool cmp(ll index1,ll index2)
{
    return wt[index1]<wt[index2];
}

bool OK(ll res)
{
    ll indexCake = 0;
    ll indexPerson = 0;
    ll khabe = res;
    ll left = no[sortedIndex[indexCake]];
    
    while(indexCake<n)
    {
        if(wt[sortedIndex[indexCake]]<=ecap[indexPerson])
        {
            if(left<khabe)
            {
                khabe -= left;
                indexCake++;
                if(indexCake==n)
                    return true;
                left = no[sortedIndex[indexCake]];
            }
            else
            {
                left -= khabe;
                indexPerson++;
                if(indexPerson==m && left==0) return true;
                if(indexPerson==m) return false;
                khabe = res;
            }   
        }   
        else
        {
            indexPerson++;
            if(indexPerson==m)
                return false;
            khabe = res;
        }
    }
}

ll bsearch(ll lo, ll hi)
{
    while(lo<hi)
    { 
        ll mid = (lo+hi)/2;
        if(OK(mid))
            hi = mid;
        else
            lo = mid + 1;
    } 
    if(OK(hi))
        return hi;
    else
        return -1;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    test
    {
        cin>>n>>m;
        ecap = new ll[m];
        wt = new ll[n];
        no = new ll[n];
        ll sum = 0;
        sortedIndex = new ll[n];
        rep0(m)
            cin>>ecap[i];
        rep0(n)
            cin>>wt[i];
        rep0(n)
        {
            cin>>no[i];
            sum+=no[i];
            sortedIndex[i] = i;
        } 
        
        /* sort eating capacity according to ascending order */
        sort(ecap,ecap+m);
        
        /* sort according to ascending order of weight of cakes of weight array and corresponding no of cakes array */
        sort(sortedIndex,sortedIndex+n,cmp); 
        
        ll minTime = bsearch(1,sum);
        cout<<minTime<<endl;
    }
    return 0;
}
