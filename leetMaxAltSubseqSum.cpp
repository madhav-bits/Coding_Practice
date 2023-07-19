/*
*
//******************************************************1911. Maximum Alternating Subsequence Sum.******************************************************

https://leetcode.com/problems/maximum-alternating-subsequence-sum/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[4,2,5,3]
[5,6,7,8]
[6,2,1,2,4,5]
[4,5,3,4,7,6,5,4,3,2,1,3,4,5,6,5,4,3,2,5,6,7,8,9,7,6,6,5,4,7,6,5]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Dynamic Programming based. Here, at every step we try to maximize the sum of subseq of even, odd lengths. When at index 'i', we maximize
// subseq. of length even by maximizing evenIndex by curr. num to oddIndexMax until last index, we maximize subseq. of length odd by maximizing evenIndexMax
// till last index-curr. num with oddIndexMax. As there is only dependency b/w two consec. indices and only two states(even/odd index)in subseq., maintaining 
// two vars would work. We do this until last index, we return evenIndexMax, we can safely ignore oddIndexMax because we odd indexmax after substracting a
// value from the even indexMax in curr./prev. indices. evenIndexMax at last index is the max. of all the evenIndexMax in the iteration.







class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long int oddIndexMax=0, evenIndexMax=0;
        for(int&num:nums) {
            long long int tempEven=max(evenIndexMax, oddIndexMax+num);		// Maximizing even length subseq. total
            oddIndexMax=max(oddIndexMax, evenIndexMax-num);					// Maximizeing odd length subseq. total.
            evenIndexMax=tempEven;
        }
        return evenIndexMax;												// Returning the max total of the subsequence.
    }
};

