#include<bits/stdc++.h>
#include<cmath>
#include<climits>
#define test ll t; cin>>t; while(t--)
#define rep0(n) for(ll i=0;i<(n);i++)
#define rep1(n) for(ll i=1;i<=(n);i++)
using namespace std;
typedef long long ll;
ll primes[10000];
void sieve()
{
    fill(primes,primes+10000,true);
    primes[0] = primes[1] = false;
    for(ll i=2;i<=sqrt(10000);i++)
        if(primes[i])
            for(ll j=i*i;j<10000;j+=i)
                primes[j] = false;
}
ll bfs(ll src,ll tgt)
{
    queue<ll> q;
    ll visited[10000];
    fill(visited,visited+10000,-1);
  
    visited[src] = 0;
    q.push(src);
    while(!q.empty())
    {
        ll no = q.front(); q.pop();
        string number = to_string(no);
        for(ll i=0;i<number.length();i++)
        {
            if(i!=0 && (number[i]-'0')!=0) //0 wont come as first digit but may come in other places if it does not already contain 0.
            {
                string temp = number;
                temp[i] = '0';
                ll tno = stol(temp);
                if(primes[tno] && visited[tno]==-1)
                {
                    visited[tno] = visited[no] + 1;
                    if(tno==tgt)
                        return visited[tno];
                    q.push(tno);
                }
            }
            for(ll digit=1;digit<=9;digit++)
            {
                if((number[i]-'0')!=digit)
                {
                    string temp = number;
                    temp[i] = digit + '0';
                    ll tno = stol(temp);
                    if(primes[tno] && visited[tno]==-1)
                    {
                        visited[tno] = visited[no] + 1;
                        if(tno==tgt)
                            return visited[tno];
                        q.push(tno);
                    }
                }
            }
        }
    }
            
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    sieve();
    test
    {
        ll src,tgt;
        cin>>src>>tgt;
        if(src==tgt)
            cout<<"0"<<endl;
        else
        {
            ll ans = bfs(src,tgt);
            if(ans==-1)
                cout<<"Impossible"<<endl;
            else
                cout<<ans<<endl;
        }
    }
    return 0;
}