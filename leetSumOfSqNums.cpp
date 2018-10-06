/*
*
//******************************************************633. Sum of Square Numbers.***********************************************

Given a non-negative integer c, your task is to decide whether there're two integers a and b such that a2 + b2 = c.

Example 1:
Input: 5
Output: True
Explanation: 1 * 1 + 2 * 2 = 5
Example 2:
Input: 3
Output: False




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



8


1


0


3


4


5


9



18




// Time Complexity: O(logn).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logn).
// Space Complexity: O(1).	
// This algorithm is Binary Search based. As, we need a pair of numbers, we get the maxm. of nums allowed as answer(sqrt(num)). Then, we do a 
// Binary search on this pair.








class Solution {
public:
    bool judgeSquareSum(int c) {
        int i=0,j=sqrt(c);
        // cout<<"floor: "<<(j)<<endl;
        if(j*j==c) return true;												// Checking if given num is perfect square.
        while(i<=j){														// Binary Search loop.
            int sum=(i*i)+(j*j);											// Sum of squares of pair of numbers.
            if(sum==c) return true;											// If sum is obtained, return true.
            if(sum<c) i++;													// If sum is less, we inc. the lower value.
            else j--;														// If sum is greater, we dec. the higher value.
        }
        return false;														// If target not achievable, return false.
    }
};

