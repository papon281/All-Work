import java.util.*;
import java.io.*;
public class LinkedStackOfStrings {
	private int n=0 ; // size of the stack
	private Node first ; // top of stack
	// helper Node class
	private class Node {
		private String item ;
		private Node next ;
	}
	// is the stack empty?
	public boolean isEmpty(){
		return first==null ;
	}
	// number of elements on the stack
	public int size(){
		return n ;
	}
	// add an element to the stack
	public void push(String item) {
		Node oldfirst=first;
		first=new Node();
		first.item=item ;
		first.next=oldfirst ;
		n++;
	}
	// delete and return the most recently added element
	public String pop (){
		if (isEmpty()) throw new NoSuchElementException ( "stack underflow" );
		String item=first.item ; // save item to return
		first=first.next ; // delete first node
		n--;
		return item ; // return the saved item
	}
	
	//Method for seraching the given Strings from the stack
	public boolean find(String key){
		// iterate until the stack is empty
		while(!isEmpty()){
			// fetch the top element and remove it from stack
			String top = pop();
			// compare the top elements with key
			if(top.compareTo(key)==0){
				// key found
				return true;
			}
		}
		// key is not found in the stack
		return false;
	}

	// test client
	public static void main ( String [] args ){
		LinkedStackOfStrings stack = new LinkedStackOfStrings();
		String key=args[0];
		Scanner scan=new Scanner(System.in);
		while(scan.hasNextLine()){
			String line=scan.nextLine();
			String[] item=line.split(" ");
			for(String str : item){
				stack.push(str);
			}
			if(stack.isEmpty()){
				System.out.println("BAD INPUT");
			}
		}
		// invoke find method of stack class to check if key exist or not
		if(!stack.find(key)){
			// key does not exist
			System.out.println(key+" does not exist in the linked stack");
		}
		else{
			// key exist
			System.out.println(key+ " exists in the linked stack");
		}
	}
}