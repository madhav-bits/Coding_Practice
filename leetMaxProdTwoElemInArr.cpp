/*
*
//**************************************************1464. Maximum Product of Two Elements in an Array.***********************************************

https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/



Given the array of integers nums, you will choose two different indices i and j of that array. Return the maximum value of (nums[i]-1)*(nums[j]-1).
 

Example 1:

Input: nums = [3,4,5,2]
Output: 12 
Explanation: If you choose the indices i=1 and j=2 (indexed from 0), you will get the maximum value, that is, 
(nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12. 

Example 2:

Input: nums = [1,5,4,5]
Output: 16
Explanation: Choosing the indices i=1 and j=3 (indexed from 0), you will get the maximum value of (5-1)*(5-1) = 16.
Example 3:

Input: nums = [3,7]
Output: 12
 

Constraints:

2 <= nums.length <= 500
1 <= nums[i] <= 10^3



*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.

[2,3,1,5]
[1,1,1,1,1]
[1,1,2,2]
[1,1,2]




// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, as the values are positive their product would be >=0. We keep track of two max values and multiply and return
// the product at the end of iteration.











class Solution {
public:
    int maxProduct(vector<int>& v) {
        int max1=v[0], max2=INT_MIN;
        for(int i=1;i<v.size();i++){
            if(v[i]>=max1){													// If curr. val>=max value.
                max2=max1;													// Updating second and first max accordingly.
                max1=v[i];
            }else if(v[i]>max2) max2=v[i];									// If curr. val>second max, updating it's value accordingly.
        }
        return (max1-1)*(max2-1);											// Multiplying the nums and returning it.
    }
};

