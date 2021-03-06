import acm.graphics.*;
import acm.program.*;
import java.awt.event.*;
;


public class DrawingLines extends GraphicsProgram {
	/*
	 * Write a GraphicsProgram that allows the user to draw lines on the canvas. Pressing the
		mouse button sets the starting point for the line. Dragging the mouse moves the other
		endpoint around as the drag proceeds. Releasing the mouse fixes the line in its current
		position and gets ready to start a new line. For example, suppose that you press the
		mouse button somewhere on the screen and then drag it rightward an inch, holding the
		button down. 
	 */
	private GLine line;
	public void init(){
		setSize(600, 500);
	}
	public void run(){
		addMouseListeners();
	}
	public void mousePressed(MouseEvent e) {
		line = new GLine(e.getX(), e.getY(),e.getX(), e.getY());
		add(line);
	}
	public void mouseDragged(MouseEvent e){	
		line.setEndPoint(e.getX(), e.getY());
	}
	public void mouseClicked(MouseEvent e) {}
	public void mouseEntered(MouseEvent e) {}
	public void mouseExited(MouseEvent e) {}
	public void mouseReleased(MouseEvent e) {}
	   
}
