package CTCI;


/*
 * 
 * 1-8) Assume you have a method isSubstring which checks if one word is a substring of another. Given two strings, s1 and s2, write code to 
 * check if s2 is a rotation of s1 using only one call to isSubstring (i.e., “waterbottle” is a rotation of “erbottlewat”).
 * 
 * 
 * 
 * //Time Complexity: O(m*n).												// Fn. which says str2 is substring of str1 or not?
   //Space Complexity: O(n).
 *
 */
 


//Time Complexity: O(m*n).													// Fn. which says str2 is substring of str1 or not?
//Space Complexity: O(n).


// We first check whether they have equal length strings or not? If not return false stringhtforward. If not append a string to itself, if the next
// string is reversed form first string,then it will be substirng of this newly formed string.
//Ex: "apple" and "pplea"  First string modified to "appleapple", and now "pplea" can be found from index->1 to index->5 in the newly formed string.
// As, string2 a rotated form of original stirng1


public class ArraysStrings8 {

	static boolean isSubstring(StringBuffer sb1, StringBuffer sb2) {		// API, need not give full implementation.
		return true;
	}

	static boolean isRotation(StringBuffer sb1, StringBuffer sb2) {
		if(sb1.length()!=sb2.length()) return false;
		sb1.append(sb1);													// Appending string into itself.
		System.out.println("Updated sb1: "+sb1);
		return (isSubstring(sb2,sb1));										// Checking if str2 can be found as substring in newly formed str1.
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
//		double d=1_2_3;
		int d=12_3;
		System.out.println(d);
		StringBuffer sb1=new StringBuffer("erbottlewat");
		StringBuffer sb2= new StringBuffer("waterbottle");
		boolean res=isRotation(sb1, sb2);
		System.out.println("They are rotated strings."+res);
		
		
	}

}
