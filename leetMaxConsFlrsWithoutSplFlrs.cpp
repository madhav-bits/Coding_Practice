/*
*
//*************************************2274. Maximum Consecutive Floors Without Special Floors.****************************************

https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


2
9
[4,6]
6
8
[7,6,8]



// Time Complexity: O(nlogn).  												//n-#special floors.
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).												//n-#special floors.
// Space Complexity: O(1).	
// This algorithm is Sorting based. As the #special floors is small, we approach this by sorting the special floors array, in order to account b/w bottom to 
// first special floor and last special floor to top floor, we push two other values top+1, bottom-1. We iter. over array and calc. diff. b/w curr.-1 and prev. 
// floor and try to maximize the gap and return it at the end of iter.







class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& v) {
        v.push_back(bottom-1);												// Add boundaries to consider gap b/w boundaries and first, last spl floors.
        v.push_back(top+1);
        sort(v.begin(), v.end());											// Sort the special floors array.
        int res=0;
        for(int i=1;i<v.size();i++) {										// Iter. over special floors.
            res=max(res, v[i]-v[i-1]-1);									// Calc. gap b/w curr. and prev. spl floor and track max. gap.
        }
        return res;															// Returning max. #consec. floors without a spl floor.
    }
};

