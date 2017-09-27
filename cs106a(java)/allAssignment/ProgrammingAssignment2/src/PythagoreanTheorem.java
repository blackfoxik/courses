import acm.program.*;
public class PythagoreanTheorem extends ConsoleProgram{
	/*
	 * TASK
	 * Write a ConsoleProgram that accepts values for a and b as ints and then calculates
		the solution of c as a double.
	 * 
	 */
	public void run(){
		int a = readInt("a: ");
		int b = readInt("b: ");
		double c =  Math.sqrt(a*a+b*b);
		println("c = "+Double.toString(c));
	}
}
