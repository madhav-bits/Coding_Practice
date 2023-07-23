/*
*
//******************************************************2784. Check if Array is Good.******************************************************

https://leetcode.com/problems/check-if-array-is-good/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[2, 1, 3]
[1, 1]
[3, 4, 4, 1, 2, 1]



// Time Complexity: O(nlogn).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(1).	
// This algorithm is Sorting based. As the array length is smaller, we simply sort the array, check if values present in sorted array are as per the condition,
// which is arr[i]=i+1 for all indices, except the last index where it should have a repeated value of nums.size()-1, which we check separately. If all the
// conditions are met we return true.







class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(), nums.end());										// Sort the given array.
        for(int i=0;i<nums.size()-1;i++) {
            if(nums[i]!=i+1) return false;									// If sorted values doesn't meet condition, return false.
        }
        return nums.back()==(nums.size()-1);								// Check the condition for the last index also, if it satisfies we return true.
    }
};

