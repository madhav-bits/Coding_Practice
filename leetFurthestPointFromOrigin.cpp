/*
*
//******************************************************2833. Furthest Point From Origin.******************************************************

https://leetcode.com/problems/furthest-point-from-origin/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"L_RL__R"
"_R__LL_"
"_______"
"RL___RLR__LL_RR_L_LLR__LR___RR_LR__LLLL_LLL_RR"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. We calc. the final psn based on L, Rs in the string as these can't be changed. We get the left, right extremes of final 
// psn based on how we use blanks, if we use all blanks as Rs then we get right extreme psn, and if we use all blanks as L, then we get left extrems final psn.
// If orig. final psn is>=0, we return right extreme else we return left extreme as they would be at max. dist from origin of the both.







class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int minm=0, maxm=0, curr=0, blanks=0;
        for(char&ch:moves) {
            if(ch=='_') blanks++;											// Counting #blanks in the string.
            else if(ch=='L') curr--;										// Updating curr. psn based on L, Rs.
            else curr++;
        }
        return curr<0?blanks-curr:blanks+curr;								// If final psn is +ve, we return right extreme else we return left extreme.
    }
};

