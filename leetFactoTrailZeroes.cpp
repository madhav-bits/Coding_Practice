/*
*
//******************************************************172. Factorial Trailing Zeroes.***********************************************

Given an integer n, return the number of trailing zeroes in n!.

Example 1:

Input: 3
Output: 0
Explanation: 3! = 6, no trailing zero.
Example 2:

Input: 5
Output: 1
Explanation: 5! = 120, one trailing zero.
Note: Your solution should be in logarithmic time complexity.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


999
1001
1
11
9




// Time Complexity: O(logn).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logn).
// Space Complexity: O(1).	
// This algorithm is observation based. Trailing zeroes are formed by multiplying multiples of 5 with even numbers, also multiples of 10, which
// can be furthur decomposed into multiples of 5, infact few of them can be decomposed into power of 5, which might need counting multiple
// times.





class Solution {
public:
    int trailingZeroes(int n) {
        int res=0;
        for(long long i=5;i<=n;i*=5){											// Inc. the power of 5.
            res+=(n/i);															// Counting no. of multiples of that power of 5-
        }																		// -Each contributing to one trailing zero.
        return res;																// Returning trailing zeroes.
    }
};