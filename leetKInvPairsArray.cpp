/*
*
//**********************************************************629. K Inverse Pairs Array.***************************************************

Given two integers n and k, find how many different arrays consist of numbers from 1 to n such that there are exactly k inverse pairs.

We define an inverse pair as following: For ith and jth element in the array, if i < j and a[i] > a[j] then it's an inverse pair; Otherwise, it's 
not.

Since the answer may be very large, the answer should be modulo 109 + 7.

Example 1:
Input: n = 3, k = 0
Output: 1
Explanation: 
Only the array [1,2,3] which consists of numbers from 1 to 3 has exactly 0 inverse pair.
Example 2:
Input: n = 3, k = 1
Output: 2
Explanation: 
The array [1,3,2] and [2,1,3] have exactly 1 inverse pair.
Note:
The integer n is in the range [1, 1000] and k is in the range [0, 1000].




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


3
7

4
11

5
10

5
11




// Time Complexity: O(n*k).  
// Space Complexity: O(n*k).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*k).
// Space Complexity: O(n*k).	
// This algorithm is Dynamic Programming based. Here, dp[n][k] denotes max. #seq. with k inverse pairs using nums 1 to n,We start from basic 
// cases of seq. length 2,3 to n. We create a 2D array of n rows, k clmns. We formulate any index acc. to recursive relation given below.
// dp[n][k] = dp[n-1][k]+dp[n-1][k-1]+dp[n-1][k-2]+...+dp[n-1][k+1-n+1]+dp[n-1][k-n+1]	// Inter row dependency.
// dp[n-1][k] here, n would be at end of n-1 seq. dp[n-1][k-1], here, n would be before last num, thus contributing one inv. pair to the total,
// n-1 seq. would contribute k-1 to the total. This way, n could be at any psn in n seq. Thus, we sum all those possib. and assign it to dp[n][k]
// dp[n][k+1] = dp[n-1][k+1]+dp[n-1][k]+dp[n-1][k-1]+dp[n-1][k-2]+...+dp[n-1][k+1-n+1]	// Clmn wise dependency.
// Above can be modified into dp[n][k+1] = dp[n][k]+dp[n-1][k+1]-dp[n-1][k+1-n]			// Clmn wise dependency.
// We fill the 2D array, then return the index corresponding to the nums and inverse pairs.
// For num-n, n*(n-1)/2 inverse pairs are possible at max.
// This link has clear explanation for the problme, refer in case below explanation is unclear.
// https://leetcode.com/problems/k-inverse-pairs-array/discuss/104815/Java-DP-O(nk)-solution





class Solution {
public:
    int kInversePairs(int n, int k) {
        int mod=1000000007;
        if(k>n*(n-1)/2 ||k<0) return 0;
        if(k==0 || k==n*(n-1)/2) return 1;									// Edge case, we return 1.
        vector<vector<int>>dp(n+1,vector<int>(k+1,0));						// Creating a 2D array of n+1 rows, k+1 clmns.
        dp[2][0]=1;dp[2][1]=1;												// Setting up base case values.
        for(int i=3;i<=n;i++){												// Starting from third row.
            dp[i][0]=1;														// Base case for that row.
            for(int j=1;j<=min(k,i*(i-1)/2);j++){							// Going through all possib. inverse pairs for given num.
                dp[i][j]=dp[i][j-1]+dp[i-1][j];
                if(j-i>=0) dp[i][j]-=dp[i-1][j-i];							// If index valid.
                dp[i][j]=(dp[i][j]+mod)%mod;								// As, dp[i][j] is sum of two modulus nums, dp[i-1][j-1] is also mod num.
            }
        }
        return dp[n][k];													// Returning #seq. with given num. range and req. inverse pairs.
    }
};