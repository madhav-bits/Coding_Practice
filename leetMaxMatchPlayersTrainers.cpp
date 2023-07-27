/*
*
//*******************************************2410. Maximum Matching of Players With Trainers.***************************************

https://leetcode.com/problems/maximum-matching-of-players-with-trainers/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[4,7,9]
[8,2,5,8]
[1,1,1]
[10]
[5,6,4,3,2,5,6,7,5,6,7,8,9,8,7,6,5,4,2,9,1,6,8,9,8,7,6,5,4,2]
[6,7,5,3,2,1,6,7,8,9,8,6,4,5,3,4,3,2,6,7,5,6,3]



// Time Complexity: O(nlogn+mlogn).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlong+mlogm).
// Space Complexity: O(1).	
// This algorithm is Greedy based. We assign the trainer with lowest ability >= player ability, so that players with greater ability would have more greater 
// ability trainers and thus increasing their prob. of getting matched with a trainer. Thus we get max. matching b/w players and trainers.







class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int res=0, j=0;
        sort(players.begin(), players.end());								// Sort trainers, players based on their ability.
        sort(trainers.begin(), trainers.end());
        for(int i=0;i<players.size() && j<trainers.size();i++) {
            while(j<trainers.size() && trainers[j]<players[i]) j++;			// Skipping all trainers<curr. player, as they can't be matched with greater plyrs either.
            if(j++<trainers.size()) res++;									// Matching curr. plyr with trainer with least ability>=curr. plyr ability.
        }
        return res;															// Returning maxm. #matching b/w players and trainers.
    }
};

