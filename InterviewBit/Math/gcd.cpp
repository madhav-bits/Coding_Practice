/*
*
//**********************************************************Greatest Common Divisor.***************************************************


https://www.interviewbit.com/problems/greatest-common-divisor/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



12
9


1
0

0
3


12
3



// Time Complexity: O(logn).  												// Not exactly, as it depends on divisor.
// Space Complexity: O(1).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(logn).												// Not exactly, as it depends on divisor.
// Space Complexity: O(1).	
// This algorithm is division based. This is just implementation of classic way of calculating GCD. One base to focus on is when the smaller 
// number is 0, we return the larger value.








int Solution::gcd(int num1, int num2) {										
    if(num1<num2) return gcd(num2,num1);									// Making num1 as greater value.
    if(num2==0) return num1;												// If smaller num is 0, return greater num.
    int rem=num1%num2;														// Calc. remainder.
    if(rem==0) return num2;													// If rem=0, return smaller number(divisor).
    return gcd(num2,rem);													// Else, enter next step of calculating GCD.
}
