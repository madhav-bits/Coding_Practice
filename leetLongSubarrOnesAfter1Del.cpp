/*
*
//*****************************************1493. Longest Subarray of 1's After Deleting One Element.*****************************************

https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/


Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array.

Return 0 if there is no such subarray.

 

Example 1:

Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
Example 2:

Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
Example 3:

Input: nums = [1,1,1]
Output: 2
Explanation: You must delete one element.
Example 4:

Input: nums = [1,1,0,0,1,1,1,0,1]
Output: 4
Example 5:

Input: nums = [0,0,0]
Output: 0
 

Constraints:

1 <= nums.length <= 10^5
nums[i] is either 0 or 1.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.

[1,1,1,1,1]

[1,1,1,0,1,1,1,1,0,0,1,1,1]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is observation based. Here, we keep of conseq. seqs of ones, we add two consecutive one seqs separated by single zero. There
// is also a case that array if full of ones, so we keep track whether we are able to find any zeroes or not. At the end of iter. we add
// the last seq. of ones with it's preceeding seq. of ones. If there is no zero found, we have to delete a 1 from the array and return the res.






class Solution {
public:
    int longestSubarray(vector<int>& v) {
        int prev=0, curr=0, res=0;
        bool first=false;
        for(auto num:v){
            if(num==1) curr++;												// Count #ones in seq.
            else{
                first=true;													// Notes that we found zero.
                res=max(res, prev+curr);									// Adding prev. and curr. seq. length.
                prev=curr;													// Updating curr. seq. as prev.
                curr=0;														// Updating curr. seq. length as 0.
            }
        }
        if(first) res=max(res, prev+curr);									// Adding last seq. with it's preceeding seq and maximize res.
        else res=curr-1;													// If arr is full of ones, assign total len-1 to res.
        return res;															// Returning the maxm. seq. length after 1 deletion.
    }
};
