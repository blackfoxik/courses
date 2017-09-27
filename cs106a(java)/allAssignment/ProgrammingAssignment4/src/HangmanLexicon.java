import acm.util.*;
import java.io.*;
import java.util.*;

public class HangmanLexicon {
	private List<String> lexicon;
	
	HangmanLexicon(){
		try{
			lexicon = new ArrayList<String>();	
			BufferedReader reader = new BufferedReader(new FileReader("ShorterLexicon.txt"));
			String line = reader.readLine();
			while(line!=null){
				lexicon.add(line);
				line = reader.readLine();
			}
			reader.close();
		}
		catch(FileNotFoundException e){
			
		}
		catch(IOException e){
			throw new ErrorException(e);
		}
		
	}
	
	/** Returns the number of words in the lexicon. */
	public int getWordCount() {
		return lexicon.size();
	}
	
	/** Returns the word at the specified index. */
	public String getWord(int index) {
		return lexicon.get(index);
	};
}