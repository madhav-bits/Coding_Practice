/*
*
//******************************************************2319. Check if Matrix Is X-Matrix.******************************************************

https://leetcode.com/problems/check-if-matrix-is-x-matrix/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[2,0,0,1],[0,3,1,0],[0,5,2,0],[4,0,0,2]]
[[5,7,0],[0,3,1],[0,5,0]]



// Time Complexity: O(n*n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*n).
// Space Complexity: O(1).	
// This algorithm is iteration based. We place conditions to check diagonal and no-diagonal indices and look for expected values, if conditions arne't met,we
// return false. If we go through entire traversal of matrix without any issues, we return true.







class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int len=grid.size();
        for(int i=0;i<len;i++) {											// Traversing the Matrix.
            for(int j=0;j<len;j++) {
                if((i==j || i+j==len-1)) {									// Condition for identify diagonals.
                    if(grid[i][j]==0) return false;							// If zero found in diagonal indices, we return false.
                }else if(grid[i][j]!=0) return false;						// If non-zero found in non-diag indices, we return false.
            }
        } 
        return true;														// We return true as the matrix met the conditions.
    }
};

