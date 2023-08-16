/*
*
//*************************************************2310. Sum of Numbers With Units Digit K.************************************************

https://leetcode.com/problems/sum-of-numbers-with-units-digit-k/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


58
9
37
2
0
7
1997
7
2996
3
2
8



// Time Complexity: O(1).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(1).	
// This algorithm is observation based. If we add integers with units digit 'k', we observe a cycle of length 10 for the units digit of the sum, they keep 
// repeating so we only need to check for sets of length 10. We mainly concentrate on the units digit of the sum and units digit of given num because once
// the units digit matches, we can place any combination of nums in tens, hundreds... digits in all the nums which add up to (given num-k*i). We need to observe
// that if even after units digits matches but i*k>given num, then we can't form any subset and iterating will be of no use as i*k is only going to increase 
// as we iter. forward, so we return -1. If units digit matches and i*k<given num, we return #nums in the set->'i'.







class Solution {
public:
    int minimumNumbers(int num, int k) {
        if(num==0) return 0;
        int numUnit=num%10;
        for(int i=1;i<=10;i++) {											// Checking until sets of length<=10.
            int currUnit=(i*k)%10;
            if(currUnit==numUnit) {											// If Units digit of given num and sum of nums in sets matches.
                if(i*k>num) return -1;										// If sum of unit's digits in set>given num, we return -1.
                return i;													// Else we return #nums in the set.
            }
        }
        return -1;															// Returning -1 as no such set found.
    }
};

