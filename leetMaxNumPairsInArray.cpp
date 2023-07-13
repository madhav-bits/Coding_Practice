/*
*
//******************************************************2341. Maximum Number of Pairs in Array.******************************************************

https://leetcode.com/problems/maximum-number-of-pairs-in-array/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,3,2,1,3,2,2]
[1,1]
[0]
[4,3,2,1,4,5,6,4,3,7,6,5,4,3,8,7,6,5,4,9]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, we form pairs with indices of same value, if a num occur x times, we can form x/2 pairs as only occur. matters. If
// if occurs odd #times, 1 occur. would be leftover as it can be paired with same value. We use this and store #occur. of each num in an array and iter. the
// array and add #pairs=occur[i]/2, #leftOvers=occur[i]%2 to zero, one index of res respectively and return it at the end of iter.







class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        vector<int>occur(101,0);
        for(int&num:nums) occur[num]++;										// Track #occur. of each num.
        vector<int>res({0,0});
        for(int i=0;i<=100;i++) {
            res[0]+=occur[i]/2;												// Adding #pairs curr. num can form to res.
            res[1]+=occur[i]%2;												// Adding #leftovers curr. num will leave to res.
        }
        return res;															// Returning {pairs, leftOvers} formed from the given array.
    }
};

