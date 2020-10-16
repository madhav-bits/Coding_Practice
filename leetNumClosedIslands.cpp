/*
*
//********************************************1254. Number of Closed Islands.**********************************************

https://leetcode.com/problems/number-of-closed-islands/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


[[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
[[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
[[1,1,1,1,1,1,1],[1,0,0,0,0,0,1],[1,0,1,1,1,0,1],[1,0,1,0,1,0,1],[1,0,1,1,1,0,1],[1,0,0,0,0,0,1],[1,1,1,1,1,1,1]]




// Time Complexity: O(n*m).  												// n- #rows, m-#cols in the matrix.
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).													// n- #rows, m-#cols in the matrix.
// Space Complexity: O(1).	
// This algorithm is DFS based. Here, we iter. over entire matrix. When we encounter a zero, we start DFS and mark all 
// adj. zeroes, if we encounter borders of the matrix in the process, then all the iter. zeroes in this DFS won't count 
// towards an island, so we store and return false from this call. If we retur from the DFS call, we add this island.








class Solution {
public:

    bool markIslands(vector<vector<int>>&grid, int row, int col){
        grid[row][col]=1;
        vector<int>dirs({-1,0,1,0,-1});
        bool res=true;
        for(int j=0;j<4;j++){												//  Iter. in four directions.
            int dx=dirs[j], dy=dirs[j+1];
            if(row+dx<0 || row+dx>=grid.size() || col+dy<0 || col+dy>=grid[0].size()){// Touched borders of matrix.
                res=false;													// Indicating that borders are touched.
                continue;
            } 
            if(grid[row+dx][col+dy]==1) continue;							// Prevents duplicate iteration.
            if(!markIslands(grid, row+dx, col+dy)) res=false;				// Forwarding that borders are touched.
        }
        return res;															// Indicating the results of iteration.
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int res=0;
        for(int i=0;i<grid.size();i++){										// Iter. over matrix.
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1) continue;
                if(markIslands(grid, i, j)) res++;							// Start DFS to mark attached zeroes.
            }
        }
        return res;															// Returning the #closed islands.
    }
};