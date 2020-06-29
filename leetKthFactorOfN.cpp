/*
*
//***************************************************1492. The kth Factor of n.***************************************************

https://leetcode.com/problems/the-kth-factor-of-n/description/



Given two positive integers n and k.

A factor of an integer n is defined as an integer i where n % i == 0.

Consider a list of all factors of n sorted in ascending order, return the kth factor in this list or return -1 if n has less than k factors.

 

Example 1:

Input: n = 12, k = 3
Output: 3
Explanation: Factors list is [1, 2, 3, 4, 6, 12], the 3rd factor is 3.
Example 2:

Input: n = 7, k = 2
Output: 7
Explanation: Factors list is [1, 7], the 2nd factor is 7.
Example 3:

Input: n = 4, k = 4
Output: -1
Explanation: Factors list is [1, 2, 4], there is only 3 factors. We should return -1.
Example 4:

Input: n = 1, k = 1
Output: 1
Explanation: Factors list is [1], the 1st factor is 1.
Example 5:

Input: n = 1000, k = 3
Output: 4
Explanation: Factors list is [1, 2, 4, 5, 8, 10, 20, 25, 40, 50, 100, 125, 200, 250, 500, 1000].
 

Constraints:

1 <= k <= n <= 1000




*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


100, 12

1000, 29


13,3

256, 14



// Time Complexity: O(n^0.5).
// Space Complexity: O(n^0.5).												// The #facrors is extremely random, I just made it=Time Compl.

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^0.5).
// Space Complexity: O(n^0.5).												// The #facrors is extremely random, I just made it=Time Compl.	
// This algorithm is iteration based. Here, we iter. over all nums and store their factors in two arrays. Factors <=sqrt(n) in small arr., 
// greater than sqrt(n) is stored in large array. If small arr. size>=k, we return values to small array, else we move to large array, we 
// change the required index accordingly as factors are stored in desc. order in large array. If factor number is larger than large arr. 
// we return -1. 






class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int>small, large;											// Store the factors.
        for(int i=1;i*i<=n;i++){											// Iter. over all nums and find factors.
            if(n%i!=0) continue;
            small.push_back(i);												// Factors<=sqrt(n) are stored in small arr.
            if(i!=(n/i)) large.push_back(n/i);								// Factors>sqrt(n) are stored in large arr.
            // cout<<"small: "<<small.back()<<" and large: "<<large.back()<<endl;
        }
        if(k<=small.size()) return small[k-1];								// Returning the factor from small arr.
        k-=small.size();													// Refactoring target factor number.
        if(k>large.size()) return -1;										// If target is> large arr. size, then there is no such factor.
        return large[large.size()-k];										// Returning the factor from large arr.
    }
};
