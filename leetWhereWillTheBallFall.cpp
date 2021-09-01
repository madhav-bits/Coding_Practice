/*
*
//******************************************************1706. Where Will the Ball Fall.***********************************************

https://leetcode.com/problems/where-will-the-ball-fall/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


[[1,1,1,-1,-1],[1,1,1,-1,-1],[-1,-1,-1,1,1],[1,1,1,1,-1],[-1,-1,-1,-1,-1]]
[[-1]]
[[1,1,1,1,1,1],[-1,-1,-1,-1,-1,-1],[1,1,1,1,1,1],[-1,-1,-1,-1,-1,-1]]




// Time Complexity: O(m*n).  												// m-#rows in grid, n-#cols in grid.
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m*n).													// m-#rows in grid, n-#cols in grid.
// Space Complexity: O(n).	
// This algorithm is iteration based. Here, the ball moves to it's adjacent indices if they have same value. Index with '1' moves to right if 
// adjacent also has '1'. Index with '-1' moves to left, if adjacent also has -1. The balls only moves 1 step in each row as each reaches the 
// lower half in a move. If we don't have suitable values in adjacent indices then the ball is stuck in that row. If we are able to reach
// to the bottom of the grid, we take the column value if not we store -1 in the result. In this way we get the final col values for each of the 
// balls.











class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int>res;
        for(int j=0;j<grid[0].size();j++){
            int row=0, col=j;
            while(row<grid.size()){
                // cout<<"curr row: "<<row<<" and curr col: "<<col<<endl;
                if(col+1<grid[0].size() && grid[row][col]==1 && grid[row][col]==grid[row][col+1]) col++;// Calc. move in curr. row.
                else if(col-1>=0 && grid[row][col]==-1 && grid[row][col]==grid[row][col-1]) col--;
                else break;													// If no move possible in curr. row, we return -1.
                row++;
            }
            // cout<<"final row: "<<row<<endl;
            if(row==grid.size()) res.push_back(col);						// If bottom row+1 reached.
            else res.push_back(-1);											// Else we store -1.
        }
        return res;															// Returning the balls final positions.
    }
};

