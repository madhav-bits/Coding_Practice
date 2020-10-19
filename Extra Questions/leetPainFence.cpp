/*
*
//**********************************************************276. Paint Fence.**********************************************************

https://leetcode.com/problems/paint-fence/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


3
2

0
3

1
4

4
10

5
23



// Time Complexity: O(n).													// n- #posts to be painted.  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// n- #posts to be painted.  
// Space Complexity: O(1).	
// This algorithm is Dynamic Programming and Observation based. Here, we breakdown the dp[i] into two parts dp[i](same paint as i-1)
// and dp[i](diff. color to prev. index). We form equations for these components for which we get dp[i-1]+dp[i-2]*(k-1). We use this
// recurrent equation and fill the dp array and return dp[n].
// dp[i] is #ways to fill dp array/fence till ith index/post.


// This link has the best explanation/derivation for the above recurrent equation.
// https://leetcode.com/problems/paint-fence/discuss/178010/The-only-solution-you-need-to-read








class Solution {
public:
    int numWays(int n, int k) {
        if(n<=1) return n*k;												// Base case.
        int dp[n+1];														// Declaring dp array.
        dp[0]=0;															// Filling up default initial values.
        dp[1]=k;
        dp[2]=k*k;
        for(int i=3;i<=n;i++){
            dp[i]=(dp[i-1]+dp[i-2])*(k-1);									// Filling dp[i] using recurrent equation.
        }
        return dp[n];														// #ways to fill dp array till nth index/post.
    }
};