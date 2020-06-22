/*
*
//************************************1374. Generate a String With Characters That Have Odd Counts.***********************************

https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts/description/


Given an integer n, return a string with n characters such that each character in such string occurs an odd number of times.

The returned string must contain only lowercase English letters. If there are multiples valid strings, return any of them.  

 

Example 1:

Input: n = 4
Output: "pppz"
Explanation: "pppz" is a valid string since the character 'p' occurs three times and the character 'z' occurs once. Note that there 
are many other valid strings such as "ohhh" and "love".
Example 2:

Input: n = 2
Output: "xy"
Explanation: "xy" is a valid string since the characters 'x' and 'y' occur once. Note that there are many other valid strings such 
as "ag" and "ur".
Example 3:

Input: n = 7
Output: "holasss"
 

Constraints:

1 <= n <= 500




*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.

4

3

1

23

33

30



// Time Complexity: O(n).													// n- length of the string requested for.
// Space Complexity: O(1).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// n- length of the string requested for.
// Space Complexity: O(1).	
// This algorithm is observation based. Here, we print n-1 time char 'a', if (n-1) is even, to make it odd numbered char., we will add 
// the last char also an 'a', if it is odd, we add new char 'b', since it is added only once, it is added odd num. of times.








class Solution {
public:
    string generateTheString(int n) {
        string res="";
        for(int i=0;i<n-1;i++) res+='a';									// Adding (n-1) times char 'a'.
        if(n%2==1) res+='a';												// If n is odd, (n-1) is even, we make one more 'a' to make it odd numbered.
        else res+='b';														// If n is even, (n-1) is even, we add another char 'b'.
        return res;															// Returning the formed string.
    }
};

