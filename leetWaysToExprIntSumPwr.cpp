/*
*
//******************************************2787. Ways to Express an Integer as Sum of Powers.*****************************************

https://leetcode.com/problems/ways-to-express-an-integer-as-sum-of-powers/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


10
2
4
1
5
2
300
2
300
1
300
3
234
4



// Time Complexity: O(n*n).											// n-target number. In case power=1, target=n.
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*n).											// n-target number. In case power=1, target=n.
// Space Complexity: O(n).	
// This algorithm is Dynamic Programming based.  Since we are trying to get combination of powers, we iter. over each of nums in a sequence so that duplicate combination can't 
// be formed, we iter. nums until their power value<=target. For each num and it's power, we iter. over range of integers to form highest to least so that each curr. num's 
// power don't get added on top of each other twice, we use dp[i]+=dp[i-pow(num,x)]. After iter. over all possible nums and it's powers, we return dp[target].







class Solution {
public:
    int numberOfWays(int target, int x) {
        int res=0, mod=1000000007;
        int dp[target+1];
        memset(dp, 0, sizeof(dp));
        dp[0]=1;															// Base condition, as zero had already occurred.
        int num=1;
        int val=pow(num, x);
        while(val<=target) {												// We iter. until power value<=target.
            for(int i=target;i>=val;i--) {									// Iter. from greater to lower num to avoid duplicate usage of curr. num and it's power.
                if(dp[i-val]!=0) dp[i]=(0ll+dp[i]+dp[i-val])%mod;			// Updating occur. of curr. int based on occur. of (curr. int-curr. power value).
            }
            val=pow(++num, x);												// Calc. power of next number.
        }
        return dp[target];													// Returning #unique ways of choosing nums where sum of nums power vals=target.
    }
};


