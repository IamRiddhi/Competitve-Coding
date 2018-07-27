#include<bits/stdc++.h>
using namespace std;
int *finish;
bool cmp(int a,int b)
{
  return finish[a]<finish[b];
}
int main()
{
   int n;
   cin>>n; 
   int *start = new int[n];
   finish = new int[n];
   for(int i=0;i<n;i++)
     cin>>start[i]>>finish[i];
   
  	int *sortedIndex = new int[n];
  	for(int i=0;i<n;i++)
      sortedIndex[i] = i;
  
   //sorting according to finish time
  	sort(sortedIndex,sortedIndex+n,cmp);
  
  	int tot = 1;
  	int prevFinishTime = finish[sortedIndex[0]];
  	for(int i=1;i<n;i++)
    {
      if(start[sortedIndex[i]]>=prevFinishTime)
      {
        tot++;
        prevFinishTime = finish[sortedIndex[i]];
      }
    }
  	cout<<tot<<endl;
}
