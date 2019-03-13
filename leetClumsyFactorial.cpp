/*
*
//********************************************************1006. Clumsy Factorial.***************************************************

Normally, the factorial of a positive integer n is the product of all positive integers less than or equal to n.  For example, 
factorial(10) = 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1.

We instead make a clumsy factorial: using the integers in decreasing order, we swap out the multiply operations for a fixed rotation 
of operations: multiply (*), divide (/), add (+) and subtract (-) in this order.

For example, clumsy(10) = 10 * 9 / 8 + 7 - 6 * 5 / 4 + 3 - 2 * 1.  However, these operations are still applied using the usual order of 
operations of arithmetic: we do all multiplication and division steps before any addition or subtraction steps, and multiplication and 
division steps are processed left to right.

Additionally, the division that we use is floor division such that 10 * 9 / 8 equals 11.  This guarantees the result is an integer.

Implement the clumsy function as defined above: given an integer N, it returns the clumsy factorial of N.

 

Example 1:

Input: 4
Output: 7
Explanation: 7 = 4 * 3 / 2 + 1
Example 2:

Input: 10
Output: 12
Explanation: 12 = 10 * 9 / 8 + 7 - 6 * 5 / 4 + 3 - 2 * 1
 

Note:

1 <= N <= 10000
-2^31 <= answer <= 2^31 - 1  (The answer is guaranteed to fit within a 32-bit integer.)




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



1

2

3

4


5


10


11

12


13


14


16


17



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is observation based. Here, since the operations are in a loop and operands are known to us and follow a loop. They
// can be broken into independent groups of four, we calculate value for each group and add it to final result. Since,we are following the
// trend and subtract the neg. part of first group, we add it 2 times to final result for converting it to posi. value. Here, all edge
// cases are handled by assigning the vars default values, if in case they aren't valid(Since, we are handling block size of 4 at a time.
// At the end of iter. we have the sum of all groups in the result var.






class Solution {
public:
    int clumsy(int n) {
        long long int res=0;												// Stores the final result.
        int first=-1;														// Tracks the first neg. contribution.
        for(int i=n;i>0;i-=4){												// Iter. over all nums.
            long long int a=max(i,0), b=max(i-1,1), c=max(i-2,1), d=max(i-3,0);	// Assigning values to all vars.
            if(first==-1) first=(a*b/c);									// Temp. storing first neg. value.
            res+=(-a*b/c)+d;												// Adding contri. to final result.
            // cout<<"val: "<<(-a*b/c)<<" and second: "<<d<<endl;
        }
        res+=2*first;														// Converting first neg. contri. to positive contri.
        return res;															// Returning the factorial sum.
    }
};