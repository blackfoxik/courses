import acm.program.*;
import acm.util.ErrorException;

import java.io.*;
import java.util.*;

public class Histogram extends ConsoleProgram {
	public void run(){
		ArrayList<Integer> scores = getListScoresFromFile();
		showHistogram(scores);
	}
	private void showHistogram(ArrayList<Integer> scores){
		int curCount;
		for(int i = 0; i<=100; i+=10){
			curCount = 0;
			for(int j = 0; j<scores.size();j++){
				if(scores.get(j)>=i&&scores.get(j)<=i+9){
					curCount++;
				}
			}
			
			println(viewForInterval(i)+getStars(curCount));
			
		}
	}
	private String viewForInterval(int curInt){
		String result = "";
		if(curInt<10){
			result ="00-09: ";
		}else if(curInt==100){
			result ="  100: ";
		}
		else{
			
			result = curInt+"-"+(curInt+9)+": ";
		}
		return result;
	}
	private String getStars(int curCount){
		String result = "";
		for(int i=0;i<curCount;i++){
			result +="*";
		}
		return result;
	}
	private ArrayList<Integer> getListScoresFromFile(){
		ArrayList<Integer> scores = new ArrayList<Integer>();
		BufferedReader reader = openFile();
		int curNumber = 0;
		
		try{
			String curLine = reader.readLine();
			while(curLine!=null){
				curNumber = Integer.parseInt(curLine);
				scores.add(curNumber);
				curLine = reader.readLine();	
			}
			reader.close();		
			}
		catch(IOException e){
			throw new ErrorException(e);	
		}
		
		return scores;
	}
	
	private BufferedReader openFile(){
		BufferedReader reader = null;
		
		while(reader==null){
			try{
				String fileName = "MidtermScores.txt";
				reader = new BufferedReader(new FileReader(fileName));
			}
			catch(IOException e){
				println("incorrect file name, try again");
				break;
			}
		}
		return reader;
	}

}
