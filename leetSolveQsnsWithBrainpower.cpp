/*
*
//******************************************************2140. Solving Questions With Brainpower.******************************************************

https://leetcode.com/problems/solving-questions-with-brainpower/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[3,2],[4,3],[4,4],[2,5]]
[[1,1],[2,2],[3,3],[4,4],[5,5]]
[[1,1],[2,2],[3,3],[4,4],[5,5],[4,2],[5,1],[7,4],[15,6],[15,3],[8,5],[2,2],[8,3],[9,2],[6,5],[5,4],[10,2]]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is DP based. At every index we have two decision whether to take/not take the curr. value, if we take it, we have to skip next v[i][1] vals.
// As curr. index has affect on later indices we iter. in reverse drn so that all affected indices are covered and based on that we can make decision now.
// For the case where we don't take curr. index, it's best total would be best of next index.
// For the case where we take curr. index, it's best total would be curr. val+best case of i+v[i][1]+1 index.
// We return max of dp[0] array as it indicates the best possible sum of points starting from index '0'.







class Solution {
public:
    long long mostPoints(vector<vector<int>>& v) {
        // vector<vector<long long int>>dp(v.size(), vector<long long int>(2, 0));//[i][0] indicates i is used, [i][1] indicates 'i' isn't taken.
        long long int dp[v.size()][2];										//[i][0] indicates i is used, [i][1] indicates 'i' isn't taken.
        memset(dp, 0, sizeof(dp));
        dp[v.size()-1][0]=v.back()[0];
        for(int i=v.size()-2;i>=0;i--) {
            dp[i][1]=max(dp[i+1][0], dp[i+1][1]);							// As we skip curr. value, it's best total would depend on next index.
            dp[i][0]=v[i][0];												// Taking curr. value.
            if(i+v[i][1]+1<v.size()) dp[i][0]+=max(dp[i+v[i][1]+1][0], dp[i+v[i][1]+1][1]);// Adding best total from next eligible index.
        }
        
        return max(dp[0][0], dp[0][1]);										// Returning the best of dp[0] array for best total score.
    }
};











//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is DP based. This logic is same as the above one, except that it avoids redundant space usage, we don't need two entries (taken/skip) per each
// index, just 1 would suffice.











class Solution {
public:
    long long mostPoints(vector<vector<int>>& v) {
        long long int dp[v.size()];
        memset(dp, 0, sizeof(dp));
        dp[v.size()-1]=v.back()[0];
        for(int i=v.size()-2;i>=0;i--) {
            dp[i]=v[i][0];													// Taking curr. value.
            if(i+v[i][1]+1<v.size()) dp[i]+=dp[i+v[i][1]+1];				// Adding next eligible index's best score.
            dp[i]=max(dp[i], dp[i+1]);										// Assigning best of (taken, skip) to curr. dp index.
        }
        
        return dp[0];														// Returning dp[0] for best total score.
    }
};

