import java.util.*;
import java.util.Arrays;
import java.io.*;
class pairString{
	String first;
	String second;
	pairString(String first,String second){
		this.first=first;
		this.second=second;
	}
}
public class Solution2{
	/*List<String> largestItemAssociation(Pair<String,String> itemAssociation){
		helpText = helpText.replaceAll("[^A-Za-z]"," ");
		String helpTextarray[] =helpText.split(" ");
		Set<String> uniqueWord = new HashSet<String>();
		for(int i=0; i<helpTextarray.length; i++){
			uniqueWord.add(helpTextarray[i]);
		}
		int count[] = new int[uniqueWord.size()];
		int index = 0;
		for( String str : uniqueWord ){
			int Count = 0;
			for ( int j = 0; j<helpTextarray.length; j++ ) {
				if(!wordsToExclude.contains(str) && str.equals(helpTextarray[j])){
					Count++;
				}
			}
			count[index]=Count; 
			index++;
		}
		int max=count[0];
		for(int i=0;i<uniqueWord.size();i++){
			if(count[i]>=max){
				max=count[i];
			}
		}
		index=0;
		List<String> string=new ArrayList<>();
		for(String str: uniqueWord){
			if(count[index]==max){
				string.add(str);
			}
			index++;
		}
		return string;

	}*/
	public static void main(String[] args){
		String item;
		Scanner sc = new Scanner(System.in);
		item = sc.nextLine();
		item = item.replaceAll("[^A-Za-z]"," ");
		List<pairString> ItemAssociation=new ArrayList<>();
		String[] itemarray=item.split(" ");
		//pairString pair=new pairString();
		for(int i=0; i<itemarray.length; i=i+2){
			String one=itemarray[i];
			String two=itemarray[i+1];
			pairString p1=new pairString(one,two);
			ItemAssociation.add(p1);
		}
		//Solution solution=new Solution();
		//frequentlyUseWrds=solution.retrieveMostFrequentlyUseWords(Helptext,WordsToexclude);
		System.out.println(ItemAssociation);
	}
}