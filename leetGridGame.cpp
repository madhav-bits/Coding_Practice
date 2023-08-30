/*
*
//**********************************************************2017. Grid Game.**********************************************************

https://leetcode.com/problems/grid-game/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[2,5,4],[1,5,1]]
[[3,3,1],[8,5,2]]
[[1,3,1,15],[1,3,3,1]]
[[1,13,21,15,24,6,15,27,5,13,9],[11,3,5,21,6,17,12,1,3,15,14]]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Prefix Sum based. We first calculate the suffixSum of all nums in first row. While iter. over the array, when at index 'i', we assume that 
// the first player takes the turn at this index in his play, if he takes a turn at index 'i' and uses all first row indices till 'i' and [i,n-1] indices in 
// second row, the second player will be left with [i+1,n-1] in first row and [0,i-1] in second row, two possible ways avaiable for second player to collect 
// max coins is using all left out coins as mentioned above in any ONE of the two rows. So, at every step we get the max of the two possibilities and track 
// the min of the max possibility in each index and return this min value. 







class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long suffix1=accumulate(grid[0].begin(), grid[0].end(), 0ll);
        long long int prefix2=0, res=suffix1;
        for(int i=0;i<grid[0].size();i++) {
            suffix1-=grid[0][i];											// Updating suffixSum to reflect sum of collectable nums in first row.
            if(max(suffix1, prefix2)<res) res=max(suffix1, prefix2);		// Tracking min of the max of two new possibilities at every index.
            prefix2+=grid[1][i];											// Updating sum of collectable nums in second row.
        }
        return res;															// Returning the min possible points that second player will win.
    }
};

