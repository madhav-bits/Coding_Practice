/*
*
//**************************************2357. Make Array Zero by Subtracting Equal Amounts.***************************************

https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,5,0,3,5]
[0]
[0,0,0,0,0]
[5,4,6,3,0,0,1,8,7,6,10,12,0,0,0,14,12,2,3,4,5,2,1]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Map based. Whenever we make a value=0 by substracting it's value, we are essentially pulling the x-axis up by least value units. In this
// step we are eseentially removing all least valued num's indices and dec. gap of other values to x-axis, in the next step we remove the next least value, 
// thus we obesrve that in each step each unique least value gets removed, so if we count #unique values in the array, that would be the #steps needed to 
// make entire array filled with zeroes.







class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int res=0;
        vector<bool>occur(101, false);										// Tracks if a num has occurred in the given array.
        occur[0]=true;
        for(int&num:nums) {
            if(occur[num]==false) res++;									// If this is first occurrance of num, we inc. the res.
            occur[num]=true;												// Mark the num as occurred.
        }
        return res;															// Returning total #steps needed to make all nums in the array =0.
    }
};


