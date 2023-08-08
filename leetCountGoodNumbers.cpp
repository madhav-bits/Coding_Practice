/*
*
//******************************************************1922. Count Good Numbers.******************************************************

https://leetcode.com/problems/count-good-numbers/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


1
2
3
4
5
6
7
50
100
1000000
13840209480234
13840209480235
2644669545352



// Time Complexity: O(logn).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logn).
// Space Complexity: O(1).	
// This algorithm is Observation based. Here, for every zero index, we can place 5 even digits, in odd indices, we can place 4 prime numbers. So, we see a pattern that for a 
// string of n length, (n+1)/2 even indices each have 5 possible digits in them, n/2 odd indices each have 4 prime digits in them. We multiply all these possibilities to get 
// total #good strings of length 'n' that satisfies the conditions.







class Solution {
public:
    
    int getPower(int num, long long int exp) {								// Calculates value of 'num' to the power of 'exp'.
        int mod=1000000007, res=1;    
        while(exp>0) {
            if((exp&1)!=0) res=(1ll*res*num)%mod;
            exp>>=1;
            num=(1ll*num*num)%mod;
        }
        return res;
    }
    
    int countGoodNumbers(long long n) {
        int mod=1000000007, prod=5, len=1;
        int res=getPower(20, n/2);											// As 5^n/2, 4^n/2 have same power, we club both of them leading to 20^n/2
        if(n%2==1) res=(1ll*res*5)%mod;										// If n is odd, we multiply with 5 one more time.
        return res;															// Returning the total #good strings of length 'n' that satisfies the conditions.
    }
};

