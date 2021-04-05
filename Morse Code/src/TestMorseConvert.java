import java.util.Scanner;
import java.io.*;

//Driver Code
public class TestMorseConvert {
	public static void main(String[] args) throws FileNotFoundException {
		//Input Stream
	    Scanner sc = new Scanner(System.in);	
		while(true) {
			//Show the option
			System.out.println("1. Print Conversion Code");
			System.out.println("2. Convert String");
			System.out.println("3. Convert File");
			System.out.println("4. Exit");
			System.out.println("Enter Choice: ");
			//Input the choice
			int n = sc.nextInt();
			//Print the Key and Value
			if(n == 1) {
				System.out.println("The Converted Code is: ");
				MorseCodeConvert morse = new MorseCodeConvert("morsecode.txt");
				morse.printConversionCode();
				
			}
			
			//Convert the string to morse code
			if(n == 2) {
				String str;
				str = sc.next();
				System.out.println("The Converted String is: ");
				MorseCodeConvert morsecode = new MorseCodeConvert("morsecode.txt");
				morsecode.encodeString(str);
			}
			
			//Convert the file data into mors ecode
			if(n == 3) {
				try {
					File file = new File(sc.next());
					Scanner s = new Scanner(file);
					MorseCodeConvert morse = new MorseCodeConvert("morsecode.txt");
					System.out.println("The Converted file is:");
					while(s.hasNextLine()) {
						String line = s.nextLine();
						morse.encodeFile(line);
					}
				}
				catch(Exception ex) {
					System.out.println(ex.getMessage());
				}
				
			}	
			
			//Exit the program
			if(n==4) {
				System.exit(0);
			}
			
			//Show the message if input inmvaid number
			if(n<1 && n>4) {
				System.out.println("Please enter the number between 1-4");
				System.out.println();
			}
		}
	}
}