/*
*
//******************************************************2304. Minimum Path Cost in a Grid.******************************************************

https://leetcode.com/problems/minimum-path-cost-in-a-grid/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[5,3],[4,0],[2,1]]
[[9,8],[1,5],[10,12],[18,6],[2,4],[14,3]]
[[5,1,2],[4,0,3]]
[[12,10,15],[20,23,8],[21,7,1],[8,1,13],[9,10,25],[5,3,2]]



// Time Complexity: O(m*n*n).												// m-#rows, n-#cols in the matrix.
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m*n*n).												// m-#rows, n-#cols in the matrix.
// Space Complexity: O(n).	
// This algorithm is Dynamic Programming based. Here, at every index, we try to minimize the path cost to all indices of next step, since members of a row can 
// only go to next row, when we are on a row 'i', we try to update min path cost to all indices in next row. So, we iter. until 'rows-2' and calc. min Cost 
// path until last row. Now, we iter. over last row separately and add minCost+grid[i][j] and track the min sum and return it.







class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int rows=grid.size(), cols=grid[0].size();
        int dp[2][cols], res=INT_MAX;
        memset(dp, 0, sizeof(dp));
        for(int i=0;i<rows-1;i++) {											// Iter. over all but last row of the matrix.
            for(int j=0;j<cols;j++) dp[(i+1)%2][j]=INT_MAX;
            for(int j=0;j<cols;j++) {										// Iter. over all indices in 'i' row.
                for(int k=0;k<cols;k++) {									// Updating minCost to 'i+1' row indices based on minCost to 'i' row indices.
                    dp[(i+1)%2][k]=min(dp[(i+1)%2][k], dp[i%2][j]+grid[i][j]+moveCost[grid[i][j]][k]);
                }
            }
        }
        for(int j=0;j<cols;j++) {											// Iter. over last row separately.
            res=min(res, dp[(rows-1)%2][j]+grid[rows-1][j]);				// Tracking the minCost to reach any of the last row indices.
        }
        return res;															// Returning the minCost to reach any of the last row indices.
    }
};

