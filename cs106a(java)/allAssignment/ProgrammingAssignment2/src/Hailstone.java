import acm.program.*;
import java.util.*;

public class Hailstone extends ConsoleProgram{
	/*
	 * TASK
	 * Write a ConsoleProgram that reads in a number from the user and then displays the
		Hailstone sequence for that number, just as in Hofstadter’s book, followed by a line
		showing the number of steps taken to reach 1.
	 */
	public void run(){
		int userNumber = readInt("Enter a number: ");
		int countOperations = 0;
		while(userNumber!=1){
			if(userNumber%2==0){
				println(userNumber+" is even, so I take half: "+userNumber/2);
				userNumber/=2;
			}
			else{
				println(userNumber+" is odd, so I make 3n+1: "+(userNumber*3+1));
				userNumber=userNumber*3+1;
			}
			countOperations++;
		}
		println("The process took "+countOperations+" to reach 1");
	}
  
}
