/*
*
//*********************************************2225. Find Players With Zero or One Losses.*********************************************

https://leetcode.com/problems/find-players-with-zero-or-one-losses/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]
[[2,3],[1,3],[5,4],[6,4]]



// Time Complexity: O(n+m).  												// n-#matches, m-range of palyer ids.
// Space Complexity: O(m).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n+m).													// n-#matches, m-range of palyer ids.
// Space Complexity: O(m).	
// This algorithm is iteration based. We maintain two arrays- one to track if an player had occurred/played atleast once, other tracks #losses a players had. 
// We iter. over matches and mark both the players to have played atleast a match in first array and we inc.the #losses of v[i][1] player in second array.
// We iter. over inc. order of players ids and add a player who played atleast once and had zero losses to zero index of res and with only 1 loss to 1 index of
// res. We return res at the end of iter.





class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>>res(2);
        bool occur[100001];
        int losses[100001];
        memset(occur, false, sizeof(occur));
        memset(losses, 0, sizeof(losses));
        for(vector<int>&v:matches) {
            occur[v[0]]=true;												// Mark both the players to have played atleast once.
            occur[v[1]]=true;
            losses[v[1]]++;													// Inc. the #losses of player.
        }
        for(int i=1;i<=100000;i++) {										// Iter. over inc. order of player ids.
            if(occur[i]==0) continue;										// If player didn't played atleast one match.
            if(losses[i]==0) res[0].push_back(i);							// If 0 matches lost.
            else if(losses[i]==1) res[1].push_back(i);						// If only 1 match lost.
        }
        return res;															// Returning 2d array of players, who played and lost 0,1 matches resp.
    }
};

