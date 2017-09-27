 
import acm.program.*;
import acm.io.*;

public class FibonacciSequence extends ConsoleProgram{
	/* TASK
	 * Write a program that displays the terms in the Fibonacci sequence, starting with Fib(0)
	    and continuing as long as the terms are less than 10,000.
	   This program continues as long as the value of the term is less than the maximum value,
		so that the loop construct you need is a while, presumably with a header line that looks
		like this:
		while (term < MAX_TERM_VALUE)
		Note that the maximum term value is specified using a named constant.
	 */
	
	private static final int MAX_TERM_VALUE = 10000;
	
	public void run() {
		displayFibonacci();
	}

	private void displayFibonacci(){
		int term = 1;//current result of function, which calculates by term = Fn-1 + Fn-2 where n>=2
		int Fn_1 = 1;//item Fn-1
		int Fn_2 = 0;//item Fn-2
		println(Fn_2);
		while(term<MAX_TERM_VALUE){
				println(term);
				term = Fn_2+Fn_1;
				Fn_2 = Fn_1;
				Fn_1 = term;
		}
		/*
		// * we can use another approach (which represented below) without Fn_1 variable, but I prefer to develop simple application
			
			int Fn_2 = 0;//item Fn-2
			int term = 1;//current result of function
			println(Fn_2);
			while(term<MAX_TERM_VALUE){
					println(term);	
					term = term +Fn_2;
					Fn_2 = term - Fn_2;
			}
		*/	
	} 	
}
