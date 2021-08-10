/*
*
//**********************************1526. Minimum Number of Increments on Subarrays to Form a Target Array.**********************************

https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


[1,2,3,2,1]
[3,1,1,2]
[3,1,5,4,2]
[1,1,1,1]
[2,3,2,5,1,2,3,6]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Greedy Approach based.Here, we greedily pick subarrays and request to inc it's values. If few consecutive indices have greater
// values, if would be optimal if we fill up the entire range of indices with least value first and then focus on next least value for the broken
// subarray and request to increase the value, here we are optimally filling the indices such that no extra calls nor unnecessary calls are given. 
// In this way we get minm. #calls. If we observe a greater value than curr. height/value of tracking subarray, we might have to give some calls
// to get the curr. value, which is (curr. value-curr. Height), so we add this calls to res var. If lower or equal curr. val is encountered, 
// this height is already obtained in the process of forming greater heights, so we don't add it to final res. We return the res at the end of 
// the iteration.








class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int res=0, currHeight=0;											// Tracks #calls made till now, curr. subarray height/val.
        for(int num:target){
            if(num>currHeight) res+=num-currHeight;							// Extra calls required to get curr. val from curr. Height/val.
            currHeight=num;													// Updating the subarr. height/value to curr. value.
        }
        return res;															// Returning the #calls/operations.
    }
};