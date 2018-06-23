/*
-------------------------------------------------PROBLEM STATEMENT----------------------------------------------
Gary is a teacher at XYZ school. To reward his N students he bought a packet of N candies all with different flavours. But the problem is some students like certain flavour while some doesn't. Now Gary wants to know the number of ways he can distribute these N candies to his N students such that every student gets exactly one candy he likes.
Input Format :
Line 1 : An integer N (1<= N <= 16) denoting number of students and candies.
Next N lines : N integers describing the preferences of one student. 1 at i'th (0 <= i < N) position denotes that this student likes i'th candy , 0 means he doesn't.
Assume input to be 0-indexed based.
Output Format :
Return the number of ways Gary can distribute these N candies to his N students such that every student gets exactly one candy he likes.``
Sample Input:
3
1 1 1
1 1 1
1 1 1
Sample Output:
6
*/

/*------------------SOLUTION-----------------*/
typedef long long ll;
long long solve(int like[][MAXN],ll n)
{
	ll *dp = new ll[1<<n];
  	fill(dp,dp+(1<<n),0);
  	dp[(1<<n)-1] = 1; //no candies can be assigned.
  	ll noOfBits = 0;
  	for(ll temp=(1<<n)-1;temp>0;temp>>=1)
         if(temp&1!=0) noOfBits++;
  
  	for(ll mask =(1<<n)-2; mask>=0; mask--)
    {
       /*--- find the person no -----*/
       ll setBits = 1;
       for(ll temp=mask;temp>0;temp>>=1)
         if(temp&1!=0) setBits++;

      /* finding out which candy is not being assigned yet...ie find the reset bits */
       for(ll i=0;i<noOfBits;i++)
         if(((1<<i)&mask)==0 && like[setBits-1][i]==1)
	       dp[mask] += dp[mask|(1<<i)];
    }
  	return dp[0];
}
