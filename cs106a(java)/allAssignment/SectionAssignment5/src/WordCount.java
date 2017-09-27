import acm.program.*;
import java.io.*;
import java.util.*;
import acm.util.*;

public class WordCount extends ConsoleProgram {
	/* TASK
	 * Write a program WordCount that reads a file and reports how many lines, words, and
		characters appear in it.
	 * 
	 */
	public void run(){
		openFileAndCountWordsLinesCharacters();
	}
	private void openFileAndCountWordsLinesCharacters(){
		BufferedReader reader = openFile();
		int lines = 0;
		int countWords = 0;
		int countChars = 0;
		try{
			
			String curLine = reader.readLine();
			while(curLine!=null){
				countWords += countWords(curLine);
				lines++;
				countChars += curLine.length();
				curLine = reader.readLine();
				
			}
			reader.close();
			println("Lines = "+lines);
			println("Words = "+countWords);
			println("Chars = "+countChars);
			
		}
		catch(IOException e){
			throw new ErrorException(e);	
		}
	}
	private int countWords(String curLine){
		int countWords = 0;
		String[] arrWordsInCurLine = curLine.split(" ");
		for(int i = 0; i< arrWordsInCurLine.length; i++){
			String curWord = arrWordsInCurLine[i];
			if(curWord.length()>0){
				for(int j = 0; j<curWord.length();j++){
					char curSign = curWord.charAt(j);
					if(!Character.isLetterOrDigit(curSign)&&j<curWord.length()-1){
						countWords++;
					}	
				}
					countWords++;
				}
				
		}
		return countWords;
	}
	private BufferedReader openFile(){
		BufferedReader reader = null;
		
		while(reader==null){
			try{
				String fileName = readLine("File: ");
				reader = new BufferedReader(new FileReader(fileName));
			}
			catch(IOException e){
				println("incorrect file name, try again");
			}
		}
		return reader;
	}
}
