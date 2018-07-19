 	#include<bits/stdc++.h>
	int highestFrequency(int *input, int n)
    {	 
		
     	unordered_map<int,int> m;
      	for(int i=0;i<n;i++)
            m[input[i]]++;
     	int maximum= INT_MIN;
      	int elem;
      for(int i=0;i<n;i++)
      {
        if(maximum<(m[input[i]]))
        {
          maximum=m[input[i]];
          elem=input[i];
        }
      }
      return elem;
 	}

