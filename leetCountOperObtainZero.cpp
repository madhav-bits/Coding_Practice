/*
*
//******************************************************2169. Count Operations to Obtain Zero.******************************************************

https://leetcode.com/problems/count-operations-to-obtain-zero/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


2
3
10
10
4748
4858
10000
497
256
8
8
256
8
257



// Time Complexity: O(logn).  												// n-max. num provided.
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logn).												// n-max. num provided.
// Space Complexity: O(1).	
// This algorithm is Observation based. Here, we use modulus to dec. the greater number to new number which is less than smaller number of the two rather than
// substracting smaller number from the greater one until becomes smaller. If greater number is divisible by smaller number, it gets converted to zero, as part
// of process.

// Time Complexity is O(logn) because at every step the bigger number gets converted to half of the smaller number in the worst case scenario, if it happens
// all the time, it takes (logn) time/( '/', '%' oper) for the num to get to zero.





class Solution {
public:
    int countOperations(int num1, int num2) {
        int res=0;
        while(num1!=0 && num2!=0) {											// If num1 is greater.
            if(num1>=num2) {
                res+=num1/num2;												// This gives #steps to convert num1 to a num<num2.
                num1%=num2;													// This gives modified/new num after all the oper on num1 by num2.
            }else {															// If num1 is greater.
                res+=num2/num1;
                num2%=num1;
            }
        }
        return res;															// Returning the total #operations required.
    }
};

