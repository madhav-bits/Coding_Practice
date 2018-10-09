/*
*
//**********************************************************866. Prime Palindrome.*****************************************************

Find the smallest prime palindrome greater than or equal to N.

Recall that a number is prime if it's only divisors are 1 and itself, and it is greater than 1. 

For example, 2,3,5,7,11 and 13 are primes.

Recall that a number is a palindrome if it reads the same from left to right as it does from right to left. 

For example, 12321 is a palindrome.

 

Example 1:

Input: 6
Output: 7
Example 2:

Input: 8
Output: 11
Example 3:

Input: 13
Output: 101
 

Note:

1 <= N <= 10^8
The answer is guaranteed to exist and be less than 2 * 10^8.



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


100


1


2

132231


312



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Observation based. One most important observation is that even palindromes aren't Prime numbers. So, we just focus on odd
// length palindromes, which we build using integers starting from 1(Creating a string from curr. num, reversing around last digit). We, check
// whether this num is prime or not? If it's prime and >=given num. then, we return this number.


// This link has even detailed explanation of below algorithm:
// https://leetcode.com/problems/prime-palindrome/discuss/146798/Search-Palindrome-with-Even-Digits





class Solution {
public:
    
    bool isPrime(int num){													// Returns whether prime number or not?
        if(num<=2) return (num==2);											// Base cases.
        if(num%2==0) return false;
        for(int i=3;i*i<=num;i+=2){
            if(num%i==0) return false; 										// If divisible, not a prime.
        }
        return true;														// If prime, return true.
    }
    
    int primePalindrome(int N) {
        if(8<=N && 11>=N) return 11;										// Base cases.
        for(int i=0;i<100000;i++){											// Start using nums from 1.
            string temp=to_string(i);										// Stringigy curr. num.
            string rev=temp;												// Reverse curr. num.
            reverse(rev.begin(), rev.end());								
            temp=temp+rev.substr(1);										// Get odd length Palin. string by reversing around last digit.
            int num=stoi(temp);												// Get it's num. rep.
            if(num>=N && isPrime(num)) return num;							// If curr. num is prime and greater than given num, return curr. num
        }
        return -1;															// If no such num. found return -1.
    }
};