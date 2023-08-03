/*
*
//******************************************************1979. Find Greatest Common Divisor of Array.******************************************************

https://leetcode.com/problems/find-greatest-common-divisor-of-array/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[2,5,6,9,10]
[7,5,6,8,3]
[3,3]




// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. We iter. over array and track the min, max values in the array, calc their gcd and return it.







class Solution {
public:
    
    int gcd(int minm, int maxm) {											// Calc. gcd of two nums.
        while(minm) {
            int rem=maxm%minm;
            maxm=minm;
            minm=rem;
        }
        return maxm;
    }
    
    int findGCD(vector<int>& nums) {
        int res=-1, minm=INT_MAX, maxm=INT_MIN;
        for(int num:nums) {													// Iter. over entire array.
            if(num>maxm) maxm=num;											// Tracking minm, maxm values in the array.
            if(num<minm) minm=num;
        }
        return gcd(minm, maxm);												// Returning GCD of minm, maxm values in the array.
    }
};

