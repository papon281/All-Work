import java.util.Scanner;
import java.io.*;
import java.lang.Math;
public class Point{
	private double x,y,z;
	// point initialized from parameters it's constructor
	public Point(double x,double y,double z){
		this.x=x;
		this.y=y;
		this.z=z;
	}
	// accessor methods
	public double getX(){
		return x;
	}
	public double getY(){
		return y;
	}
	public double getZ(){
		return z;
	}
	// Euclidean distance between this point and q point
	public double distanceTo(Point q){
		double dx=this.x-q.x;
		double dy=this.y-q.y;
		double dz=this.z-q.z;
		return Math.sqrt(dx*dx+dy*dy+dz*dz);
	}
	// return a string representation of this and q point
	public String toString(){
		return "(" + x + "," + y + "," + z +")";
	}
		//// test client
		public static void main(String[] args){
		int i,j=0;
		double x1=Double.parseDouble(args[0]);
		double y1=Double.parseDouble(args[1]);
		Double z1=Double.parseDouble(args[2]);
		Point p=new Point(x1,y1,z1);
		double x2=Double.parseDouble(args[3]);
		double y2=Double.parseDouble(args[4]);
		double z2=Double.parseDouble(args[5]);
		Point q=new Point(x2,y2,z2);
		System.out.println("The first point is "+ p.toString());
		System.out.println("The second point is"+" "+q.toString());
		double distance=p.distanceTo(q);
		System.out.println("Their Euclidean distance is"+ " "+String.format("%.2f",distance));
	}
}