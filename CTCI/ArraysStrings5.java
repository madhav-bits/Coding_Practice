package CTCI;


/*
 * 
 * 1-5) Write a method to replace all spaces in a string with ‘%20’.
 * 
 * 
 * 
 * //Time Complexity: O(n).
   //Space Complexity: O(n).
 *
 */
 


//Time Complexity: O(n).
//Space Complexity: O(n).


// We create another stringbuffer, and append "%20" whenever we encounter ' ' in orig. string, else append the char into stringbuffer.


public class ArraysStrings5 {

	
	static String replaceChar(StringBuffer s) {
//		s=s.replace(" ","%20");												// This does the replacing stuff in a single line of code.
		StringBuffer sb2= new StringBuffer("");
		int len=s.length();
		for(int i=0;i<len;i++) {
			if(s.charAt(i)==' ') {											// If ' ' encountered, append "%20".
				sb2.append("%20");
			}
			else sb2.append(s.charAt(i));									// Else, char as it is.
		}
		return sb2.toString();												// Convert stringbuffer to string and return.
	}
	
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		StringBuffer s=new StringBuffer("ab cdd  g j");
		String res=replaceChar(s);
		System.out.println("The new string: " +res);
	}

}
