
/* -----------------------PROBLEM STATEMENT-----------------------

Toll Gate

Find the minimum cost to travel from source to destination with multiple toll gates across. There are challenges at each toll gate to minimize the cost.
Choices
1) One can either chose to pay the toll
2) One can battle at the toll gate to avoid paying by having his own set of men they travel with them(initially zero)
3) One can pay double the toll cost and hire all men at each tolls to battle and avoid toll cost.
Note
1) You can chose to battle at particular toll if your number of hired men is strictly greater than the count of all men at respective toll gate
2) Each hired man can battle for 3 times only
3) For each battle you will lose equal no. of men with you as well as available in the toll gate. Rest of them will lose 1 round of battle irrespective of whether they are alive or not. After 3 battles, they will not survive. If you have 10 men with you and total no. of toll men is 8, then you can lose 8 men in battle and remaining 2 men lost 1 round of battle and hence they can be available for 2 more rounds only.
Input Format
First line contains an integer n, denoting number of toll gates
Next n lines contain 2 integers each, denoting number of men and cost of that toll gate.
Sample Input
7
10 100
70 5
80 15
20 60
50 90
30 80
10 10
Sample Output
150

*/


/* --------------------SOLUTION----------------*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// hired i means men having strength i remaining
ll compute(ll *men,ll *price,ll n, ll tollNo, ll cost, ll hired1,ll hired2,ll hired3)
{
  	static ll minimum = LLONG_MAX;
	if(tollNo==n)  
    {
      	minimum = min(minimum,cost);
    	return minimum;  
    }
    /* we have three options....either hire or fight or just pay*/
  	
  	/* just paying*/
  	ll pay = compute(men,price,n,tollNo+1,cost+price[tollNo],hired1,hired2,hired3);
  	
    /* hire */
  	ll hire = compute(men,price,n,tollNo+1,cost+2*price[tollNo],hired1,hired2,hired3+men[tollNo]);
  
    /* fight */
  	ll fight = LLONG_MAX;
  	
    if((hired1+hired2+hired3)>men[tollNo])
    {
      	ll value; ll value3=0;
      	if(men[tollNo]<=hired1) 
          value = 0; 
      	else
        {
            value = men[tollNo] - hired1; 
          	if(value>hired2)
            {
              value3 = value-hired2;
              value = hired2; 
            }
        }     
  		fight = compute(men,price,n,tollNo+1,cost,hired2-value,hired3-value3,0);
    }
  	return min(pay,min(hire,fight));
}
int main()
{
  	ll n, *men,*cost;
  	cin>>n;
  	men = new ll[n];
  	cost = new ll[n];
  	for(ll i=0;i<n;i++)
      cin>>men[i]>>cost[i];
  	cout<<compute(men,cost,n,0,0,0,0,0);
    return 0;
}
