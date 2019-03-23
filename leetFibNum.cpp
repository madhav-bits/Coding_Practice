/*
*
//********************************************************509. Fibonacci Number.*************************************************

The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the 
two preceding ones, starting from 0 and 1. That is,

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), for N > 1.
Given N, calculate F(N).

 

Example 1:

Input: 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
Example 2:

Input: 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
Example 3:

Input: 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
 

Note:

0 ≤ N ≤ 30.






*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


0

1


23


34




// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, finabocci num. of particular index, as curr. fib. num depends on prev. two nums, we  only 
// store prev. two fib.nums, at the end of iter. we have our result fib. num. on the last index, which we return.








class Solution {
public:
    int fib(int num) {
        if(num<=1) return num;												// Base conditions.
        int prev2=0, prev=1;												// Prev. two fib. nums.
        for(int i=2;i<=num;i++){											// Iter. till target fib. num.
            int temp=prev+prev2;											// Calc. curr. fib. num.
            prev2=prev;														// Updating prev. two fib num.
            prev=temp;
        }
        return prev;
    }
};