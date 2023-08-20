/*
*
//***************************************2829. Determine the Minimum Sum of a k-avoiding Array.****************************************

https://leetcode.com/problems/determine-the-minimum-sum-of-a-k-avoiding-array/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


5
4
2
6
4
10
5
10
6
10
19
10
4
9
5
9
3
9
12
9
16
9
23
45



// Time Complexity: O(n+k).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n+k).
// Space Complexity: O(1).	
// This algorithm is Greedy+Observation based. Here, as we want min sum of nums, we pick the least possible values in every step. As any pair of nums chosen
// shouldn't add up to 'k', we pick first half [0, k/2] and ignore second half till 'k': (k/2,k], because we greedily pick the first half nums to get least sum,
// if we had reached a stage to consider picking second half nums that means all first half nums are already picked, now any num in second half would pair with
// one in first half leading to a total of 'k', which is undesirable. To fill up for the remaining nums, we pick nums to the right of k, as they are >k, adding
// any num to them would make total='k'. If the req. nums<k/2, we simply pick as many required and return their total.







class Solution {
public:
    
    int getSumRange(int start, int len) {									// As the range is small, we iter. calc. their total rather than formula.
        int res=0;
        for(int i=0;i<len;i++) {											// Iter. over nums in consideration and adding them.
            res+=start+i;
        }
        return res;															// Returning sum of nums in consideration.
    }
    
    int minimumSum(int n, int k) {
        if(n<=k/2) return getSumRange(1, n);								// If req. num<k/2, we pick as many req. and return total.
        return getSumRange(1,k/2) + getSumRange(k, n-k/2);					// Calling fn. to calc. sum of nums in consideration and return total of two parts.
    }
};

