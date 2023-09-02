/*
*
//**********************************************1920. Build Array from Permutation.***********************************************

https://leetcode.com/problems/build-array-from-permutation/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[0,2,1,5,3,4]
[5,0,1,2,3,4]
[5,3,2,0,4,6,1]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. We iter. over nums array and update res array based on condition specified and return res at the end of iter. 







class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int>res(nums.size(),0);
        for(int i=0;i<nums.size();i++) res[i]=nums[nums[i]];				// Updating res array based on the condition specified.
        return res;															// Returning res array formed on using condition specified on nums array.
    }
};

