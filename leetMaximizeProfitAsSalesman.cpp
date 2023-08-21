/*
*
//**********************************************2830. Maximize the Profit as the Salesman.************************************************

https://leetcode.com/problems/maximize-the-profit-as-the-salesman/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


5
[[0,0,1],[0,2,2],[1,3,2]]
5
[[0,0,1],[0,2,10],[1,3,2]]
20
[[0,4,5],[0,3,6],[6,8,10],[7,12,20],[16,17,3],[19,19,2],[16,18,5]]



// Time Complexity: O(n!).  
// Space Complexity: O(n*n!).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n!).
// Space Complexity: O(n*n!).	
// This algorithm is Dynamic Programming based. We iter. over sorted offers and try to maximize the profits obtained, when we are at an offer, we would have
// already iter. over offers which started before curr. offer and tried to maximize the profits on their end indices. Some offers might have already finished 
// curr. offer start index, we try to iter. over indices b/w prev. offer start and curr. offer start and track the max. profit and update inidces until dp[v[0]].
// As, we are using curr. offer we add max. profit till v[0]-1 and profit of curr. offer and try to maximize profit on index v[1] and move to next offer and 
// track the curr. offer start, so that we can iter. from this to next offer start and update middle indices with max profit till that index.


// dp[i]- max profit using any combi of non-overlapping offers till that index.




class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        int dp[n];
        memset(dp, 0, sizeof(dp));
        offers.push_back({n-1, n-1,0});
        sort(offers.begin(), offers.end());									// Sort the given offers.
        int prevStart=1;
        for(vector<int>&v:offers) {											// Iter. over given offers.
            for(int i=prevStart;i<=v[0];i++) {								// Iter. over indices from prev. start to curr. start and update dp[i] with max val.
                dp[i]=max(dp[i], dp[i-1]);									// Updating such that dp[i] stores max profit till curr. index.
            }
            int prev=(v[0]>0)?dp[v[0]-1]:0;									// Max profit till prev. index of curr. offer's start.
            dp[v[1]]=max(dp[v[1]], prev+v[2]);								// Add prev. index's maxProfit and curr. offer's profit and update dp[v[1]].
            prevStart=v[0]+1;												// Tracking prev. offer's start index.
        }
        return dp[n-1];														// Returning max profit till last index.
    }
};

