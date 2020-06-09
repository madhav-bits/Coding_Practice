/*
*
//**********************************************1403. Minimum Subsequence in Non-Increasing Order.*****************************************

https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order/description/


Given the array nums, obtain a subsequence of the array whose sum of elements is strictly greater than the sum of the non included 
elements in such subsequence. 

If there are multiple solutions, return the subsequence with minimum size and if there still exist multiple solutions, return the 
subsequence with the maximum total sum of all its elements. A subsequence of an array can be obtained by erasing some (possibly zero) 
elements from the array. 

Note that the solution with the given constraints is guaranteed to be unique. Also return the answer sorted in non-increasing order.

 

Example 1:

Input: nums = [4,3,10,9,8]
Output: [10,9] 
Explanation: The subsequences [10,9] and [10,8] are minimal such that the sum of their elements is strictly greater than the sum of 
elements not included, however, the subsequence [10,9] has the maximum total sum of its elements. 
Example 2:

Input: nums = [4,4,7,6,7]
Output: [7,7,6] 
Explanation: The subsequence [7,7] has the sum of its elements equal to 14 which is not strictly greater than the sum of elements not 
included (14 = 4 + 4 + 6). Therefore, the subsequence [7,6,7] is the minimal satisfying the conditions. Note the subsequence has to 
returned in non-decreasing order.  
Example 3:

Input: nums = [6]
Output: [6]
 

Constraints:

1 <= nums.length <= 500
1 <= nums[i] <= 100



*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


[4,3,10,9,8]
[4,4,7,6,7]
[6]




// Time Complexity: O(nlogn).												// n- length of the array.
// Space Complexity: O(1).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).												// n- length of the array.
// Space Complexity: O(1).	
// This algorithm is Sorting based. Here, we want minm. set of nums whose sum is greater than total/2. They want it to be of minm.
// length, so we sort the given array, we iter. from highest value to lowest value, we stop when the sum of picked nums is >total/2, we 
// return the nums collected till then. It requires greater total, in case of same len. smallest subseq, since we are taking greatest 
// values first, our way of pickig values satisfies this requirement.






class Solution {
public:
    vector<int> minSubsequence(vector<int>& v) {
        vector<int>temp=v;									
        vector<int>res;														// Stores the final list of nums.
        int total=0;
        for(auto num: v) total+=num;										// Calc. total of nums in the array.
        sort(temp.begin(), temp.end());										// Sort the given array.
        int sum=0, index=v.size()-1;										// Tracks sum of picked nums, index of value to be picked.
        while(sum<=total/2){												// Till sum<=total/2.
            res.push_back(temp[index]);										// Pick curr. value.
            sum+=temp[index];												// Updating the sum of picked values.
            index--;														// Dec. the index.
        }
        return res;															// Return the stored values.
    }
};
