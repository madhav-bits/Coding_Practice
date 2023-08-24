/*
*
//************************************************2270. Number of Ways to Split Array.************************************************

https://leetcode.com/problems/number-of-ways-to-split-array/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[10,4,-8,7]
[2,3,1,0]
[4,7,6,5,4,8,-9,-5,-7,8,-5,4,-3,6,-7,8,-9,7,5,-4,3,6,8,8,-7,5]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Suffix sum based. We first calculate sum of all nums in the array. Later, while iterating over array we calc. prefixSum of nums until 'i',
// and keep substracting nums from the suffixSum so that we have sum of indices>'i', if prefixSum>=suffixSum, we inc. res and we continue the process. We 
// return res at the end of iter.







class Solution {
public:
    int waysToSplitArray(vector<int>& v) {
        long long int suffix=accumulate(v.begin(), v.end(), 0ll);
        int res=0;
        long long int prefix=0;
        for(int i=0;i<v.size()-1;i++) {										// Iter. over array.
            prefix+=v[i];													// Calc. prefix sum till 'i'.
            suffix-=v[i];													// Calc. suffix sum till 'i+1' from the last index.
            if(prefix>=suffix) res++;										// If prefixSum>=suffixSum, we inc. res.
        }
        return res;															// We return total #ways to split array.
    }
};


