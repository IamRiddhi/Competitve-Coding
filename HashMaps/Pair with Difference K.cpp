#include<bits/stdc++.h>
void printPairs(int *a, int n, int k) {
  	unordered_map<int,int> map;
	for(int i=0;i<n;i++)
    {
      if(map[a[i]])
      	map[a[i]] += 1;
      else
        map[a[i]] = 1;
      
	  
      if(map[a[i]+k])
      {
        int dec = 0;
        if(a[i]==a[i]+k)
          dec++;
        for(int j=0;j<map[a[i]+k]-dec;j++)
          cout<<min(a[i],a[i]+k)<<" "<<max(a[i],a[i]+k)<<endl;
      }
      if(map[a[i]-k] && a[i]-k!=a[i]+k)
      {
         int dec = 0;
         if(a[i]==a[i]-k)
          	dec++;
        for(int j=0;j<map[a[i]-k]-dec;j++)
          cout<<min(a[i],a[i]-k)<<" "<<max(a[i],a[i]-k)<<endl;
      }
    }
}


