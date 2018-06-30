/*
*
//******************************************************325. Maximum Size Subarray Sum Equals k.***********************************************

Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.

Note:
The sum of the entire nums array is guaranteed to fit within the 32-bit signed integer range.

Example 1:

Input: nums = [1, -1, 5, -2, 3], k = 3
Output: 4 
Explanation: The subarray [1, -1, 5, -2] sums to 3 and is the longest.
Example 2:

Input: nums = [-2, -1, 2, 1], k = 1
Output: 2 
Explanation: The subarray [-1, 2] sums to 1 and is the longest.
Follow Up:
Can you do it in O(n) time?




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[-2, -1, 2, 1]
2


[-2, 0,-1, 2, 1]
3


[0,1,-2,-1,-1, 2,-3, 0,1]
-1


// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm iterates the array, at each step, we get a cumulative sum of all elem. from start till that elem. Then, we find the index
// at which a total of sum till curr. index-target had occured in the past, then subtract those indices to get the required subarray's length.
// One small thing to work on is that, as zero sum had occured, before even start values from given array, we set the index at which sum of 0
// first occured is -1. Once, we attain a new sum and push that index into map, we won't update that sum's index again(even the sum reoccurs 
// in the future). Thus, ensuring we get the longest substring. 








class Solution {
public:
    int maxSubArrayLen(vector<int>& v, int k) {
        int res=0;															// Tracks max. length of subarray, satisfying cdn.
        unordered_map<int,int>m;											// Saves cumulative sum till that index as key, index as value.
        int sum=0;															// Tracks cumulative sum.
        m[0]=-1;															// As sum=0, had occured before counting values in array, m[0]=-1.
        for(int i=0;i<v.size();i++){
            // cout<<"Curr. index: "<<i<<endl;
            sum+=v[i];														// Calc. the cumulative sum.
            if(m.count(sum-k)==1){											// If curr. sum minus target has occured in past.
                // cout<<"sum: "<<sum<<" and index of sum-k: "<<m[sum-k]<<endl;
                res=max(res,i-m[sum-k]);									// Extract subarray len, and try to udpate the res value.
            }
            if(m.count(sum)==0) m[sum]=i;									// If curr. sum hasn't occured in past, then push it into map.
        }
        
        return res;															// Returning the max Subarray len value.
    }
};