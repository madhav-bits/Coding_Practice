/*
*
//**********************************************1800. Maximum Ascending Subarray Sum.***********************************************

https://leetcode.com/problems/maximum-ascending-subarray-sum/



Given an array of positive integers nums, return the maximum possible sum of an ascending subarray in nums.

A subarray is defined as a contiguous sequence of numbers in an array.

A subarray [numsl, numsl+1, ..., numsr-1, numsr] is ascending if for all i where l <= i < r, numsi < numsi+1. Note that a subarray of size 1 
is ascending.

 

Example 1:

Input: nums = [10,20,30,5,10,50]
Output: 65
Explanation: [5,10,50] is the ascending subarray with the maximum sum of 65.
Example 2:

Input: nums = [10,20,30,40,50]
Output: 150
Explanation: [10,20,30,40,50] is the ascending subarray with the maximum sum of 150.
Example 3:

Input: nums = [12,17,15,13,10,11,12]
Output: 33
Explanation: [10,11,12] is the ascending subarray with the maximum sum of 33.
Example 4:

Input: nums = [100,10,1]
Output: 100
 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100



*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


[10,20,30,5,10,50]
[10,20,30,40,50]
[4,3,2,1]
[12,17,15,13,10,11,12]
[100,10,1]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, we track total of a inc. sequence. If an index break that seq, we maixmize the total with total obtained till
// then, and udpate new total to curr. num. We try to update the res with total obtained for last seq. We return max sequence total at end of iter.








class Solution {
public:
    int maxAscendingSum(vector<int>& v) {
        int res=0, total=v[0];												// Track max sequence total, curr. seq. total.
        for(int i=1;i<v.size();i++){										
            if(v[i-1]<v[i]) total+=v[i];									// If curr. num is also part of seq., we add it to curr. total.
            else{
                res=max(res, total);										// Update max total with curr. total/prev. seq. total.
                total=v[i];													// Set curr. num as curr. total
            }
        }
        res=max(res, total);												// Update max total with last seq. total.
        return res;															// Return max sequence total.
    }
};

