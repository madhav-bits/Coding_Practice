/*
*
//**********************************************1293. Shortest Path in a Grid with Obstacles Elimination.**********************************************

https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/




Given a m * n grid, where each cell is either 0 (empty) or 1 (obstacle). In one step, you can move up, down, left or right from and to an empty cell.

Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right corner (m-1, n-1) given that you can eliminate at 
most k obstacles. If it is not possible to find such walk return -1.

 

Example 1:

Input: 
grid = 
[[0,0,0],
 [1,1,0],
 [0,0,0],
 [0,1,1],
 [0,0,0]], 
k = 1
Output: 6
Explanation: 
The shortest path without eliminating any obstacle is 10. 
The shortest path with one obstacle elimination at position (3,2) is 6. Such path is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (3,2) -> (4,2).
 

Example 2:

Input: 
grid = 
[[0,1,1],
 [1,1,1],
 [1,0,0]], 
k = 1
Output: -1
Explanation: 
We need to eliminate at least two obstacles to find such a walk.
 

Constraints:

grid.length == m
grid[0].length == n
1 <= m, n <= 40
1 <= k <= m*n
grid[i][j] == 0 or 1
grid[0][0] == grid[m-1][n-1] == 0



*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


[[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]]
1
[[0,1,1],[1,1,1],[1,0,0]]
1



// Time Complexity: O((m^2)*(n^2)).											// m-#rows, n=#cols in the matrix.
// Space Complexity: O(m*n).	


//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O((m^2)*(n^2)).											// m-#rows, n=#cols in the matrix.
// Space Complexity: O(m*n).	
// This algorithm in BFS based. Here, since we are trying to find min. dist. to bottom right with k removable obstacles, we maintain a 2D array, where
// we store the obstacles encountered on the way to reach it, if we reached same index with lower obstacles on the way, we also push this incidence into
// the queue and start looking for bottom right, as we can overcome more obstacles on the way than the earlier pushed instance into queue. Here, each
// index can be revisited K times, where K can be at max m*n. The first instance we reached bottom right is the shortest path to reach it.










class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        if(grid.size()==1 && grid[0].size()==1) return 0;
        vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),INT_MAX));// Stores min. obstacles encountered on the way to reach each index.
        queue<pair<int,int>>q;
        vector<int>dirs({-1,0,1,0,-1});
        q.push({0,0});
        visited[0][0]=0;
        int steps=0;
        while(!q.empty()){													// Till all possible ways are explored.
            steps++;
            int len=q.size();
            for(int i=0;i<len;i++){
                int x=q.front().first/grid[0].size(),y=q.front().first%grid[0].size();
                int obstacles=q.front().second;
                q.pop();
                // if(visited[x][y]<obstacles) continue;						
                // cout<<" extracted x: "<<x<<" and y: "<<y<<" and obstacles: "<<obstacles<<endl;
                for(int j=0;j<4;j++){
                    int dx=dirs[j], dy=dirs[j+1];
                    if(x+dx<0 || x+dx>=grid.size() || y+dy<0 || y+dy>=grid[0].size() || visited[x+dx][y+dy]<=obstacles) continue;
                    if((x+dx)==grid.size()-1 && (y+dy)==grid[0].size()-1) return steps;// If bottom right index is found, we return dist. from start.
                    int newObstacles=obstacles+(grid[x+dx][y+dy]==1?1:0);
                    if(newObstacles>k) continue;
                    if(grid[x+dx][y+dy]==1 && visited[x+dx][y+dy]<=newObstacles) continue;// If a path with more obstacles is found(also more long), we ignore it.
                    
                    visited[x+dx][y+dy]=newObstacles;
                    q.push({(x+dx)*grid[0].size()+(y+dy),newObstacles});					// We try paths with fewer obstacles.
                    // cout<<"Added x: "<<x+dx<<" and y: "<<y+dy<<endl;
                }
            }
        }
        return -1;															// If bottom right is not reachable, we return -1.
    }
};
