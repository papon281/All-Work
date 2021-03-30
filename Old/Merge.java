import java.util.*;
import java.io.*;
public class Merge{
	/***************************************************************************
* Merge the subarrays a[lo] .. a[mid-1] and a[mid] .. a[hi-1] into
* a[lo] .. a[hi-1] using the auxilliary array aux[] as scratch space.
*
* Precondition: the two subarrays are in ascending order
* Postcondition: a[lo] .. a[hi-1] is in ascending order
*
***************************************************************************/
	private static void merge(Comparable[] a,Comparable[] aux,int lo,int mid,int hi) {
		int i=lo,j=mid ;
		for(int k=lo;k<hi;k++){
			if(i==mid){
				aux[k]=a[j++];
			}
			else if(j==hi){ 
				aux[k]=a[i++];
			}
			else if(a[j].compareTo(a[i])<0){ 
				aux[k]=a[j++];
			}
			else{
				aux[k]=a[i++];
			}
		}
		for(int k=lo;k<hi;k++){
			a[k]=aux[k];
		}
	}
	/***************************************************************************
* Mergesort the subarray a[lo] .. a[hi-1], using the
* auxilliary array aux[] as scratch space.
***************************************************************************/
	public static void sort(Comparable[] a,Comparable[] aux,int lo,int hi){
		// base case
		if(hi-lo<=1){
			return ;
		}
		// sort each half, recursively
		int mid=lo+(hi-lo)/2 ;
		Merge.sort(a,aux,lo,mid);
		Merge.sort(a,aux,mid,hi);
		// merge back together
		Merge.merge(a,aux,lo,mid,hi);
	}
	/***************************************************************************
* Sort the array a using mergesort.
***************************************************************************/
	public static void sort (Comparable[] a) {
		int n=a.length ;
		Comparable[] aux=new Comparable[n];
		Merge.sort(a,aux,0,n);
	}
	/***************************************************************************
	Sort the subarray a[lo..hi] using mergesort.
***************************************************************************/
	public static void sort(Comparable[] a,int low,int high){
		int n=high-low+1;
		Comparable[] aux=new Comparable[n];
		Merge.sort(a,aux,low,high);
	}
	/***************************************************************************
* Check if array is sorted - useful for debugging.
***************************************************************************/
	private static boolean isSorted(Comparable[] a){
		for ( int i=1;i<a.length;i++){
			if (a[i].compareTo(a[i-1])<0){
				return false ;
			}
		}
		return true;
	}
	/***************************************************************************
* Show results.
***************************************************************************/
	public static void show(Comparable[] a) {
		for(int i=0;i<a.length;i++){
			System.out.println(a[i]);
		}
	}
	/***************************************************************************
	* Test client.
	***************************************************************************/
	public static void main(String [] args) {
		String[] a=new String[args.length-2];
		int i=0,j=0,k=0;
		int low=Integer.parseInt(args[0]);
		int high=Integer.parseInt(args[1]);
		String[] b=new String[high-low+1];
		for(i=2;i<args.length;i++){
			a[j++]=args[i];
		}
		//Copy the subarray into a new array;
		for(i=low;i<=high;i++){
			b[k++]=a[i];
		}
		//Sort the subarray using merge sort
		Merge.sort(b);
		for(i=low,j=0;(i<=high&j<b.length);i++,j++){
			a[i]=b[j];
		}
		assert isSorted(b);
		for(i=0;i<a.length;i++){
			System.out.print(a[i]+" ");
		}
		System.out.println();
	}
}