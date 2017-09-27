import acm.program.*;
import acm.io.*;
import acm.graphics.*;

import javax.swing.*;

import java.awt.event.*;
import java.util.*;

public class UsingInteractors extends GraphicsProgram {
	public void init(){
		boxes = new HashMap<String,Box>();
		setControlPanel();		
		addMouseListeners();
		addActionListeners();
		
	}
	private void setControlPanel(){
		JLabel labelName = new JLabel("Name");
		
		textField = new JTextField(20);
		textField.addActionListener(this);
		
		JButton addButton = new JButton ("Add");
		JButton removeButton = new JButton ("Remove");
		JButton clearButton = new JButton ("Clear");
	
		add(labelName,SOUTH);
		add(textField,SOUTH);
		add(addButton,SOUTH);
		add(removeButton,SOUTH);
		add(clearButton,SOUTH);
	}
	public void actionPerformed(ActionEvent e){
		String cmd = e.getActionCommand().toString();
		
		if(cmd.equals("Add")||e.getSource()==textField){
			Box newBox = new Box(textField.getText());
			newBox.setLocation(getWidth()/2-newBox.getWidth()/2, getHeight()/2-newBox.getHeight()/2);
			boxes.put(textField.getText(), newBox);
			add(newBox);
		}
		
		if(cmd.equals("Remove")){
			String boxKey = textField.getText();
			GObject objForRemove = boxes.get(boxKey);
			if(objForRemove != null){
				remove(objForRemove);
				boxes.remove(boxKey);
			}
		}
		if(cmd.equals("Clear")){
			removeAll();
			boxes.clear();
		}
		
	}
	public void mousePressed(MouseEvent e){
		GObject objAtMousePoint = getElementAt(e.getX(),e.getY());
				if(objAtMousePoint!=null){
					currMoveObj = objAtMousePoint;
					deltaX = e.getX() - currMoveObj.getX();
					deltaY = e.getY() - currMoveObj.getY();
				}
	}
	
	public void mouseReleased(MouseEvent e){
		currMoveObj = null;
		deltaX = 0;
		deltaY = 0;
	}
	public void mouseDragged(MouseEvent e){
		if(currMoveObj != null){
			currMoveObj.setLocation(e.getX()-deltaX, e.getY()-deltaY);
		}
	}
	private HashMap<String,Box> boxes;
	private JTextField textField;
	private GObject currMoveObj;
	private double deltaX;
	private double deltaY;

}


