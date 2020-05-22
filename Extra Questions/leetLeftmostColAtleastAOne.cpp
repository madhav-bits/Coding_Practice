/*
*
//*****************************************1428. Leftmost Column with at Least a One.*****************************************

https://leetcode.com/problems/leftmost-column-with-at-least-a-one/description/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[0,0],[1,1]]

[[0,0],[1,1]]
[[0,0],[0,1]]
[[0,0],[0,0]]
[[0,0,0,1],[0,0,1,1],[0,1,1,1]]



// Time Complexity: O(m+n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m+n).
// Space Complexity: O(1).	
// This algorithm is iteration based. We will iterate from top right, if curr. index has 1, we move left, else, we move to next row in
// search of ones. If we are out of bounds, we will stop. If we are still in last but one col, it's that we haven't find atleast one 1.
// Else, we return col+1, as this is the last time we had encountered 1 and moved to curr. col.








/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &v) {
        vector<int>dims=v.dimensions();										// Get dims of the matrix.
        int col=dims[1]-1, row=0;											// Init. indices to top right.
        while(row<dims[0] && col>=0){										// Until we are out of bounds.
            if(v.get(row, col)==1) col--;									// If curr. index has 1, we dec. the col number.
            else row++;														// If it is 0, we move to next row in search of 1.
        }
        if(col==dims[1]-1) return -1;										// We haven't encountered any 1.
        return col+1;														// Returning the prev. col with 1.
    }
};

