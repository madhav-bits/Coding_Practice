/*
*
//****************************************2294. Partition Array Such That Maximum Difference Is K.************************************

https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[3,6,1,2,5]
2
[1,2,3]
1
[2,2,4,5]
0
[3,1,3,4,2]
0




// Time Complexity: O(nlogn).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(1).
// This algorithm is Sorting based. Here, as we are forming subseq and tracking maxm, minm in each subseq, the order of nums in it doesn't matter, so we sort
// the array for easy processing. We iter. over sorted array and pick the first ungrouped num and make it minm val of this group and greedily push all the vals
// to the right until v[i]-minm>k, and this v[i] starts the next group and it becomes minm val for that group, we inc. res by 1 to account for this grp. We 
// return res at the end of iter.







class Solution {
public:
    int partitionArray(vector<int>& v, int k) {
        sort(v.begin(), v.end());											// Sorting the given array.
        int res=1, minm=v[0];												// Setting the minm for first group and counting it in res.
        for(int i=0;i<v.size();i++) {										// Iter. over given array.
            if(v[i]-minm>k) {												// If curr. val-minm>k, curr. val can't be part of this grp, so we start next grp.
                res++;														// Inc. res by 1 for next grp.
                minm=v[i];													// Setting minm. val for next grp.
            }
        }
        return res;															// Returning minm. of grps that nums be divided into.
    }
};

