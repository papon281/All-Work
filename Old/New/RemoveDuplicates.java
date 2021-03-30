import java.util.*;
import java.io.*;
import java.util.Arrays;
import java.util.ArrayList;

public class RemoveDuplicates{
	//Generic method for remove the duplicates element from arraylist
	public static <E> ArrayList<E> removeDuplicates(ArrayList<E> list){
		//Create a new arraylist
		ArrayList<E> newlist=new ArrayList<E>();
		//For loop for remove the duplicate elements from list
		for(E element: list){
			//If newlist canont contain the element then add to the newlist otherwise not
			if(!newlist.contains(element)){
				newlist.add(element);
			}
		}
		//Return newlist
		return newlist;
	}

	//Test programm
	public static void main(String[] args){

		ArrayList<Integer> intlist=new ArrayList<Integer>();//Create a integer type arraylist
		ArrayList<Double> doublelist=new ArrayList<Double>();//Create a double type arraylist
		ArrayList<Integer> intnewlist=new ArrayList<Integer>();//Arraylist for recieve return of int type value
		ArrayList<Double> doublenewlist=new ArrayList<Double>();//Arraylist for recieve the return of double type value


		int n;
		//Prompt the user for input the size of list and value
		System.out.print("Enter the size of arraylist: ");
		Scanner sc=new Scanner(System.in);
		n=sc.nextInt();

		System.out.print("Enter the value: ");
		//Loop for add the value in list
		for(int i=0;i<n;i++){
			int value=sc.nextInt();
			intlist.add(value);
		}

		//Print the duplicate and non-duplicate list
		System.out.println("Arraylist with duplicates "+intlist);
		intnewlist=removeDuplicates(intlist);
		System.out.println("Arraylist without duplicates "+intnewlist);

		//Again prompt the user for input the size and value of list
		System.out.print("Again enter the size of your arraylist: ");
		n=sc.nextInt();

		System.out.print("Enter the value: ");
		//Loop for add the value in list
		for(int i=0;i<n;i++){
			double value=sc.nextDouble();
			doublelist.add(value);
		}

		//Print the duplicate and non-duplicate list
		System.out.println("Arraylist with duplicates "+doublelist);
		doublenewlist=removeDuplicates(doublelist);
		System.out.println("Arraylist without duplicates "+doublenewlist);
	}
}