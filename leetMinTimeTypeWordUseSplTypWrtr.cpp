/*
*
//********************************************1974. Minimum Time to Type Word Using Special Typewriter.*****************************************

https://leetcode.com/problems/minimum-time-to-type-word-using-special-typewriter/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"abc"
"bzca"
"jlabjlalibjsl"
"cfagtgjzleljs"
"dcba"
"abcdef"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is observation based. Here, at every step we decide on whether to board the board CW or ACW for optimum moves each time and write the char.
// We calc. diff b/w curr. and prev. char to get gap b/w, we apply mod to get dist b/w them. As, we can also move in other drn, we calc. 26-curr. which gives
// other drn. moves, we use the minm of them and add it to res, we return res at the end of iter.







class Solution {
public:
    int minTimeToType(string word) {
        int res=0;
        char prev='a';
        for(char &ch:word) {
            int dist=abs(ch-prev);											// Calc. dist b/w curr. and prev. char.
            dist=min(dist, 26-dist);										// Using minm. of the moves in both drns
            res+=dist;														// Adding minm. moves to res.
            prev=ch;
        }
        return res+word.length();											// Returning minm. #moves needed to type the given word.
    }
};

