import java.util.*;
import java.io.*;
import java.lang.*;
public class Histogram{
	public static void main(String[] args) throws IOException{
                // scanner object to read from standard input
		In scan=new In();
		//Initialize array to store inputs
		int[] num=new int[10000];
                // store number of input content
		int size=0;
                int i = 0;
		while(scan.hasNextLine()){
			//Read line from text file
			String line=scan.readLine();
			//Store strings from line in a string array
	               String[] strNumbers = line.split(" ");
        	        //For loop for store string value into integer array
        	        for(String str : strNumbers){
        	        	//Convert the string into integer and store into the array
        	        	num[i++]=Integer.parseInt(str);
        	        	//size of array
        	        	size++;
        	        }
	       }
	       //number of intervals
                int n=num[0];
                //left range of histogram
                int left=num[1];
                //right range of histogram
                int right=num[2];
                // range internal.
                int interval_range=(right-left)/n;
                //initialize the size of every intervals
                int[] intervals=new int[n];
                //Copy the left value,which we using as a satarting value of our interval 
                int start_value=left;
                int count=0;
                //Array index
                int k=0;
                //loop for search the number of every intervals
                //increase the interval array index values
                //while count equal n loop terminated
                while(count<n){
                	for(int j=3;j<size;j++){
                		if((num[j]>=start_value) && (num[j]<(start_value+interval_range))){
                			intervals[k]++;
                		}
                	}
                	//Updated left value
                	start_value=start_value+interval_range;
                	//increase index
                	k++;
                	//increase counting of intervals
                	count++;
                }
                // initialize the canvas to draw. Using default canvas size
                StdDraw.setCanvasSize();
                //intervals value is the width of our rctangle
                int width=(right-left)/n;
                // set left to 0 to draw the histogram from left side of the canvas
                left = 0;
                //Loop for draw the n interval rectangles
                for(int j=1;j<=n;j++){
                	//X coordinate
                	double x=(double)left;
                	//Y coordinate
                	double y=0;
                	//Center coordinate for the ractangles
                	double interval=(double) (intervals[j-1]);
                        // calculate x co-ordinate of center. X-axis is scalled by 0.01
                	double centerX=(x+(width/2.0))/100.0;
                        // calculate y co-ordinate of center. X-axis is scalled by 0.1
                	double centerY=(y+(interval/2.0))/10.0;
                	//Draw the rectangles
                	StdDraw.rectangle(centerX,centerY,(width/2.0)/100.0,(interval/2.0)/10.0);
                        // update left value of next range
                        left=left+width;
                }
	}
}