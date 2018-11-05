/*
*
//******************************************************N digit numbers with digit sum S.***********************************************

Find out the number of N digit numbers, whose digits on being added equals to a given number S. Note that a valid number starts from 
digits 1-9 except the number 0 itself. i.e. leading zeroes are not allowed.

Since the answer can be large, output answer modulo 1000000007

**

N = 2, S = 4 
Valid numbers are {22, 31, 13, 40} 
Hence output 4.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



4
14



// Time Complexity: O(n*m).  
// Space Complexity: O(n*m).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).
// Space Complexity: O(n*m).	
// This algorithm is Dynamic Programming based. More precisely, it's Hashing to avoid repetitive calculations. Here, in the DFS, we subtract
// nums at each step, then forward, remaining steps, remaining sum to be formed, if we reach remaining sum of 0 with 0 steps left, then we 
// return 1, if a combi. of remSum and remSteps is already calculated, we return that value. Thus, at the end we return the total combi. for 
// given target sum and total moves allowed. 


// dp[remSum][remSteps] indicates #ways to attain remSum from remSteps.









long findCombi(int target, vector<vector<int>>&dp, int remLen){
    if(target<0 || remLen<0) return 0;										// Termintaing conditions.
    int mod=1000000007;
    if(dp[target][remLen]!=-1) return dp[target][remLen];					// If already calc., return the value directly.
    long res=0;																// Tracks #Combi. with curr. remSum and remSteps.
    for(int i=0;i<=9;i++){													// Subtract allowed vals. in curr. step.
        res=(res+findCombi(target-i,dp,remLen-1))%mod;						// Give recursive call with remSum-i and remSteps-1.
    }
    dp[target][remLen]=res;													// Assign the calc. moves to dp array.
    return res;																// Return the moves.
}

int Solution::solve(int len, int target) {
    int mod=1000000007;
    vector<vector<int>>dp(target+1,vector<int>(len+1,-1));					// Return the dp array.
    dp[0][0]=1;																// Base case.
    long res=0;																// Tracks total #moves.
    for(int i=1;i<=9;i++){													// Subtract possible vals. in  first step.
        res=(res+findCombi(target-i,dp,len-1))%mod;							// Give recursive call to obtain #combi. to get remSum.
    }
    return res;																// Return the total #moves to get target from alowed moves.
}
