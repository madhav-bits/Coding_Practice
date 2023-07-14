/*
*
//******************************************************2348. Number of Zero-Filled Subarrays.******************************************************

https://leetcode.com/problems/number-of-zero-filled-subarrays/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,3,0,0,2,0,0,4]
[0,0,0,2,0,0]
[2,10,2019]
[0,0,0,0,0]
[1,2,3,4,5]
[0]
[0,0]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, we form subarrays with zeroes and whenever we add new zero to a subarray, it forms subarrays statring from length
// [1,  total #consec. zeroes] with all indices in the subarray respectively, so for every zero, we inc. the subarray length and add it to res, else we reset
// the subarray length to 0.







class Solution {
public:
    long long zeroFilledSubarray(vector<int>& v) {
        long long int res=0;
        int len=0;
        for(int i=0;i<v.size();i++) {
            if(v[i]==0) len++;												// Tracking #zeroes in the subarray.
            else len=0;
            res+=0ll+len;													// Adding #zeroes as curr. index forms zeroes subarray with all indices in subarray
        }																	// as start indices.
        return res;															// Returning the total #zero-filled subarrays.
    }
};

