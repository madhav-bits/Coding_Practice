/*
*
//******************************************************2381. Shifting Letters II.******************************************************

https://leetcode.com/problems/shifting-letters-ii/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"abc"
[[0,1,0],[1,2,1],[0,2,1]]
"dztz"
[[0,0,0],[1,1,1]]
"abjalejboiadjvoiqpojiojv"
[[0,4,1],[5,7,0],[2,4,0],[3,8,0],[0,17,1],[4,9,1],[17,19,0],[21,23,0],[7,23,0]]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Mod Arithmatic based. We take an array to mark boundaries of each of the shifts and the moves they request, as the shifts overlap the 
// requests add/cancel each other. We do a prefixSum on the indices to know what would be the final #moves each index has and we apply these moves to curr. 
// char in given string and return the given string after iter.







class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        // cout<<" str len: "<<s.length()<<endl;
        int moves[s.length()];
        memset(moves, 0, sizeof(moves));
        for(vector<int>&v:shifts) {											// Marking the requested moves on the array.
            if(v[2]==0) v[2]=-1;
            moves[v[0]]+=v[2];												// Marking the start of the interval.
            if(v[1]+1<s.length()) moves[v[1]+1]+=(-v[2]);					// Negating the move after the close of the interval.
        }
        // for(int i=1;i<s.length();i++) moves[i]+=moves[i-1];
        for(int i=0;i<s.length();i++) {
            if(i>0) moves[i]+=moves[i-1];									// Doing prefixSum of moves.
            moves[i]%=26;
            moves[i]=(moves[i]+26)%26;										// Mod arithmatic to bring moves to [0,25] range.
            int psn=((s[i]-'a')+moves[i])%26;								// Calc. final char. after the moves.
            s[i]=('a'+psn);													// Updating index with the final char.
        }
        return s;															// Returning the str after applying the  shifts.
    }
};

