/*
*
//******************************************************1175. Prime Arrangements.******************************************************

https://leetcode.com/problems/prime-arrangements/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


5
100
97
91
69
64
43
8
2
1
3
5
4
10
8
9
6
25



// Time Complexity: O(nlog(logn)).
// Space Complexity: O(n).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*sqrt(n)).
// Space Complexity: O(1).	
// This algorithm is observation based. We call the function to determine whether a number is prime or not. We get #primes and #non-primes, we iter. over
// numbers, if curr. num is prime, we multiply curr. primeCount with prev. #ways and this would give factorial(#primes) which is #ways in which #primes nums
// can be arranged among themselves. We do the same with non-primes too, we multiply both these #ways to get total #ways in which all nums can be arranged 
// and return it.







class Solution {
public:
    
    bool isPrime(int num) {													// Calc. given num is prime or not.
        if(num==1) return false;
        if(num==2) return true;
        if(num%2==0) return false;
        for(int i=3;i*i<=num;i+=2) {
            if(num%i==0) return false;
        }
        return true;
    }
    
    
    int numPrimeArrangements(int n) {
        int res=0, mod=1000000007;
        int nonPrime=1, prime=1;
        int npCount=0, pCount=0;
        for(int i=1;i<=n;i++) {
            if(isPrime(i)) {
                pCount++;
                prime=(1ll*prime*pCount)%mod;							// Calc. #ways in curr. available primes can be arranged.
            }else {
                npCount++;
                nonPrime=(1ll*nonPrime*npCount)%mod;					// Calc. #ways in curr. available non-primes can be arranged.
            }
        }
        return (1ll*prime*nonPrime)%mod;								// Returning the total #ways in which all primes, non-primes can be arranged.
    }
};








//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlog(logn)).
// Space Complexity: O(n).	
// This algorithm is Sieve of Erathosthenes based. We use this technique to mark all the composite numbers, get primes and composite numbers count, calc.
// number of ways thes two types of nums can be arranged differently among themselves and multiply these two number of ways to get total #ways and return it.




// A link for quick Sieve of Erathosthenes recap: https://www.geeksforgeeks.org/sieve-of-eratosthenes/






class Solution {
public:
    
    int getPrimeCount(vector<bool>&v) {
        v[1]=false;
        for(int i=2;i<v.size();i++) {
			if(v[i]==false) continue;
            for(int j=i*i;j<v.size();j+=i) v[j]=false;
        }    
        int primes=0;
        for(int i=1;i<v.size();i++) {
            if(v[i]) primes++;
        }
        return primes;
    }
    
    int numPrimeArrangements(int n) {
        int res=0, mod=1000000007;
        
        vector<bool>v(n+1, true);
        int primes=getPrimeCount(v);
        int nonPrimes=n-primes;
        int primeCount=1, nonPrimeCount=1;
        
        while(primes) {
            primeCount=(1ll*primeCount*primes)%mod;
            primes--;
        }
        
        while(nonPrimes) {
            nonPrimeCount=(1ll*nonPrimeCount*nonPrimes)%mod;
            nonPrimes--;
        }
        
        return (1ll*primeCount*nonPrimeCount)%mod;
    }
};

