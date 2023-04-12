s/*
*
//******************************************************2395. Find Subarrays With Equal Sum.******************************************************

https://leetcode.com/problems/find-subarrays-with-equal-sum/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[4,2,4]
[1,2,3,4,5]
[0,0,0]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Map based. Here, we iter. over given array, we calc. subarrays ending with curr. index and check whether such sum had been encountered in the past, if yes we return true.
// If no duplicate sums are found in the iter. we return false.







class Solution {
public:
    bool findSubarrays(vector<int>& v) {
        unordered_set<int>m;																			// Stores all prev. occured sums.
        for(int i=1;i<v.size();i++) {																	// Iter. over array.
            int total=v[i]+v[i-1];																		// Get total of subarray ending with curr. index.
            if(m.count(total)==1) return true;															// If curr. total is encountered prev., then return true.
            m.insert(total);																			// Inserting curr. total into set.
        }
        return false;																					// No duplicate subarray total found.
    }
};

