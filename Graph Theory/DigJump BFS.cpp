#include<bits/stdc++.h>
#include<cmath>
#include<climits>
#define test ll t; cin>>t; while(t--)
#define rep0(n) for(ll i=0;i<(n);i++)
#define rep1(n) for(ll i=1;i<=(n);i++)
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s;
    cin>>s;
    ll n = s.length();
    unordered_map<char,vector<ll>> mp;
    for(ll i=0;i<n;i++)
        mp[s[i]].push_back(i);
    queue<ll> q;
    ll *visited = new ll[n];
    fill(visited,visited+n,-1);
    q.push(0);
    visited[0] = 0;
    if(n==1)
    {
        cout<<"0"<<endl;
        return 0;
    }
    remove(mp[s[0]].begin(),mp[s[0]].end(),0);
    while(!q.empty())
    {
        ll ind = q.front(); q.pop();
        if(s[ind]==s[n-1])
        {
            cout<<visited[ind]+1<<endl;
            break;
        }
        if(ind-1>=0 && visited[ind-1]==-1)
        {
            visited[ind-1] = visited[ind] + 1;
            q.push(ind-1);
            remove(mp[s[ind-1]].begin(),mp[s[ind-1]].end(),ind-1);
        }
        if(ind+1<n && visited[ind+1]==-1)
        {
            visited[ind+1] = visited[ind] + 1;
            if(ind+1==n-1)
            {
                cout<<visited[ind+1]<<endl;
                break;
            }
            remove(mp[s[ind+1]].begin(),mp[s[ind+1]].end(),ind+1);
            q.push(ind+1);
        }
        vector<ll> indices = mp[s[ind]];
        for(ll j=0;j<indices.size();j++)
            if(visited[indices[j]]==-1)
            {
                visited[indices[j]] = visited[ind] + 1;
                q.push(indices[j]);
                if(indices[j]==n-1)
                {
                    cout<<visited[indices[j]]<<endl;
                    break;
                }
            }
        mp[s[ind]].clear();
    }
    return 0;
}