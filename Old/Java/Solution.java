import java.util.*;
import java.util.Arrays;
import java.io.*;
public class Solution{
	List<String> retrieveMostFrequentlyUseWords(String helpText,List<String> wordsToExclude){
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

	}
	public static void main(String[] args){
		String Helptext;
		String word;
		Scanner sc = new Scanner(System.in);
		Helptext=sc.nextLine();
		word=sc.nextLine();
		word=word.replaceAll("[^A-Za-z]"," ");
		List<String> WordsToexclude=new ArrayList<>(Arrays.asList(word.split(" ")));
		List<String> frequentlyUseWords=new ArrayList<>();
		Solution solution=new Solution();
		frequentlyUseWords=solution.retrieveMostFrequentlyUseWords(Helptext,WordsToexclude);
		for(String str : frequentlyUseWords)
			System.out.print(str+" ");
	}
}