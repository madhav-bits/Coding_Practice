/*
*
//******************************************************2433. Find The Original Array of Prefix Xor.******************************************************

https://leetcode.com/problems/find-the-original-array-of-prefix-xor/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[5,2,0,3,1]
[13]
[5,4,23,21,25,43,23,26,54,34,7,9,8,6,45,46,56,7,8,9,67,65,90,9,5,4,3,6]



// Time Complexity: O(n!).  
// Space Complexity: O(n*n!).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n!).
// Space Complexity: O(n*n!).	
// This algorithm is observation based. pref[i] is XOR of all prev. indices till 'i', if we XOR pref[i] with pref[i-1] that will negate/remove all the prev. nums upto 'i-1' indices and only index 'i'
// remains, which we append to res. We use same technique to update all indices of res and return it at the end of iter.







class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int>res(pref.size(),0);
        res[0]=pref[0];																					// Init. value at index-'0'.
        for(int i=1;i<pref.size();i++) {
            res[i]=pref[i]^pref[i-1];																	// This would result in the orig. number at index 'i'. 
        }
        return res;																						// Returning the orig. array.
    }
};

