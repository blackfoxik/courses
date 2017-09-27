/*
 * File: NameSurferDataBase.java
 * -----------------------------
 * This class keeps track of the complete database of names.
 * The constructor reads in the database from a file, and
 * the only public method makes it possible to look up a
 * name and get back the corresponding NameSurferEntry.
 * Names are matched independent of case, so that "Eric"
 * and "ERIC" are the same names.
 */
import java.util.*;
import java.io.*;


public class NameSurferDataBase implements NameSurferConstants {
	private HashMap <String,String> localStorage = new HashMap<String,String>();
/* Constructor: NameSurferDataBase(filename) */
/**
 * Creates a new NameSurferDataBase and initializes it using the
 * data in the specified file.  The constructor throws an error
 * exception if the requested file does not exist or if an error
 * occurs as the file is being read.
 * @throws IOException 
 */
	public NameSurferDataBase(String filename) throws IOException {
		// You fill this in //
		filename = "names-data.txt";
		BufferedReader br = new BufferedReader(new FileReader(filename));
		try {
		    StringBuilder sb = new StringBuilder();
		    String line = br.readLine();

		    while (line != null) {
		    	String[] arrOfLine = line.split(" ");
				String name = arrOfLine[0];
				localStorage.put(name, line);
		        line = br.readLine();
		    }
		}
		catch(IOException e){
			 e.toString();
		}
		finally {
		    br.close();
		}
	}
	
/* Method: findEntry(name) */
/**
 * Returns the NameSurferEntry associated with this name, if one
 * exists.  If the name does not appear in the database, this
 * method returns null.
 */
	public NameSurferEntry findEntry(String name) {
		
		// You need to turn this stub into a real implementation //
		String nameForFind = localStorage.get(name);
		if(nameForFind != null){
			NameSurferEntry result = new NameSurferEntry(localStorage.get(name));
			return result;
		}
		else{
			return null;	
		}
	}
}

