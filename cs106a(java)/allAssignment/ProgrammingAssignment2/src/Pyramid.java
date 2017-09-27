import acm.graphics.*;
import acm.program.*;

public class Pyramid extends GraphicsProgram{
	/*TASK
	 * Write a GraphicsProgram subclass that draws a pyramid consisting of bricks
	arranged in horizontal rows, so that the number of bricks in each row decreases by
	one as you move up the pyramid
	The pyramid should be centered at the bottom of the window and should use
	constants for the following parameters:
	BRICK_WIDTH The width of each brick (30 pixels)
	BRICK_HEIGHT The height of each brick (12 pixels)
	BRICKS_IN_BASE The number of bricks in the base (14)
	The numbers in parentheses show the values for this diagram, but you must be able
	to change those values in your program.
	 */
	private static final int BRICK_WIDTH = 30; 
	private static final int BRICK_HEIGHT = 12; 
	private static final int BRICKS_IN_BASE = 14;
	
	public void init(){
		setSize(600, 500);
	}
	public void run(){
		showPyramid();
	}
	private void showPyramid(){
		for(int i =0; i<BRICKS_IN_BASE;i++){
			for(int j=0;j<BRICKS_IN_BASE-i;j++){
				int currentBricksInBase = BRICKS_IN_BASE-i;
				int currentSizeOfBase = BRICK_WIDTH*currentBricksInBase;
				int positionX = getWidth()/2-currentSizeOfBase/2+BRICK_WIDTH*j;
				int positionY = getHeight()-BRICK_HEIGHT*i-BRICK_HEIGHT;
				GRect rect = new GRect(positionX,positionY,BRICK_WIDTH,BRICK_HEIGHT);
				add(rect);
				
		}
	}
	}
}
