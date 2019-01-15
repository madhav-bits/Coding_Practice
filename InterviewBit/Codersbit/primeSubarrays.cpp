/*
*
//****************************************************************Prime Subarrays.*********************************************************

https://www.interviewbit.com/problems/prime-subarrays/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



3 1 2 3




5 3 5 1 3 9



7 4 9 4 6 2 5 6




// Time Complexity: O((n^2)*m*sqrt(m)).  									// m is the sum of elements in the array.
// Space Complexity: O(m).	

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O((n^2)*m*sqrt(m)).										// m is the sum of elements in the array.
// Space Complexity: O(m).	
// This algorithm is Steve of EratoSthenes based. Here, we first note all the prime numbers till sum of elements in the array. Next, we start
// from different indices and form subarray's sum starting at those indices. At each step, we check whether sum is equal to prime or not from 
// pre marked primes vector. If the sum is prime, we inc. the count by 1. At the end of iter., we return the count.








int Solution::solve(vector<int> &v) {
    int res=0;																// Tracks #subarrays with prime sum.
    int sum=0;																// Tracks Sum of elements in the array.
    for(auto num:v) sum+=num;												// Get sum of all elements in the array.
    vector<bool>primes(sum+1,true);											// Setting the vector tracking prime numbers to true.
    primes[0]=false; primes[1]=false;										// Base cases.
    for(int i=2;i*i<=sum;i++){												// Implementing Sieve of EratoSthenes algorithm.
        if(primes[i]){					
            for(int j=2*i;j<=sum;j+=i)
                primes[j]=false;											// Marking the multiples of primes as composite number.
        }
    }
    for(int i=0;i<v.size();i++){											// Iterating over diff. start indices for subarrays.
        int total=0;														// Tracks the sum of subarray elements.
        for(int j=i;j<v.size();j++){										// Iter. over array to include elements into subarray.
            total+=v[j];													// Adding the value to subarray sum.
            if(primes[total]) res++;										// If sum is prime, inc. the count.
        }
    }
    return res;																// Returning the count of subarrays with prime sum.
}
