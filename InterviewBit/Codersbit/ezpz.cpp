/*
*
//******************************************************************EZPZ.***********************************************************

https://www.interviewbit.com/problems/ezpz/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



14



50


6



17



// Time Complexity: O(sqrt(n)).  
// Space Complexity: O(1).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(sqrt(n)).
// Space Complexity: O(1).	
// This algorithm is Number Theory based. This is based on Goldbach Conjecture, which states that every even number <4*(10^18), can be written as 
// sum of two prime numbers. Here, if numbers<=1 is given, return -1, if an even number is given, return 2. If odd is given, check if it's prime, 
// then return 1, else check if number-2 is prime, if it is return 2, else number-3 would be even( sum of 2 primes) and we return 3 as a result.




// https://en.wikipedia.org/wiki/Goldbach%27s_conjecture
// This link has description of Goldbach Conjecture.



bool isPrime(int target){													// Checks whether number. is prime or not.
    if(target%2==0) return false;
    for(int i=3;i*i<=target;i+=2){
        if(target%i==0) return false;
    }    
    return true;
}

int Solution::solve(int target) {
    if(target<=1) return -1;												// Base case.
    if(target%2==0) return 2;												// If number is even, return 2.
    if(isPrime(target)) return 1;											// If given number is prime.
    if(isPrime(target-2)) return 2;											// If number-2 is prime number.
    return 3;																// As number-3 is even(sum of 2 prime no.) and 3 would make 3 prime nums.
}
