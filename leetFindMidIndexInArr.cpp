s/*
*
//******************************************************1991. Find the Middle Index in Array.******************************************************

https://leetcode.com/problems/find-the-middle-index-in-array/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[2,3,-1,8,4]
[1,-1,4]
[2,5]




// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is is PrefixSum based. Here, we have to find first index where prefixSum== suffixSum excluding curr. value and return the index. We calc. total of all nums and keep on subtracting curr. nums as we iter. over the 
// array to get suffixSum from that index onwards, keep on addding encountered indices to get prefixSum and compare them, we return the index, if they are equal. We return -1 if no such instance encountered.







class Solution {
public:
    int findMiddleIndex(vector<int>& arr) {
        int total=accumulate(arr.begin(), arr.end(),0);													// Calc. total of all nums in array.
        int left=0;
        for(int i=0;i<arr.size();i++) {
            total-=arr[i];																				// Removing curr. num from suffixSum.
            if(left==total) return i;																	// If prefixSum, suffixSum are equal, return curr. index.
            left+=arr[i];																				// Adding curr. num to prefixSum.
        }
        return -1;																						// No matching instance found.
    }
};

