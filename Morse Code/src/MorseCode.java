import java.util.*;
import java.io.*;

//Morsecode class
public class MorseCode {
	private char ch;
	private String str;
	public String find = "";
	
	//Constructor
	public MorseCode(char ch, String str){
		while(str.isBlank()) {
			break;
		}
		this.ch = ch;
		this.str = str;
	}
	
	//Getter method for character
	public char getCharacter() {
		return ch;
	}
	
	//Setter method for character
	public void setCharacter(char c) {
		ch =c;
	}
	
	
	//Getter method for encoding of character
	public String getEncoding() {
		return str;
	}
	
	//Setter method for encoding character
	public void setEncoding(String s) {
		str = s;
	}
}
