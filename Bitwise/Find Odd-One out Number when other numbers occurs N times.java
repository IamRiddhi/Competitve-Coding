/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
     public static int singleNumber(final List<Integer> A) {
        int n = 2; // every no occuring n times;
	    int s = 1; // the odd-one out no occuring s times;
	    int odd_one_out = 0;
	    for(int i = 0 ; i < 32 ; i++)
	    {
	        int sum = 0;
	        for(int x : A)
	        {
	            int bit = x & (1<<i);
	            if(bit != 0)
	                sum++;
	        }
	        sum = sum % n;
	        if(sum != 0) // this is the set bit of the odd-one out number;
	            odd_one_out = (odd_one_out | (1<<i) );
	    }
	    return odd_one_out;
    }
	public static void main (String[] args) {
	    Scanner sc = new Scanner(System.in);
	    int t = sc.nextInt();
	    while(t-->0)
	    {
	        int n = sc.nextInt();
	        List<Integer> lst = new ArrayList<>();
	        for(int i=0;i<n;i++)
	            lst.add(sc.nextInt());
	       System.out.println(singleNumber(lst));
	    }
	    
	}
}
