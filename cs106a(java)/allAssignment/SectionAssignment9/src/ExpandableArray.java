
/**
* This class provides methods for working with an array that expands
* to include any positive index value supplied by the caller.
*/
public class ExpandableArray {
	/**
	* Creates a new expandable array with no elements.
	*/
	public ExpandableArray() {
		//You fill in the implementation . . .
		innerArray = new Object[1];
	}
	/**
	* Sets the element at the given index position to the specified.
	* value. If the internal array is not large enough to contain that
	* element, the implementation expands the array to make room.
	*/
	public void set(int index, Object value) {
		// You fill in the implementation . . .
		if(index>=innerArray.length){
			expandArray(index);
			innerArray[index] = value;
		}
		else{
			innerArray[index] = value;
		}
	}
	private void expandArray(int size){
		
		//Object[] copy = new Object[innerArray.length];
		Object[] copy = innerArray.clone();
		innerArray = new Object[size+1];
		for(int i = 0; i < copy.length; i++){
			innerArray[i] = copy[i];
		}
	}
	/**
	* Returns the element at the specified index position, or null if
	* no such element exists. Note that this method never throws an
	* out-of-bounds exception; if the index is outside the bounds of
	* the array, the return value is simply null.
	*/
	public Object get(int index) {
		//You fill in the implementation . . .
		if(index>=innerArray.length){
			return null;
		}
		else{
			return innerArray[index];
		}
	}
	private Object[] innerArray;
}
