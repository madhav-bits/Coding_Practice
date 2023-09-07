/*
*
//*******************************************2087. Minimum Cost Homecoming of a Robot in a Grid.*******************************************

https://leetcode.com/problems/minimum-cost-homecoming-of-a-robot-in-a-grid/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,0]
[2,3]
[5,4,3]
[8,2,6,7]
[0,0]
[0,0]
[5]
[26]
[9,2]
[4,9]
[4,5,3,6,5,4,8,6,6,5]
[3,6,7,3,4,2,5,7,7,6]



// Time Complexity: O(m+n).													//m-#rows, n-#cols in the  matrix.
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m+n).													//m-#rows, n-#cols in the  matrix.
// Space Complexity: O(1).	
// This algorithm is Greedy based. We observe that when we make L, R moves we enter a new col and we have to add that colCost to res. For us to reach home in 
// any path, we need to have the cols directly b/w start and home covered atleast,same applies to directly in middle rows too. If a path either contains
// multiple instances of same index or any other row, cols other than the direct in b/w rows, cols would only increase the res and this path also must contain
// our direct in b/w rows, cols. So, we avoid duplicates and non middle rows, cols in our path and take the shortest path b/w directly connecting start, pos
// and calc. their cost and return it.







class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int res=-rowCosts[startPos[0]]-colCosts[startPos[1]];
        int maxRow=max(startPos[0], homePos[0]), maxCol=max(startPos[1], homePos[1]);
        for(int row=min(startPos[0], homePos[0]);row<=maxRow;row++) res+=rowCosts[row];// Covering all directly in middle rows.
        for(int col=min(startPos[1], homePos[1]);col<=maxCol;col++) res+=colCosts[col];// Covering all directly in middle cols.
        return res;															// Returning the minm cost to reach home.
    }
};

