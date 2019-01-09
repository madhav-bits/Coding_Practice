/*
*
//************************************************************Largest Coprime Divisor.*****************************************************

https://www.interviewbit.com/problems/largest-coprime-divisor/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


30
11




27
6



64
20




70
51




// Time Complexity: O(n).  													// Not exactly linear, as it depends on prime factors of A.
// Space Complexity: O(1).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// Not exactly linear, as it depends on prime factors of A.
// Space Complexity: O(1).	
// This algorithm is recursion based. Here, since we need a factor whose prime factors shouldn't match with that of B. We keep on removing 
// common prime factors of A and B from A, such that we get a factor which doesn't have common prime divisors to that of B, that is gcd is 1.










int gcd(int num1, int num2){												// Calc. gcd of two numbers.
    if(num1==0) return num2;												// num1 is divisor and num2 is dividend.
    return gcd(num2%num1, num1);
}

int Solution::cpFact(int A, int B) {
    int val=gcd(A,B);														// Calc. common maximum prime factors among two numbers to remove.
    while(val!=1){															// Until there exists common prime factors other than 1.
        A/=val;																// Removing common prime factors from A.
        val=gcd(A,B);														// Calc. new largest group of common prime factors.
    }
    return A;																// Returning largest coprime divisor.
}