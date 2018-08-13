/*
*
//************************************************************709. To Lower Case.****************************************************

Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.

 

Example 1:

Input: "Hello"
Output: "hello"
Example 2:

Input: "here"
Output: "here"
Example 3:

Input: "LOVELY"
Output: "lovely"




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"HAZaoz,"


""

"*&^(@(@Azaz"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. As we need to implement LowerCase fn. I had just checked for Block chars in the chars enocuntered in the
// iteration. If, we encounter, block chars, I had replaced those chars with their smaller case versions. At the end of iteraion, I had 
// returned the modifed str.








class Solution {
public:
    string toLowerCase(string s) {
        for(int i=0;i<s.length();i++)										// Iter. over entire given array.
            if(s[i]>=65 && s[i]<=90) s[i]+=32;								// If we encounter Block chars, convert it into Smaller Case chars.
        return s;															// Return the modified str.
    }
};