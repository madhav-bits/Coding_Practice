/*
*
//****************************************2770. Maximum Number of Jumps to Reach the Last Index.******************************************

https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,3,6,4,1,2]
2
[1,3,6,4,1,2]
3
[1,3,6,4,1,2]
0
[1,0,3,4,2]
2



// Time Complexity: O(n^2).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n).	
// This algorithm is Dynamic Programming based. Here, at every index, we check all indices>i if they satisfy the condition, if yes we give recursive call to get max. steps from 
// them add 1 step of curr. index and assign it to dp[i], if we don't find any way to reach last index from curr. index we get -1 from all the recursive calls given from here, so
// we assign dp[i]=-1 and return the same to parent call. We return dp[0] which gives max. steps from zero index to last index.

// dp[i]=0 means index not visited.
// dp[i]=-1 means visited but not was not able to reach last index.
// dp[i]=rem. values means this is the max. steps from this index to last index.







class Solution {
public:
    
    int getMaxSteps(vector<int>&v, int index, int target, vector<int>&dp) {
        // cout<<"index: "<<index<<endl;
        if(index==v.size()-1) return 0;
        if(dp[index]!=0) return dp[index];									// As index already visited, return the max. steps directly.
        int steps=-1;
        for(int j=index+1;j<v.size();j++) {									// Check all possible bigger indices.
            if((v[j]-v[index])<=target && (v[j]-v[index])>=-target && dp[j]!=-1) steps=max(steps, getMaxSteps(v, j, target, dp));// If v[j] meets conditions, get max. steps from 'j'.
        }
        dp[index]=(steps==-1)?-1:steps+1;									// If we can't reach last index, assign -1 else assign max. steps+1.
        return dp[index];													// Returning max. steps to reach last index from curr. index.
    }
    
    int maximumJumps(vector<int>& v, int target) {
        vector<int>dp(v.size(), 0);											// Tracks max. steps to reach last index from curr. index.
        return getMaxSteps(v, 0, target, dp);								// Returning max. steps to reach last index from first index.
    }
};


