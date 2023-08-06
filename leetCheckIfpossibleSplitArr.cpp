/*
*
//*********************************************2811. Check if it is Possible to Split Array.********************************************

https://leetcode.com/problems/check-if-it-is-possible-to-split-array/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[2, 2, 1]
4
[2, 3, 3, 2, 3]
6
[2,3,2,3,2,3,2,3,2,3,1]
6
[2,2,2,2,2,2,2,2,2,3,3,2,2,2,2,2,2,2]
6
[1]
1
[1,2]
5



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is observation based. As, we can break the array into subarrays where in every step in can subarr. of length 1 or subarr with sum of vals>target. For this to 
// be possible we need to have atleast 1 pair of adj. indices whose sum>=target, irrespective of the breaks we make to get subarrays we will eventually reach a stage where the 
// subarray size =3, there for use to break it to 2 pieces, we need to have 2 adj. indices with sum>=target, which is what we are looking now. We iter. over array and look for 
// such pair, the moment we find one, we return true. If we didn't find one over the entire iter., we return false.







class Solution {
public:
    bool canSplitArray(vector<int>& v, int target) {
        if(v.size()<=2)  return true;										// Base condition.
        for(int i=0;i+1<v.size();i++) {										// We iter. over entire array.
            if(v[i]+v[i+1]>=target) return true;							// Adj. indices with sum>=target, we return true.
        }
        return false;														// No adj. indices with sum>=target found, so we return false.
    }
};


