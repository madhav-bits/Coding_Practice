/*
*
//**********************************************2248. Intersection of Multiple Arrays.************************************************

https://leetcode.com/problems/intersection-of-multiple-arrays/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[3,1,2,4,5],[1,2,3,4],[3,4,5,6]]
[[1,2,3],[4,5,6]]



// Time Complexity: O(n+m).  												//n-total #nums in the array, m-range of nums in array.
// Space Complexity: O(m).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n+m).													//n-total #nums in the array, m-range of nums in array.
// Space Complexity: O(m).	
// This algorithm is Map based. Here, since each array in 2d array consists of distinct values, if a number to occurs in every row of the array it will
// occur size of the nums array times. We use this and track #occur of each num in the 2D array, later we iter. over occur. tracker array and add all those 
// nums which occurred size of array times and this vlaues will be sorted.







class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int occur[1001], len=nums.size();
        memset(occur, 0, sizeof(occur));
        vector<int>res;
        for(vector<int>&v:nums) {
            for(int& num:v) occur[num]++;									// Tracking #occur of each num in the array.
        }
        for(int i=1;i<=1000;i++) if(occur[i]==len) res.push_back(i);		// Collecing nums which occurred in every row of the array.
        return res;															// Returning nums which occurred in every row of the array.
    }
};

