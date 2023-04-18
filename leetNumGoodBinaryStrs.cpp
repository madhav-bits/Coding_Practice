/*
*
//******************************************************2533. Number of Good Binary Strings.******************************************************

https://leetcode.com/problems/number-of-good-binary-strings/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


2
3
1
2
4
4
4
3
6
10
2
3
948
8584
35
55



// Time Complexity: O(n).																				// n-maxLength of the substring.
// Space Complexity: O(n).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).																				// n-maxLength of the substring.
// Space Complexity: O(n).	
// This algorithm is DP based. Here, we use DP array to store #substrings of length 'i', dp[i] #good substrings of length 'i' which ends with either 0/1. When at index 'j', we use dp[j-zeroGroup], 
// dp[j-oneGroup] to use the prev. formed #substrings of lesser length and add zeroGroup length zeroes or oneGroup length ones to them to form 'j' length curr. good substring. We collect #substrs
// of length [minLength, maxLength] and return the res.\


// First I had used 2d array to store #substrings, dp[0][i] stores #substrings which ends with '0' of length 'i'. As when populating dp[0][j] we use both dp[0][j-oneGroup] and dp[1][j-oneGroup], there
// is no need to store these two values in separate indices and we can store them in a same index which resulted in the simplified sln.







class Solution {
public:
    int goodBinaryStrings(int minLength, int maxLength, int oneGroup, int zeroGroup) {
        int mod=1000000007, res=0;
        // vector<vector<int>>dp(2, vector<int>(maxLength+1, 0));
        // dp[0][zeroGroup]=1;// #substrings of length zeroGroup ending with 0.
        // dp[1][oneGroup]=1;// #substrings of length oneGroup ending with 1.
        // for(int i=min(oneGroup, zeroGroup)+1;i<=maxLength;i++) {
        //     if(i>zeroGroup) {
        //         dp[0][i]=(0ll+dp[0][i]+dp[0][i-zeroGroup]+dp[1][i-zeroGroup])%mod;
        //     }
        //     if(i>oneGroup) dp[1][i]=(0ll+dp[1][i-oneGroup]+dp[0][i-oneGroup])%mod;
        // }
        // for(int i=minLength;i<=maxLength;i++) {
        //     res=(0ll+res+dp[0][i]+dp[1][i])%mod;
        //     // cout<<"i: "<<i<<" zero: "<<dp[0][i]<<" and ones: "<<dp[1][i]<<endl;
        // }
        // return res;
        
        
        vector<int>dp(maxLength+1, 0);																	// Stores #substrings of length 'i'.
        dp[0]=1;
        for(int i=min(oneGroup, zeroGroup);i<=maxLength;i++) {
            if(i>=zeroGroup) dp[i]=(0ll+dp[i-zeroGroup])%mod;											// Updating #substrings of length 'i' using 'i-oneGroup' substring as we add oneGroup ones to it.
            if(i>=oneGroup) dp[i]=(0ll+dp[i]+dp[i-oneGroup])%mod;										// Updating #substrings of length 'i' using 'i-zeroGroup' substring as we add zeroGroup 0s to it.
            if(i>=minLength) res=(0ll+res+dp[i])%mod;													// Adding #substrings of length in the range [minLength, maxLength] to res.
        }
        return res;																						// Returning #substrings of length in the range [minLength, maxLength].
    }
};
