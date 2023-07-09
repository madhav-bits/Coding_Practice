/*
*
//******************************************************2761. Prime Pairs With Target Sum.******************************************************

https://leetcode.com/problems/prime-pairs-with-target-sum/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


10
2
1000000
848488
325535
97
12345



// Time Complexity: O(nlog(log(n))).
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlog(log(n))).
// Space Complexity: O(n).	
// This algorithm is Sieve of Eratostehenes based. First, we do sieve to find out list of primes in the given range of nums, we use pointer method to iter. 
// over this list of primes while ensuring prime1<=prime2 and add these pairs to res.







class Solution {
public:
    
    vector<int> getPrimes(int cap) {										// Sieve to find the list of primes.
        // vector<bool>isPrime(cap+1, true);
        bool isPrime[cap+1];
        memset(isPrime, 1, sizeof(isPrime));
        for(int i=2;i*i<=cap;i++) {
            for(int j=i*i;j<=cap;j+=i) {
                isPrime[j]=false;
            }
        }
        vector<int>primes({2});
        for(int i=3;i<=cap;i+=2) {
            if(isPrime[i]) primes.push_back(i);
        }
        return primes;
    }
    
    vector<vector<int>> findPrimePairs(int n) {
        vector<vector<int>>res;
        vector<int>primes=getPrimes(n);
        int i=0,j=primes.size()-1;
        while(i<=j) {														// Two ptr method to iter. over primes and return pairs whose sum is target.
            if(primes[i]+primes[j]<n) i++;									// If sum is<target, inc. left ptr.
            else if(primes[i]+primes[j]>n) j--;								// If sum is>target, dec. right ptr.
            else {															// If sum is =target, add this pair to res.
                res.push_back({primes[i++], primes[j--]});
            }
        }
        return res;															// Returning prime pairs whose sum is target.
    }
};










//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlog(log(n))).
// Space Complexity: O(n).
// This algorithm is same as the last one, instead of creating separate functions and copying the primes list, we simply use the isPrime array used in sieve,
// iter. in the first half of this array, check if pairs are prime during this iter. and add to res if both are true and return the res at the end of iter.





class Solution {
public:
    
    vector<vector<int>> findPrimePairs(int n) {
        bool isPrime[n+1];
        memset(isPrime, true, sizeof(isPrime));
        for(int i=2;i*i<=n;i++) {											// Sieve to calc. and identify primes in the given range.
            for(int j=i*i;j<=n;j+=i) {
                isPrime[j]=false;
            }
        }
        if(2<=n/2 && isPrime[n-2]) res.push_back({2,n-2});					// Base case.
        for(int i=3;i<=n/2;i+=2) {											// Iter. in first half of range of nums.
            if(isPrime[i] && isPrime[n-i]) res.push_back({i, n-i});			// If prime pair found, add them to res.
        }
        return res;															// Returning prime pairs whose sum is target.
    }
};