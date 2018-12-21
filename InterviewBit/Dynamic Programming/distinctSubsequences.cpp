/*
*
//************************************************************Distinct Subsequences.*****************************************************

https://www.interviewbit.com/problems/distinct-subsequences/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



rabbbit
rabit


rabbit
rait


gate
a



// Time Complexity: O(n^2).  
// Space Complexity: O(n).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n).													
// This algorithm is Dynamic Programming based. This is simplified version of Edit Distance, that is deleting from one of the strings is allowed.
// If two chars from both strings match dp[i][j], we take the possibilities from prev. row, prev. clmn dp[i-1][j-1]. We also take values from 
// prev. row as deleting chars on the rows is allowed. At the end, we return the dp[s.length()%2][t.length()].

// dp[(i+1)%2][j+1] indicates #combinations to acheive t.substr(j) from s.substr(i).






int Solution::numDistinct(string s, string t) {
    int res=0;
    vector<vector<int>>dp(2, vector<int>(t.length()+1, 0));					// Declaring the 2D DP array.
    // for(int i=0;i<=s.length();i++) dp[i][0]=1;							// Base case, when all chars from given str had to be deleted to match
																			// empty target string.
    for(int i=0;i<s.length();i++){											// Iter. over given string.
        dp[i%2][0]=1;														// Init. base case when empty target string is given.
        for(int j=0;j<t.length();j++){										// Iter. over target string.
            dp[(i+1)%2][j+1]=0;												// Setting the curr. index to default value.
            if(s[i]==t[j]) dp[(i+1)%2][j+1]+=dp[i%2][j];					// If curr. chars match, get #combinations from prev. row, prev. clmn.
            if(i-1>=0) dp[(i+1)%2][j+1]+=dp[i%2][j+1];						// Also getting #combinations from prev. row(Deleting a char from "s").
            
        }
    }
    // for(auto nums: dp){
    //     for(auto num:nums){
    //         cout<<num<<" ";
    //     }
    //     cout<<endl;
    // }
    
    return dp[(s.length())%2][t.length()];									// Returning #combinations to get t from s.
}
