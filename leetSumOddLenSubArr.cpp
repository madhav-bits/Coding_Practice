/*
*
//******************************************1588. Sum of All Odd Length Subarrays.*****************************************

https://leetcode.com/problems/sum-of-all-odd-length-subarrays/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


[1,43,62,84,4,42,22,15,31]


// Time Complexity: O(n^2).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(1).	
// This algorithm is prefix sum based. Here, we do a prefix sum from the left and store it in the same array. We iter. 
// over all odd lengths, at each len. we itet. over all starts, we get total of subarray from prefix[last]-prefix[start]
// and add it to final res.








class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        for(int i=1;i<arr.size();i++)										// Updating array with prefix sum.
            arr[i]+=arr[i-1];
        int res=0;
        for(int len=1;len<=arr.size();len+=2){								// Iter. over all odd lengths.
            res+=arr[len-1];												// Adding total of subarr starting at '0' idx.
            // cout<<"len: "<<len<<endl;
            for(int close=len;close<arr.size();close++){					// Iter. over all starts for subarray.
                res+=arr[close]-arr[close-len];								// Adding subarray total to res.
                // cout<<arr[close]-arr[close-len]<<" ";
            }
            // cout<<endl;
        }
        return res;															// Returning the sum of all subarrays.
    }
};