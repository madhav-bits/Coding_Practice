/*
*
//******************************************2828. Check if a String Is an Acronym of Words.******************************************

https://leetcode.com/problems/check-if-a-string-is-an-acronym-of-words/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["never","gonna","give","up","on","you"]
"ngguoy"
["an","apple"]
"a"
["alice","bob","charlie"]
"abc"
["ab","bc"]
"abc"
["cb","ba","aa"]
"abc"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. As we are forming acronym form first chars of words in str, we check whether acronym and array have same length, if no
// we return false,as it can't be acronym. Now, we iter. over array and acronym at same time and check if curr. str's first char and acronym's curr. char are 
// same else we return false, if we reached end of iter, we return true.







class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        if(words.size()!=s.length()) return false;							// If unequal length, return false.
        for(int i=0;i<words.size();i++) {									// Check first chars match the chars of acronym.
            if(words[i][0]!=s[i]) return false;								// If first char doens't match, we return false.
        }
        return true;														// If it's acronym, we return true.
    }
};

