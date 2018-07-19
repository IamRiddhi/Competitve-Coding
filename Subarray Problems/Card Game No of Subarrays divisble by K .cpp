#include<bits/stdc++.h>
#include<cmath>
#include<climits>
#define test ll t; cin>>t; while(t--)
#define rep0(n) for(ll i=0;i<(n);i++)
#define rep1(n) for(ll i=1;i<=(n);i++)
#define PII pair<ll,ll>
#define f first
#define s second
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n,k,x;
    cin>>n>>k;
    x = k; 
    ll *a;
    a = new ll[n];
    rep0(n)
        cin>>a[i];
    
    /* -------  Finding out prime factors of K ------------*/
    vector<PII> pfK;
    vector<PII>::iterator it;
    
    for(ll i=2;i*i<=x;i++)
    {
        if(x%i==0)
        {
            ll cnt = 0;
            while(x%i==0)
            {
                cnt++;
                x/=i;
            }
            pfK.push_back(make_pair(i,cnt));
        }
    }   
    
    if(x!=1)
        pfK.push_back(make_pair(x,1));
    
    /* ---------Prime Factors of K found out and stored in pfK vector -------------*/
    
    /* ------ Now working on array -------*/
    
    vector<PII> pfKC = pfK; // this will be the prime factor of K with powers intialised to 0.
    for(it=pfKC.begin();it!=pfKC.end();it++) //initialising to 0.
        it->s = 0;
    
    ll count = 0;
    
    /* ----- j is back pointer and i is front pointer. Whenever we find that j...i is divisible by k then we can say
    that (n-i) parts are also divisible by k.-------*/
    
    ll j = 0;
    for(ll i=0;i<n;i++)
    {
        /* -- adding common prime factors of a[i] and K to pfKC vector---*/
        for(ll z=0;z<pfKC.size();z++)
        {
            if(a[i] % pfKC[z].f==0)
            {
                x = a[i];
                ll cnt = 0;
                while(x%pfKC[z].f==0)
                {
                    cnt++;
                    x/=(pfKC[z].f);
                }
                (pfKC[z].s)+=cnt;
            }
        }
        
        while(j<=i)
        {
            ll z;
            for(z=0;z<pfK.size();z++) //checking whether j...i is divisible by k
                if(pfKC[z].s<pfK[z].s) //if power of any of prime factors of j...i less than power of any particular prime factor of k, then j....i is not divisible by k.
                    break;
                        
            if(z!=pfK.size()) break; // if not divisible by k, break and increase i.
            
            /* ---- j.....i  is divisible by k -----*/
            
            count+=(n-i); //add the contribution for this subarray.
            
            /* -----remove j's contribution by removing factors of a[j] from pfKC.----*/
            for(z=0;z<pfK.size();z++)
            {
                if(a[j] % pfKC[z].f==0)
                {
                    x = a[j];
                    ll cnt = 0;
                    while(x%pfKC[z].f==0)
                    {
                        cnt++;
                        x/=(pfKC[z].f);
                    }
                    (pfKC[z].s)-=cnt;
                }
            }
            j++;
        }
    }
    
    cout<<count<<endl;
    return 0;
}