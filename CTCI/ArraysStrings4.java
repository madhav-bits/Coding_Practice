package CTCI;

/*
 * 
 *1-4) Write a method to decide if two strings are anagrams or not.

*/
 
// Time Complexity: O(n).
// Space Complexity: O(n).


//Here, I store the #occurances of all chars in Array. In the iteration of second string, I check whether those chars had occured in s or not? If they
// haven't occured in "S" as #times in "t", then return false. If the curr. char had occured in "S", then decrease it's count. 




public class ArraysStrings4 {

	static boolean checkAnagram(String s,String t) {
		if(s.length()!=t.length()) return false;
		int[] str1= new int[128];											// Stores #occurrances of chars in "S".
		
		for(int i=0;i<s.length();i++) str1[s.charAt(i)]++;					// Noting the count in string "S".
		for(int j=0;j<t.length();j++) {
			if(str1[t.charAt(j)]==0) return false;							// Curr. char haven't occurred in "S" as #times in "t".
			str1[t.charAt(j)]--;											// Dec. the count of #occurrances of char in "S".
		}
		return true;														// If all counts match, then return true.
	}
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String s=new String("ea");											// Declaring and initializing two strings.
		String t=new String("ae");
		boolean res=checkAnagram(s,t);
		System.out.println("The result is: "+res);

	}

}
