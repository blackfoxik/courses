import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;

import acm.program.*;

public class DataStructure extends ConsoleProgram {
	public void run(){
		try {
			readFile();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		showCities();
		makeTrip();
	}
	
	private void makeTrip(){
		ArrayList<String> travel = new ArrayList<String>();
		println("Let's plan a round-trip route");
		String startCity = readLine("Enter the staring city ");
		showDestinationsFrom(startCity);
		String curCity = askDestinationFrom(startCity);
		travel.add(startCity);
		travel.add(curCity);
		while(!curCity.equals(startCity)){
			showDestinationsFrom(curCity);
			curCity = askDestinationFrom(curCity);
			travel.add(curCity);
		}
		showRoute(travel);
	}
	
	private String askDestinationFrom(String city){
		return readLine("Where do you want to go from "+city+" ");
	}
	
	private void showRoute(ArrayList<String> travel){
		println("The route you've chosen is:");
		String textRoute = "";
		for(int i = 0;i<travel.size();i++ ){
			if(i==travel.size()-1){
			textRoute += travel.get(i);
			}
			else{
				textRoute += travel.get(i)+" -> ";
			}
		}
		println(textRoute);
	}
	
	private void showDestinationsFrom(String city){
	
		ArrayList<String> curDest = flights.get(city);
		println("From "+city+" you can directly fly to:");
		for(int i = 0;i<curDest.size();i++ ){
			println(" "+curDest.get(i));
		}
	} 


	
	private void showCities(){
		for(int i = 0;i<cities.size();i++ ){
			println(cities.get(i));
		}
	}
	private void readFile() throws IOException{
		String filename = "flights.txt";
		BufferedReader br = new BufferedReader(new FileReader(filename));
		try {
		    StringBuilder sb = new StringBuilder();
		    String line = br.readLine();

		    while (line != null) {
		    	String[] arrOfLine = line.split("->");
				String cityNameFrom = arrOfLine[0];
				cityNameFrom = cityNameFrom.trim();
				String cityNameTo  = arrOfLine[1];
				if(flights.containsKey(cityNameFrom)){
					flights.get(cityNameFrom).add(cityNameTo);
				}
				else{
					flights.put(cityNameFrom, new ArrayList<String>());
					flights.get(cityNameFrom).add(cityNameTo);
				}
				
				
				if(!cities.contains(cityNameFrom)){
					cities.add(cityNameFrom);
				}
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
	private HashMap<String,ArrayList<String>> flights = new HashMap<String,ArrayList<String>>();
	private ArrayList<String> cities = new ArrayList<String>();
 
}
