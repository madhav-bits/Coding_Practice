/*
*
//******************************************2309. Greatest English Letter in Upper and Lower Case.********************************************

https://leetcode.com/problems/greatest-english-letter-in-upper-and-lower-case/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"lEeTcOdE"
"arRAzFif"
"AbCdEfGhIjK"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. We iter. over array and mark occurrance of upper, lower case chars in two arrays, later we iter. over from the back 
// and return the first char which occurred in both arrays. If no such char present we return empty array.







class Solution {
public:
    string greatestLetter(string s) {
        bool lowerCase[26],upperCase[26];
        memset(lowerCase, false, sizeof(lowerCase));
        memset(upperCase, false, sizeof(upperCase));
        for(char&ch:s) {
            if(isupper(ch)) upperCase[ch-'A']=true;							// Marking uppercase char has occurred.
            else lowerCase[ch-'a']=true;									// Marking lowercase char has occurred.
        }
        for(int i=25;i>=0;i--) {											// Iter. from greater to lower chars.
            if(lowerCase[i] && upperCase[i]) return string(1,'A'+i);		// If both upper, lowercase char occurred, we return the uppercase char as string.
        }
        return "";															// Return empty string if no char occurred in both upper, lowerCase.
    }
};

