import acm.graphics.*;

public class HangmanCanvas extends GCanvas {
	private GCompound scaffold;
	private GCompound man;
	private GOval head;
	private GLine body;
	private GCompound leftArm;
	private GCompound rightArm;
	private GCompound leftLeg;
	private GCompound rightLeg;
	private GLine leftFoot;
	private GLine rightFoot;
	private GLabel riddleWord;
	private GLabel incorrectGuess;
	private int turns;
	
	
	 private void showScaffold(){
		 scaffold = new GCompound();
		 double centerPositionX = this.getWidth()/2;
		 double startScaffoldPositionY = this.getHeight()/16;
		 GLine rope = new GLine(centerPositionX,startScaffoldPositionY,centerPositionX,startScaffoldPositionY+ROPE_LENGTH);
		 GLine scaffoldTop = new GLine(centerPositionX-BEAM_LENGTH,startScaffoldPositionY,centerPositionX,startScaffoldPositionY);
		 GLine scaffoldPole = new GLine(centerPositionX-BEAM_LENGTH,startScaffoldPositionY,centerPositionX-BEAM_LENGTH,startScaffoldPositionY+SCAFFOLD_HEIGHT);
		 scaffold.add(scaffoldTop);
		 scaffold.add(scaffoldPole);
		 scaffold.add(rope);
		 this.add(scaffold); 
	 }
	 
	 private void prepareLabels(){
		 double centerPositionX = this.getWidth()/2;
		 double startScaffoldPositionY = this.getHeight()/16;
		 riddleWord = new GLabel("",centerPositionX-HIP_WIDTH-FOOT_LENGTH,startScaffoldPositionY+ROPE_LENGTH+HEAD_RADIUS*2+BODY_LENGTH+LEG_LENGTH+60);
		 riddleWord.setFont("sense-bold-32");
		 incorrectGuess = new GLabel("",centerPositionX-HIP_WIDTH-FOOT_LENGTH,startScaffoldPositionY+ROPE_LENGTH+HEAD_RADIUS*2+BODY_LENGTH+LEG_LENGTH+80);
		 this.add(riddleWord);
		 this.add(incorrectGuess);
		 
	 }
	 
