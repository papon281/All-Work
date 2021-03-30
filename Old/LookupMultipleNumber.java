import java.util.*;
import java.io.*;
import java.util.HashMap;
import java.util.Queue;
import java.lang.*;
public class LookupMultipleNumber{
	public static void main(String[] args) throws Exception{
		// Create an object of file input stream
		In in=new In(args[0]);
		// read maximumn size of values to display for a key
		int max_size=Integer.parseInt(args[1]);
		// key column position of the csv file
		int keyField=Integer.parseInt(args[2]);
		// value column position of the csv file
		int valField=Integer.parseInt(args[3]);
		// read all lines from the csv file and store into an array of string
		String[] database=in.readAllLines();
		// Creata an object of key-value map where value is a queue of string
		HashMap<String, Queue<String>> st=new HashMap<String,Queue<String>>();
		for(int i=0;i<database.length;i++){
			// split the line read from csv
			String[] tokens=database[i].split(",");
			// read key
			String key=tokens[keyField];
			// read value
			String val=tokens[valField];
			//Add the value of same key in queue;
			if(!st.containsKey(key)){
				// if key is new, initiate the queue against current key
				Queue<String> q = new LinkedList<String>();
				st.put(key, q);
			}
			// append current value in the queue of current key
			st.get(key).add(val);
		}
		Scanner scan = new Scanner(System.in);
		while (scan.hasNext()){
			// read user input
			String s = scan.nextLine();
			if(st.containsKey(s)){
				// if key  exist, extract the queue of string against input key
				Queue<String> vals = st.get(s);
				int size = max_size;
				//Print the values of input key
				// print maximum of max_size values if more is present in the queue
				while(size > 0 && !vals.isEmpty()){
					StdOut.print(vals.poll());
					size--;
					if(size > 0) StdOut.print(" ");
				}
				StdOut.println();
			}
			else{
				// display message that key is not found
				StdOut.println("Not found");
			}
		}
	}
}