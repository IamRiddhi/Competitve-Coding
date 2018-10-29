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
        ll n,m,**mat;
        cin>>n>>m;
        mat= new ll*[n];
        ll maximum = LLONG_MIN;
        pair<ll,ll> src;
        rep0(n)
            mat[i] = new ll[m];
        for(ll i=0;i<n;i++)
            for(ll j=0;j<m;j++)
            {
                cin>>mat[i][j];
                if(maximum<mat[i][j])
                {
                    maximum = mat[i][j];
                    src.first = i;
                    src.second = j;
                }
            }
        bool **visited = new bool*[n];
        for(ll i=0;i<n;i++)
        {
            visited[i] = new bool[m];
            fill(visited[i],visited[i]+m,false);
        }
        queue<pair<ll,ll>> q;
        q.push(src);
        visited[src.first][src.second] = true;
        ll cnt = 1;
        ll pushed = 1;
        while(pushed<(n*m))
        {
            if(q.empty())
            {
                maximum = LLONG_MIN;
                ll mi,mj;
                for(ll i=0;i<n;i++)
                    for(ll j=0;j<m;j++)
                    {
                        if(!visited[i][j] && maximum<mat[i][j])
                        {
                            maximum = mat[i][j];
                            mi = i;
                            mj = j;
                        }
                    }
                q.push(make_pair(mi,mj));
                visited[mi][mj] = true;
                cnt ++;
                pushed++;
            }
            vector<pair<ll,ll>> v;
            while(!q.empty())
            {
                pair<ll,ll> p = q.front(); q.pop();
                v.push_back(p);
            }
            vector<pair<ll,ll>>::iterator it;
            bool fl = true;
            maximum = LLONG_MIN;
            ll si,sj;
            for(it=v.begin();it!=v.end();it++)
            {
                ll i = (*it).first;
                ll j = (*it).second;
                if(i+1<n && !visited[i+1][j])
                {
                    if(mat[i+1][j]<=mat[i][j])
                    {
                        visited[i+1][j] = true;
                        q.push(make_pair(i+1,j));
                        pushed++;
                    }
                    else
                    {
                        fl = false;
                        if(maximum<mat[i+1][j])
                        {
                            maximum = mat[i+1][j];
                            si = i+1;
                            sj = j;
                        }
                    }
                }
                if(i-1>=0 && !visited[i-1][j])
                {
                    if(mat[i-1][j]<=mat[i][j])
                    {
                        visited[i-1][j] = true;
                        q.push(make_pair(i-1,j));
                        pushed++;
                    }
                    else
                    {
                        fl = false;
                        if(maximum<mat[i-1][j])
                        {
                            maximum = mat[i-1][j];
                            si = i-1;
                            sj = j;
                        }
                    }
                }        
                if(j+1<m && !visited[i][j+1])
                {
                    if(mat[i][j+1]<=mat[i][j])
                    {
                        visited[i][j+1] = true;
                        q.push(make_pair(i,j+1));
                        pushed++;
                    }
                    else
                    {
                        fl = false;
                        if(maximum<mat[i][j+1])
                        {
                            maximum = mat[i][j+1];
                            si = i;
                            sj = j+1;
                        }
                    }
                }
                if(j-1>=0 && !visited[i][j-1])
                {
                    if(mat[i][j-1]<=mat[i][j])
                    {
                        visited[i][j-1] = true;
                        q.push(make_pair(i,j-1));
                        pushed++;
                    }
                    else
                    {
                        fl = false;
                        if(maximum<mat[i][j-1])
                        {
                            maximum = mat[i][j-1];
                            si = i;
                            sj = j-1;
                        }
                    }
                }
                if(pushed==0 and !fl)
                {
                    cnt++;
                    pushed++;
                    visited[si][sj] = true;
                    q.push(make_pair(si,sj));
                }
                
            } 
        }
        cout<<cnt<<endl;        
    }
    return 0;
}