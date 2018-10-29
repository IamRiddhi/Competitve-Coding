import java.util.Scanner;

class Trie
{
	public Trie left;
  	public Trie right;
}
public class Main
{
  	public static void insert(Trie t,int n)
    {
    	for(int bit=31;bit>=0;bit--)
        {
        	int b = (1<<bit)&n;
            if(b!=0)
            {
            	if(t.right==null)
                  t.right = new Trie();
              	t = t.right;
            }
          	else
            {
            	if(t.left==null)
                  t.left = new Trie();
              	t = t.left;
            }
        }
    }
  	public static int findMaxPair(Trie t,int n)
    {
      	int maximum = 0;
      	for(int bit=31;bit>=0;bit--)
        {
          int b = (1<<bit)&n;
          if(b!=0) //to maximise, take 0 and go left.
          {
          	  if(t.left==null)
              	t = t.right;
           	  else
              {
                t = t.left;
                maximum += Math.pow(2,bit);
              }
          }
          else // to maximise, take 1 and go right.
          {
            if(t.right==null)
              t = t.left;
            else
            {
              t = t.right;
              maximum += Math.pow(2,bit);
            }
          }
        }
      	return maximum;
    }
	public static void main(String[] args)
    {
		Trie t = new Trie();
      	Scanner sc = new Scanner(System.in);
      	int n = sc.nextInt();
     	int a[] = new int[n];
      	for(int i=0;i<n;i++)
          a[i] = sc.nextInt();
      	insert(t,0);
      	int maximum = a[0];
      	int cum_xor = a[0]; //cumulative xor
        insert(t,cum_xor);
      	  
      for(int i=1;i<n;i++)
        {
       		cum_xor = cum_xor ^ a[i];
            maximum = Math.max(findMaxPair(t,cum_xor),maximum); 
          	insert(t,cum_xor);
        }
      	System.out.println(maximum);
	}
}
