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
       	n = sc.nextInt();
      	Polygon p = new Polygon(n);
      	double x[] = new double[n];
      	double y[] = new double[n];
      	for(int i=0;i<n;i++)
          x[i] = sc.nextDouble();
        for(int i=0;i<n;i++)
          y[i] = sc.nextDouble();
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
      	
      	System.out.println(Math.abs(totArea)/2.0);
	}
}