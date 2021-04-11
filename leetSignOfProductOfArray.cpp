/*
*
//******************************************************1822. Sign of the Product of an Array.***************************************************

https://leetcode.com/problems/sign-of-the-product-of-an-array/



There is a function signFunc(x) that returns:

1 if x is positive.
-1 if x is negative.
0 if x is equal to 0.
You are given an integer array nums. Let product be the product of all values in the array nums.

Return signFunc(product).

 

Example 1:

Input: nums = [-1,-2,-3,-4,3,2,1]
Output: 1
Explanation: The product of all values in the array is 144, and signFunc(144) = 1
Example 2:

Input: nums = [1,5,0,2,-3]
Output: 0
Explanation: The product of all values in the array is 0, and signFunc(0) = 0
Example 3:

Input: nums = [-1,1,-1,1,-1]
Output: -1
Explanation: The product of all values in the array is -1, and signFunc(-1) = -1
 

Constraints:

1 <= nums.length <= 1000
-100 <= nums[i] <= 100


*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


[-1,-2,-3,-4,3,2,1]
[1,5,0,2,-3]
[1,-2,2,-4,1,6,-4,2,0]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is observation based. Here, we keep track of the 	sign of the product based on the signs of the nums. If we encounter a neg. value we
// change the sign of the result, we start by setting the sign to 1. If we encounter 0, we return 0 directly. We return the sign at the end of the iter.







class Solution {
public:
    int arraySign(vector<int>& nums) {
        int res=1;															// Keeps track of the sign of the product of nums.
        for(int num:nums){
            if(num==0) return 0;											// If num is 0, we retun 0 directly.
            if(num<0) res*=-1;												// If num is neg. change the sign of the product of nums.
        }
        return res;															// We reutrn the sign of the product of all nums.
    }
};

