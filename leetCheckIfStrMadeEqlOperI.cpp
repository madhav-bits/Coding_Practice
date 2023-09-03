/*
*
//***************************************2839. Check if Strings Can be Made Equal With Operations I.**********************************

https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-i/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"abcd"
"cdab"
"abcd"
"dcab"



// Time Complexity: O(1).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(1).	
// This algorithm is observation based. Here, since the length of the string is 4, we only have two pairs of indices which can swap. (0,2) and (1,3) are pairs.
// We compare s[0] to t[0], if equals we go to next iter. else we swap (0,2) in s string hoping that zero index in both strs matches. We do the same with index 
// 1 too. We dont' check index 2,3 because even if chars don't match we can't swap them with 0,1 because they might have matched or else swapped with these 
// indices as they didn't match earlier, if we swap back we might make them not meet condition. Now, we return whether if two strings are equal.







class Solution {
public:
    bool canBeEqual(string s, string t) {
        if(s[0]!=t[0]) swap(s[0], s[2]);									// Swap (0,2) if curr. indices in two strs doesn't match.
        if(s[1]!=t[1]) swap(s[1], s[3]);									// Swap (1,3) if curr. indices in two strs doesn't match.
        return (s==t);														// Returning if two strings are equal after the swaps if any.
    }
};

