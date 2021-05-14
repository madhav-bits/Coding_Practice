/*
*
//*********************************************1848. Minimum Distance to the Target Element.***********************************************

https://leetcode.com/problems/minimum-distance-to-the-target-element/


Given an integer array nums (0-indexed) and two integers target and start, find an index i such that nums[i] == target and abs(i - start) is minimized. 
Note that abs(x) is the absolute value of x.

Return abs(i - start).

It is guaranteed that target exists in nums.

 

Example 1:

Input: nums = [1,2,3,4,5], target = 5, start = 3
Output: 1
Explanation: nums[4] = 5 is the only value equal to target, so the answer is abs(4 - 3) = 1.
Example 2:

Input: nums = [1], target = 1, start = 0
Output: 0
Explanation: nums[0] = 1 is the only value equal to target, so the answer is abs(0 - 0) = 0.
Example 3:

Input: nums = [1,1,1,1,1,1,1,1,1,1], target = 1, start = 0
Output: 0
Explanation: Every value of nums is 1, but nums[0] minimizes abs(i - start), which is abs(0 - 0) = 0.
 

Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 104
0 <= start < nums.length
target is in nums.



*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


[1,2,3,4,5]
5
3
[1]
1
0
[1,1,1,1,1,1,1,1,1,1]
1
0
[3,6,3,67,3,7,4,2,7,3,2,3,67,89,8,64,5]
67
10



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Pointer based. As we are trying to find index with target value and close to start index, we take two pointers and iter. towards both
// ends one step at a time. If we find target value in either of left, right indices we return the abs(i-start). As we are moving in both the dirs at the
// same time, we get the minm. abs(i-start) upon finding the target value.









class Solution {
public:
    int getMinDistance(vector<int>& v, int target, int start) {
        int left=start, right=start+1;										// Init. left and right ptrs.
        while(left>=0 || right<v.size()){									// All indices are checked.
            if(left>=0 && v[left]==target) return start-left;				// If left index has target value, return the dist. from start index.
            else if(right<v.size() && v[right]==target) return right-start;	// If the right index has target val, return the dist. from start index.
            left--;															// Moving both the ptrs towards both the ends.
            right++;
        }
        return -1;
    }
};

