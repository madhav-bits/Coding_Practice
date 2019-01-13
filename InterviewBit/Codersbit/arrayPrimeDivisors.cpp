/*
*
//************************************************************Array and Prime Divisors.*****************************************************


https://www.interviewbit.com/problems/array-and-prime-divisors/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



2 2 4
1000000



5 1 2 3 4 5
6




// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is iteration based. I had used "SIEVE OF ERATOSTHENES" to mark numbers till target number whether they are prime or not? Then we 
// iterate over the given array and check whether they are prime are not and they divide given number or not? If it divides, inc. the count and
// return the count at the end of iteration.








int Solution::solve(vector<int> &v, int num) {
    vector<bool>prime(num+1, true);											// Tracks whether a num is prime or not.
    prime[0]=false;prime[1]=false;											// Marking 0,1 as composite number.
    for(int i=2;i<=num;i++){												// Iter. over nums and marking prime's mulitples as composite.
        if(prime[i]==false) continue;										// If curr. num is composite, skip it.
        // cout<<"i: "<<i<<endl;
        for(int j=2*i;j<=num;j+=i){											// Marking all mulitples of prime till target num. as composite.
            prime[j]=false;
        }
    }
    int res=0;																// Tracks #prime divisors of given number.
    for(auto dig:v){														// Iter. over given numbers.
        if(prime[dig]==true && num%dig==0) res++;							// If curr. num is prime and divisor of given number, inc. the count.
    }
    return res;																// Return the count of prime divisors.
}
