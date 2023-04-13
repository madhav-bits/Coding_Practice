/*
*
//******************************************************2413. Smallest Even Multiple.******************************************************

https://leetcode.com/problems/smallest-even-multiple/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


5
1
2
3
4
6
7
8
9
150



// Time Complexity: O(1).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(1).	
// This algorithm is observation based. Here, since have to return first multiple, for even number, that number itself would be the answer as it's even and multiple for an odd number, it would be 2*n.







class Solution {
public:
    int smallestEvenMultiple(int n) {
        return (n%2==0)?n:2*n; 																			// Returning the smallest even multiple of given number.
    }
};
