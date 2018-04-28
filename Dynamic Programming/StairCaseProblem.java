import java.util.*;
public class StairCaseProblem
{
	public static void main(String args[])
	{
	  		Scanner inp= new Scanner(System.in);
			int j;
			int n= inp.nextInt();
			StringBuilder stairs[][]= new String Builder[n+1][];
			stairs[0]=new StringBuilder[1];
			stairs[0][0]= new StringBuilder(); //left as blank
			stairs[1]= new StringBuilder[1];
			stairs[1][0]= new StringBuilder();
			stairs[1][0].append("1");
			
			for(int i=2;i<=n;i++)
			{
				stairs[i]= new StringBuilder[stairs[i-1].length+stairs[i-2].length];
				for(j=0;j<stairs[i-1].length;j++)
				{
					stairs[i][j]= new StringBuilder();
					stairs[i][j].append(stairs[i-1][j]+",1");
				}
				for(int k=0;k<stairs[i-2].length;k++)
				{
					 stairs[i][j]= new StringBuilder();
					 stairs[i][j].append(stairs[i-2][k]+",2");
					 j++;
				}
			}
			for(StringBuilder sb: stairs[n])
			    System.out.print("["+sb+"],");
			 
	}		
}