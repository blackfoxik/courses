import acm.graphics.*;
import acm.program.*;
import java.awt.*;
import java.util.*;
import java.util.List;


public class ImageProcessing extends GraphicsProgram {
	public void init(){
		setSize(600, 500);
	}
	public void run(){
		GImage originalPict = new GImage("Alien.jpg",50,50);
		GImage flippedHorizontalPict = flipHorizontal(originalPict);
		double flippedPictPositionX = originalPict.getX()+originalPict.getWidth()+50;
		flippedHorizontalPict.setLocation(flippedPictPositionX,originalPict.getY());
		add(originalPict);
		add(flippedHorizontalPict);
		
	}
	private GImage flipHorizontal(GImage pictOrigin){
		
		int[][] arrPixels = pictOrigin.getPixelArray();
		for(int i = 0; i<arrPixels.length;i++){
			arrPixels[i] = reverseArray(arrPixels[i]); 
		}
		return new GImage(arrPixels);
	}
	private int[] reverseArray(int[] array){
		for(int i=0;i<array.length/2;i++){
			int temp = array[i];
			array[i]=array[array.length-1-i];
			array[array.length-1-i] = temp;
		}
		return array;
	}
}
