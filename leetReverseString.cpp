/*
*
//**********************************************************344. Reverse String.***************************************************

Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


""
"a"
"abcd"
"abcde"
"hello a"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm swaps chars which are at same dist. from start and end, upto the half of the string's length.



class Solution {
public:
    string reverseString(string s) {
        int len=s.length();
        for(int i=0;i<len/2;i++){																	// Swap chars upto half of the length.
            swap(s[i], s[len-1-i]);
        }
        return s;																					// Returning the modified length.
    }
};