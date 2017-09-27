/*
 * File: NameSurferGraph.java
 * ---------------------------
 * This class represents the canvas on which the graph of
 * names is drawn. This class is responsible for updating
 * (redrawing) the graphs whenever the list of entries changes or the window is resized.
 */

import acm.graphics.*;
import java.awt.event.*;
import java.util.*;
import java.awt.*;

public class NameSurferGraph extends GCanvas
	implements NameSurferConstants, ComponentListener {
	private HashMap<String,NameSurferEntry> addedNames = new HashMap<String,NameSurferEntry>();	
	private String fontStyle;
	/**
	* Creates a new NameSurferGraph object that displays the data.
	*/
	public NameSurferGraph() {
		addComponentListener(this);
		//	 You fill in the rest //
	}
	
	/**
	* Clears the list of name surfer entries stored inside this class.
	*/
	public void clear() {
		//	 You fill this in //
		addedNames.clear();
		update();
	}
	
	/* Method: addEntry(entry) */
	/**
	* Adds a new NameSurferEntry to the list of entries on the display.
	* Note that this method does not actually draw the graph, but
	* simply stores the entry; the graph is drawn by calling update.
	*/
	public void addEntry(NameSurferEntry entry) {
		// You fill this in //
		addedNames.put(entry.getName(),entry);
		update();
	}
	
	
	
	/**
	* Updates the display image by deleting all the graphical objects
	* from the canvas and then reassembling the display according to
	* the list of entries. Your application must call update after
	* calling either clear or addEntry; update is also called whenever
	* the size of the canvas changes.
	*/
	public void update() {
		//	 You fill this in //
		
		removeAll();
		showGrid();
		showData();
	}
	private void showData(){
		int curNumberOfColor = 1;
		for(String curName: addedNames.keySet()){
			Color curColor = getColor(curNumberOfColor);
			drawDataForName(curName,curColor);
			curNumberOfColor += 1;
		}
	}

	private void drawDataForName(String curname,Color curColor){

		NameSurferEntry curItem = addedNames.get(curname);
		double decade = getWidth()/NDECADES;
		for(int i=0; i<NDECADES; i++){
			int curValue = curItem.getRank(i);
			int nextValue = getNextRank(curItem,i);
	
			double curStartPositionX =decade*i;
			double curFinPositionX =decade*(i+1);
			double curStartPositionY = getPositionYByCurValue(curValue);
			double curFinPostionY = getPositionYByCurValue(nextValue);
		
			String textLabel = getTextForCurLabel(curname,curValue);
			GLabel curlabel = new GLabel(textLabel,curStartPositionX,curStartPositionY);
			curlabel.setFont(Font.decode(fontStyle));
			curlabel.setColor(curColor);
			
			GLine curline = new GLine(curStartPositionX,curStartPositionY,curFinPositionX,curFinPostionY);		
			curline.setColor(curColor);
			add(curlabel);
			if(i<NDECADES-1)add(curline);	
		}
		
	}
	
	private String getTextForCurLabel(String curname,int curValue){
		return curname+" "+Integer.toString(curValue);
	}
	
	private int getNextRank(NameSurferEntry curItem, int curStep){
		int nextRank;
		if(curStep<NDECADES-1) {
			nextRank = curItem.getRank(curStep+1);
		}
		else{
			nextRank = curItem.getRank(curStep);
		}
		return nextRank;
	}
	
	private double getPositionYByCurValue(int curValue){
		double oneTick = getCurTickSize();
		double topBorder = getTopLinePositionY();
		double bottomBorder = getBottomLinePositionY();
		double positionY;
		if(curValue>0){
			positionY = topBorder+oneTick*curValue;
		}
		else{
			positionY = bottomBorder;
		}
		return positionY;
	}
	
	private double getCurTickSize(){
		double height = getHeight();
		double oneEight = height/8;
		double oneTick = (height-oneEight)/1000;
		return oneTick;
	}
	
	private Color getColor(int curNumberOfColor){
		curNumberOfColor = curNumberOfColor%4;
		if(curNumberOfColor == 0){
			curNumberOfColor = 4;
		}
		Color colorForBack;
		switch(curNumberOfColor){
		case 1:
			colorForBack = Color.BLACK;
			break;
		case 2:
			colorForBack = Color.RED;
			break;
		case 3:
			colorForBack = Color.BLUE;
			break;
		case 4:
			colorForBack = Color.MAGENTA;
			break;
		default:
			colorForBack = Color.BLACK;	
			break;
		}
		return colorForBack;
	}
	
	private void showGrid(){
		showVerticalLinesAndLabelsForDecade();
		showTopAndBottomLines();	
	}
	
	private void showVerticalLinesAndLabelsForDecade(){
		double decade = getWidth()/NDECADES;
		for(int i=0; i<NDECADES;i++){
			GLine line = new GLine(decade*i,0,decade*i,getHeight());
			if(i!=0)add(line);
			int curDecada = 1900 + 10*i;
			String textDecada = Integer.toString(curDecada); 
			GLabel labelDecada = new GLabel(textDecada);
			fontStyle = "Helvetica-"+Integer.toString(getWidth()/55);
			labelDecada.setFont(Font.decode(fontStyle));
			labelDecada.setLocation(decade*i+decade/10,getHeight()-labelDecada.getHeight());
			add(labelDecada);
		}
	}
	private void showTopAndBottomLines(){
		double topLinePosY = getTopLinePositionY();
		double bottomLinePosY = getBottomLinePositionY();
		GLine top = new GLine(0,topLinePosY,getWidth(),topLinePosY);
		GLine bottom = new GLine(0,bottomLinePosY,getWidth(),bottomLinePosY);
		add(top);
		add(bottom);
	}
	
	private double getTopLinePositionY(){
		int delimeter = 16;
		return getHeight()/delimeter;
	}
	private double getBottomLinePositionY(){
		int delimeter = 16;
		return getHeight()-getHeight()/delimeter;
	}
	
	/* Implementation of the ComponentListener interface */
	public void componentHidden(ComponentEvent e) { }
	public void componentMoved(ComponentEvent e) { }
	public void componentResized(ComponentEvent e) { update(); }
	//public void componentResized(ComponentEvent e) { }
	public void componentShown(ComponentEvent e) { }
}
