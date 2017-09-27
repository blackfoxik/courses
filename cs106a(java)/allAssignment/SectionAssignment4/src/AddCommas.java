import acm.program.*;
public class AddCommas extends ConsoleProgram{
	/*TASK
	 * When large numbers are written out on paper, it is traditional—at least in the United
		States—to use commas to separate the digits into groups of three. For example, the
		number one million is usually written in the following form:
		1,000,000
	 * 
	 */
	public void run() {
		 while (true) {
			 String digits = readLine("Enter a numeric string: ");
			 if (digits.length() == 0) break;
			 	println(addCommasToNumericString(digits));
		 	}
		}
	private String addCommasToNumericString(String digits){
		if(digits.length()<=3){
			return digits; 
		}
		else{	
			String firstPart = "";
			String restPart = "";
			int reminder = digits.length()%3;
			if(reminder>0){
				 firstPart = digits.substring(0,reminder);
				 restPart = digits.substring(reminder,digits.length());
			}
			else{
				restPart = digits;
			}
			String result = "";
			for(int i=0;i<restPart.length();i+=3){
				if(i+3==restPart.length()){
					result+=restPart.subSequence(i, i+3);
				}
				else{
					result+=restPart.subSequence(i, i+3)+",";
				}
					
			}
			if(reminder>0){
				result = firstPart+","+result;
			}
			return result;
		}
	}

}
