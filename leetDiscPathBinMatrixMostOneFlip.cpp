/*
*
//*************************************2556. Disconnect Path in a Binary Matrix by at Most One Flip.*************************************

https://leetcode.com/problems/disconnect-path-in-a-binary-matrix-by-at-most-one-flip/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[1,1,1],[1,0,0],[1,1,1]]
[[1,1,1],[1,0,1],[1,1,1]]
[[1,1,1,1,0],[1,1,1,1,1],[0,0,1,1,1]]
[[1,1,1,0,0],[1,1,1,1,1],[0,1,1,1,1]]
[[1,1,1,0,1],[1,0,1,0,0],[1,1,0,1,1],[0,0,1,0,1],[1,0,1,1,1]]
[[1,1,0,0,1],[1,1,1,1,0],[1,1,0,1,1],[1,0,1,1,1],[1,1,0,1,1]]
[[1,1,1,1,1,1],[1,0,1,1,1,1],[1,1,1,0,1,1],[0,0,0,1,1,1]]



// Time Complexity: O(n*m).  												// Solution 2 exhibits better Time, Space Complexity combination.
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).
// Space Complexity: O(n+m).	
// This algorithm is Observation based. Here, we do Forward, Backward Checking, in Forward checking we remove all those '1's which aren't connected to the 
// source, in Backward checking we remove all '1's which aren't connected to destination. So, both checking are required and after forward and backward 
// checking we are left with only those '1's which ARE part of ANY of the paths from the source to destination. 
// Now, we iter. over matrix and count #ones in the diagonals(same i+j value), where we consider diagonals as gates, if any of the diagonals have #occur. of
// 1s <=1, then we either dont have path from source to dest. or we can flip this 1 and disconnect source from destination, so we return true. If we dont find
// any such instance we return false.



// This discussion forum link has detailed explanation for the approach: 
// https://leetcode.com/problems/disconnect-path-in-a-binary-matrix-by-at-most-one-flip/discuss/3142814/clever-diagonals-with-diagram-explanation/





class Solution {
public:
    
    bool isPossibleToCutPath(vector<vector<int>>& grid) { 
        
        // Forward Checking.
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if((i==0 && j==0) || grid[i][j]==0) continue;
                grid[i][j]=0;
                if((i>0 && grid[i-1][j]) ||
                  (j>0 && grid[i][j-1])) grid[i][j]=1;						// Connecting node to the source.
            }
        }
        
        // Backward Checking.
        for(int i=grid.size()-1;i>=0;i--) {
            for(int j=grid[0].size()-1;j>=0;j--) {
                if((i==grid.size()-1 && j==grid[0].size()-1) || grid[i][j]==0) continue;
                grid[i][j]=0;
                if((i+1<grid.size() && grid[i+1][j]) ||
                  (j+1<grid[0].size() && grid[i][j+1])) grid[i][j]=1;		// Connecting node to the destination.
            }
        }
        
        vector<int>occur(grid.size()+grid[0].size()-1, 0);
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                // cout<<grid[i][j]<<" ";
                if(grid[i][j]==1) occur[i+j]++;								// Counting #1s in the diagonals with same i+j value.
            }
            // cout<<endl;
        }
        for(int i=1;i<occur.size()-1;i++) if(occur[i]<2) return true;		// If any diag. has #1s <=1, we return true as we don't have path/this can be flipped to break path.
        return false;														// As we didn't have any way to disconnect the path.
    }
};










//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).
// Space Complexity: O(1).
// This solution is observation based. Here, we first find a path from src to dest and disable it from using. If we are able to find another path which 
// isn't dependent on first path, then we cannot disconnect the path with single flip at max.
// My understanding is that: Our first DFS selects the path that is closest towards left, bottom sides of matrix. When we do second DFS, we dont find path 
// becuase there is no independent path or there is a path which is dependant on first path. If it's dependant on first path, we can always flip a node in 
// first path and make the second path disconnected from destination.





// This discussion forum link has better explanation for this solution: 
// https://leetcode.com/problems/disconnect-path-in-a-binary-matrix-by-at-most-one-flip/discuss/3141656/Explained-Run-DFS-2-times-oror-Very-simple-and-easy-to-Understand-Solution
// https://leetcode.com/problems/disconnect-path-in-a-binary-matrix-by-at-most-one-flip/discuss/3154733/Priority-of-directions






class Solution {
public:
    vector<int>dirs;
    bool dfs(vector<vector<int>>&grid, int row, int col) {
        if(row==grid.size()-1 && col==grid[0].size()-1) return true;
        grid[row][col]=0;													// Marking path as visited, so that it can't be resued.
        if(row+1<grid.size() && grid[row+1][col] && dfs(grid, row+1, col)) return true;
        if(col+1<grid[0].size() && grid[row][col+1] && dfs(grid, row, col+1)) return true;
        return false;
    }
    
    bool isPossibleToCutPath(vector<vector<int>>& grid) { 
        if(!dfs(grid, 0, 0)) return true;									// If no path found and is disconnected, return true.
        grid[0][0]=1;
        return !dfs(grid, 0, 0);											// If no second path found, return true as it can be connected if it depends on first path.
        
    }
};

