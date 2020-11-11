/*
*
//*******************************1637. Widest Vertical Area Between Two Points Containing No Points.***********************************

https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.

Worked on test cases provided with the question.
[[8,7],[9,9],[7,4],[9,7]]
[[3,1],[9,0],[1,0],[1,4],[5,3],[8,8]]


// Time Complexity: O(nlogn).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(n).	
// This algorithm is sorting based. Here, we want to get the max. diff b/w two consecutive points on x-axis coordinates. So, we
// extract x -coordinates into new array, sort it and track the max. diff b/w two consec. points.







class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& u) {
        vector<int>v;
        for(auto nums:u) v.push_back(nums[0]);
        sort(v.begin(), v.end());
        int res=0;
        for(int i=1;i<v.size();i++){
            res=max(res, v[i]-v[i-1]);
        }
        return res;
    }
};