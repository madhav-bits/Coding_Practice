/*
*
//******************************************************1824. Minimum Sideway Jumps.******************************************************

https://leetcode.com/problems/minimum-sideway-jumps/


There is a 3 lane road of length n that consists of n + 1 points labeled from 0 to n. A frog starts at point 0 in the second lane and wants to 
jump to point n. However, there could be obstacles along the way.

You are given an array obstacles of length n + 1 where each obstacles[i] (ranging from 0 to 3) describes an obstacle on the lane obstacles[i] at 
point i. If obstacles[i] == 0, there are no obstacles at point i. There will be at most one obstacle in the 3 lanes at each point.

For example, if obstacles[2] == 1, then there is an obstacle on lane 1 at point 2.
The frog can only travel from point i to point i + 1 on the same lane if there is not an obstacle on the lane at point i + 1. To avoid obstacles, 
the frog can also perform a side jump to jump to another lane (even if they are not adjacent) at the same point if there is no obstacle on the new lane.

For example, the frog can jump from lane 3 at point 3 to lane 1 at point 3.
Return the minimum number of side jumps the frog needs to reach any lane at point n starting from lane 2 at point 0.

Note: There will be no obstacles on points 0 and n.

 

Example 1:


Input: obstacles = [0,1,2,3,0]
Output: 2 
Explanation: The optimal solution is shown by the arrows above. There are 2 side jumps (red arrows).
Note that the frog can jump over obstacles only when making side jumps (as shown at point 2).
Example 2:


Input: obstacles = [0,1,1,3,3,0]
Output: 0
Explanation: There are no obstacles on lane 2. No side jumps are required.
Example 3:


Input: obstacles = [0,2,1,0,3,0]
Output: 2
Explanation: The optimal solution is shown by the arrows above. There are 2 side jumps.
 

Constraints:

obstacles.length == n + 1
1 <= n <= 5 * 105
0 <= obstacles[i] <= 3
obstacles[0] == obstacles[n] == 0




*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


[0,1,2,3,0]
[0,1,1,3,3,0]
[0,2,1,0,3,0]
[0,1,2,3,1,3,1,2,3,1,1,3,1,3,1,1,3,0]
[0,1,2,2,3,2,1,2,1,1,3,1,1,3,1,1,2,0]
[0,3,1,3,2,1,1,2,1,2,1,3,1,1,3,1,3,2,1,3,2,1,1,1,0]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is DP based. Here, at every step we calc. the minm. Sideway Jumps needed to reach that psn. We maintain a 2D array where we use values
// from prev. row((i-1)%2)) and update curr. row(i%2) values. If a curr. index has block, we set it to max. value possible, else we assign the jumps until
// prev. row's same psn. After updating all curr. indices based on prev. row same psns. Now, we account for sideway jumps from same row. Thus, we have 
// minm. jumps to curr. row's all psns. At the end of iter. we take the minm. jumps among jumps to last row's all psns and return it.









class Solution {
public:
    int minSideJumps(vector<int>& v) {
        vector<vector<int>>dp(2,vector<int>(3,0));							// DP array to keep track of minm. jumps to a row's all psns.
        dp[0][0]=1;dp[0][2]=1;												// Init. minm. jumps to first row's psns.
        int maxm=v.size()+1;
        for(int i=1;i<v.size();i++){
            if(v[i]!=1) dp[i%2][0]=dp[(i-1)%2][0];							// If curr. psn is empty, take jumps from prev. row same psn.
            else dp[i%2][0]=maxm;											// If curr. psn has obstacle, set it to max. jumps.
        
            if(v[i]!=2) dp[i%2][1]=dp[(i-1)%2][1];
            else dp[i%2][1]=maxm;
            
            if(v[i]!=3) dp[i%2][2]=dp[(i-1)%2][2];
            else dp[i%2][2]=maxm;
            
            if(v[i]!=1) dp[i%2][0]=min(dp[i%2][0], 1+min(dp[i%2][1], dp[i%2][2]));// Accoutning for side jumps from same row's diff. psns.
            if(v[i]!=2) dp[i%2][1]=min(dp[i%2][1], 1+min(dp[i%2][0], dp[i%2][2]));
            if(v[i]!=3) dp[i%2][2]=min(dp[i%2][2], 1+min(dp[i%2][0], dp[i%2][1]));
            // cout<<"top: "<<dp[i%2][0]<<" mid: "<<dp[i%2][1]<<" bottom: "<<dp[i%2][2]<<endl;
        }
        int res=min({dp[(v.size()-1)%2][0], dp[(v.size()-1)%2][1], dp[(v.size()-1)%2][2]});// Returning minm. jumps among all psns in last row.
        return res;															// Returning minm. jumps.
    }
};

