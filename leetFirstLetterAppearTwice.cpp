/*
*
//******************************************************2351. First Letter to Appear Twice.******************************************************

https://leetcode.com/problems/first-letter-to-appear-twice/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"abccbaacz"
"abcdd"
"baab"




// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is map based. Here, we use an array to trac whether if an char had occurred, if we encounter a char which had already occurred that means 
// this is the first char which occurred twice, so we return curr. char.







class Solution {
public:
    char repeatedCharacter(string s) {
        vector<bool>occur(26, false);										// Tracks if a char has occurred.
        for(char&ch:s) {
            if(occur[ch-'a']) return ch;									// If a char had already occurred, we return curr. char as this is second occurance.
            occur[ch-'a']=true;												// Marking the curr. char has occurred.
        }
        return '*';															
    }
};

