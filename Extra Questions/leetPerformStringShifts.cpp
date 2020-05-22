/*
*
//******************************************************1427. Perform String Shifts.***********************************************

https://leetcode.com/problems/perform-string-shifts/description/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"abc"
[[0,1],[1,2]]


"abcdefg"
[[1,1],[1,1],[0,2],[1,3]]



// Time Complexity: O(n+m).													// m-Length of shift array, n-length of string.  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n+m).													// m-Length of shift array, n-length of string.
// Space Complexity: O(1).	
// This algorithm is iteration based. We keep track of #leftMoves after going through shift array. We do %len, to dec. #leftMoves
// to be < length of string. We use the string reverse technique, to shift required number of chars.






class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int leftMoves=0, len=s.length();
        for(int i=0;i<shift.size();i++){									// Iter. over all shifts.
            if(shift[i][0]==0) leftMoves+=shift[i][1];						// We inc. the #moves to the left.
            else leftMoves-=shift[i][1];									// We dec. the #moves to the left.
        }
        leftMoves%=len;
        leftMoves=(leftMoves+len)%len;										// We use %len, to dec. #moves to <length of string.
        if(leftMoves==0) return s;											// If #moves=0, then no change required.
        
        leftMoves=len-leftMoves;											// Changing leftMoves to meet reverse params.
        reverse(s.begin(), s.end());										// Reversing the str acc. to requirement.
        reverse(s.begin(), s.begin()+leftMoves);
        reverse(s.begin()+leftMoves,s.end());
        return s;															// Returning the string.
    }
};


