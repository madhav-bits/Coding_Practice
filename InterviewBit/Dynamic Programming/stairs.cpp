/*
*
//*******************************************************************Stairs.*******************************************************


https://www.interviewbit.com/problems/stairs/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


3


7

12

16



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Dynamic Programming based. We start from the base cases. We build on the #steps starting from 1 to n. As, #ways to 
// a step, depends on #ways to step-1, step-2, we add #ways to both lower steps, to get #ways to curr. step. Thus, at end, we get #ways to 
// given step number.








int Solution::climbStairs(int target) {
    if(target<=1) return 1;													// Base case.
    vector<int>dp(target+1);												// Decl. DP array.
    dp[0]=1;dp[1]=1;														// Init. base cases.
    for(int i=2;i<=target;i++){												// Building the DP array.
        dp[i]=dp[i-1]+dp[i-2];												// Updating curr. index based on prev. 2 steps values.
    }
    return dp[target];														// Return #ways to target step number.
}
