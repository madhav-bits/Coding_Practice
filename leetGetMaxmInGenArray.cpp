/*
*
//*************************************************1646. Get Maximum in Generated Array.***********************************************

https://leetcode.com/problems/get-maximum-in-generated-array/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


7
89
100
48
39


// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Dynamic Programming based. We fill the Dp array values based on rules provided. At every step, we track the maxm.
// value formed and return it at end.








class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n<=1) return n;
        vector<int>dp(n+1,0);
        dp[1]=1;
        int maxm=1;
        for(int i=2;i<=n;i++){
            if(i%2==0) dp[i]=dp[i/2];
            else dp[i]=dp[i/2]+dp[i/2+1];
            maxm=max(maxm, dp[i]);
        }
        return maxm;
    }
};