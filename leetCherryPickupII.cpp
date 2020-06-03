/*
*
//********************************************************1463. Cherry Pickup II.**************************************************

https://leetcode.com/problems/cherry-pickup-ii/description/



Given a rows x cols matrix grid representing a field of cherries. Each cell in grid represents the number of cherries that you can 
collect.

You have two robots that can collect cherries for you, Robot #1 is located at the top-left corner (0,0) , and Robot #2 is located at 
the top-right corner (0, cols-1) of the grid.

Return the maximum number of cherries collection using both robots  by following the rules below:

From a cell (i,j), robots can move to cell (i+1, j-1) , (i+1, j) or (i+1, j+1).
When any robot is passing through a cell, It picks it up all cherries, and the cell becomes an empty cell (0).
When both robots stay on the same cell, only one of them takes the cherries.
Both robots cannot move outside of the grid at any moment.
Both robots should reach the bottom row in the grid.
 

Example 1:



Input: grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
Output: 24
Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
Cherries taken by Robot #1, (3 + 2 + 5 + 2) = 12.
Cherries taken by Robot #2, (1 + 5 + 5 + 1) = 12.
Total of cherries: 12 + 12 = 24.
Example 2:



Input: grid = [[1,0,0,0,0,0,1],[2,0,0,0,0,3,0],[2,0,9,0,0,0,0],[0,3,0,5,4,0,0],[1,0,2,3,0,0,6]]
Output: 28
Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
Cherries taken by Robot #1, (1 + 9 + 5 + 2) = 17.
Cherries taken by Robot #2, (1 + 3 + 4 + 3) = 11.
Total of cherries: 17 + 11 = 28.
Example 3:

Input: grid = [[1,0,0,3],[0,0,0,3],[0,0,3,3],[9,0,3,3]]
Output: 22
Example 4:

Input: grid = [[1,1],[1,1]]
Output: 4
 

Constraints:

rows == grid.length
cols == grid[i].length
2 <= rows, cols <= 70
0 <= grid[i][j] <= 100 


*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


[[3,1,1],[2,5,1],[1,5,5],[2,1,1]]


[[1,0,0,0,0,0,1],[2,0,0,0,0,3,0],[2,0,9,0,0,0,0],[0,3,0,5,4,0,0],[1,0,2,3,0,0,6]]



// Time Complexity: O(m*n*n).  												// m-rows, n-cols of the array.
// Space Complexity: O(m*n*n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m*n*n).												// m-rows, n-cols of the array.			
// Space Complexity: O(m*n*n).	
// This algorithm is Dyanmic Programming based. Here, since we have two robots, we take combination of all their possible positions.
// As, robot can be in a row in a single psn, we deal the calculations row wise. We use DP Top Down approach. dp[x][y][z] stores best
// total possible for robots from that psn to all indices in the bottom rows. We return the stored value from DP array if that psn is
// already visited. We return dp[0][cols-1][cols-1] at the end of the process.








class Solution {
public:
    int dp[70][70][70];														// Declare the DP array.
    int dfs(vector<vector<int>>&grid, int row, int col1, int col2){
        if(row>=(int)grid.size()) return 0;									// Out of bounds cases.
        if(dp[row][col1][col2]!=-1) return dp[row][col1][col2];				// If already visited, return the value.
        int ans=0, cols=(int)grid[0].size();
        for(int da=-1;da<=1;da++){											// All possible cols in the next row(curr. row+1).
            for(int db=-1;db<=1;db++){
                int newCol1=col1+da, newCol2=col2+db;
                if(newCol1<0 || newCol2<0 || newCol1>=cols || newCol2>=cols) continue;// Out of bounds cases.
                ans=max(ans, dfs(grid, row+1, newCol1, newCol2));			// Getting vals. from possible indies from next row.
            }
        }
        int cherries=(col1==col2)?grid[row][col1]:grid[row][col1]+grid[row][col2];// Adding vals. from curr. row's indices.
        dp[row][col1][col2]=ans+cherries;									// Add. curr. row's vals with bottom row's contri.
		dp[row][col2][col1]=ans+cherries;									// Even reversing both cols gives same vals, so we assign to swapped cols index also.
        // cout<<"row: "<<row<<" and col1: "<<col1<<" col2: "<<col2<<" and dp val: "<<dp[row][col1][col2]<<endl;
        return dp[row][col1][col2];											// Return the DP array value.
    }
    
    
    int cherryPickup(vector<vector<int>>& grid) {
        int rows=grid.size(), cols=grid[0].size();	
        memset(dp,-1,sizeof(dp));											// Init. the DP array.
        return dfs(grid,0,0,cols-1);										// DFS call to fill the DP array.
    }
};