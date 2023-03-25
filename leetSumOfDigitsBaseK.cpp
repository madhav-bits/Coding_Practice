/*
*
//******************************************************1837. Sum of Digits in Base K.******************************************************

https://leetcode.com/problems/sum-of-digits-in-base-k/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


34
6
39
6
48
6
49
6
10
10
49
7
99
9
98
8
100
10
100
9



// Time Complexity: O(logn(basek)).																		// n-#number provided, k-base the given number has to be converted to.
// Space Complexity: O(1).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logn(basek)).																		// n-#number provided, k-base the given number has to be converted to.
// Space Complexity: O(1).	
// This algorithm is iteration based. We convert the num to base k, in the process, we add the converted bits and return the total.







class Solution {
public:
    int sumBase(int n, int k) {
        int res=0;
        while(n) {																						// Converting n from base 10 to base k.
            res+=n%k;																					// Adding the digits(in base k).
            n/=k;
        }
        return res;
    }
};

