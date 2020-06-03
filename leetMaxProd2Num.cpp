/*
*
//*****************************************1464. Maximum Product of Two Elements in an Array.****************************************

https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/description/


Given the array of integers nums, you will choose two different indices i and j of that array. Return the maximum value of 
(nums[i]-1)*(nums[j]-1).
 

Example 1:

Input: nums = [3,4,5,2]
Output: 12 
Explanation: If you choose the indices i=1 and j=2 (indexed from 0), you will get the maximum value, that is, 
(nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12. 
Example 2:

Input: nums = [1,5,4,5]
Output: 16
Explanation: Choosing the indices i=1 and j=3 (indexed from 0), you will get the maximum value of (5-1)*(5-1) = 16.
Example 3:

Input: nums = [3,7]
Output: 12
 

Constraints:

2 <= nums.length <= 500
1 <= nums[i] <= 10^3




*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.

[3,43,2,46,76,2,20]

[1,5,2,1,7,5]



// Time Complexity: O(n).  												// n- length of the array.
// Space Complexity: O(k).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// n- length of the array.
// Space Complexity: O(k).	
// This algorithm is observation based. As, all the (nums-1) are non-neg. The largest product involves largest num. So, we keep track of 
// largest num. till now and multiply curr. num with it and try to maximize the product. If the curr. num is the max. num, with this
// product maxm. num is multiplied with max. value till now. In the further iter. maxm. num is multiplied with all the rest nums. with
// greater indices and each product val. is used to maximize the maxm product value.







class Solution {
public:
    int maxProduct(vector<int>& v) {
        int maxm=0, res=0;													// Tracks maxm. num and maxm. product of the array.
        for(int num:v){														// Iter. over array.
            num--;															// Dec. the val as per the requirement.
            res=max(res, maxm*num);											// Use the product to maximize the maxm product value.
            maxm=max(maxm, num);											// Update the maxm. value in the array var.
        }
        return res;															// Return the maxm product value.
    }
};