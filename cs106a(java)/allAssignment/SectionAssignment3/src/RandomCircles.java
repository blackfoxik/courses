import java.awt.Color;

import acm.graphics.*;
import acm.program.*;
import java.util.*;

public class RandomCircles extends GraphicsProgram{
	/*
	 * TASK
	 * Write a GraphicsProgram that draws a set of ten circles with different sizes, positions,
		and colors. Each circle should have a randomly chosen color, a randomly chosen radius
		between 5 and 50 pixels, and a randomly chosen position on the canvas, subject to the
		condition that the entire circle must fit inside the canvas without extending past the edge. 
	 */
	private static final int MIN_RADIUS = 5;
	private static final int MAX_RADIUS = 50;
	public void init(){
		setSize(600, 500);
	}
	public void run(){
		drawRandomCircles();
	}
	private void drawRandomCircles() {
		
		for (int i=0;i<10;i++){
			GOval oval = getRandomOval();
			add(oval);
		}
		
	}
	private GOval getRandomOval(){
		//radius
		int radius = getRandomFromMINToMAX(MIN_RADIUS,MAX_RADIUS);
		//position X
		int maxPositionX = getWidth()-radius*2;
		int minPositionX = 0+radius*2;
		int positionX = getRandomFromMINToMAX(minPositionX,maxPositionX);
		//position Y
		int maxPositionY = getHeight()-radius*2;
		int minPositionY = 0+radius*2;
		int positionY = getRandomFromMINToMAX(minPositionY,maxPositionY);
		//color
		Color ovalColor = getRandomColor();
		 
		//oval
		GOval oval = new GOval(positionX,positionY,radius,radius);	
		oval.setFillColor(ovalColor);
		oval.setFilled(true);
		return oval;
	}
	private int getRandomFromMINToMAX(int minValue,int maxValue){
		Random random = new Random();
		int result = random.nextInt(maxValue);
		while(result<minValue){
			result = random.nextInt(maxValue);
		}
		return result;
	}
	private Color getRandomColor(){
		Random random = new Random();
		int r = random.nextInt(255);
		int g = random.nextInt(255);
		int b = random.nextInt(255);
		Color color = new Color(r,g,b);
		return color;
	}
}
