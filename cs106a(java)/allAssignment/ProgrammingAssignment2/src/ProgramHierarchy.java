import acm.graphics.*;
import acm.program.*;

public class ProgramHierarchy extends GraphicsProgram{
	/*
	 * TASK
	 * The only classes you need to create this picture are GRect, GLabel, and GLine. The
		major part of the problem is specifying the coordinates so that the different elements 
		– 3 –
		of the picture are aligned properly. The aspects of the alignment for which you are
		responsible are:
		• The width and height of the class boxes should be specified as named constants
		so that they are easy to change.
		• The labels should be centered in their boxes. You can find the width of a label by
		calling label.getWidth() and the height it extends above the baseline by calling
		label.getAscent(). If you want to center a label, you need to shift its origin by
		half of these distances in each direction.
		• The connecting lines should start and end at the center of the appropriate edge of
		the box.
		• The entire figure should be centered in the window.
	 */
	private static final int BOX_WIDTH = 200;
	private static final int BOX_HEIGHT = 100;
	
	public void init(){
		setSize(600, 500);
	}
	public void run(){
		showHierarchy();
	}
	private void showHierarchy(){
		//create points for boxes
		GPoint pointProgramBox = getPointProgramBox();
		GPoint pointChildConsoleBox = getPointChildConsoleBox();
		GPoint pointChildGraphicBox = getPointChildGraphicBox();
		GPoint pointChildDialogBox = getPointChildDialogBox();
		
		//create boxes by points
		GRect mainBox = getBoxByPoint(pointProgramBox);
		GRect childBoxConsole = getBoxByPoint(pointChildConsoleBox);
		GRect childBoxGraphic = getBoxByPoint(pointChildGraphicBox);
		GRect childBoxDialog = getBoxByPoint(pointChildDialogBox);
		
		//put lines from parent to child
		putLineFromParentToChild(mainBox,childBoxConsole);
		putLineFromParentToChild(mainBox,childBoxGraphic);
		putLineFromParentToChild(mainBox,childBoxDialog);
		
		//put labels
		putLabelOnBox(mainBox,"Program");
		putLabelOnBox(childBoxConsole,"ConsoleProgram");
		putLabelOnBox(childBoxGraphic,"GraphicProgram");
		putLabelOnBox(childBoxDialog,"DialogProgram");
	} 
	private GPoint getPointProgramBox(){
		double positionMainBoxX = getWidth()/2 - BOX_WIDTH/2;
		double	positionMainBoxY = getHeight()/2 - (BOX_HEIGHT*1.5);
		GPoint mainBoxPoint = new GPoint(positionMainBoxX,positionMainBoxY);
		return mainBoxPoint;
	}
	private GPoint getPointChildConsoleBox(){
		double positionchildBoxConsoleX = getWidth()/2 - BOX_WIDTH/2;
		double positionchildBoxConsoleY = getHeight()/2+(BOX_HEIGHT*0.5);
		GPoint childBoxConsolePoint = new GPoint (positionchildBoxConsoleX,positionchildBoxConsoleY);
		
		return childBoxConsolePoint;
	}
	private GPoint getPointChildGraphicBox(){
		double gapBetweenChildBoxes = BOX_WIDTH*0.3;
		double positionchildBoxGraphicX = getWidth()/2 - BOX_WIDTH/2-BOX_WIDTH-gapBetweenChildBoxes;
		double positionchildBoxGraphicY = getHeight()/2+(BOX_HEIGHT*0.5);		
		GPoint childChildGraphicBoxPoint = new GPoint(positionchildBoxGraphicX,positionchildBoxGraphicY);	
		
		return childChildGraphicBoxPoint;
	}
	private GPoint getPointChildDialogBox(){
		double gapBetweenChildBoxes = BOX_WIDTH*0.3;
		double positionchildBoxDialogY = getHeight()/2+(BOX_HEIGHT*0.5);
		double positionchildBoxDialogX = getWidth()/2 - BOX_WIDTH/2+BOX_WIDTH+gapBetweenChildBoxes;
		GPoint childChildGraphicBoxPoint = new GPoint(positionchildBoxDialogX,positionchildBoxDialogY);
		
		return childChildGraphicBoxPoint;
	}
	private GRect getBoxByPoint(GPoint pointBox){
		GRect box = new GRect(pointBox.getX(),pointBox.getY(),BOX_WIDTH,BOX_HEIGHT);
		add(box);
		return box;
	}
	private void putLineFromParentToChild(GRect parent,GRect child){
		double positionParentX = parent.getX()+BOX_WIDTH/2;
		double positionParentY = parent.getY()+BOX_HEIGHT;
		
		double positionChildX = child.getX()+BOX_WIDTH/2;
		double positionChildY = child.getY();
		
		GLine lineFromParentToChild = new GLine(positionParentX,positionParentY,positionChildX,positionChildY);
		add(lineFromParentToChild);
	}
	private void putLabelOnBox(GRect box,String labelString){
		GLabel label = new GLabel(labelString);
		double positionLabelX = box.getX() + BOX_WIDTH/2-label.getWidth()/2;
		double positionLabelY = box.getY() + (BOX_HEIGHT/2)+(label.getAscent()/2);
		label.setLocation(positionLabelX, positionLabelY);
		add(label);
	}

}
