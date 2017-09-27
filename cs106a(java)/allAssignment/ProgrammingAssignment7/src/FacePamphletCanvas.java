/*
 * File: FacePamphletCanvas.java
 * -----------------------------
 * This class represents the canvas on which the profiles in the social
 * network are displayed.  NOTE: This class does NOT need to update the
 * display when the window is resized.
 */


import acm.graphics.*;
import java.awt.*;
import java.util.*;

public class FacePamphletCanvas extends GCanvas 
					implements FacePamphletConstants {
	
	/** 
	 * Constructor
	 * This method takes care of any initialization needed for 
	 * the display
	 */
	public FacePamphletCanvas() {
		// You fill this in
	}

	
	/** 
	 * This method displays a message string near the bottom of the 
	 * canvas.  Every time this method is called, the previously 
	 * displayed message (if any) is replaced by the new message text 
	 * passed in.
	 */
	public void showMessage(String msg) {
		// You fill this in
		msgLabel = new GLabel(msg);
		msgLabel.setFont(MESSAGE_FONT);
		msgLabel.setLocation(getWidth()/2-msgLabel.getWidth()/2,getHeight()-BOTTOM_MESSAGE_MARGIN);
		add(msgLabel);
	}
	
	
	/** 
	 * This method displays the given profile on the canvas.  The 
	 * canvas is first cleared of all existing items (including 
	 * messages displayed near the bottom of the screen) and then the 
	 * given profile is displayed.  The profile display includes the 
	 * name of the user from the profile, the corresponding image 
	 * (or an indication that an image does not exist), the status of
	 * the user, and a list of the user's friends in the social network.
	 */
	public void displayProfile(FacePamphletProfile profile) {
		// You fill this in
		removeAll();
		if(profile!=null){
		showProfileName(profile.getName());
		showProfileImage(profile.getImage());
		showStatus(profile);
		showFriends(profile);
		}
	}
	private void showFriends(FacePamphletProfile profile){
		GLabel friendsLabel = new GLabel("Friends:");
		friendsLabel.setFont(PROFILE_FRIEND_LABEL_FONT);
		friendsLabel.setLocation(getWidth()/2-friendsLabel.getWidth()/2,pointImage.getY());
		add(friendsLabel);
		Iterator<String> it = profile.getFriends();
		int count = 0;
		while(it.hasNext()){
			GLabel curFriendLabel = new GLabel(it.next());
			curFriendLabel.setFont(PROFILE_FRIEND_FONT);
			curFriendLabel.setLocation(getWidth()/2-friendsLabel.getWidth()/2,pointImage.getY()+friendsLabel.getHeight()+curFriendLabel.getHeight()*count);
			add(curFriendLabel);
			count +=1;
		}
	}
	
	private void showStatus(FacePamphletProfile profile){
		String status = profile.getStatus();
		GLabel statusLabel = new GLabel(status);
		statusLabel.setFont(PROFILE_STATUS_FONT);
		statusLabel.setLocation(LEFT_MARGIN,pointImage.getY()+IMAGE_HEIGHT+STATUS_MARGIN);
		
		if(status.equals("")){
			statusLabel.setLabel("No current status");
		}
		else{
			status = profile.getName()+" is "+profile.getStatus();
			statusLabel.setLabel(status);
		}
		this.add(statusLabel);
	}
	
	private void showProfileImage(GImage image){
		if(image==null){
			drawRectangleWithNoImageLabel();
		}
		else{
			image.setLocation(LEFT_MARGIN, TOP_MARGIN+pointLabelName.getY());
			pointImage = image.getLocation();
		
			double kX;
			double kY;
			if(image.getWidth()>IMAGE_WIDTH){
				 kX = 1/(image.getWidth()/IMAGE_WIDTH);
			}
			else{
				 kX = IMAGE_WIDTH/image.getWidth();
			}
			if(image.getHeight()>IMAGE_HEIGHT){
				 kY = 1/(image.getHeight()/IMAGE_HEIGHT);
			}
			else{
				 kY = IMAGE_HEIGHT/image.getHeight();
			}
			image.scale(kX,kY);
			add(image);
		}
	}
	
	private void drawRectangleWithNoImageLabel(){
		GRect rect = new GRect (IMAGE_WIDTH,IMAGE_HEIGHT);
		rect.setLocation(LEFT_MARGIN, TOP_MARGIN+pointLabelName.getY());
		pointImage = rect.getLocation();
		add(rect);
		
		GLabel noImageLabel = new GLabel("No Image");
		noImageLabel.setFont(PROFILE_IMAGE_FONT);
		double pointY = rect.getY()+(rect.getHeight()/2)+(noImageLabel.getAscent()/2); 
		noImageLabel.setLocation(rect.getX()+rect.getWidth()/2-noImageLabel.getWidth()/2, pointY);
		add(noImageLabel);
	}
	
	private void showProfileName(String name){
		GLabel nameLabel = new GLabel(name);
		nameLabel.setFont(PROFILE_NAME_FONT);
		nameLabel.setColor(Color.BLUE);
		nameLabel.setLocation(LEFT_MARGIN,TOP_MARGIN+nameLabel.getHeight()/2);
		pointLabelName = new GPoint(nameLabel.getLocation());
		this.add(nameLabel);
	}
	private GPoint pointLabelName;
	private GPoint pointImage;
	private GLabel msgLabel;
}
