import acm.program.*;
import java.util.*;

public class FindRange extends ConsoleProgram{
	/*
	 * TASK
	 * Write a ConsoleProgram that reads in a list of integers, one per line, until a sentinel
		value of 0 (which you should be able to change easily to some other value). When the
		sentinel is read, your program should display the smallest and largest values in the
		list
		Your program should handle the following special cases:
		• If the user enters only one value before the sentinel, the program should report
		that value as both the largest and smallest.
		• If the user enters the sentinel on the very first input line, then no values have been
		entered, and your program should display a message to that effect.
	 */
	private static final int  SENTITEL = 0;
	public void run(){
		ArrayList<Integer> arrayUserNumbers = new ArrayList<Integer>();
		int currentNumber = readInt("? ");
		while(currentNumber!=SENTITEL){	
			arrayUserNumbers.add(currentNumber);
			currentNumber = readInt("? ");
		}
		if(arrayUserNumbers.isEmpty()){
			println("was entered number which equal the sentitel");
		}else if(arrayUserNumbers.size()==1){
			println("both smallest and largest is :"+arrayUserNumbers.get(0));
		}else{
			//print MIN MAX
			Collections.sort(arrayUserNumbers);
			println("smallest: "+arrayUserNumbers.get(0));
			println("largest: "+arrayUserNumbers.get(arrayUserNumbers.size()-1));
		}
	}

}
