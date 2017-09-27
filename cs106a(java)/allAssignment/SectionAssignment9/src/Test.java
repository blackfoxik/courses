
public class Test {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ExpandableArray myArr = new ExpandableArray();
		myArr.set(10, "tenth");
		myArr.set(2, "second");
		myArr.set(20, "twenteenth");
		System.out.println((String)myArr.get(2));
		System.out.println((String)myArr.get(10));
		System.out.println((String)myArr.get(20));
		System.out.println((String)myArr.get(15));
	}

}
