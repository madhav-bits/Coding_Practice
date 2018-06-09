/*
*
//**********************************************************258. Add Digits.**************************************************

Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

Example:

Input: 38
Output: 2 
Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2. 
             Since 2 has only one digit, return it.
Follow up:
Could you do it without any loop/recursion in O(1) runtime?




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


0
1
9
10
243420
243423
243424



// Time Complexity: O(1).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(1).	
// This algorithm is observation based. Non-negative numbers generally follow a pattern. That if their digits are added until only 1 digit is
// remained, is the digit(the remainder) we get if we divide the number by 9.







class Solution {
public:
    int addDigits(int num) {
        if(num==0) return 0;									// IF the given is 0, just return it directly.
        int res=num%9;											// Calc. the result.
        if(res==0) return 9;									// If the rem. is 0, we have to return 0,as rem/single digit would be conv. to 0.
        return res;												// Returning the result.
    }
};