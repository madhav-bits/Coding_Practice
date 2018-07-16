package CTCI;

/*
 * 
 *1-3)  Design an algorithm and write code to remove the duplicate characters in a string without using any additional buffer. NOTE: One or two 
 * additional variables are fine. An extra copy of the array is not.
FOLLOW UP
Write the test cases for this method.

*/
 
// Time Complexity: O(n).
// Space Complexity: O(n).


//Here, at any instant, we make the all the chars till "i-1" index are unique.

public class ArraysStrings3 {

	static String removeDup(StringBuffer sb) {
		int len=sb.length();
		boolean[] arr= new boolean[128];
		int i=0,j=0;
		for(;i<sb.length();i++) {
			System.out.println("The curr. index: "+ i);
			if(arr[sb.charAt(i)]!=false) {
				while(j<sb.length() && arr[sb.charAt(j)]!=false) j++;		// Iterate till next unique char.
				if(j<sb.length()) {											// If found.
					char temp=sb.charAt(i);									// Swap current duplicate and next unique char.
					sb.setCharAt(i, sb.charAt(j));
					sb.setCharAt(j, temp);
					j++;
				}
				else														// If next unique char not found, then break;
					break;
			}
			arr[sb.charAt(i)]=true;											// Marking curr. char as visited.
				
		}
		System.out.println("string is: "+sb);
		return sb.substring(0,i).toString();								// Returning the unique chars substring.
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
//		char* c= {'a','b'};
		StringBuffer s=new StringBuffer("aaabbb");//acdbae //aadbbcdba
		String res=removeDup(s);
		System.out.println("The output is: "+res);
	}

}
