/*
*
//************************************1941. Check if All Characters Have Equal Number of Occurrences.**************************************

https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"abacbc"
"aaabb"
"aaabbbcccdd"
"abcabcabcddddabc"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is map based. We iter. over given string and store #occur. each char in string in occur array and track maxOccur of any char, later we iter. over occur 
// array and check if all non-zero occur.=maxOccur, else we return false, if no issues observed, we return true at the end of iter.







class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int maxOccur=0;	
        int occur[26];														// Tracks #occur of each char in the string.
        memset(occur, 0, sizeof(occur));
        for(char&ch:s) {
            if(++occur[ch-'a']>maxOccur) maxOccur=occur[ch-'a'];			// Update #occur. of each char, maxOccur of any char in the string.
        }
        for(int i=0;i<26;i++) {
            if(occur[i]!=0 && occur[i]!=maxOccur) return false;				// If any non-zero occur!=maxOccur, we return false as all occur. aren't equal.
        }
        return true;														// Returning true as all chars have occur. same #times in the string.
    }
};

