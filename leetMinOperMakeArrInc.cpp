/*
*
//******************************************************1827. Minimum Operations to Make the Array Increasing.******************************************************

https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/





*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,1,1]
[1,5,2,4,1]
[8]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, we increase the value of curr. index if it is less than prev. index value+1. Thus, we only increase the value to the least at every
// step and we get least number of increments by the end of iter.







class Solution {
public:
    int minOperations(vector<int>& v) {
        int res=0;
        for(int i=1;i<v.size();i++) {
            if(v[i-1]+1>v[i]) {												// If curr. val is < prev+1, we inc. the curr. value.
                res+=(v[i-1]+1-v[i]);
                v[i]=v[i-1]+1;
            }
        }
        return res;															// Returning the total #increments.
    }
};

