import acm.program.*;
import java.util.*;
import java.io.*;

public class UniqueNames extends ConsoleProgram{
	public void run(){
		ArrayList<String> names = new ArrayList<String>();
		String curName="default";
		//while(!curName.equals(System.getProperty("line.separator"))){
		boolean inArray;
		while(true){
			inArray = false;
			curName = readLine("Enter name:");
			if(curName.equals(""))break;
			if(!names.contains(curName)){
				names.add(curName);
			}
		/*	for(int j = 0;j<names.size();j++){
				if(names.get(j).equals(curName)){
					inArray = true;
					break;
				}
			}
			if(inArray==false){
				names.add(curName);
			}*/
			
		}
		Collections.sort(names);
		println("Unique name list contains:");
		for(int i=0;i<names.size();i++)
		{
			println(names.get(i));
		}
		
	}
}
