/*
 * File: Yahtzee.java
 * ------------------
 * This program will eventually play the Yahtzee game.
 */

import acm.io.*;
import acm.program.*;
import acm.util.*;
import java.util.*;


public class Yahtzee extends GraphicsProgram implements YahtzeeConstants {
	
	public static void main(String[] args) {
		new Yahtzee().start(args);
	}
	
	public void run() {
		IODialog dialog = getDialog();
		nPlayers = dialog.readInt("Enter number of players");
		playerNames = new String[nPlayers];
		for (int i = 1; i <= nPlayers; i++) {
			playerNames[i - 1] = dialog.readLine("Enter name for player " + i);
		}
		display = new YahtzeeDisplay(getGCanvas(), playerNames);
		playGame();
	}

	private void playGame() {
		/* You fill this in */
	int[][] arrPlayersScores = new int[nPlayers][13];	
	int[][] arrPlayersChosenCategory = new int[nPlayers][13];
	
	for(int curTurn=0;curTurn<=12;curTurn++){	
		for(int curPlayer=1; curPlayer<=nPlayers;curPlayer++){
			display.printMessage(playerNames[curPlayer-1]+"'s turn.");
			display.waitForPlayerToClickRoll(curPlayer);
			int[] dices = getArrayDices();
			//int[] dices = {1,2,3,4,2};
			display.displayDice(dices);
			display.waitForPlayerToSelectDice();
			dices = reRollDices(dices);	
			display.displayDice(dices);
			display.waitForPlayerToSelectDice();
			dices = reRollDices(dices);	
			display.displayDice(dices);
			display.printMessage(playerNames[curPlayer-1]+" selects category");
			
			int category = display.waitForPlayerToSelectCategory();
			while(categoryWasChosenBefore(category,curPlayer,arrPlayersChosenCategory)){
				display.printMessage(playerNames[curPlayer-1]+" you must select another one category!");
				category = display.waitForPlayerToSelectCategory();
			}
			addCategoryInArrayOfChosenCategory(category,curPlayer,arrPlayersChosenCategory);
			int curScores = getScoresByCategory(category,dices);
			display.updateScorecard(category, curPlayer, curScores);
			saveCurrentProgress(category, curPlayer, curScores,arrPlayersScores);
		}
	}
		//finish of game
		int[][] playersTotalScores = new int[nPlayers][1];
		
		for (int i=0; i<nPlayers;i++){
			//check scores each players
			int curUppScores = 0;
			int curUppBonus = 0;
			for(int u=0;u<=5;u++){
				curUppScores += arrPlayersScores[i][u];
			}
			display.updateScorecard(7, i+1, curUppScores);
			if(curUppScores >= 63){
				curUppBonus = 35;
			}
			display.updateScorecard(8, i+1, curUppBonus);
			int curLowerScores = 0;
			for(int u=6;u<=12;u++){
				curLowerScores += arrPlayersScores[i][u];
			}
			display.updateScorecard(16, i+1, curLowerScores);
			int totalCurScores = curUppScores + curUppBonus + curLowerScores;
			display.updateScorecard(17, i+1, totalCurScores);
			
			playersTotalScores[i][0] = totalCurScores;
		}
		int maxScores = 0;
		int numberLeader = 0;
		for(int i=0; i<nPlayers;i++){
			if(playersTotalScores[i][0]>maxScores){
				maxScores = playersTotalScores[i][0];
				numberLeader = i;
			}
		}
		
		display.printMessage(playerNames[numberLeader]+" you win! your scores are "+maxScores);
		display.waitForPlayerToClickRoll(numberLeader+1);
	}
	
	private void saveCurrentProgress(int category,int curPlayer,int curScores, int[][] arrPlayersScores){
		if(category>0&&category<=6){
			category -= 1;
		}
		else{
			category -= 3;
		}
		arrPlayersScores[curPlayer-1][category] = curScores;
	}
	
	private void addCategoryInArrayOfChosenCategory(int category, int curPlayer,int[][] arrPlayersChosenCategory){
		if(category>0&&category<=6){
			category -= 1;
		}
		else{
			category -= 3;
		}
		arrPlayersChosenCategory[curPlayer-1][category] = 1;
	}
	
	private boolean categoryWasChosenBefore(int category, int curPlayer, int[][] arrPlayersChosenCategory){
		if(category>0&&category<=6){
			category -= 1;
		}
		else{
			category -= 3;
		}
		if(arrPlayersChosenCategory[curPlayer-1][category]!=0){
			return true;
		}
		else{
			return false;
		}
		
	}
	
