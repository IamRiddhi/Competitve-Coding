import java.util.Scanner;
class Trie
{
	public Trie left,right;
  	public int leafNodes;
  	public Trie()
  	{
  	    left = right = null;
  	    leafNodes = 1;
  	}
}
public class Main
{	
    public static void insert(Trie t,int n)
    {
        Trie root = t ;
        for(int pos=31;pos>=0;pos--)
        {
          int bit = (1<<pos)&n;
          if(bit==0)
          {
            if(t.left==null)
              t.left = new Trie();
            else
                t.left.leafNodes++;
            t = t.left;
          }
          else
          {
            if(t.right==null)
              t.right = new Trie();
            else
                t.right.leafNodes++;
            t = t.right;
          }
        }
    }
    public static int countSubarrays(Trie t,int n,int p)
    {
        int count = 0;
        for(int pos=31;pos>=0;pos--)
        {
            if(t==null)
              break;
            int a = (1<<pos)&n;
            int k = (1<<pos)&p;
            a = Math.min(a,1);
            k = Math.min(k,1);
            if(a==0 && k==0)
                t = t.left;
            else if(a==0 && k==1)
            {
              if(t.left!=null)
                count += t.left.leafNodes;
              t = t.right;
            }
            else if(a==1 && k==0)
              t = t.right;
            else if(a==1 && k==1)
            {
                if(t.right!=null)
                  count += t.right.leafNodes;
                t = t.left;
            }
        }
        return count;
    }
	public static void main(String[] args) 
    {
		Scanner sc = new Scanner(System.in);
      	int t = sc.nextInt();
      	while(t-->0)
        {
          int n = sc.nextInt();
          int k = sc.nextInt();
          int a[] = new int[n];
          for(int i=0;i<n;i++)
            a[i] = sc.nextInt();
          Trie root = new Trie();
          int cum_xor = 0;
          insert(root,cum_xor);
          long count = 0;
          for(int i=0;i<n;i++)
          {
          	cum_xor = cum_xor ^ a[i];
            count += countSubarrays(root,cum_xor,k);
            insert(root,cum_xor);
          }
          System.out.println(count);
        }
	}
}