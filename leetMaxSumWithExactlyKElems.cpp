/*
*
//******************************************************2656. Maximum Sum With Exactly K Elements.******************************************************

https://leetcode.com/problems/maximum-sum-with-exactly-k-elements/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,2,3,4,5]
3
[5,5,5]
2
[4,6,5,3,2,5,4,3,7,6,5,7,8,6,5,8,4,6]
12
[4,6,5,3,2,5,4,3,7,6,5,7,8,6,5,8,4,6]
11
[4,6,5,3,2,5]
1
[4,6,5,3,2,5]
3
[4,6,5,3,2,5]
4



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is observation based. Here, in order to get max score, we have to add max num from the array at every step. So, we extract the max number and increase it's value by 1 k-1 times and 
// add it to res at every step. We use AP formula to get the sum of nums.







class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int maxm=*max_element(nums.begin(), nums.end());												// Get the max number.
        return (k*(2*maxm+(k-1)))/2;																	// Return AP total of the sequence starting with max number from the array.
    }
};

