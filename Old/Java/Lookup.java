import java.util.*;
import java.io.*;
import java.util.Set;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Queue;
import java.lang.*;
public class Lookup {
	public static void main(String[] args) throws Exception{
		File file=new File(args[0]);
		In in=new In(file);
		int keyField=Integer.parseInt(args[1]);
		int valField=Integer.parseInt(args[2]);
		String[] database=in.readAllLines();
		StdOut.println(database);
		HashMap<String, String> st=new HashMap<String,String>();
		for(int i=0;i<database.length;i++){
			String[] tokens=database[i].split(",");
			String key=tokens[keyField];
			String val=tokens[valField];
			st.put(key,val);
		}
		while (!StdIn.isEmpty()) {
			String s=StdIn.readString();
			if(st.containsKey(s)){
				StdOut.println(st.get(s));
			}
			else{
				StdOut.println("Not found");
			}
		}
	}

}