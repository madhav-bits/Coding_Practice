/*
*
//************************************************2221. Find Triangular Sum of an Array.***********************************************

https://leetcode.com/problems/find-triangular-sum-of-an-array/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,2,3,4,5]
[5]
[5,7,4,3,6,7,8,9,5,2,2,6,7,8,7,4,6,3,6,8,8,4,4]



// Time Complexity: O(n^2).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(1).	
// This algorithm is iteration based. We observe that the flow of values and their contribution in the final sum represents a binomial expression/pascal
// triangle. final res=nc0*v[0]+nc1*v[1]+nc2*v[2]+........+ncn*v.back(), this gives linear Time Complexity to solve the problem, but it got a bit complicated 
// to calculate ncr values and track them, so i skipped it.
// In this algo, we use brute force method, where we iterate over the allowed range of indices and add 'i' and 'i+1' indices values and update 'i' index with 
// the sum%10. We repeat the same process in the next iter. and we stop this process when we don't have any indices to iterate and return the first index
// which stores the result of the process.







class Solution {
public:
    int triangularSum(vector<int>& v) {
        for(int cap=v.size()-1;cap>0;cap--) {								// Tracks max. index to iterate until in this loop.
            for(int i=0;i<cap;i++) {										// Iter. over the array upto max. index.
                v[i]=(v[i]+v[i+1])%10;										// Update indices based on the sum%mod values.
            }
        }
        return v[0];														// Returning the result of the process.
    }
};

