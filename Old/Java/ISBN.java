import java.util.Scanner;
import java.io.*;
public class ISBN{
	public static void main(String[] args){
		int i,num=0,j=10;
		String code=args[0];
		//For loop for find the sum up all digit value multiply by their index value from rightmost index
		for(i=0;i<code.length();i++){
			num=num+((code.charAt(i)-'0')*j);
			j--;
		}
		//find the checksum digit
		num=11-(num%11);
		//check if tchecksum digit is 10 or not
		if(num==10){
			code=code+'X';
		}
		else if(num==11){
			code=code+'0';
		}
		//concatenation the checksum digit with our input string at the right
		else{
			code=code+(Integer.toString(num));
		}
		System.out.println("The ISBN number would be"+" "+code);
	}
}
