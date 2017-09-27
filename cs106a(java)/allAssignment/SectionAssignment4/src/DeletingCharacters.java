import acm.program.*;

public class DeletingCharacters extends ConsoleProgram {
	/*
	 * Write a method
		public String removeAllOccurrences(String str, char ch)
		that removes all occurrences of the character ch from the string str.
	 * 
	 */
	public void run(){
		removeAllOccurrences("This is a test", 't');
		removeAllOccurrences("Summer is here!", 'e');
		removeAllOccurrences("---0---", '-') ;
	}
	private void removeAllOccurrences(String strOrigin, char occur){
		println(strOrigin.replaceAll(Character.toString(occur), ""));
	}
}
