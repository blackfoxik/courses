import java.util.*;
import acm.program.*;

public class CountNames extends ConsoleProgram {
	
	public void run(){
		HashMap<String,Integer> names = new HashMap<String,Integer>();
		askNames(names);
		printNames(names);
	}
	private void askNames(HashMap<String,Integer> names){
		while(true){
			String curName = readLine("Enter name: ");
			if(curName.equals("")){
				break;
			}
			else if(names.containsKey(curName)){
				names.put(curName, names.get(curName)+1);
			}
			else{
				names.put(curName, 1);
			}
		}
	}
	private void printNames(HashMap<String,Integer> names){
		for (Map.Entry<String, Integer> entry : names.entrySet()) {
		    println("Entry ["+entry.getKey()+"] has count " +entry.getValue());
		}
	}
}
