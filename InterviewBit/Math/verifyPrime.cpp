/*
*
//****************************************************************Verify Prime.*********************************************************

https://www.interviewbit.com/problems/verify-prime/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



17


16



3


2


1


0


23



101


// Time Complexity: O(sqrt(n)).  
// Space Complexity: O(1).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(sqrt(n))).
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, we iterate over nums till sqrt(num), check whether they divide the target number or not? If they 
// divide, we return 0, if they don't divide it, we return 1.








int Solution::isPrime(int num) {	
    if(num<=1) return 0;													// Base cases.
    if(num<=3) return 1;
    if(num%2==0) return 0;													// Check for even numbers.
    for(int i=3;i*i<=num;i+=2){												// Check whether odd num. divides target num. or not?
        if(num%i==0) return 0;												// If divides, return 0.
    }
    return 1;																// If it's prime, return 1.
}
