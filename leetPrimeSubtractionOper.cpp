/*
*
//******************************************************2601. Prime Subtraction Operation.******************************************************

https://leetcode.com/problems/prime-subtraction-operation/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[4,9,6,10]
[5,8,3]
[5,7,8,14,19,21,26,33,39,43,47]
[3,6,7,8,10,14,16,19,21,25,23,28]
[3,5,6,4,7,12,19]



// Time Complexity: O(mlog(logm)+nlogl).									// m-max. num in the array, n-#nums in the array, l-#primes in the range.
// Space Complexity: O(m+l).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(mlog(logm)+nlogl).									// m-max. num in the array, n-#nums in the array, l-#primes in the range.
// Space Complexity: O(m+l).	
// This algorithm is Sieve, Binary Search based. We use sieve to find primes in the given range. We iter. array and try to dec. each value to the lowest value
// possible to give more possibilities for the later nums to form increasing vals after subtracing primes from them. When at index 'i', we get prev. num after
// changes, and make sure curr. num is >=prev. num+1 after substractions, we calc. how much can we remove(rem) from curr. num while maintaining inc. order, we 
// use upper_bound to find min prime>rem, as we need to remove <=rem for curr. val>=prev. val+1, we take prev. prime of upper_bound which would be <rem, if we 
// don't have such prime, we don't substract any prime number from curr. num and track the curr. num after changes. If the curr. num is already <least possible 
// num in curr. index for an increasing array, we directly return false. If we are able to reach end of array without any issues we return true as we are able
// to form an increasing array.







class Solution {
public:
    
    void sieve(int cap, vector<int>&primes) {								// Sieve to find primes in the given range of nums.
        bool isPrime[cap+1];
        memset(isPrime, true, sizeof(isPrime));
        for(int i=2;i*i<=cap;i++) {
            if(isPrime[i]==false) continue;
            for(int j=i*i;j<=cap;j+=i) isPrime[j]=false;
        }
        for(int i=2;i<=cap;i++) {
            if(isPrime[i]) primes.push_back(i);
        }
        return ;
    }
    
    bool primeSubOperation(vector<int>& v) {
        int i=0;
        for(int i=1;i<v.size();i++) {										// Base condition, if array is already sorted, we avoid the process.
            if(v[i]<=v[i-1]) break;
        }
        if(i==v.size()) return true;
        
        vector<int>primes;
        int maxm=*max_element(v.begin(), v.end());
        sieve(maxm, primes);
        int previous=0;
        for(int& num:v) {													// Iter. over all nums in the arr.
            if(previous+1>num) return false;								// If curr. num is already <least possible curr val for arr to be valid.
            int rem=num-(previous+1);										// we want greatest prime<=rem, so that curr. num-prime>=(prev+1).
            auto ind=upper_bound(primes.begin(), primes.end(), rem);		// We calc. least prime>=rem and move to prev. prime.
            int currPrime=(ind==primes.begin())?0:*(prev(ind));				// If there is not prev. prime we use 0(dont' use prime) else we use prev. prime.
            num-=currPrime;													// Subtract prime from curr. num.
            previous=num;													// Storing curr. num after changes.
            // cout<<"curr num: "<<previous<<endl;
        }
        return true;														// Returning true if we are able to form a increasing array.
    }
};

