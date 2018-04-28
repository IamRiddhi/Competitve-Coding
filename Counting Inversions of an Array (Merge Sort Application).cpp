#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#include<bits/stdc++.h>
#include<algorithm>
#define test ll t; cin>>t; while(t--)
using namespace std;
long long merge(long long input[],long long leftStart, long long leftEnd, long long rightStart, long long rightEnd)
{ 
	long long i,j;
  	long long  inversions = 0;
  	i= leftStart;
  	j= rightStart;
  	long long*dummy = new long long[rightEnd-leftStart+1];
  	long long dummyPos=0;
  	while(i<=leftEnd && j<=rightEnd)   
    {
      if(input[i]<input[j]) // no inversions if left array is less than right array
      {
        dummy[dummyPos++] = input[i];
        i++;
      }
      else if(input[i]>input[j]) /* if the rightArray[j] is lesser than leftArray[i](note that rightArray[j] is smallest among all untouched rightArray elements)
      								 then if rightArray[j] is lesser than leftArray[i] and since rightArray[j] is smallest among right array therefore,
      								 rightarray[j] will be lesser than all remaining elements of leftArray(if a number of a part is lesser than smaller number of 
      								 another part then it will be lesser than all number of that part/
      								 PATI BANGLA BHASAI EKta No jodi onyo ekta part er smaller number r thekei choto hye jai then obviously sobar theke choto hbe...karon
      								 porer number gulo oi part e aro boro hobe.) */
      {
        dummy[dummyPos++] = input[j];
        inversions+=(leftEnd-i+1);
        j++;
      }
      else //equality case 
       /*the left array is equal to right array element and since both left and right part are sorted then it is obvious je all the numbers
      succeeding the right array(elements after rightArray[j]) will be greater or equal to left array number at i hence , no inversion for left[i] 
      and hence i can be incremented. But j cannot be incremented because there may exist a number in the left array which can be greater than right[j]
      as left[i] is in increasing order. Let's take an example,
      left part : 2 7 9
      right part : 2 5 9
      Now see,  right part 1st element 2 is = left part 1st element....and right part is in increasing order so there can't exist any number greater than
      left part 1st element ie 2. Either it will be equal or greater. hence we can say no inversion for 1st element of left part and increment i.
      However 2nd element 7 is greater than 1st elemnent2.
      had we incremented both i and j when left[i]==right[j] as we do in merge sort , we would have missed the inversion count for 7,2 and 9,2.
      ie inversion count for right[0] > 7 and 9 of left part would have been missed.
      SO DONT INCREMENT RIGHT PART WHEN EQUAL , ALWAYS INCREMENT THE LEFT PART WHEN EQUAL BECUASE THAT IS SAFE TO INCREMENT SINCE WE KNOW RIGHT PART
      WILL GO ON INCREASING AND CANT BE LESS THAN LEFT[i]. 
      HOWEVER FROM RIGHT PART'S PERSPECTIVE , LEFT PART WILL GO INCREASING AS WELL , SO WE HAVE TO CHECK THAT WHETHER ITS NOT GREATER THAN RIGHT PART ELEMENTS.
  		*/
      {
        dummy[dummyPos++] = input[i];
        i++;
      }
    }
  	while(i<=leftEnd)
    {
      dummy[dummyPos++] = input[i];
      i++;
    }
  	while(j<=rightEnd)
    {
      dummy[dummyPos++] = input[j];
      j++;
    }
  
	for(long long p=0;p<dummyPos;p++)
      input[p+leftStart] = dummy[p];

    delete[] dummy;
    return inversions;
}
long long myMergeSort(long long input[],long long start, long long end)
{
  	if(start==end) 
      	return 0;
  	long long mid = (start+end)/2;
	return myMergeSort(input,start,mid) + myMergeSort(input,mid+1,end) + merge(input,start,mid,mid+1,end); /*inversions of left array due to merging 
																											+ inversions of right array due to merging
																											+ inversions to merge these 2 arrays */
}
int main()
{
    test
    {
        ll n;
        long long*a;
        cin>>n;
        a= new ll[n];
        for(ll i=0;i<n;i++)
            cin>>a[i];
        cout<<myMergeSort(a,0,n-1)<<endl;
    }
    return 0;
}

