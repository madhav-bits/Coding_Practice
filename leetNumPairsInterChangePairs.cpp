/*
*
//******************************************************2001. Number of Pairs of Interchangeable Rectangles.******************************************************

https://leetcode.com/problems/number-of-pairs-of-interchangeable-rectangles/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[4,8],[3,6],[10,20],[15,30]]
[[4,5],[7,8]]
[[50,100],[501,1000],[3,6],[4,9],[9,1],[49999,100000]]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Map based. Here, as we are looking for pairs, at every step of iter., we map curr. rect to all prev. iter rect with same ratio by adding
// their count to res, this means we mapped curr. rect with each of prev. rects with same ratio, thus we ensure to cover all possible pairs in this way and 
// return total #pairs at the end of iter.







class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        long long int res=0;
        unordered_map<double,int>m;											// Tracks #rect with same ratio.
        for(vector<int>&v:rectangles) {
            double temp=(0.0+v[0])/v[1];									// Calc. ratio for the curr. rect.
            res+=m[temp];													// Mapping curr. rect with all prev. rects with same ratio, adding #pairs to res.
            m[temp]++;														// Inc. the curr. ratio count in map.
        }
        return res;															// Returning total #pairs count.
    }
};

