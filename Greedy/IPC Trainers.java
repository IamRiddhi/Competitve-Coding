/* package codechef; // don't place package name! */
import java.util.*;
import java.lang.*;
import java.io.*;

class Trainer implements Comparable<Trainer>
{
    public long days,lectures,sadness;
    public Trainer(long d,long l,long s) 
    {
        days = d;
        lectures = l;
        sadness = s;
    }
    public int compareTo(Trainer y) throws NullPointerException ,ClassCastException
    {
        if(this.sadness>y.sadness)
            return -1;
        else    
            return 1;
    }
}
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
	    Scanner sc = new Scanner(System.in);
	    int tc = sc.nextInt();
	    while(tc-->0)
	    {
	        int n = sc.nextInt();
	        int d = sc.nextInt();
	        Trainer t[] = new Trainer[n];
	        ArrayList<PriorityQueue<Trainer>> td = new ArrayList<PriorityQueue<Trainer>>();
	        for(int i=0;i<=d;i++)
	            td.add(null);
	        for(int i=0;i<n;i++)
	        {
	             int x,y,z;
	             x = sc.nextInt();
	             y = sc.nextInt();
	             z = sc.nextInt();
	             PriorityQueue<Trainer> pq = null;
	             if(td.get(x)==null)
	                pq = new PriorityQueue<>();
	             else
	                pq = td.get(x);
	             pq.add(new Trainer(x,y,z));
	             td.set(x,pq);
	             t[i] = new Trainer(x,y,z);
	        }
	        
	        PriorityQueue<Trainer> trainers = new PriorityQueue<>();
	        for(int day=1;day<=d;day++)
	        {
	            PriorityQueue<Trainer> trpq = td.get(day);
	            if(trainers.size()==0 && trpq==null)
	                continue;
	             if(trpq!=null)
	                trainers.addAll(trpq);
	             Trainer x = trainers.poll();
	             x.lectures -= 1;
	             if(x.lectures>0)
	                trainers.add(x);
	        }
	        Iterator<Trainer> itr = trainers.iterator();
	        long sad = 0;
            while(itr.hasNext()) 
            {
                Trainer x = itr.next();
                sad += (x.lectures*x.sadness);
            } 
            System.out.println(sad);
	    }
	}
}
