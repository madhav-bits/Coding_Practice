/*
*
//********************************************https://leetcode.com/problems/partition-array-for-maximum-sum/.*************************************

1043. Partition Array for Maximum Sum


Given an integer array arr, you should partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has 
their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning.

 

Example 1:

Input: arr = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: arr becomes [15,15,15,9,10,10,10]
Example 2:

Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
Output: 83
Example 3:

Input: arr = [1], k = 1
Output: 1
 

Constraints:

1 <= arr.length <= 500
0 <= arr[i] <= 109
1 <= k <= arr.length



*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


[1,15,7,9,2,5,10]
3
[1,4,1,5,7,3,6,1,9,9,3]
4
[1,4,4,1,3,5,2,9,7,2,3,5,6,1,9,0,9,20,3]
6



// Time Complexity: O(n*k).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*k).
// Space Complexity: O(n).	
// This algorithm is DP based. Here, dp[i] indicates maxm. sum possible for subarray of [0,i] indices. For the last window ending at 'i', it can start from
// [i-k-1,i] and we try to maximize the sum of this window's contribution and all previous subarrays's maxm. possible sm until start of window. Thus, we
// have max. possible sum for this array in the last index of dp array.




// This link gives the intuition behind the approach.
// https://leetcode.com/problems/partition-array-for-maximum-sum/discuss/290863/JavaC%2B%2BPython-DP-O(K)-Space






class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& v, int k) {
        vector<int>dp(v.size(),0);											// Stores maxm. possible sum for subarray until index 'i'.
        for(int i=0;i<v.size();i++){
            int maxm=v[i];
            for(int gap=0;gap<k && i-gap>=0;gap++){
                maxm=max(maxm, v[i-gap]);
                dp[i]=max(dp[i], (gap+1)*maxm+((i-gap-1>=0)?dp[i-gap-1]:0));// Finding maxm. contribution of curr. window+all prev. windows.
            }
            // cout<<"i: "<<i<<" and dp: "<<dp[i]<<endl;
        }
        return dp.back();													// Returning maxm. possible sum for this subarray.
    }
};