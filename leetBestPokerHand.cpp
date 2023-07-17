/*
*
//******************************************************2347. Best Poker Hand.******************************************************

https://leetcode.com/problems/best-poker-hand/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[13,2,3,1,9]
["a","a","a","a","a"]
[4,4,2,4,4]
["d","a","a","b","c"]
[10,10,2,12,9]
["a","b","c","a","d"]
[10,10,10,10,9]
["a","b","c","d","d"]



// Time Complexity: O(1).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(1).	
// This algorithm is map based. We iter. over given set of cards and store #occur. of each rank and suit, we apply conditions in order of preference to
// determine the best poker hand.







class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        vector<int>occurRanks(14,0);
        bool isFlush=true;
        int maxRep=0;
        for(int i=0;i<ranks.size();i++) {
            if(++occurRanks[ranks[i]]>maxRep) maxRep=occurRanks[ranks[i]];	// Tracking #occur. of each rank and suit.
            if(suits[i]!=suits[0]) isFlush=false;
        }
        if(isFlush) return "Flush";											// If all suits are of same type, return "Flush".
        if(maxRep>=3) return "Three of a Kind";								// If >=3 ranks are of same type, return "Three of a Kind".
        else if(maxRep==2) return "Pair";									// If 2 ranks are of same type, return "Pair".
        return "High Card";													// Return "High Card" if none of the above conditions met.
    }
};

