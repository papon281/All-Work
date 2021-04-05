import java.util.*;
import java.io.*;
import java.lang.Math;
public class Hamming{
	//Method for convert inetger into binary to specific length;
	public static String toBinary(int x, int len) {
		if (len > 0) {
			return String.format("%" + len + "s",Integer.toBinaryString(x)).replaceAll(" ", "0");
		}
		return null;
	}
	public static void main(String[] args){
		// read hamming distance from arguments
		int k=Integer.parseInt(args[0]);
		// provided bit string to calculate hamming distance from
		String s=(args[1]);
		//Length of given string
		int n=s.length();
		//Calculate the max number we found from our given String
		double range=Math.pow(2,n);
		//Boolean value for tracking, is there any such string or not 
		Boolean find=false;
		//Loop for find the binary represent of inetgr number from max number to 0
		for(int i=((int) range)-1;i>=0;i--){
			//Received the return string from our method 
			String newString=toBinary(i,n);
			int j=0;
			int count=0;
			//Condtion for terminate the loop
			while(j < n){
				//Compare to string
				if(s.charAt(j)!=newString.charAt(j)){
					//Count the difference bit
					count++;
				}
				//Incement the index value
				j++;
			}
			//check the condition of hamming distance
			if(k == count){
				// enable the flag that bit string found with provided hamming distance
				find = true;
				//Print the String
				System.out.print(newString+" ");
			}
		}
		if(find==false){
			//If there is no such string print this
			System.out.println("There is not any String Which fulfil our condition");
		} else {
			// otherwise print a new line.
			System.out.println();
		}
	}
}