/*
*
//********************************************2124. Check if All A's Appears Before All B's.*********************************************

https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"aaabbb"
"abab"
"bbb"
"aaaaabbbb"
"aaaaabbbbbbbabbbbb"
"aaaaaaa"
"bbbbbb"
"a"
"b"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. We use a variable to indicate whether we had encountered 'b' char. in the iter.. If we encounter 'a' char after this
// variable is set, that means there is a 'b' after 'a' char, we return false then. If we finish the iter. without any issues, we return true.







class Solution {
public:
    bool checkString(string s) {
        bool found=false;
        for(char&ch:s) {
            if(ch=='b') found=true;											// Marking that an 'b' char had occurred.
            else if(found) return false;									// If 'a' occurred after 'b', we return false.
        }
        return true;														// Returning true as the string met the condition.
    }
};

