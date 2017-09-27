/* 
 * File: FacePamphlet.java
 * -----------------------
 * When it is finished, this program will implement a basic social network
 * management system.
 */

import acm.program.*;
import acm.graphics.*;
import acm.util.*;
import java.awt.event.*;
import javax.swing.*;

public class FacePamphlet extends Program 
					implements FacePamphletConstants {

	/**
	 * This method has the responsibility for initializing the 
	 * interactors in the application, and taking care of any other 
	 * initialization that needs to be performed.
	 */
	public void init() {
		// You fill this in
		this.setSize(APPLICATION_WIDTH,APPLICATION_HEIGHT);
		
		addInteractors();
		addActionListeners();
		db = new FacePamphletDatabase();
		canvas = new FacePamphletCanvas();
		add(canvas);
    }
    
	private void addInteractors(){
		   JLabel nameLabel = new JLabel("Name");
		   add(nameLabel,NORTH);
		   nameTextField = new JTextField(TEXT_FIELD_SIZE);
		   add(nameTextField,NORTH);
		   JButton addButton = new JButton("Add");
		   add(addButton,NORTH);
		   JButton deleteButton = new JButton("Delete");
		   add(deleteButton,NORTH);
		   JButton lookupButton = new JButton("Lookup");
		   add(lookupButton,NORTH);
		   
		   
		   statusTextField = new JTextField(TEXT_FIELD_SIZE);
		   add(statusTextField,WEST);
		   statusTextField.addActionListener(this);
		   add(new JButton("Change Status"),WEST);
		   add(new JLabel(EMPTY_LABEL_TEXT),WEST);
		   
		   pictureTextField = new JTextField(TEXT_FIELD_SIZE);
		   add(pictureTextField,WEST);
		   pictureTextField.addActionListener(this);
		   add(new JButton("Change Picture"),WEST);
		   add(new JLabel(EMPTY_LABEL_TEXT),WEST);
		   
		   addFriendTextField = new JTextField(TEXT_FIELD_SIZE);
		   add(addFriendTextField,WEST);
		   addFriendTextField.addActionListener(this);
		   add(new JButton("Add Friend"),WEST);
		   add(new JLabel(EMPTY_LABEL_TEXT),WEST);
		   
	}
    /**
     * This class is responsible for detecting when the buttons are
     * clicked or interactors are used, so you will have to add code
     * to respond to these actions.
     */
    public void actionPerformed(ActionEvent e) {
		// You fill this in as well as add any additional methods
    	String cmd = e.getActionCommand();
    	if(cmd.equals("Add")){
    		addProfile();
    	}
    	if(cmd.equals("Delete")){
    		deleteProfile();
    	}
    	if(cmd.equals("Lookup")){
    		lookupProfile();
    	}
    	if(cmd.equals("Change Status")||e.getSource()==statusTextField){
    		changeStatus();
    	}
    	if(cmd.equals("Change Picture")||e.getSource()==pictureTextField){
    		changePicture();
    	}
    	if(cmd.equals("Add Friend")||e.getSource()==addFriendTextField){
    		addFriend();
    		
    	}
	}
    
    private void addFriend(){
    	if(currentProfile != null){
			String nameFriend = addFriendTextField.getText();
			if(db.containsProfile(nameFriend)){
				currentProfile.addFriend(nameFriend);
				FacePamphletProfile profileFriend = db.getProfile(nameFriend);
				profileFriend.addFriend(currentProfile.getName());
				updateCanvas(currentProfile.getName()+" and " +nameFriend+" now are friends");
			}
			else{
				//name friend does not exist
				updateCanvas("profile with name:"+nameFriend+" does not exist");
			}
		}
		else{
			updateCanvas("you should select the profile to add friends");
		}
    }
    
    private void updateCanvas(String msg){
    	canvas.displayProfile(currentProfile);
    	canvas.showMessage(msg);
    }
    
    private void changePicture(){
    	if(currentProfile != null){
			GImage image  = getImage(pictureTextField.getText());
			currentProfile.setImage(image);
			updateCanvas("image updated to: "+pictureTextField.getText());
		}
		else{
			updateCanvas("you should select the profile to change image");
		}
    }
    
    private void changeStatus(){
		if(currentProfile != null){
			currentProfile.setStatus(statusTextField.getText());
			updateCanvas("status updated to: "+statusTextField.getText());
		}
		else{
			updateCanvas("you should select the profile to change status");
		}
		
    }
    
    private void lookupProfile(){
 		String name = nameTextField.getText();
		if(db.containsProfile(name)){
			FacePamphletProfile profile = db.getProfile(name);
			currentProfile = profile;	
			updateCanvas("profile: "+profile.toString());
			
		}
		else{
			currentProfile = null;
			updateCanvas("profile : "+name+" does't exist");
		}
		
    }
    
    private void deleteProfile(){
    	String name = nameTextField.getText();
		if(db.containsProfile(name)){
			db.deleteProfile(name);
			currentProfile = null;
			updateCanvas("profile "+name+" was deleted");
			
		}
		else{
			currentProfile = null;
			updateCanvas("profile : "+name+" does't exist");
		}
    }
    
    private void addProfile(){
    	String name = nameTextField.getText();
		if(db.containsProfile(name)){
			FacePamphletProfile profile = db.getProfile(name);
			currentProfile = profile;
			updateCanvas("profile "+name+" already exist");
		}
		else{
			FacePamphletProfile profile = new FacePamphletProfile(name);
			db.addProfile(profile);
			currentProfile = profile;
			updateCanvas("New profile created");
		}
    }
    
    
    private GImage getImage(String fileName){
    	GImage image = null;
    	 try {
    		 image = new GImage(fileName);
    	 } catch (ErrorException ex) {
    		 // Code that is executed if the filename cannot be opened.
    	 }
    	 return image;
    }
    private JTextField nameTextField;
    private JTextField statusTextField;
    private JTextField pictureTextField;
    private JTextField addFriendTextField;
    private FacePamphletDatabase db;
    private FacePamphletProfile currentProfile;
    private FacePamphletCanvas canvas;
    
}
