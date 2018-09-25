/*
*
//**************************************************************Reverse integer.*******************************************************



https://www.interviewbit.com/problems/reverse-integer/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



1

-10

-9

1

10

9

-2147483648


2147483647





// Time Complexity: O(logn/log10).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logn/log10).
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, we pass only positive values to the function, and reverse it. After obtaining the result, if the given 
// int is neg, we convert the result to neg.. After that whether the result is overflowing(less than INT_MIN, greater than INT_MAX), if it is
// return 0. If with in ranges of int, we return the result. 

// We reverse the integer by removing each digit at a time, we form the reverse num from removed digits by summing up the removed ints.







long revInt(int num){														
    long res=0;																// Tracks reversed int.
    while(num){																// Until all digits are extracted from given num.
        int rem=num%10;														// Extracting LSdigit from give num.
        res=(res*10)+rem;													// Adding curr. digit to prev. removed digits.
        num/=10;															// Removing LSdigit from give num.
    }
    return res;																// Returning the reversed num.
}

int Solution::reverse(int num) {
    if(num>=-9 && num<=9) return num;										// Base cases.
    int sign=1;																// Stores whether given num is neg. or not.
    if(num<0) sign=-1;														// Stores if given num is neg.
    long res=revInt(abs(num));												// Calling fn. to reverse the int.
    res*=sign;																// Multiplying with sign of orig. int.
    if(res<INT_MIN || res>long(INT_MAX)) return 0;							// If overflowed, return 0.
    return (int)res;														// Else, return the reversed int.
}
