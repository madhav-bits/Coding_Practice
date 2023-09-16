/*
*
//******************************************************1035. Uncrossed Lines.******************************************************

https://leetcode.com/problems/uncrossed-lines/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,4,2]
[1,2,4]
[2,5,1,2,5]
[10,5,2,1,5,2]
[1,3,7,1,7,5]
[1,9,2,5,1]



// Time Complexity: O(n*m).													//n,m-lengths of two arrays.
// Space Complexity: O(m).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).													//n,m-lengths of two arrays.
// Space Complexity: O(m).	
// This algorithm is Dynamic Programming based. For every index in first array, we try to match it with every index in second array. If we observe a pair 
// of match indices (i,j) resp in two arrays, the length of before these indices in resp. arrays is inde. of curr. indices which we track in earlier dp iter.
// So, if matches we use dp[i][j]=1+dp[i-1][j-1] to get best #matches in first i,j indices in both arrays resp. If not matches we take the best of other 
// possibe. and assign to dp[i][j]. At the end of iter. we return dp[u.size()%2][v.size()] to best #matches in first len1, len2 indices of both arrays.







class Solution {
public:
    int maxUncrossedLines(vector<int>& u, vector<int>& v) {
        int dp[2][v.size()+1];
        memset(dp, 0, sizeof(dp));
        for(int i=1;i<=u.size();i++) {										// Iter. across both arrays.
            for(int j=1;j<=v.size();j++) {
                if(u[i-1]==v[j-1]) dp[i%2][j]=1+dp[(i-1)%2][j-1];			// If matches, we assign 1+ prev. dp values.
                else dp[i%2][j]=max(dp[i%2][j-1], dp[(i-1)%2][j]);			// If not matches, we use best of prev. values.
            }
        }
        return dp[u.size()%2][v.size()];									// Returning the max. #connecting lines possible.
    }
};

