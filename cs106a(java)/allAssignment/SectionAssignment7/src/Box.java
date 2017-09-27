import java.awt.Color;
import acm.graphics.*;
import acm.program.*;


public class Box extends GCompound{
	
	public Box(String name){
		GRect rect = new GRect(BOX_WIDTH,BOX_HEIGHT);
		GLabel boxName = new GLabel(name);
		this.add(rect,-BOX_WIDTH / 2, -BOX_HEIGHT / 2);
		this.add(boxName,-boxName.getWidth()/2,boxName.getAscent()/2);
		
	}
	private static final double BOX_WIDTH = 120;
	private static final double BOX_HEIGHT = 50;
}