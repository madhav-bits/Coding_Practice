/*
*
//******************************************1458. Max Dot Product of Two Subsequences.*****************************************

https://leetcode.com/problems/max-dot-product-of-two-subsequences/description/


Given two arrays nums1 and nums2.

Return the maximum dot product between non-empty subsequences of nums1 and nums2 with the same length.

A subsequence of a array is a new array which is formed from the original array by deleting some (can be none) of the characters 
without disturbing the relative positions of the remaining characters. (ie, [2,3,5] is a subsequence of [1,2,3,4,5] while [1,5,3] is 
not).

 

Example 1:

Input: nums1 = [2,1,-2,5], nums2 = [3,0,-6]
Output: 18
Explanation: Take subsequence [2,-2] from nums1 and subsequence [3,-6] from nums2.
Their dot product is (2*3 + (-2)*(-6)) = 18.
Example 2:

Input: nums1 = [3,-2], nums2 = [2,-6,7]
Output: 21
Explanation: Take subsequence [3] from nums1 and subsequence [7] from nums2.
Their dot product is (3*7) = 21.
Example 3:

Input: nums1 = [-1,-1], nums2 = [1,1]
Output: -1
Explanation: Take subsequence [-1] from nums1 and subsequence [1] from nums2.
Their dot product is -1.
 

Constraints:

1 <= nums1.length, nums2.length <= 500
-1000 <= nums1[i], nums2[i] <= 1000




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[2,1,-2,5]
[3,0,-6]

[3,-2]
[2,-6,7]


[-1,-1]
[1,1]


[2,1,-2,5,-10,7,4,-4,-6]
[3,0,-6,-4,-4,18,4,-4,2,-2]


[-3,-8,3,-10,1,3,9]
[9,2,3,7,-9,1,-8,5,-1,-1]



// Time Complexity: O(n*m).  												// m,n are length of both arrays.
// Space Complexity: O(n*m).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).													// m,n are length of both arrays.
// Space Complexity: O(n*m).	
// This algorithm is Dynamic Programming based. dp[i][j] stores max. product of subarrays upto index 'i' in first arr and 'j' in sec
// arr. When, we are at i,j index, we multiply u[i-1] and v[j-1] and get value from dp[i-1][j-1], it is neg. we take is zero, indi-
// -cating that the subsstr has started at this pair of indices. We also try to update the curr. index{i,j} with values stored in 
// dp[i-1][j] and dp[i][j-1] indicating one string has ingnored other arr's curr. char and paired with some char in that earlier index.
// Thus, it considers all possib. and assigns max. possible value to {i,j} index. The last index in last col stores max. dot product
// of both arrays's subsequences.






class Solution {
public:
    int maxDotProduct(vector<int>& u, vector<int>& v) {
        vector<vector<int>>dp(u.size()+1, vector<int>(v.size()+1, -1000001));	// Init. 2D array.
//         dp[0][0]=u[0]*v[0] 
//         for(int i=1;i<u.size();i++){
//             dp[i][0]=max(u[i]*v[0], dp[i-1][0]);
//         }
        
//         for(int j=1;j<v.size();j++){
//             dp[0][j]=max(u[0]*v[j], dp[0][j-1]);
//         }
        
        for(int i=1;i<=u.size();i++){										// Iter. over 2D DP array.
            for(int j=1;j<=v.size();j++){
                dp[i][j]=max({(u[i-1]*v[j-1])+max(0,dp[i-1][j-1]), dp[i-1][j], dp[i][j-1]});// dp[i][j] is assigned max. of left, right, diagonal indices.
                // cout<<"i: "<<i<<" and j: "<<j<<" and dp: "<<dp[i][j]<<endl; // For diagonal, if it has neg, we take it as zero, indicating that substring starts at curr. pair of index.
            }
        }
        return dp[(int)u.size()][(int)v.size()];							// Returns the max. dot product of two arrays.
    }
};