	 private void prepareMan(){
		 man = new GCompound();
		 this.add(man);	
		 
		 double centerPositionX = this.getWidth()/2;
		 double startScaffoldPositionY = this.getHeight()/16;
		 head = new GOval(centerPositionX-HEAD_RADIUS,startScaffoldPositionY+ROPE_LENGTH,HEAD_RADIUS*2,HEAD_RADIUS*2);
		 body = new GLine(centerPositionX,startScaffoldPositionY+ROPE_LENGTH+HEAD_RADIUS*2,centerPositionX,startScaffoldPositionY+ROPE_LENGTH+HEAD_RADIUS*2+BODY_LENGTH);
		 
		 leftArm = new GCompound();
		 GLine upperArmLeft = new GLine(centerPositionX,startScaffoldPositionY+ROPE_LENGTH+HEAD_RADIUS*2+ARM_OFFSET_FROM_HEAD,centerPositionX-UPPER_ARM_LENGTH,startScaffoldPositionY+ROPE_LENGTH+HEAD_RADIUS*2+ARM_OFFSET_FROM_HEAD);
		 GLine lowerArmLeft = new GLine(centerPositionX-UPPER_ARM_LENGTH,startScaffoldPositionY+ROPE_LENGTH+HEAD_RADIUS*2+ARM_OFFSET_FROM_HEAD,centerPositionX-UPPER_ARM_LENGTH,startScaffoldPositionY+ROPE_LENGTH+HEAD_RADIUS*2+ARM_OFFSET_FROM_HEAD+LOWER_ARM_LENGTH);
		 leftArm.add(upperArmLeft);
		 leftArm.add(lowerArmLeft);
		 
		 
		 rightArm = new GCompound();
		 GLine upperArmRight = new GLine(centerPositionX,startScaffoldPositionY+ROPE_LENGTH+HEAD_RADIUS*2+ARM_OFFSET_FROM_HEAD,centerPositionX+UPPER_ARM_LENGTH,startScaffoldPositionY+ROPE_LENGTH+HEAD_RADIUS*2+ARM_OFFSET_FROM_HEAD);
		 GLine lowerArmRight = new GLine(centerPositionX+UPPER_ARM_LENGTH,startScaffoldPositionY+ROPE_LENGTH+HEAD_RADIUS*2+ARM_OFFSET_FROM_HEAD,centerPositionX+UPPER_ARM_LENGTH,startScaffoldPositionY+ROPE_LENGTH+HEAD_RADIUS*2+ARM_OFFSET_FROM_HEAD+LOWER_ARM_LENGTH);
		 rightArm.add(upperArmRight);
		 rightArm.add(lowerArmRight);
		 
		 leftLeg = new GCompound();
		 GLine hipLeft = new GLine(centerPositionX,startScaffoldPositionY+ROPE_LENGTH+HEAD_RADIUS*2+BODY_LENGTH,centerPositionX-HIP_WIDTH,startScaffoldPositionY+ROPE_LENGTH+HEAD_RADIUS*2+BODY_LENGTH);
		 GLine legLeft = new GLine(centerPositionX-HIP_WIDTH,startScaffoldPositionY+ROPE_LENGTH+HEAD_RADIUS*2+BODY_LENGTH,centerPositionX-HIP_WIDTH,startScaffoldPositionY+ROPE_LENGTH+HEAD_RADIUS*2+BODY_LENGTH+LEG_LENGTH);
		 leftLeg.add(hipLeft);
		 leftLeg.add(legLeft);
		 
		 rightLeg = new GCompound();
		 GLine hipRight = new GLine(centerPositionX,startScaffoldPositionY+ROPE_LENGTH+HEAD_RADIUS*2+BODY_LENGTH,centerPositionX+HIP_WIDTH,startScaffoldPositionY+ROPE_LENGTH+HEAD_RADIUS*2+BODY_LENGTH);
		 GLine legRight = new GLine(centerPositionX+HIP_WIDTH,startScaffoldPositionY+ROPE_LENGTH+HEAD_RADIUS*2+BODY_LENGTH,centerPositionX+HIP_WIDTH,startScaffoldPositionY+ROPE_LENGTH+HEAD_RADIUS*2+BODY_LENGTH+LEG_LENGTH);
		 rightLeg.add(hipRight);
		 rightLeg.add(legRight);
		 
		 leftFoot = new GLine(centerPositionX-HIP_WIDTH,startScaffoldPositionY+ROPE_LENGTH+HEAD_RADIUS*2+BODY_LENGTH+LEG_LENGTH,centerPositionX-HIP_WIDTH-FOOT_LENGTH,startScaffoldPositionY+ROPE_LENGTH+HEAD_RADIUS*2+BODY_LENGTH+LEG_LENGTH);
		 rightFoot = new GLine(centerPositionX+HIP_WIDTH,startScaffoldPositionY+ROPE_LENGTH+HEAD_RADIUS*2+BODY_LENGTH+LEG_LENGTH,centerPositionX+HIP_WIDTH+FOOT_LENGTH,startScaffoldPositionY+ROPE_LENGTH+HEAD_RADIUS*2+BODY_LENGTH+LEG_LENGTH);
	  
	 }
	private void addNextBodyPart(){
		turns++;
		switch(turns){
		case 1:
			man.add(head);
			break;
		case 2:
			man.add(body);
			break;
		case 3:
			man.add(leftArm);
			break;
		case 4:
			man.add(rightArm);
			break;
		case 5:
			man.add(leftLeg);
			break;
		case 6:
			man.add(rightLeg);
			break;
		case 7:
			man.add(leftFoot);
			break;
		case 8:
			man.add(rightFoot);
			break;		
		}
	 
	}

	/** Resets the display so that only the scaffold appears */
	public void reset() {
		
		this.removeAll();
		showScaffold();
		prepareMan();
		prepareLabels();
		turns = 0;
	}
	
	/**
	* Updates the word on the screen to correspond to the current
	* state of the game. The argument string shows what letters have
	* been guessed so far; unguessed letters are indicated by hyphens.
	*/
	public void displayWord(String word) {
	/* You fill this in */
		riddleWord.setLabel(word);	
	}
	/**
	* Updates the display to correspond to an incorrect guess by the
	* user. Calling this method causes the next body part to appear
	* on the scaffold and adds the letter to the list of incorrect
	* guesses that appears at the bottom of the window.
	*/
	public void noteIncorrectGuess(char letter) {
		String curIncorrectString = incorrectGuess.getLabel() + Character.toString(letter);
		incorrectGuess.setLabel(curIncorrectString);
		addNextBodyPart();
	}
	/* Constants for the simple version of the picture (in pixels) */
	private static final int SCAFFOLD_HEIGHT = 360;
	private static final int BEAM_LENGTH = 144;
	private static final int ROPE_LENGTH = 18;
	private static final int HEAD_RADIUS = 36;
	private static final int BODY_LENGTH = 144;
	private static final int ARM_OFFSET_FROM_HEAD = 28;
	private static final int UPPER_ARM_LENGTH = 72;
	private static final int LOWER_ARM_LENGTH = 44;
	private static final int HIP_WIDTH = 36;
	private static final int LEG_LENGTH = 108;
	private static final int FOOT_LENGTH = 28;

}
