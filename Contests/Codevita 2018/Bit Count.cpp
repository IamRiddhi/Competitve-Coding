#include<bits/stdc++.h>
#include<bitset>
#include<cmath>
#include<climits>
#define test ll t; cin>>t; while(t--)
#define rep0(n) for(ll i=0;i<(n);i++)
#define rep1(n) for(ll i=1;i<=(n);i++)
using namespace std;
typedef long long ll;
long long merge(ll myArray[],long long leftStart, long long leftEnd, long long rightStart, long long rightEnd)
{
	long long i,j;
  	long long  inversions = 0;
  	i= leftStart;
  	j= rightStart;
  	ll *codevita = new ll[rightEnd-leftStart+1];
  	long long codevitaPos=0;
  	while(i<=leftEnd && j<=rightEnd)
    {
      if(myArray[i]<myArray[j])
      {
        codevita[codevitaPos++] = myArray[i];
        i++;
      }
      else if(myArray[i]>myArray[j])
      {
        codevita[codevitaPos++] = myArray[j];
        inversions+=(leftEnd-i+1);
        j++;
      }
      else //equality case
      {
        codevita[codevitaPos++] = myArray[i];
        i++;
      }
    }
  	while(i<=leftEnd)
    {
      codevita[codevitaPos++] = myArray[i];
      i++;
    }
  	while(j<=rightEnd)
    {
      codevita[codevitaPos++] = myArray[j];
      j++;
    }
  
	for(long long p=0;p<codevitaPos;p++)
      myArray[p+leftStart] = codevita[p];

    delete[] codevita;
    return inversions;
}
long long myMergeSort(ll myArray[],long long start, long long end)
{
  	if(start==end) 
      	return 0;
  	long long mid = (start+end)/2;
	return myMergeSort(myArray,start,mid) + myMergeSort(myArray,mid+1,end) + merge(myArray,start,mid,mid+1,end);
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        ll n,*a;
        cin>>n;
        char ch;
        a= new ll[n];
        ll x;
        rep0(n)
        {
            cin>>x>>ch;
            ll count = 0;
            while (x)
            {
                count += x & 1;
                x >>= 1;
            }
            a[i] = count;
        }
        cout<<myMergeSort(a,0,n-1)<<endl;
    return 0;
}