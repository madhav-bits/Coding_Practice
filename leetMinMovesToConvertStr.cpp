/*
*
//******************************************************2027. Minimum Moves to Convert String.******************************************************

https://leetcode.com/problems/minimum-moves-to-convert-string/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"XXX"
"XXOX"
"OOOO"
"XOXXOXOOXOXOOXXOXXOOXOXO"
"XOXXOX"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Greedy based. Here, we greedily convert the first occurred 'X' and it's two next indices and count this move as this is the only way this 'X' could be 
// converted, as next two indices are covered, we move to i+3 and we rep. As we aren't revisiting any index and we aren't making any unncessary moves, we are bound to get 
// minm. #moves.







class Solution {
public:
    int minimumMoves(string s) {
        int res=0;
        for(int i=0;i<s.length();i++) {
            if(s[i]=='X') {													// Greedily converting first encountered 'X' and two next indices.
                res++;
                i+=2;
            }
        }
        return res;															// Returning the minm. #moves to convert entire string to 'O's.
    }
};

