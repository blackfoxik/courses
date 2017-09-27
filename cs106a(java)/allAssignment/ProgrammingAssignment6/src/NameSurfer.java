/*
 * File: NameSurfer.java
 * ---------------------
 * When it is finished, this program will implements the viewer for
 * the baby-name database described in the assignment handout.
 */

import acm.program.*;

import java.awt.event.*;
import java.io.IOException;
import java.awt.*;
import javax.swing.*;

public class NameSurfer extends Program implements NameSurferConstants {

/* Method: init() */
/**
 * This method has the responsibility for reading in the data base
 * and initializing the interactors at the bottom of the window.
 */
	public void init() {
	    // You fill this in, along with any helper methods //
		this.setSize(APPLICATION_WIDTH, APPLICATION_HEIGHT);
		setInteractors();
		addActionListeners();
	
		graph = new NameSurferGraph();
		add(graph);
		//addMouseListener();
	}

/* Method: actionPerformed(e) */
/**
 * This class is responsible for detecting when the buttons are
 * clicked, so you will have to define a method to respond to
 * button actions.
 */
	public void actionPerformed(ActionEvent e) {
		// You fill this in //
		String cmd = e.getActionCommand();
		if(cmd.equals("Graph")||e.getSource()==nameTextField){
			try {
				NameSurferDataBase db = new NameSurferDataBase("");
				NameSurferEntry test = db.findEntry(nameTextField.getText());
				graph.addEntry(test);
			} catch (IOException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
		}
		if(cmd.equals("Clear")){
			graph.clear();
		}
	}
	
	private void setInteractors(){
		JLabel labelName = new JLabel("Name");
		
		nameTextField = new TextField(30); 
		nameTextField.addActionListener(this);
		
		JButton graphButton = new JButton("Graph");
		JButton clearButton = new JButton("Clear");
		
		add(labelName,SOUTH);
		add(nameTextField,SOUTH);
		add(graphButton,SOUTH);
		add(clearButton,SOUTH);
		
	}
	
	private TextField nameTextField;
	private NameSurferGraph graph;
}
