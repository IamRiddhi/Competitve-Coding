import java.util.Scanner;
class Trie
{
	public Trie children[] = new Trie[26];
  	public int max_wt;
  	public Trie(int wt)
    {
    	max_wt = wt;
    }
}
class TestClass 
{
  	public static void insertTrie(Trie t,String s,int wt)
    {
    	for(int i=0;i<s.length();i++)
        {
        	char ch = s.charAt(i); 
          	if(t.children[ch-'a']==null)
              t.children[ch-'a'] = new Trie(wt);
          	else
              t.children[ch-'a'].max_wt = Math.max(t.children[ch-'a'].max_wt,wt);
         	t = t.children[ch-'a'];
        }
    }
  	public static int queryTrie(Trie t,String s)
    {
    	for(int i=0;i<s.length();i++)
        {
        	char ch = s.charAt(i);
            if(t.children[ch-'a']==null)
              return -1;
          	else
              t = t.children[ch-'a'];
        }
      	return t.max_wt;
    }
	public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
		    int n,q;
        n = sc.nextInt();
      	q = sc.nextInt();
      	Trie root = new Trie(-1);
      	for(int i=0;i<n;i++)
        {
            String s = sc.next();
          	int wt = sc.nextInt();
          	insertTrie(root,s,wt);
        }
      	while(q-->0)
        {
        	String query = sc.next();
          	System.out.println(queryTrie(root,query));
        }
	}
}