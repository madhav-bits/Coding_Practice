/*
*
//******************************************2016. Maximum Difference Between Increasing Elements.*******************************************

https://leetcode.com/problems/maximum-difference-between-increasing-elements/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[7,1,5,4]
[9,4,3,2]
[1,5,2,10]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Greedy based. To get max. diff we maintain the minm. value of the nums iterated till now, when we are at an index, we try to max. diff that this num can 
// get by substracting min. val of all prev. values and try to maximize the diff, we also try to update the minm. value if curr. val is lesser than it. We return the diff. at 
// the end of iter.







class Solution {
public:
    int maximumDifference(vector<int>& v) {
        int minm=v[0], res=-1;
        for(int i=1;i<v.size();i++) {
            if(v[i]>minm && v[i]-minm>res) res=v[i]-minm;					// If Inc. pair found, try to maximize the diff and track max. diff.
            if(v[i]<minm) minm=v[i];										// Tracking min. val encountered during iteration.
        }
        return res;															// Returning the max. diff b/w inc. values.
    }
};

