#include<bits/stdc++.h>
#include<cmath>
#include <cstdlib>
#include<iostream>
#include<string>
#include<climits>
#define test ll t; cin>>t; while(t--)
#define rep0(n) for(ll i=0;i<(n);i++)
#define rep1(n) for(ll i=1;i<=(n);i++)
using namespace std;
typedef long long ll;
std::vector<std::string> split(const std::string& s, char delimiter)
{
   std::vector<std::string> tokens;
   std::string token;
   std::istringstream tokenStream(s);
   while (std::getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token);
   }
   return tokens;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string input; 
    cin>>input;
    
    /* space seperated inputs for m,n */
    ll m,n;
    vector<string> vs = split(input,',');
    m = atol(vs[0].c_str());
    n = atol(vs[1].c_str());
    
    /* taking input for 2d array*/
    ll **chute = new ll*[n];
    rep0(n)
        chute[i] = new ll[m];
        
    for(ll i=0;i<m;i++)
    {
        cin>>input; vs = split(input,',');
        for(ll j=0;j<n;j++)
            chute[j][i] = atol(vs[j].c_str());
    }
    
    /*main program*/
    ll *pointers = new ll[m];
    for(ll j=0;j<m;j++) pointers[j] = n-1;
    ll *values = new ll[m];
    for(ll j=0;j<m;j++) values[j] = chute[pointers[j]][j];
    
    ll totElems = m*n;
    while(totElems--)
    {
        /* find maximum from values and append it to output string */
        ll maximum = -1;
        ll maxIndex = -1;
        for(ll j=0;j<m;j++)
        {
         
            if(maximum<values[j]) { maximum = values[j]; maxIndex = j; }
        }
        cout<<maximum;
        //decreasing pointer and updating values
        if(pointers[maxIndex]==0) values[maxIndex] = INT_MIN;
        else { pointers[maxIndex]--; values[maxIndex] = chute[pointers[maxIndex]][maxIndex]; }
    }
            
    cout<<endl;                    
    return 0;
}
