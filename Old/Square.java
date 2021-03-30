import java.util.*;
import java.io.*;
public class Square{
	private double x; // upper left x co-ordinate of square
	private double y; // uper left y co-ordinate of square
	private double length; // side length of the square
	//Constructor to initialize a square object
	Square(double x,double y,double length){
		this.x = x;
		this.y = y;
		this.length = length;
	}
	//Accesor method of x
	public double getX(){
		return x;
	}
	// Accessor method of y
	public double getY(){
		return y;
	}
	// Accessor method of length
	public double getLength(){
		return length;
	}
	//return the area of a square
	public double area(){
		return (length*length);
	}
	// return the perimeter of a square 
	public double perimeter(){
		return (4*length);
	}
	// return true of current square intersect with the parameterized square
	// false otherwise
	boolean intersects(Square b){
		//Top right coordinate of first square
		double square1_top_rightX=this.x+this.length;
		double square1_top_rightY=this.y;
		//bottom right coordinate of first square
		double square1_bottom_rightX=this.x;
		double square1_botom_rightY=this.y-this.length;
		//bottom left coordinate of first square
		double square1_botom_leftX=this.x;
		double square1_botom_leftY=this.y-this.length;
		//Top right coordinate of second square
		double square2_top_rightX=b.x+b.length;
		double square2_top_rightY=b.y;
		////bottom right coordinate of second square
		double square2_bottom_rightX=b.x;
		double square2_botom_rightY=b.y-b.length;
		//bottom left coordinate of second square
		double square2_botom_leftX=b.x;
		double square2_botom_leftY=b.y-b.length;
		// If one square is on left side of other
		if(this.x>=square2_bottom_rightX || b.x>=square1_bottom_rightX){
        	return false; 
		}
		// If one square is above other
		if(this.y<=square2_botom_rightY || b.x<=square1_botom_rightY){
			return false;
		}
    	return true; 
	}
	//Return the boolean value if current square contains the parameterized square
	boolean contains(Square b){
		//Top right coordinate of first square
		double square1_top_rightX=this.x+this.length;
		double square1_top_rightY=this.y;
		//bottom right coordinate of first square
		double square1_bottom_rightX=square1_top_rightX;
		double square1_botom_rightY=this.y-this.length;
		//bottom left coordinate of first square
		double square1_botom_leftX=this.x;
		double square1_botom_leftY=this.y-this.length;
		//Top right coordinate of second square
		double square2_top_rightX=b.x+b.length;
		double square2_top_rightY=b.y;
		////bottom right coordinate of second square
		double square2_bottom_rightX=square2_top_rightX;
		double square2_botom_rightY=b.y-b.length;
		//bottom left coordinate of second square
		double square2_botom_leftX=b.x;
		double square2_botom_leftY=b.y-b.length;
		// check if all the points of second square is inside of the first square
		if((this.x >= b.x) && (square1_bottom_rightX<=square2_bottom_rightX)){
			if((this.y >= b.y) && (square1_botom_rightY <= square2_botom_rightY))
				return true;
		}
		return false;
	}
	
	public static void main(String[] args){
		//Upper left cordinate of first square
		double x1=Double.parseDouble(args[0]);
		double y1=Double.parseDouble(args[1]);
		//Length of first square
		double length1=Double.parseDouble(args[2]);
		//Object of First square
		Square square1=new Square(x1,y1,length1);
		//Print the  area of first square
		System.out.println("The area is "+square1.area());
		//Print the perimeter of first square
		System.out.println("The perimeter is "+square1.perimeter());
		Scanner scan=new Scanner(System.in);
		System.out.print("Enter the upper-left coordinates and the length of a square: ");
		//Uper left coordinate of second square
		double x2=scan.nextDouble();
		double y2=scan.nextDouble();
		//length of second square
		double length2=scan.nextDouble();
		//Object declare for second square
		Square square2=new Square(x2,y2,length2);
		//Condition of check the interstcing of two square and print
		if(!square1.intersects(square2)){
			System.out.println("It intersects the first square.");
		}
		else{
			System.out.println("It's not intersects the first square.");
		}
		//Condition of check the containng method of two square and print
		if(!square1.contains(square2))
			System.out.println("It does not contain the first square.");
		else
			System.out.println("It contains the first square.");
		//Call the draw method for draw the square
		// initialize the canvas to draw. Using default canvas size
		StdDraw.setCanvasSize();
		// draw the first square
		StdDraw.square(square1.getX() + square1.getLength()/2.0, square1.getY() + square1.getLength()/2.0, square1.getLength()/2.0);
		// draw the second square
		StdDraw.square(square2.getX() + square2.getLength()/2.0, square2.getY() + square2.getLength()/2.0, square2.getLength()/2.0);
	}
}