	private int getScoresByCategory(int category, int[] dices){
		Arrays.sort(dices);
		int curScores=0;
		//ones-sixes
		if(category>0 && category<7){
			for(int i=0;i<dices.length;i++){
				if(dices[i]==category){
					curScores+=dices[i];
				}
			}
		}
		//chance
		if(category == 15){
			curScores = getSumOfDices(dices);
		}
		
		//THREE_OF_A_KIND = 9;
		if(category == 9){
			if(isThreeOfAKind(dices)){
				curScores = getSumOfDices(dices);
			}
			else{
				curScores = 0;
			}
		}
		//FOUR_OF_A_KIND = 10;
		if(category == 10){
			if(isFourOfAKind(dices)){
				curScores = getSumOfDices(dices);
			}
			else{
				curScores = 0;
			}
		}
		//YAHTZEE = 14;
		if(category == 14){
			if(isYahtzee(dices)){
				curScores = 50;
			}
			else{
				curScores = 0;
			}
		}
		//FULL_HOUSE = 11;
		if(category == 11){
			if(isFullHouse(dices)){
				curScores = 25;
			}
			else{
				curScores = 0;
			}
		}
		//LARGE_STRAIGHT = 13;
		if(category == 13){
			if(isLargeStraight(dices)){
				curScores = 40;
			}
			else{
				curScores = 0;
			}
		}
		//SMALL_STRAIGHT = 12;
		if(category == 12){
			if(isSmallStraight(dices)){
				curScores = 30;
			}
			else{
				curScores = 0;
			}
		}
		
		
		
		return curScores;
	} 
	
	private int getSumOfDices(int[] dices){
		int sum = 0;
		for(int i=0;i<dices.length;i++){
			sum+=dices[i];
		}
		return sum;
	}
	
	private boolean isSmallStraight(int[] dices){
		
		 String line = "";
		 for(int i=0;i<dices.length;i++){
			 line+=dices[i];
		 }
		 int[] pattern = {1,2,3,4};
		 boolean match = false;
		 for(int i=0;i<=2;i++){
			 String[] charPattern = new String[4];
			 for(int j=0;j<=3;j++){
				 charPattern[j] = Integer.toString(pattern[j]); 
			 }
			 
			 
			 
			 if(line.indexOf(charPattern[0])!=-1
					 &&line.indexOf(charPattern[1])!=-1
					 &&line.indexOf(charPattern[2])!=-1
					 &&line.indexOf(charPattern[3])!=-1){
				 match = true;
				 break;
			 }
			 else{
				 //coun++
				 for(int k =0; k<=3;k++){
					 pattern[k] = pattern[k]+1;
				 }
			 }
		 }
		 
			 if(match){
				 return true;
			 }
			 else{
				 return false;
			 }
			
	}
	
	
	private boolean isLargeStraight(int[] dices){
		
	 String line = "";
	 for(int i=0;i<dices.length;i++){
		 line+=dices[i];
	 }
	 
	 if(line.equals("12345")||line.equals("23456")){
		 return true;
	 }
	 else{
		 return false;
	 }
	}
	
	
	private boolean isFullHouse(int[] dices){
		if((dices[0]==dices[1]&&dices[2]==dices[3]&&dices[3]==dices[4])||((dices[0]==dices[1]&&dices[1]==dices[2])&&dices[3]==dices[4])){
			return true;
		}
		else{
			return false;
		}
	}
	
	private boolean isYahtzee(int[] dices){
		int countOfMatches = 0;
		for(int i=0;i<dices.length;i++){
			//curItem = dices[i];
			countOfMatches = 0;
			for(int j=0;j<dices.length;j++){
				if(dices[i] == dices[j] && i!=j){
					countOfMatches += 1;
				}
			}
			if(countOfMatches >= 4){
				break;
			}
		}
		if(countOfMatches >= 4){
			return true;
		}
		else{
			return false;
		}
	}
	
	private boolean isFourOfAKind(int[] dices){
		int countOfMatches = 0;
		for(int i=0;i<dices.length;i++){
			//curItem = dices[i];
			countOfMatches = 0;
			for(int j=0;j<dices.length;j++){
				if(dices[i] == dices[j] && i!=j){
					countOfMatches += 1;
				}
			}
			if(countOfMatches >= 3){
				break;
			}
		}
		if(countOfMatches >= 3){
			return true;
		}
		else{
			return false;
		}
	}
	
	private boolean isThreeOfAKind(int[] dices){
		int countOfMatches = 0;
		for(int i=0;i<dices.length;i++){
			//curItem = dices[i];
			countOfMatches = 0;
			for(int j=0;j<dices.length;j++){
				if(dices[i] == dices[j] && i!=j){
					countOfMatches += 1;
				}
			}
			if(countOfMatches >= 2){
				break;
			}
		}
		if(countOfMatches >= 2){
			return true;
		}
		else{
			return false;
		}
	}

	
	private int[] reRollDices(int[] dices){
		for(int i=0;i<=4;i++){
			if(display.isDieSelected(i))
			{
				dices[i]=getRundomNuberOneToSix();
			}
		}
		return dices;
	}
	
	private int[] getArrayDices(){
		int[] arrayOfDices = new int[5];
		for(int i=0;i<=4;i++){
			arrayOfDices[i] = getRundomNuberOneToSix();
		}
		return arrayOfDices;
	}
	
	private int getRundomNuberOneToSix(){
		return rgen.nextInt(1, 6);
	}
		
/* Private instance variables */
	private int nPlayers;
	private String[] playerNames;
	private YahtzeeDisplay display;
	private RandomGenerator rgen = new RandomGenerator();

}
