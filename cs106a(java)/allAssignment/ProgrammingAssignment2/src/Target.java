import java.awt.Color;

import acm.graphics.*;
import acm.program.*;


public class Target extends GraphicsProgram {
	/*
	 * TASK
	 * This figure is simply three GOval objects, two red and one white, drawn in the correct
		order. The outer circle should have a radius of one inch (72 pixels), the white circle
		has a radius of 0.65 inches, and the inner red circle has a radius of 0.3 inches. The
		figure should be centered in the window of a GraphicsProgram subclass.
	 */
	public void init(){
		setSize(600, 500);
	}
	public void run(){
		showTarget();
	}
	private void showTarget(){
		double radiusOuterCircle = 72.0;
		double radiusWhiteCircle = 72*65/100;
		double radiusInnerCircle = 72*30/100;

		putCircleWithRadiusAndColorOnCenter(radiusOuterCircle,Color.RED);
		putCircleWithRadiusAndColorOnCenter(radiusWhiteCircle,Color.white);
		putCircleWithRadiusAndColorOnCenter(radiusInnerCircle,Color.red);
	}
	private void putCircleWithRadiusAndColorOnCenter(double radius,Color color){
		int positionCenterX = getWidth()/2;
		int positionCenterY = getHeight()/2;
		GOval oval = new GOval(positionCenterX-radius/2,positionCenterY-radius/2,radius,radius);
		oval.setFillColor(color);
		oval.setFilled(true);
		add(oval);
	}
}
