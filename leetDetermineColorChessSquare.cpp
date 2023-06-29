/*
*
//******************************************************1812. Determine Color of a Chessboard Square.******************************************************

https://leetcode.com/problems/determine-color-of-a-chessboard-square/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"a1"
"e8"
"h3"
"d6"
"g6"
"c7"



// Time Complexity: O(1).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(1).	
// This algorithm is observation based. We form conditions to determine black/white colors based on row, cols of the chessboard.






class Solution {
public:
    bool squareIsWhite(string s) {
        // if(s[0]=='a' || s[0]=='c' || s[0]=='e' || s[0]=='g') return ((s[1]-'0')%2==0);
        // return ((s[1]-'0')%2!=0);
        int col=s[0]-'a', row=s[1]-'0';
        if ((col%2!=0 && row%2!=0) || (col%2==0 && row%2==0)) return true;
        return false;
    }
};
