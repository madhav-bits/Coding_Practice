/*
*
//************************************************************994. Rotting Oranges.*****************************************************

https://leetcode.com/problems/rotting-oranges/


You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

Example 1:


Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


[[2,1,1],[1,1,0],[0,1,1]]
[[2,1,1],[0,1,1],[1,0,1]]
[[0,2]]
[[0,2,1,1],[0,1,1,1],[1,0,1,0],[1,2,1,2],[1,0,2,1]]




// Time Complexity: O(n*m).  												// n- #rows, m-#cols of the matrix.
// Space Complexity: O(n*m).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).													// n- #rows, m-#cols of the matrix.
// Space Complexity: O(n*m).	
// This algorithm is BFS based. Here, as the oranges are getting rotten by next day, if there is any other rotten orange beside it on any day. This looks 
// like BFS, we do BFS and get #days it took to get all the tranmissable oranges to get infected. 








class Solution {
public:
    int orangesRotting(vector<vector<int>>& v) {
        int total=0, rotten;
        queue<pair<int,int>>q;
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[0].size();j++){
                if(v[i][j]==0) continue;
                total++;
                if(v[i][j]==2) q.push({i,j});								// Storing indices of intital rotten oranges.
            }
        }
        rotten=q.size();
        if(rotten==total) return 0;											// If all oranges are already covered, return 0.
        vector<int>dirs({-1,0,1,0,-1});
        int steps=-1;
        while(!q.empty()){
			steps++;														// Track #days to cover all rotten oranges.
			int len=q.size();
			for(int i=0;i<len;i++){
				int row=q.front().first, col=q.front().second;
				q.pop();
				for(int j=0;j<4;j++){										// Checking for neighboring indices for fresh oranges>
                    int dx=dirs[j], dy=dirs[j+1];
                    if(row+dx<0 || row+dx>=v.size() || col+dy<0 || col+dy>=v[0].size() || v[row+dx][col+dy]!=1) continue;
                    v[row+dx][col+dy]=2;
                    rotten++;
                    q.push({row+dx, col+dy});
            }
            
            }
        }
        return (rotten!=total)?-1:steps;									// Returing total #days to cover to infect all possible oranges.
    }
};