/*
*
//******************************************************1846. Maximum Element After Decreasing and Rearranging.******************************************************

https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[2,2,1,2,1]
[100,1,1000]
[1,1,1,1,1]
[1,2,4,2,6,8,1]
[73,98,9]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration+Greedy based. Since we have to get the greatest maxm value after operations. We sort the array, so that the provided values are already in non-dec order, we only dec.
// the value of an index, if it is > prev. index value+1 to prev. value+1, if it is equal/1 more than to prev. value,we let it be. Thus we are trying to maximize value at every step. and we get 
// the greatest value at the last index of the array.







class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        arr[0]=1;
        for(int i=1;i<arr.size();i++) {
            if(arr[i]>arr[i-1]+1) arr[i]=arr[i-1]+1;													// We dec. the curr. index value, if it's greater than prev. value+1
        }
        return arr.back();																				// Return the greatest value(which would be at last index).
    }
};

