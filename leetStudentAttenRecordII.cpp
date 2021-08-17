/*
*
//************************************************552. Student Attendance Record II.***********************************************

https://leetcode.com/problems/student-attendance-record-ii/submissions/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


2
1
10
100
123
10101
100000



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Dynamic Programming based solution. We use dp array to track the #possibilities for each of the allowed states. 
// dp[day][absent][consec. late] is used to track it. At the end we add the values from all the possibilities and return it.









class Solution {
public:
    int checkRecord(int n) {
        long long int mod=1000000007;//[length, absent, late]
        // vector<vector<vector<long long int>>>dp(n+1, vector<vector<long long int>>(2, vector<long long int>(3,0)));
        long long int dp[2][2][3];
        dp[0][0][0]=1;
        dp[0][0][1]=0;
        dp[0][0][2]=0;
        dp[0][1][0]=0;
        dp[0][1][1]=0;
        dp[0][1][2]=0;
        for(int i=1;i<=n;i++){
            // Present today.
            dp[i%2][0][0]=(dp[(i-1)%2][0][0]+dp[(i-1)%2][0][1]+dp[(i-1)%2][0][2])%mod;// Adding all possib. with zero absent until i-1 day.
            dp[i%2][1][0]=(dp[(i-1)%2][1][0]+dp[(i-1)%2][1][1]+dp[(i-1)%2][1][2])%mod;// Adding all possib. with 1 absent until i-1 day.
            
            // Absent today.
            dp[i%2][1][0]=(dp[i%2][1][0]+dp[(i-1)%2][0][0]+dp[(i-1)%2][0][1]+dp[(i-1)%2][0][2])%mod;// Adding all possib. with 0 absent until i-1 day.
            
            // Late today.
            dp[i%2][0][1]=dp[(i-1)%2][0][0];								// This equals possib. with zero absent, zero consec. late till i-1 day.
            dp[i%2][1][1]=dp[(i-1)%2][1][0];								// This equals possib. with one absent, zero consec. late till i-1 day.
            
            dp[i%2][0][2]=dp[(i-1)%2][0][1];								// This equals possib. with zero absent, one consec. late till i-1 day.
            dp[i%2][1][2]=dp[(i-1)%2][1][1];								// This equals possib. with one absent, one consec. late till i-1 day.
            
        }
        return (dp[n%2][0][0]+dp[n%2][0][1]+dp[n%2][0][2]+dp[n%2][1][0]+dp[n%2][1][1]+dp[n%2][1][2])%mod;// Adding up all valid possib. on i day.
    }
};
