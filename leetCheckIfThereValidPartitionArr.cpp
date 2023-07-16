/*
*
//******************************************************2369. Check if There is a Valid Partition For The Array.******************************************************

https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[4,4,4,5,6]
[1,1,1,2]
[2,2,2,2,2,2,2]
[3,4,5,5,4,4]
[473928,473929,473930]




// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Dynamic Programming based. Here, we have to check for every conditions and confirm whether we can form valid partitions from the start to
// curr. index, if any of the conditions is true, we set current dp[i]=true and move to next index. When we do same comparisons for 'i+1' index, we might 
// revisit checking whether prev partitions are valid or not(dp[i+1-2] or dp[i+1-3]) which have been already checked by earlier comparisons, so we reuse those
// checks and assign value to dp[i+1] index. dp.back() indicates whether there are valid partitions from the start index to last index of the array.







class Solution {
public:
    bool validPartition(vector<int>& v) {
        vector<bool>dp(v.size(), false);
        for(int i=1;i<v.size();i++) {
            if(v[i]==v[i-1] && (i==1 || dp[i-2])) dp[i]=true;				// If all prev. partitions are valid,curr. pair have same value,then we set dp[i] to true.
            if(i>1 && v[i-2]==v[i-1] && v[i-1]==v[i]  && (i==2 || dp[i-3])) dp[i]=true;// Checking similarly for other conditions.
            if(i>1 && v[i-2]+1==v[i-1] && v[i-1]+1==v[i] && (i==2 || dp[i-3])) dp[i]=true;
        }
        return dp.back();													// Returning whether entire array can be split into valid partitions.
    }
};


