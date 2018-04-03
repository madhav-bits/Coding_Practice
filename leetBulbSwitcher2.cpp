/*
*
//**********************************************************672. Bulb Switcher II.***************************************************

There is a room with n lights which are turned on initially and 4 buttons on the wall. After performing exactly m unknown operations towards 
buttons, you need to return how many different kinds of status of the n lights could be.

Suppose n lights are labeled as number [1, 2, 3 ..., n], function of these 4 buttons are given below:

Flip all the lights.
Flip lights with even numbers.
Flip lights with odd numbers.
Flip lights with (3k + 1) numbers, k = 0, 1, 2, ...
Example 1:
Input: n = 1, m = 1.
Output: 2
Explanation: Status can be: [on], [off]
Example 2:
Input: n = 2, m = 1.
Output: 3
Explanation: Status can be: [on, off], [off, on], [off, off]
Example 3:
Input: n = 3, m = 1.
Output: 4
Explanation: Status can be: [off, on, off], [on, off, on], [off, off, off], [off, on, on].
Note: n and m both fit in range [0, 1000].




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


1,1
2,1
3,1
2,2
3,2



// Time Complexity: O(1).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).	
// Space Complexity: O(1).	
// This algorithm **********************************IS TOO TRICKY AND OBSERVATION ORIENTED.***********************************************



class Solution {
public:
    int flipLights(int n, int m) {				// We start discussing from the basic cases.
        if(n==0 || m==0) return 1;				// If m=0 or n==0 one case is possible(Bulb begin On or No bulbs at all).
        if(n==1) return 2;						// If n==1 with m>0 two cases are possible.
        if(n==2) return (m==1)?3:4;				// If n=2 and with m=1 ->3 cases possible(All Bulbs On not possib). With m>1 All bulbs is possible.
        if(m==1) return 4;						// Now with m=1 and n>2 4 types are possible( All Off, Even Off, Odd Off, This Pattern #bulbs Off).
        return m==2?7:8;						// Now with m=2 and n>2 7 types are possible( Patterned Off on All Bulbs On case for final 
    }											// - switch isn't possible), where as for with m>2 this case is also possible. So, 8 possib. then.
};