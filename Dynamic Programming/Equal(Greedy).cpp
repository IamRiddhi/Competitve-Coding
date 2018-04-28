#include <iostream>
#include<bits/stdc++.h>
#include<climits>
#include<queue>
using namespace std;
typedef long long ll;
#define rep(n) for(ll i=0;i<(n);i++)
#define test ll t; cin>>t; while(t--)
// If Christy chooses one co-worker and gives everyone else candy,
// this is equivalent to reducing the amount of candy for just that
// one co-worker and leaving everyone else's chocolates untouched.

// Using this fact, we can calculate in O(1) time how many 
// operations it takes to remove n chocolates - see numOps()

// The optimal solution is usually to reduce everyone's # of chocolates
// down to the minimum # in the group, however it may also be the case that
// {min-1, min-2} are more optimal since we have the option of
// taking away up to 5 chocolates at a time.

// Using all this information, we can use a greedy approach where
// we iterate over every co-worker and reduce their chocolates down
// to the minimum.

ll minMovesToMinimum(ll no) 
{
    ll moves=0;
    moves+= no/5;
    no%=5;
    moves+=no/2;
    no%=2;
    moves+=no;
    return moves;
}
int main(void)
{
    ll n,*a;
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    test
    {
        cin>>n;
        ll minimum= LLONG_MAX;
        a= new ll[n];
        rep(n)
        {
            cin>>a[i];
            minimum= min(a[i],minimum);
        }
        
        // Iterate over the list and try reducing everyone's chocolates
		// down to {min, min-1, min-2}. Take the minimum 
		// answer.
		ll minMoves= LLONG_MAX;
		for(ll j=0;j<=2;j++)
		{
            ll totalMoves= 0;
            rep(n)
                totalMoves+=(minMovesToMinimum(a[i]-(minimum-j)));
            minMoves= min(totalMoves,minMoves);
		}    
        cout<<minMoves<<endl;
    }
	return 0;
}