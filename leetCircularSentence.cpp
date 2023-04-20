/*
*
//******************************************************2490. Circular Sentence.******************************************************

https://leetcode.com/problems/circular-sentence/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"leetcode exercises sound delightful"
"eetcode"
"Leetcode is cool"
"HELLO"
"hello oworld dello Oorlh"
"abcd defG Gjkl lmna"
"a a a a a b"
"a aa a a a"
"a abc cbe egh ha"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, we store the latest non-space char, we compare it with the first char of next word, if they dont match we return false. As it's circular string we also 
// compare the first and the last char of the given string. If we dont observe any mismatches for all the checks, we return true.







class Solution {
public:
    bool isCircularSentence(string s) {
        if(s[0]!=s.back()) return false;																// Comparing first, last char as it's circular string.
        char prev=s[0];																					// Storing prev./latest non-space char.
        for(int i=1;i<s.length();i++) {																	// Iter. over given string.
            if(s[i-1]==' ' && s[i]!=prev) return false;													// Comparing last char of last word and first char of curr. word, if not eq. we return false.
            if(s[i]!=' ') prev=s[i];																	// Storing latest non-space char.
        }
        return true;																					// Return true for circular strings.
    }
};
