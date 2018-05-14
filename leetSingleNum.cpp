/*
*
//************************************************************136. Single Number.*****************************************************

Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[4,6,6,7,7]
[2,1,2,5,5]
[2,3,1,3,2]

// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Bitwise Manipulation based. If an integer occurs twice, then those two would cancel out each other in the XOR oper. The integer
// occuring once wouldn't be cancelled out.So, it remains out.



class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;																			// Maintains the XOR of ints till then.
        for(int i=0;i<nums.size();i++){
            res^=nums[i];																	// Calc. the XOR with the curr. int.
            //cout<<"New res is: "<<res<<endl;
        }
        return res;																			// Returning the res. integer(Occured once).
    }
};