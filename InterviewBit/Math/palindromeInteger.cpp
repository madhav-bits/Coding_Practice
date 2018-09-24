/*
*
//************************************************************Palindrome Integer.*****************************************************


https://www.interviewbit.com/problems/palindrome-integer/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



-1

0

1

10


100

20


21

1221

12321




// Time Complexity: O(logn/log10).  
// Space Complexity: O(1).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(logn/log10).
// Space Complexity: O(1).	
// This algorithm is iteration based. We remove digits from the number one by one and forming reverse integer from the deleted ones. If at any 
// iteration, the remaining and deleted digits are same, then we have a palindrome integer. As,we may have odd/even length palin. In each iter. 
// we check whether both ints are same before, after adding curr. deleted digit.







int Solution::isPalindrome(int num) {
    if(num<0) return false;													// Neg. values aren't palindrome.
    if(num<10) return true;													// Single digit nums.
    if(num%10==0) return false;												// As, there are no leading zeroes, 10 factors aren't palin.
    int del=0;																// Stores reverse integer.
    while(num>del){
        int rem=num%10;														// Deleting ones digit.
        num/=10;															// Calc. remaining digits.
        if(del==num) return true;											// Odd length palin.(Not considering middle digit).
        del=(del*10)+rem;													// Adding curr. deleted digit into reversed num.
        if(del==num) return true;											// Even length palin.
        // cout<<"rem: "<<rem<<" num: "<<num<<endl;
    }
    return false;															// If not a palindrome, return false.
}
