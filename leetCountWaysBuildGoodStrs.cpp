/*
*
//******************************************************2466. Count Ways To Build Good Strings.******************************************************

https://leetcode.com/problems/count-ways-to-build-good-strings/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


3
3
1
1
2
3
1
2
450
100000
234
23



// Time Complexity: O(n+m).													//n-high var, m-max. of (zero, one) var
// Space Complexity: O(m).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n+m).													//n-high var, m-max. of (zero, one) var
// Space Complexity: O(m).	
// This algorithm is Dynamic Programming based. As #ways to build string of length 'i' depends on #ways to build string of length 'i-zero' and 'i-one', as we
// are using blocks zero, one length chars. So, we use a dp array of max(zero, one)+1 so that 'i-zero' or 'i-one' don't overlap with 'i' while calc. #ways.
// We set dp[0]=1, as it indicates valid empty string. We keep on iter. and calc. #ways to build strings of length 'i' in this way, we only count those #ways
// where string length>=low and length<=high and return their total at the end of iter.







class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int len=max(zero, one)+1, res=0, mod=1000000007;
        int dp[len];
        memset(dp, 0, sizeof(dp));
        dp[0]=1;
        for(int i=min(zero, one);i<=high;i++) {
            dp[i%len]=0;
            if(i>=one) dp[i%len]=(0ll+dp[(i-one+len)%len])%mod;				// Calc. #ways for 'i' len based on #ways for 'i-one' length string.
            if(i>=zero) dp[i%len]=(0ll+dp[i%len]+dp[(i-zero+len)%len])%mod;	// Calc. #ways for 'i' len based on #ways for 'i-zero' length string.
            if(i>=low) res=(0ll+res+dp[i%len])%mod;							// Adding #ways of building strs that satisfies length requirement.
        }
        return res;															// Returning total #ways to build strs that satisfies length requirement.
    }
};






//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													//n-high var.
// Space Complexity: O(n).	
// This algorithm is Dynamic Programming based. Here, we use Top Down building approach. We calc. #valid strs that meets length requirement can be built
// starting 'i' index and is stored in dp[i] and we return #ways to build valid strs starting index '0' at the end of process.







class Solution {
public:
    
    int mod=1000000007;
    int formStrings(int len, int low, int high, int zero, int one, vector<int>&dp) {
        if(len>high) return 0;
        if(dp[len]!=-1) return dp[len];										// If populated, we return pre-calculated value.
        int res=0;
        if(len>=low && len<=high) res=1;
        int zeroCount=formStrings(len+zero, low, high, zero, one, dp);		// Get #ways to build str if zero block is added at index 'i'.
        int oneCount=formStrings(len+one, low, high, zero, one, dp);
        dp[len]=(0ll+res+zeroCount+oneCount)%mod;							// #ways to build valid str satisfying len. requirement starting 'i' index.
        return dp[len];
    }
    
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int>dp(high+1, -1);											// Tracks #ways to build valid str satisfying len. requirement starting 'i' index.
        return formStrings(0, low, high, zero, one, dp);					// Returning total #ways to build strs that satisfies length requirement.
    }
};

