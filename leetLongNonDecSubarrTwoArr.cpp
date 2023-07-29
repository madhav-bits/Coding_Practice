/*
*
//*******************************************2771. Longest Non-decreasing Subarray From Two Arrays.***************************************

https://leetcode.com/problems/longest-non-decreasing-subarray-from-two-arrays/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[2,3,1]
[1,2,1]
[1,3,2,1]
[2,2,3,4]
[1,1]
[2,2]
[11,7,7,9]
[19,19,1,7]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Dynamic Programming based. As we are trying to form subarrays curr. index only depends on prev. index, so we don't need dp array to track max. subarray
// till index 'i'. As we can use any 1 of the two nums at each index, we can pair each of the nums in curr. index with each of the nums at prev. index, so we maintain two vars
// len1, len2 indicating max subarray ending at prev. index of arr1, arr2. We compare prev. index values with curr. index vals and get max subarray ending at curr. index.
// We use both these values and try to update the max. subarray length observed in the process. We update len1, len2 with curr. index's max. subarray lenghts. We return res at 
// the end of iter.







class Solution {
public:
    int maxNonDecreasingLength(vector<int>& u, vector<int>& v) {
        int len1=1, len2=1, res=1;											// Max. subarray length ending at zero index of u, v resp.
        for(int i=1;i<u.size();i++) {
            int temp1=1, temp2=1;											// Tracks max. subarray length ending at curr. index of u, v resp.
            if(u[i]>=u[i-1]) temp1=len1+1;									// Subarray ending at u[i] and preceeded by u[i-1], get subarr length.
            if(u[i]>=v[i-1] && len2+1>temp1) temp1=len2+1;					// Subarray ending at u[i] but preceeded by v[i-1], get subarr length and track max. subarr length.
            
            if(v[i]>=v[i-1]) temp2=len2+1;
            if(v[i]>=u[i-1] && len1+1>temp2) temp2=len1+1;
            
            len1=temp1;														// Assign curr subarr lengths to len1, len2.
            len2=temp2;
            res=max({res, len1, len2});										// Track the max. subarray length observed in the process.
        }
        return res;															// Returning the max. subarray length with values from two arrays.
    }
};

