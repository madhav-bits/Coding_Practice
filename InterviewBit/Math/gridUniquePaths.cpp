/*
*
//**************************************************************Grid Unique Paths.*******************************************************

https://www.interviewbit.com/problems/grid-unique-paths/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



0
0

1
0

3
4

1
4

4
1



// Time Complexity: O(m*n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m*n).
// Space Complexity: O(m*n).	
// This algorithm is Dynamic Programming based. We iter. over entire all possible indices. As, curr. index depends on prev. column of curr. row 
// and same column of prev. row. We store all these values in a 2D DP array. We update the curr. value based on these 2 prev. values. At the 
// end of iteration, we return #possible ways to Bottom Rightmost index.








int Solution::uniquePaths(int row, int clmn) {
    if(row==0 || clmn==0) return 1;											// If no index provided to work on return 1.
    vector<vector<int>>dp(row,vector<int>(clmn,0));							// Init. a 2D array.
    dp[0][0]=1;																// Init. the start index.
    for(int i=0;i<row;i++){													// Iter. over entire 2D array.
        for(int j=0;j<clmn;j++){
            if(i==0 && j==0) continue;										// Skip the first index.
            if(j>0) dp[i][j]+=dp[i][j-1];									// Assign curr. index val based on prev. clmn of same row. 
            if(i>0) dp[i][j]+=dp[i-1][j];									// Update curr. index's val based on same clmn of prev. row.
        }
    }
    return dp[row-1][clmn-1];												// Return #possible ways to Finish index.
}












//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m*n).
// Space Complexity: O(n).	
// This algorithm is Dynamic Programming based. We iter. over entire all possible indices. As, curr. index depends on prev. column of curr. row 
// and same column of prev. row. We store all these values in a 2D DP array. We update the curr. value based on these 2 prev. values. At the 
// end of iteration, we return #possible ways to Bottom Rightmost index.


// This is Space optimized version of above algo. As, curr. index's val depends on curr. row and prev. row indices. So, we just maintain two rows.




int Solution::uniquePaths(int row, int clmn) {
    if(row==0 || clmn==0) return 1;
    vector<vector<int>>dp(2,vector<int>(clmn,0));
    dp[0][0]=1;
    for(int i=0;i<row;i++){
        for(int j=0;j<clmn;j++){
            if(i==0 && j==0) continue;
            dp[i%2][j]=0;
            if(j>0) dp[i%2][j]+=dp[i%2][j-1];
            if(i>0) dp[i%2][j]+=dp[(i-1)%2][j];
        }
    }
    return dp[(row-1)%2][clmn-1];
}
