/*
*
//******************************************************2419. Longest Subarray With Maximum Bitwise AND.******************************************************

https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,2,3,3,2,2]
[1,2,3,4]
[5,7,6,3,4,3,7,5,4,7,7,7,7,7,7,7,2,1,1,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3,4]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is observation based. AND operation on two nums always results in a lesser value, so maxm AND of a subarray would be the maxm. value in the array, where that element alone can
// be considered as subarray. In order to get the max length of the subarray with max. AND value, we need to get the length of the subarray whose all members are the maxm. value in the array, as 
// their AND result would still be maxm. value. We track the max. length of these possible subarrays containing only maxm value and return the res/max length.







class Solution {
public:
    int longestSubarray(vector<int>& v) {
        int maxm=*max_element(v.begin(), v.end());														// Calc. max value in the array.
        int currLen=0, res=0;
        for(int&num:v) {																				// Iter. to get maxm subarray length which only contains maxm value number.
            if(num==maxm) {																				// Curr. num is max number.
                if(++currLen>res) res=currLen;															// We inc. the subarray length and update the res if subarr length is longer than res.
            }else currLen=0;																			// If curr. num is not max number, reset the subarr length to 0.
        }
        return res;																						// Returning the maxm subarray length which only contains maxm value number.
    }
};

