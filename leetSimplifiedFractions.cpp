/*
*
//******************************************************1447. Simplified Fractions.***********************************************

https://leetcode.com/problems/simplified-fractions/description/

Given an integer n, return a list of all simplified fractions between 0 and 1 (exclusive) such that the denominator is 
less-than-or-equal-to n. The fractions can be in any order.

 

Example 1:

Input: n = 2
Output: ["1/2"]
Explanation: "1/2" is the only unique fraction with a denominator less-than-or-equal-to 2.
Example 2:

Input: n = 3
Output: ["1/2","1/3","2/3"]
Example 3:

Input: n = 4
Output: ["1/2","1/3","1/4","2/3","3/4"]
Explanation: "2/4" is not a simplified fraction because it can be simplified to "1/2".
Example 4:

Input: n = 1
Output: []
 

Constraints:

1 <= n <= 100




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


4

3

1

2

12

100



// Time Complexity: O(n^2*logn).  									// logn is for calculating GCD, it is log(numer.+denom.) in precise.
// Space Complexity: O(n^2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2*logn).									// logn is for calculating GCD, it is log(numer.+denom.) in precise.
// Space Complexity: O(n^2).	
// This algorithm is GCD based. Here, we iter. over 1 to n for numerators, and over i+1 to n for denominators. Since, we are trying 
// to get simplified fractions, the numerator and denominator shouldn't have any factor other than 1. So, we find gcd of numer, denom.
// for every pair, we gcd is 1, we take the pair and push into final fractions list. At the end of iter., we return the list.







class Solution {
public:
    
    int gcd(int a, int b){													// GCD algorithm.
        if(a==0) return b;
        return gcd(b%a,a);
    }
    
    vector<string> simplifiedFractions(int n) {
        vector<string>res;													// Stores simplified fractions.
        if(n==1) return res;
        for(int i=1;i<n;i++){												// Iter. over all possible numer.
            for(int j=i+1;j<=n;j++){										// Iter. over denoms. possibilities for each numer.
                if(i!=1 && gcd(i,j)!=1) continue;							// If gcd is not 1, skip the pair.
                res.push_back(to_string(i)+"/"+to_string(j));				// Store the pair of nums.
            }
        }
        return res;															// Returning the list of simplified fractions.
    }
};