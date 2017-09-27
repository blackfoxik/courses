import java.awt.Color;
import acm.graphics.*;
import acm.program.*;

public class FaceRobot extends GraphicsProgram {
	/*	TASK
	 *  This simple face consists of four parts—a head, two eyes, and a mouth—which are
		arranged as follows:
		• The head. The head is a big rectangle whose dimensions are given by the named
		constants HEAD_WIDTH and HEAD_HEIGHT. The interior of the head is gray, although it
		should be framed in black.
		• The eyes. The eyes should be circles whose radius in pixels is given by the named
		constant EYE_RADIUS. The centers of the eyes should be set horizontally a quarter of
		the width of the head in from either edge, and one quarter of the distance down from
		the top of the head. The eyes are yellow.
		• The mouth. The mouth should be centered with respect to the head in the x-dimension
		and one quarter of the distance up from the bottom of the head in the y-dimension.
		The dimensions of the mouth are given by the named constants MOUTH_WIDTH and
		MOUTH_HEIGHT. The mouth is white.
		Finally, the robot face should be centered in the graphics window.
	 */
	
	private static final int HEAD_HEIGHT = 400;
	private static final int HEAD_WIDTH = 200;
	private static final int EYE_RADIUS = 50;
	private static final int MOUTH_HEIGHT = 50;
	private static final int MOUTH_WIDTH = 100;
	
	public void init(){
		setSize(600, 500);
	}
	public void run() {
		drawFace();	
	}
	
	private void drawFace(){
		int centerWindowWidth = getWidth()/2;
		int centerWindowHeight = getHeight()/2;
		
		//head
		int headPosition_X = centerWindowWidth-HEAD_WIDTH/2;
		int headPosition_Y = centerWindowHeight-HEAD_HEIGHT/2;
		GRect head = new GRect(headPosition_X,headPosition_Y,HEAD_WIDTH,HEAD_HEIGHT);
		head.setFillColor(Color.GRAY);
		head.setFilled(true);
		
		//eyes
		int rightEyePosition_X = centerWindowWidth+(HEAD_WIDTH/2)-(HEAD_WIDTH/4)-(EYE_RADIUS/2);
		int leftEyePosition_X = centerWindowWidth-(HEAD_WIDTH/2)+(HEAD_WIDTH/4)-(EYE_RADIUS/2);
		int eyesPosition_Y = centerWindowHeight-(HEAD_HEIGHT/2)+(HEAD_HEIGHT/4)-(EYE_RADIUS/2);
		GOval rightEye = new GOval(rightEyePosition_X,eyesPosition_Y,EYE_RADIUS,EYE_RADIUS);
		GOval leftEye = new GOval(leftEyePosition_X,eyesPosition_Y,EYE_RADIUS,EYE_RADIUS);
		rightEye.setFillColor(Color.YELLOW);
		rightEye.setFilled(true);
		leftEye.setFillColor(Color.YELLOW);
		leftEye.setFilled(true);
		
		//mouth
		int mouthPosition_X = centerWindowWidth-MOUTH_WIDTH/2;
		int mouthPosition_Y = centerWindowHeight+(HEAD_HEIGHT/2)-(HEAD_HEIGHT/4)-(MOUTH_HEIGHT/2);
		GRect mouth = new GRect(mouthPosition_X,mouthPosition_Y,MOUTH_WIDTH,MOUTH_HEIGHT);
		mouth.setFillColor(Color.WHITE);
		mouth.setFilled(true);
		
		//add parts
		add(head);
		add(rightEye);
		add(leftEye);
		add(mouth);	
	} 
}
