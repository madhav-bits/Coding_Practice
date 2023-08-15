/*
*
//********************************************2521. Distinct Prime Factors of Product of Array.*****************************************

https://leetcode.com/problems/distinct-prime-factors-of-product-of-array/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[2,4,3,7,10,6]
[2,4,3,8,16]
[4,7,5,4,7,88,6,4,3,3]
[3,9,27,81]
[3,5,7,11]
[5,4,7,78,8,87,6,5,4,322,3,87]



// Time Complexity: O(n*sqrt(m)).											//n-#nums in the array, m-maxm. num in the array.
// Space Complexity: O(m).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*sqrt(m)).											//n-#nums in the array, m-maxm. num in the array.
// Space Complexity: O(m).	
// This algorithm is Factorization based. We iter. over all nums in the array and calc. prime factors for each of the nums and mark them has occurred in another
// array. After iterating the array, we visit primeFactor array and count how many prime factors had occurred while calc. factors for the nums and return the
// count of #primes occurred.

// As the range of nums is small, we used a bool array to track prime factors that occurred while factorizing nums in the array.






class Solution {
public:
    
    void getPrimeFactors(int num, vector<bool>&primeFactors) {				// Calc. prime factors for a number.
        int temp=num;
        while(temp%2==0) {
            primeFactors[2]=true;											// Marking a prime factor has occurred.
            temp/=2;
        }    
        
        for(int i=3;i*i<=num;i+=2) {
            if(temp%i!=0) continue;
            primeFactors[i]=true;
            while(temp%i==0) temp/=i;
        }
        if(temp>1) primeFactors[temp]=true;
        return ;
    }
    
    int distinctPrimeFactors(vector<int>& v) {
        int res=0;
        int maxm=*max_element(v.begin(), v.end());
        vector<bool>primeFactors(maxm+1, false);
        for(int&num:v) {													// Iter. over all nums and calc. their prime factors.
            getPrimeFactors(num, primeFactors);
        }
        for(int i=1;i<=maxm;i++) {											// Iter. and counting #prime factors that occurred while factorizing nums in arr.
            if(primeFactors[i]) res++;
        }
        return res;															// Returning total #unique prime factors that occurred while factorizing nums.
    }
};


