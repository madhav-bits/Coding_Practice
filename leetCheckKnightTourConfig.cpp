/*
*
//******************************************************2596. Check Knight Tour Configuration.******************************************************

https://leetcode.com/problems/check-knight-tour-configuration/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[0,11,16,5,20],[17,4,19,10,15],[12,1,8,21,6],[3,18,23,14,9],[24,13,2,7,22]]
[[0,3,6],[5,8,1],[2,7,4]]



// Time Complexity: O(n*n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*n).
// Space Complexity: O(1).	
// This algorithm is iteration based. We iter. from 1 to grid.size()*grid.size() of knight's steps, at every step we check in 8 possible next movies from the prev. psn in search of curr. step number.
// If not found, we return false, else we update the curr. psn row, col values. If we are able to complete the entire iter. we return true.








class Solution {
public:
    
    vector<vector<int>>dirs;
    bool searchNextJumpIndex(vector<vector<int>>&grid, int  target, int& currRow, int& currCol) {		// Function to Look in all possible curr moves for curr. step number.
        for(int i=0;i<8;i++) {																			// Looking in all possible moves for curr. step number.
            int dx=dirs[i][0], dy=dirs[i][1];
            if(currRow+dx<0 || currRow+dx>=grid.size() || currCol+dy<0 || currCol+dy>=grid[0].size() || grid[currRow+dx][currCol+dy]!=target) continue;
            currRow+=dx;																				// If curr. step num found, updating the curr. row, col values.
            currCol+=dy;
            return true;																				// If cur. step number found, return true.
        }
        return false;																					// If curr. step number not found, return false.
    }
    
    bool checkValidGrid(vector<vector<int>>& grid) {
        if(grid[0][0]!=0) return false;
        dirs=vector<vector<int>>({{-1, -2}, {-2, -1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2}});
        int currRow=0, currCol=0;
        for(int i=1;i<grid.size()*grid.size();i++) {													// Iter. over all ith steps.
            if(!searchNextJumpIndex(grid, i, currRow, currCol)) return false;							// If curr. step number is not found in any of possible movies, return false.
        }
        return true;																					// All the steps are valid, so return true.
    }
};

