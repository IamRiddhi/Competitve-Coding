#include<bits/stdc++.h>
#include<cmath>
#include<climits>
#define test ll t; cin>>t; while(t--)
#define rep0(n) for(ll i=0;i<(n);i++)
#define rep1(n) for(ll i=1;i<=(n);i++)
using namespace std;
typedef long long ll;
ll mod = 1000000007;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    test
    {
        ll r,c;
        cin>>r>>c;
        char **map = new char*[r];
        ll **dist = new ll*[r];
        for(ll i=0;i<r;i++)
        {
            map[i] = new char[c];
            dist[i] = new ll[c];
            fill(dist[i],dist[i]+c,LLONG_MAX);
        }
        for(ll i=0;i<r;i++)
            for(ll j=0;j<c;j++)
                cin>>map[i][j];
        deque<pair<ll,ll>> q;
        q.push_front(make_pair(0,0));
        dist[0][0] = 0;
        while(!q.empty())
        {
            pair<ll,ll> x =  q.front(); q.pop_front();
            ll i = x.first;
            ll j = x.second;
            if(i>0)
            {
                ll g = 1;
                if(map[i-1][j]==map[i][j])
                    g--;
                if(dist[i][j]+g<dist[i-1][j])
                {
                    dist[i-1][j] = dist[i][j] + g;
                    if(g==0)
                        q.push_front(make_pair(i-1,j));
                    else
                        q.push_back(make_pair(i-1,j));
                }
            }
            if(i<=r-2)
            {
                ll g = 1;
                if(map[i+1][j]==map[i][j])
                    g--;
                if(dist[i][j]+g<dist[i+1][j])
                {
                    dist[i+1][j] = dist[i][j] + g;
                    if(g==0)
                        q.push_front(make_pair(i+1,j));
                    else
                        q.push_back(make_pair(i+1,j));    
                }
            }
            if(j>0)
            {
                ll g = 1;
                if(map[i][j-1]==map[i][j])
                    g--;
                if(dist[i][j]+g<dist[i][j-1])
                {
                    dist[i][j-1] = dist[i][j] + g;
                    if(g==0)
                        q.push_front(make_pair(i,j-1));
                    else
                        q.push_back(make_pair(i,j-1));
                }
            }
            if(j<=c-2)
            {
                ll g = 1;
                if(map[i][j+1]==map[i][j])
                    g--;
                if(dist[i][j]+g<dist[i][j+1])
                {
                    dist[i][j+1] = dist[i][j] + g;
                    if(g==0)
                        q.push_front(make_pair(i,j+1));
                    else
                        q.push_back(make_pair(i,j+1));
                }
            }
        }
        cout<<dist[r-1][c-1]<<endl;
    }
    return 0;
}
