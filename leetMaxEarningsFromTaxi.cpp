/*
*
//******************************************************2008. Maximum Earnings From Taxi.******************************************************

https://leetcode.com/problems/maximum-earnings-from-taxi/





*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


5
[[2,5,4],[1,5,1]]
20
[[1,6,1],[3,10,2],[10,12,3],[11,12,2],[12,15,2],[13,18,1]]



// Time Complexity: O(n+m+mlogm).											// n-#psns, m-#rides provided.
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n+m+mlogm).											// n-#psns, m-#rides provided.
// Space Complexity: O(n).	
// This algorithm is Dynamic Programming based. Here, since we observe overlapping subproblems and we have to maximize the earning, so we try to maximize 
// earning at every step and use it to maximize earnings for future indices, we use DP array to track max. profit that can be earned till that index, we use
// dp[i]=max(dp[i], dp[i-1]) to ensure we dont' miss out max. possible earning from trips closed before curr. index. When, at a psn, we iter. over all trips,
// which start at curr. psn and use their end psns and maximize earnings for that psn. At the end of iter. we return max. profit earned till last psn 
// by dp.back()








class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        vector<long long int>dp(n+1,0);
        sort(rides.begin(), rides.end());									// Sort the rides based on their start psns.
        int j=0;
        for(int i=1;i<=n;i++) {
            dp[i]=max(dp[i], dp[i-1]);										// Maximize earnings till 'i' psn.
            while(j<rides.size() && rides[j][0]==i) {						// Iter. over all rides which start at curr. psn and maximize future psns.
                int earn=rides[j][1]-rides[j][0]+rides[j][2];
                dp[rides[j][1]]=max(dp[rides[j][1]], dp[i]+earn);			// Updating max. earning for future psns.
                j++;														// Moving iter. to next ride.
            }
        }
        
        return dp.back();													// Returning max. earnings till n psns.
    }
};

