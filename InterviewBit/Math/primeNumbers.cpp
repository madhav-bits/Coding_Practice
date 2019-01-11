/*
*
//****************************************************************Prime Numbers.*********************************************************

https://www.interviewbit.com/problems/prime-numbers/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



1


2



7


10



19


99





// Time Complexity: O(n^2).													// Not exactly, this is more than actual time complexity.  
// Space Complexity: O(n).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).													// Not exactly, this is more than actual time complexity.
// Space Complexity: O(n).	
// This algorithm is iteration based. The main conecpt is that, every number can be decomposed into prime factors. We iterate from 2 to given num. 
// In the process, whenever we encounter a prime number, we mark all it's multiples till the target range mentioned as non-prime. In the iter.
// by the time we reach a number, if it's still marked as prime, then there are no prime factors to it, so it's prime. At the end of whole
// process, we iter. over primes array, all the indices marked as prime would be pushed into final result vector.



// This method is Sieve of Eratosthenes.




vector<int> Solution::sieve(int n) {
    vector<int>res;															// Stores final prime numbers.
    vector<bool>primes(n+1, true);											// Tracks whether a number is prime or not.
    for(int i=2;i<=n;i++){													// Iter. over all nums.
        if(primes[i]==true){												// If a num. is prime.
            for(int j=i*2;j<=n;j+=i){										// Mark all it's multiples till given limit as non-prime.
                primes[j]=false;
            }
        }
    }
    for(int i=2;i<=n;i++){													// Iter. ove all nums in range from 2.
        if(primes[i]) res.push_back(i);										// Push the primes into final result vector.
    }
    return res;																// Return the list of primes in the range.
}
