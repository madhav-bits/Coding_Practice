/*
*
//**************************************************************Coin Sum Infinite.*******************************************************

https://www.interviewbit.com/problems/coin-sum-infinite/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


3 1 2 3
4


3 1 2 3
3






// Time Complexity: O(n*k).  
// Space Complexity: O(n).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n*k).
// Space Complexity: O(n).	
// This algorithm is Dynamic Programming based. As, we have get total number of combinations to get the given sum. We form the combinations
// in a sequence, i.e., we iterate over coins provided in a sequence to avoid permutations of same sequence. Then, for every coin, we add no. 
// of combinations of prev. sum(curr. sum-curr. coin value) to the curr. value. After iterating over all coins we get the total num. of combi.








int Solution::coinchange2(vector<int> &v, int target) {
    vector<int>dp(target+1, 0);												// Creating a DP array for all values.
    dp[0]=1;																// Base case.
    int modu=1000007;	
    for(int i=0;i<v.size();i++){											// Iter. over all coins.
        for(int j=v[i];j<=target;j++){										// Iter. over all values provided.
            dp[j]+=dp[j-v[i]];												// Adding #combinations of prev. sum to curr. sum.
            dp[j]=dp[j]%modu;												// Get the modulues value.
        }
    }
    return dp.back();														// Return #combinations for the target value.
}
