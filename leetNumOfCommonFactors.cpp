/*
*
//******************************************************2427. Number of Common Factors.******************************************************

https://leetcode.com/problems/number-of-common-factors/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


12
6
25
30
48
64
68
30
990
124
345
890



// Time Complexity: O(log(min(a,b))+min(a,b)).
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(log(min(a,b))+min(a,b)).
// Space Complexity: O(1).	
// This algorithm is iteration+GCD based. Since the divisors have to divide both the numbers, the divisors have to be divisors of gcd of both the numbers. We iter from 1 to gcd and count
// all those instances where we can divide both the numbers a, b.







class Solution {
public:
    
    int calculateGCD(int a, int b) {										// Calculates GCD of two numbers.
        if(b==0) return a;
        return calculateGCD(b, a%b);
    } 
    
    int commonFactors(int a, int b) {
        // int cap=min(a, b), res=0, i=1;
        // for(i=1;i<=cap;i++) {
        //     if(a%i==0 && b%i==0) res++;
        // }
        // return res;
        
        
        
        int gcd=calculateGCD(a, b), res=0;
        for(int i=1;i<=gcd;i++) {											// Count #divisors of gcd which divides both numbers.
            if(gcd%i==0) res++;
        }
        return res;															// Return the #common factors.
    }
};









//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(min(a,b)).
// Space Complexity: O(1).	
// This algorithm is iteration based. We iterate from 1 to min(a,b) and count all those numbers which can divide both numbers.








class Solution {
public:
    
    int commonFactors(int a, int b) {
        int cap=min(a, b), res=0, i=1;										
        for(i=1;i<=cap;i++) {												// Iterate till the least of both of numbers and count #divisors which divides both numbers.
            if(a%i==0 && b%i==0) res++;
        }
        return res;															// Return the #common factors.
    }
};

