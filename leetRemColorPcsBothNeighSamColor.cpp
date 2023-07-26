/*
*
//************************************2038. Remove Colored Pieces if Both Neighbors are the Same Color.*************************************

https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"AAABABB"
"AA"
"ABBBBBBBAAA"
"ABABABABABAAABBABBABAABAABABBBABABBBBBABABAAABABBBABAABBBABABABABABBABAAAABBBBBAAABBAB"
"AAABBB"
"AAABBBAAA"
"AAABBBBBBBAAAA"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is observation based. One observation is that since we can't entirely remove a patch of contin. A/B s making their adjacent patches now
// adj. and possib. leading to >=3 contin. A/Bs. We can safely conclude that each patch of same values are independent of each other. We iter. over array and 
// collect #A/Bs in each patch of same values, when we touch next patch, we calc. #moves we can make and add to that player accordingly and move to next index.
// At the end of iter. as alice needs more moves to win, we return if aliceMoves>bobMoves. 







class Solution {
public:
    bool winnerOfGame(string s) {
        int aliceMoves=0, bobMoves=0;										// Tracks #moves Alice, Bob can make.
        int cnt=1;
        for(int i=1;i<=s.length();i++) {
            if(i==s.length() || s[i]!=s[i-1]) {								// As we touch new patch of conti. values.
                if(s[i-1]=='A' && cnt>2) aliceMoves+=(cnt-2);				// We calc. #moves from prev. patch.
                else if(s[i-1]=='B' && cnt>2) bobMoves+=(cnt-2);
                cnt=0;														// Resetting patch length as new one started now.
            }
            cnt++;															// Inc. the patch length by 1.
        }
        return (aliceMoves>bobMoves);										// Returning if Alice can win based on #moves both players can make.
    }
};

