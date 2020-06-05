/*
*
//****************************************1413. Minimum Value to Get Positive Step by Step Sum.***************************************

https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/description/


Given an array of integers nums, you start with an initial positive value startValue.

In each iteration, you calculate the step by step sum of startValue plus elements in nums (from left to right).

Return the minimum positive value of startValue such that the step by step sum is never less than 1.

 

Example 1:

Input: nums = [-3,2,-3,4,2]
Output: 5
Explanation: If you choose startValue = 4, in the third iteration your step by step sum is less than 1.
                step by step sum
                startValue = 4 | startValue = 5 | nums
                  (4 -3 ) = 1  | (5 -3 ) = 2    |  -3
                  (1 +2 ) = 3  | (2 +2 ) = 4    |   2
                  (3 -3 ) = 0  | (4 -3 ) = 1    |  -3
                  (0 +4 ) = 4  | (1 +4 ) = 5    |   4
                  (4 +2 ) = 6  | (5 +2 ) = 7    |   2
Example 2:

Input: nums = [1,2]
Output: 1
Explanation: Minimum start value should be positive. 
Example 3:

Input: nums = [1,-2,-3]
Output: 5
 

Constraints:

1 <= nums.length <= 100
-100 <= nums[i] <= 100




*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


Worked with the test cases provided with the question.



// Time Complexity: O(n).													// n- length of the array.
// Space Complexity: O(1).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// n- length of the array.
// Space Complexity: O(1).	
// This algorithm is observation based. Here, we want our cumulative sum to be always greater than 0, so we iter. over array and track
// the minm. cumul. value. If it is >=0, we return 1(since in the question it was asked to give minm. POSITIVE value, so minm. val. we
// can return is 1). If it is neg. we calc. it's abs. val, add one  and return, so that this startValue will make sure that the cumul. 
// sum never reaches <1.








class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int minm=INT_MAX;													// Tracks minm. cumul sum.
        int total=0;														// Tracks cumul. sum.
        for(int  num:nums){													// Iter. over nums.
            total+=num;
            if(total<minm) minm=total;										// Update the minm. cumul sum var.
        }
        if(minm>=0) return 1;												// Is non-neg, return 1.
        return abs(minm)+1;													// If negative, we return it's abs. val+1.
    }
};