/*
*
//************************************************1785. Minimum Elements to Add to Form a Given Sum.************************************************

https://leetcode.com/problems/minimum-elements-to-add-to-form-a-given-sum/


You are given an integer array nums and two integers limit and goal. The array nums has an interesting property that abs(nums[i]) <= limit.

Return the minimum number of elements you need to add to make the sum of the array equal to goal. The array must maintain its property that 
abs(nums[i]) <= limit.

Note that abs(x) equals x if x >= 0, and -x otherwise.

 

Example 1:

Input: nums = [1,-1,1], limit = 3, goal = -4
Output: 2
Explanation: You can add -2 and -3, then the sum of the array will be 1 - 1 + 1 - 2 - 3 = -4.
Example 2:

Input: nums = [1,-10,9,1], limit = 100, goal = 0
Output: 1
 

Constraints:

1 <= nums.length <= 105
1 <= limit <= 106
-limit <= nums[i] <= limit
-109 <= goal <= 109



*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


[1,-1,1]
3
-4
[1,-10,9,1]
100
0
[1,5,-4,9,-5,9,5,2,7,2,-6,3,2,9,-3]
5
41


// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is observation based. Here, we find the absolute diference b/w the array total and the goal. And, in each step we can take at max. 
// limit steps towards goal, we get steps from diff/limit and if any remainder diff exists, it would be covered by last step.









class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long int total=0;
        for(int num:nums) total+=num;										// Calc. total of given array.
        long long int moves=abs(goal-total);								// Calc. abs. diff b/w total and goal.
        int steps=moves/limit;												// Calc. #full steps required towards goal.
        if(moves%limit!=0) steps++;											// If diff<limit is left out, it would take one more step.
        return steps;														// Returning #steps required to reach goal.
    }
};

