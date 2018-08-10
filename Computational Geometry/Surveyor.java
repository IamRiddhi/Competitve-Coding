/*Surveyor
A plot has been surveyed. Its boundary consists of segments that form a polygon. Each segment runs either North-South or East-West. Calculate the enclosed area.
The i-th character of direction and the i-th element of length describe the direction and length of the i-th segment of the polygon's boundary as the surveyor walked it. If you start at the surveyor's starting point and walk according to the sequence of directions and lengths reported by the surveyor, you will traverse the boundary of the polygon, ending up back at the starting point. This traversal described by the given segments may be either clockwise or counterclockwise.
Input Format
String s
Array of length of string
Output Format
Area
Constraints
direction will have between 4 and 50 characters inclusive.
length will have the same number of elements as the number of characters in direction.
Each element of direction will be an uppercase letter 'N', 'E', 'S', or 'W'.
Each element of length will be between 1 and 1000 inclusive.
The segments will represent a simple polygon. No two segments will touch or intersect (except that the last point of a segment is the first point of the next segment, and the last point of the final segment is the first point of the first segment).
Sample Test Case
"NWWSE"
{10,3,7,10,10}
Returns: 100


"NESWNWSW"
{20,200,30,100,20,30,10,70}
Returns: 4700*/

/* ---------------S  O  L  U  T  I  O  N ------------------*/
import java.util.*;
class Point
{
  public double x,y;
  public Point(double x,double y)
  {
    this.x = x;
    this.y = y;
  }
}
class Polygon
{
  public Point[] vertices;
  public Polygon(int n)
  {
    vertices = new Point[n];
  }
}
public class Main
{
	public static void main(String[] args)
    {
		int n; 
      	Scanner sc = new Scanner(System.in);
      	String dir;
      	dir = sc.next();
       	n = dir.length();
      	double l[] = new double[n];
      	for(int i=0;i<n;i++) l[i] = sc.nextDouble();
      
      	Polygon p = new Polygon(n);
      	double x[] = new double[n];
      	double y[] = new double[n];
      	x[0] = y[0] = 0;
      	for(int i=1;i<n;i++)
        {
          double valx = 0;
          if(dir.charAt(i-1)=='E')
            valx = l[i-1];
          else if(dir.charAt(i-1)=='W')
            valx = -l[i-1];
          x[i] = x[i-1] + valx;
        }
        for(int i=1;i<n;i++)
        {
           double valy = 0;
          if(dir.charAt(i-1)=='N')
            valy = l[i-1];
          else if(dir.charAt(i-1)=='S')
            valy = -l[i-1];
          y[i] = y[i-1] + valy;
        }
      
      	for(int i=0;i<n;i++)
        {
          	Point pt = new Point(x[i],y[i]);
          	p.vertices[i] = pt;
        }
      	
      	
      	/* Calculating area */
      	double totArea = 0.0;
      	for(int i=1;i<n-1;i++)
        {
        	double x1 = p.vertices[i].x - p.vertices[0].x;
          	double y1 = p.vertices[i].y - p.vertices[0].y;
          	double x2 = p.vertices[i+1].x - p.vertices[i].x;
          	double y2 = p.vertices[i+1].y - p.vertices[i].y;
          
          	double crossProduct = (x1*y2 - x2*y1);
          	totArea += crossProduct;
        }
      	
      	System.out.println((int)(Math.abs(totArea)/2.0));
	}
}