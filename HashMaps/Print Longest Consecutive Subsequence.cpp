#include<bits/stdc++.h>
#include<climits>
using namespace std;
vector<int> longestSubsequence(int *a, int n)
{
  vector<int> output;
  unordered_set<int> s;
  for(int i=0;i<n;i++)
    s.insert(a[i]);
  int maximum=1;
  for(int i=0;i<n;i++)
  {
    if(s.find(a[i]-1)==s.end()) //starting element of the sequence.
    {
    	int cur= a[i]+1;
      	while(s.find(cur)!=s.end())
          cur++;
      	if(maximum<cur-a[i])
        {
          maximum= cur-a[i];
          output.clear();
          for(int j=a[i];j<cur;j++)
            	output.push_back(j);
        }
    }
  }
  return output;
}
