import java.util.*;
import java.io.*;
import java.util.Arrays;

public class Uppercase{

	//Recursive method for count the uppercase letter in string;
	public static int searchuppercase(String message,int count){
		//Whwn length is ZERO return the Value of Count
		if(message.length()==0){
			return count;
		}
		//Increase the value of count variable
		if(Character.isUpperCase(message.charAt(0))){
			count++;
		}
		//Create a substring from the string messeage
		String tail=message.substring(1);
		//Call the method recursively
		return searchuppercase(tail,count); 
	}

	//Test Prograam
	public static void main(String[] args){
		String message;
		Scanner sc=new Scanner(System.in);
		//Prompt the user for input a number
		System .out.println("Input a message");
		message=sc.nextLine();
		//Call the method
		int count=searchuppercase(message,0);
		//Print the result
		System.out.println("The number of uppercase letters: "+count);
	}
}