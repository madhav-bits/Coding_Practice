/*
*
//******************************************************2658. Maximum Number of Fish in a Grid.******************************************************

https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[0,2,1,0],[4,0,0,3],[1,0,0,4],[0,3,2,0]]
[[1,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,1]]



// Time Complexity: O(n*m).
// Space Complexity: O(n*m).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).
// Space Complexity: O(n*m).	
// This algorithm is DFS based. We do DFS for every connected water body to collect fishes in them and track the max #fishes in a water body and return it after iter. entire matrix.







class Solution {
public:
    vector<int>dirs;
    
    int getFishes(vector<vector<int>>&grid, int row, int col) {											// DFS to collect fishes in each water body.
        int cnt=grid[row][col];
        grid[row][col]=0;
        for(int i=0;i<4;i++) {
            int dx=dirs[i], dy=dirs[i+1];
            if(row+dx<0 || row+dx>=grid.size() || col+dy<0 || col+dy>=grid[0].size() || grid[row+dx][col+dy]==0) continue;
            cnt+=getFishes(grid, row+dx, col+dy);
        }
        return cnt;
    }
    
    int findMaxFish(vector<vector<int>>& grid) {
        dirs=vector<int>({-1,0,1,0,-1});
        int res=0;
        for(int i=0;i<grid.size();i++) {																// Iter. over matrix to start DFS for each water body.
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j]==0) continue;
                int cnt=getFishes(grid, i, j);															// DFS to get #fishes in each connected water body.
                if(cnt>res) res=cnt;
            }
        }
        return res;																						// Returning the max #fishes in a water body.
    }
};

