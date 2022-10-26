import java.util.*;
import java.io.*;
public class BinarySearch {
	// return the index of the key in the sorted array a[]; -1 if not found
	public static int search(int key ,int[] a) {
	    return search (key,a,0,a.length-1);
	}
	// possible key indices in [lo, hi)
	public static int search(int key,int[] a,int lo,int hi) {
		int res = -1;
	    while(lo<=hi){
	    	int mid=lo+(hi-lo)/2;
	    	if(key<a[mid]){
	    		hi=mid-1;
	    	}
	    	else {
	    		lo=mid+1;
	    		res = mid;
	    	}
	    }
	    if(a[res]==key){
	    	return res;
	    }
	    else{
	    	return -res;
	    }
	}
	// allowlist, exception filter
	public static void main(String[] args) throws IOException{
		File file=new File(args[0]);
		int key=Integer.parseInt(args[1]);
		Scanner sc=new Scanner(file);
		String line=sc.nextLine();
        String []strNumbers = line.split(" ");
        int[] num=new int[strNumbers.length];
        int i=0;
         for(String str : strNumbers){
        	num[i++]=Integer.parseInt(str);
        }
        // sort the numbers (if needed)
	    Arrays.sort(num);
	    // prompt user to enter a number and check if it's there
		int index=search(key,num);
		System.out.println(index);
	}
}