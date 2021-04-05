import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;
import java.lang.*;
import java.io.*;

//Morsecode Converter class
public class MorseCodeConvert {
	//Arraylist for store the character and corresponding encoding string 
	ArrayList<MorseCode> listCodes = new ArrayList<MorseCode>();
	private String encode;
	private String find ="";
	
	//Method for set the character and Encoding string
	void initiaLize() {
		listCodes.add(new MorseCode('A',".-"));
		listCodes.add(new MorseCode('B',"-..."));
		listCodes.add(new MorseCode('C',"-.-."));
		listCodes.add(new MorseCode('D',"-.."));
		listCodes.add(new MorseCode('E',"."));
		listCodes.add(new MorseCode('F',"..-."));
		listCodes.add(new MorseCode('G',"--."));
		listCodes.add(new MorseCode('H',"...."));
		listCodes.add(new MorseCode('I',"--"));
		listCodes.add(new MorseCode('J',".---"));
		listCodes.add(new MorseCode('K',"-.-"));
		listCodes.add(new MorseCode('L',".-.."));
		listCodes.add(new MorseCode('M',"--"));
		listCodes.add(new MorseCode('N',"-."));
		listCodes.add(new MorseCode('O',"---"));
		listCodes.add(new MorseCode('P',".--."));
		listCodes.add(new MorseCode('Q',"--.-"));
		listCodes.add(new MorseCode('R',".-."));
		listCodes.add(new MorseCode('S',"..."));
		listCodes.add(new MorseCode('T',"-"));
		listCodes.add(new MorseCode('U',"..-"));
		listCodes.add(new MorseCode('V',"...-"));
		listCodes.add(new MorseCode('W',"-..-"));
		listCodes.add(new MorseCode('X',"-.--"));
		listCodes.add(new MorseCode('Y',"-.--"));
		listCodes.add(new MorseCode('Z',"..--"));
		listCodes.add(new MorseCode('0',"-----"));
		listCodes.add(new MorseCode('1',".----"));
		listCodes.add(new MorseCode('2',"..---"));
		listCodes.add(new MorseCode('3',"...--"));
		listCodes.add(new MorseCode('4',"....-"));
		listCodes.add(new MorseCode('5',"....."));
		listCodes.add(new MorseCode('6',"-...."));
		listCodes.add(new MorseCode('7',"--..."));
		listCodes.add(new MorseCode('8',"---.."));
		listCodes.add(new MorseCode('9',"----."));
	}
	
	//Method for get the encoding string for the corresponding character
	private String getEncode(char c){
		for(int i = 0; i < listCodes.size();i++) {
			if(listCodes.get(i).getCharacter() == c) {
				return listCodes.get(i).getEncoding();
			}
		}
		return c + "";
	}
	
	//Constructor
	public MorseCodeConvert(String fileName) throws FileNotFoundException {
		String str1="", str2="";
		File file = new File(fileName);
		Scanner s = new Scanner(file);
		while(s.hasNextLine()) {
			String line = s.nextLine();
			String[] word = line.split("\t");
			if(word.length == 1) {
				str1 = word[0];
				str2 = "";
			}
			else {
				str1 = word[0];
				str2 = word[1];
			}
			for(int i = 0; i < str1.length() ; i++)
				listCodes.add(new MorseCode(str1.charAt(i) , str2));
		}
	}
	
	//Print the character and encoding string
	void printConversionCode() {
		for(int i =0;i<listCodes.size();i++) {
			System.out.println(listCodes.get(i).getCharacter()+" "+listCodes.get(i).getEncoding());
		}
		System.out.println();
	}
	
	//Print the converted string
	void printEncodingList() {
		System.out.println(encode);
	}
	
	//Method for encode the string
	void encodeString(String str){
		//Set the char and corresponding encoding string
		encode ="";
		//Convert the string character into upper case
		str = str.toUpperCase();
		
		//Convert the every character into corresponding encoding string
		for(int i =0;i<str.length();i++) {
			//Concatenation the string 
			encode += getEncode(str.charAt(i)); 
		}
		printEncodingList();
		
	}
	
	//Method for find the character and return the object
	MorseCode find(char ch) {
		//Create the object of MorseCode class
		MorseCode morse = new MorseCode(ch,"");
		//Convert the character into upper case
		ch = Character.toUpperCase(ch);
		//Loop for search the character into listCodes 
		for(int i = 0; i < listCodes.size(); i++) {
			if(listCodes.get(i).getCharacter() == ch) {
				this.find = listCodes.get(i).getCharacter() + " " + listCodes.get(i).getEncoding();
			}
		}
		morse.find= this.find;
		//Return the object
		return morse;
	}
	
	//Method for encode the file data
	void encodeFile(String str) {
		encodeString(str);
	}
}
