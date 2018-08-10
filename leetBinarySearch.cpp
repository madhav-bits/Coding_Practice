/*
*
//************************************************************704. Binary Search.*****************************************************

Given a sorted (in ascending order) integer array nums of n elements and a target value, write a function to search target in nums. If target 
exists, then return its index, otherwise return -1.


Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4

Example 2:

Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
 

Note:

You may assume that all elements in nums are unique.
n will be in the range [1, 10000].
The value of each element in nums will be in the range [-9999, 9999].




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[-1,0,3,5,10,11,12]
9



[-1,0,3,5,9,11,12]
9



// Time Complexity: O(logn).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logn).
// Space Complexity: O(1).	
// This algorithm is Binary Search problem. This is a classic Binary Search problem. We take lowest and highest possible indices for the solution.
// We take the mid index, if the value at mid index is < target value, then the required index is in the right half of the vector, else it's in 
// the first half. Thus, we corner down possible indices and left out with one index, if the value at that index is same as that of target value,
// then we return that index, else we return -1.







class Solution {
public:
    int search(vector<int>& v, int target) {
        int low=0,high=v.size()-1;											// Lowest, highest possible indices for the solution.
        while(low<high){													// Checks all possible indices.
            int mid=low+(high-low)/2;										// Calc. mid index number.
            // cout<<"mid: "<<mid<<endl;
            if(v[mid]<target) low=mid+1;									// If mid value<target, then req. index is in right half.
            else high=mid;													// Else, it's in left half.
        }
        return (v[low]==target)?low:-1;										// If target value obtained/present in array, return that index else -1.
    }
};