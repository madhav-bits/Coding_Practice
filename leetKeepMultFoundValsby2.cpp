/*
*
//*******************************************2154. Keep Multiplying Found Values by Two.*********************************************

https://leetcode.com/problems/keep-multiplying-found-values-by-two/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[5,3,6,1,12]
3
[4,2,5,8]
2
[2,7,9]
4



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is map based. As the range of nums in array is small, we create an array to track if a number had occurred in the array. We iter. over array 
// and mark all nums in array as marked in occur array. We now keep on increasing orig value by 2 until orig is either>occur.size() or orig didn't occur in 
// nums array.







class Solution {
public:
    int findFinalValue(vector<int>& nums, int orig) {
        int maxm=*max_element(nums.begin(), nums.end());
        vector<bool>occur(maxm+1, false);
        for(int&num:nums) occur[num]=true;									// Marking all nums in array as occurred.
        while(orig<occur.size() && occur[orig]) orig*=2;					// Keep inc. orig by 2 as long as it occurs in nums array.
        return orig;														// Returning the final orig value.
    }
};


