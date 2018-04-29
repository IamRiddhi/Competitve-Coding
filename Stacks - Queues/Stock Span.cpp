#include<bits/stdc++.h>
using namespace std;
int* stockSpan(int *price, int n)
{
  	int *output= new int[n];
	stack<int> s;
  	s.push(0);
  	output[0]= 1;
  	for(int i=1;i<n;i++)
    {
	    while(!s.empty() && price[i]>price[s.top()])
          s.pop();
        if(s.empty())
          output[i]= i + 1;
        else
          output[i]= i - s.top();
        s.push(i);
    }
  	return output;
}
