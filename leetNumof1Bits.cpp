/*
*
//********************************************************191. Number of 1 Bits.*************************************************

Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

Example 1:

Input: 11
Output: 3
Explanation: Integer 11 has binary representation 00000000000000000000000000001011 
Example 2:

Input: 128
Output: 1
Explanation: Integer 128 has binary representation 00000000000000000000000010000000




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


-8
-15
1
16
17


// Time Complexity: O(logn).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logn).
// Space Complexity: O(1).	
// This algorithm is Bit Manipulation Oriented one. At every instant we check whether the first bit is one or not. We count all the occur. of 1's
// after doing Logical Right Shifts in each iteration, until the val. gets reduced to 0.



class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        while(n!=0){
            count+=(n&1);													// Checking the first bit is one or not.
            n=n>>1;															// Logical bitshift to right.
        }
        return count;														// Return the total number of ones in the int.
    }
};