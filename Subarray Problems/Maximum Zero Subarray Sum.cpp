#include<bits/stdc++.h>
using namespace std;
int lengthOfLongestSubsetWithZeroSum(int* a, int n)
{
	unordered_map<int,int> prefixSum; // index-sum pair
  	int sum=0;
  	prefixSum[sum]=-1; 
  	int maxLen=0;
  	for(int i=0;i<n;i++)
    {
    	sum+=a[i];
      	if(prefixSum.find(sum)!=prefixSum.end()) //search for the sum in hash-table
        	maxLen= max(maxLen,i -  prefixSum[sum]);
      	else
        	prefixSum[sum]=i;//insert into hash-table.
    }
  	return maxLen;
}


