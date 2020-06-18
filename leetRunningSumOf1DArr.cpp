/*
*
//************************************************1480. Running Sum of 1d Array.***********************************************

https://leetcode.com/problems/running-sum-of-1d-array/description/


Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

Return the running sum of nums.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [1,3,6,10]
Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].
Example 2:

Input: nums = [1,1,1,1,1]
Output: [1,2,3,4,5]
Explanation: Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].
Example 3:

Input: nums = [3,1,2,10,1]
Output: [3,4,6,16,17]
 

Constraints:

1 <= nums.length <= 1000
-10^6 <= nums[i] <= 10^6




*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


Worked with examples provided in the question.


// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. We form a new array where arr[i] stores sum of [0,i] indices in the orig. array. Whenever we are at
// index 'i', we add arr[i-1]+v[i] and update index 'i'.







class Solution {
public:
    vector<int> runningSum(vector<int>& v) {
        vector<int>res;
        res.push_back(v[0]);
        for(int i=1;i<v.size();i++){
            res.push_back(res.back()+v[i]);
        }
        return res;
    }
};
