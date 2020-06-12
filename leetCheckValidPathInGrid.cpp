/*
*
//******************************************1391. Check if There is a Valid Path in a Grid.***************************************

https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/description/


Given a m x n grid. Each cell of the grid represents a street. The street of grid[i][j] can be:
1 which means a street connecting the left cell and the right cell.
2 which means a street connecting the upper cell and the lower cell.
3 which means a street connecting the left cell and the lower cell.
4 which means a street connecting the right cell and the lower cell.
5 which means a street connecting the left cell and the upper cell.
6 which means a street connecting the right cell and the upper cell.


You will initially start at the street of the upper-left cell (0,0). A valid path in the grid is a path which starts from the upper 
left cell (0,0) and ends at the bottom-right cell (m - 1, n - 1). The path should only follow the streets.

Notice that you are not allowed to change any street.

Return true if there is a valid path in the grid or false otherwise.

 

Example 1:


Input: grid = [[2,4,3],[6,5,2]]
Output: true
Explanation: As shown you can start at cell (0, 0) and visit all the cells of the grid to reach (m - 1, n - 1).
Example 2:


Input: grid = [[1,2,1],[1,2,1]]
Output: false
Explanation: As shown you the street at cell (0, 0) is not connected with any street of any other cell and you will get stuck at 
cell (0, 0)
Example 3:

Input: grid = [[1,1,2]]
Output: false
Explanation: You will get stuck at cell (0, 1) and you cannot reach cell (0, 2).
Example 4:

Input: grid = [[1,1,1,1,1,1,3]]
Output: true
Example 5:

Input: grid = [[2],[2],[2],[2],[2],[2],[6]]
Output: true
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
1 <= grid[i][j] <= 6




*****************************************************************TEST CASES:**********************************************************
//These are the examples I had tweaked and worked on.


[[2,4,3],[6,5,5]]
[[4,1,3],[6,1,2]]
[[4,1,3],[6,1,1]]
[[2,4,3],[6,5,2]]
[[1,2,1],[1,2,1]]
[[1,1,2]]
[[1,1,1,1,1,1,3]]
[[2],[2],[2],[2],[2],[2],[6]]
[[4,6,3],[3,1,4]]



// Time Complexity: O(m*n).													// m- rows, n- cols of the 2D array.
// Space Complexity: O(m*n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m*n).													// m- rows, n- cols of the 2D array.
// Space Complexity: O(m*n).	
// This algorithm is DFS/BFS based. We start iter. from [0,0] and move to next index based on the roads in that index and the drn from 
// which we enter curr. index. If we are able to enter the bottom right index with from matching drn and roads inside it, we return true.
// We mark the visited nodes, so that we dont' revisit them.


// This solution also contains the BFS approach solution.




class Solution {
public:
    
    bool allowed(vector<vector<int>>&v, int targetX, int targetY, int x, int y, vector<vector<int>>&dx, vector<vector<int>>&dy){
        for(int i=0;i<2;i++){
            int newX=x+dx[v[x][y]-1][i], newY=y+dy[v[x][y]-1][i];
            // cout<<"pastX: "<<newX<<" and pastY: "<<newY<<endl;
            if(newX==targetX && newY==targetY) return true;
        }
        return false;
    }
    
    bool findPath2(vector<vector<int>>&v){
        if(v.size()==1 && v[0].size()==1) return true;
        vector<vector<int>>dx({{0,0},{-1,1},{0,1},{0,1},{-1,0},{-1,0}});
        vector<vector<int>>dy({{-1,1},{0,0},{-1,0},{1,0},{0,-1},{0,1}});
        queue<pair<int,int>>q;
        q.push({0,0});
        vector<vector<bool>>visited(v.size(), vector<bool>(v[0].size(), false));
        visited[0][0]=true;
        while(!q.empty()){
            pair<int,int>pr=q.front();
            // cout<<"curr x: "<<pr.first<<" and curr y: "<<pr.second<<endl;
            q.pop();
            for(int i=0;i<2;i++){
                int newX=pr.first+dx[v[pr.first][pr.second]-1][i], newY=pr.second+dy[v[pr.first][pr.second]-1][i];
                // cout<<"adj x: "<<newX<<" and adj Y: "<<newY<<endl;
                if(newX<0 || newX>=v.size() || newY<0 || newY>=v[0].size() || visited[newX][newY]==true || !allowed(v,pr.first,pr.second, newX, newY, dx, dy)) continue;
                if(newX==v.size()-1 && newY==v[0].size()-1) return true;
                // cout<<"adj x: "<<newX<<" and adj Y: "<<newY<<endl;
                q.push({newX, newY});
                visited[newX][newY]=true;
            }
        }
        return false;
    }
    
    bool reachedFinal(int drn, int val){							// Checks whether we entered last index with matching road and drn.
        // cout<<"drn: "<<drn<<" and val: "<<val<<endl;
        if((drn==0) && (val==2 || val==5 || val==6)) return true;
        if((drn==1) && (val==1 || val==4 || val==6)) return true;
        if((drn==2) && (val==2 || val==3 || val==4)) return true;
        if((drn==3) && (val==1 || val==3 || val==5)) return true;
        return false;
    }
    
    bool iteratePath(vector<vector<int>>&v, vector<vector<bool>>&visited, int row, int col, int drn){// DFS func.
        if(row<0 || row>=v.size() || col<0 || col>=v[0].size()) return false;
        if(row==v.size()-1 && col==v[0].size()-1 && reachedFinal(drn, v[row][col])) return true;// If last index is visited, ret. true.
        if(visited[row][col]) return false;									// If already visited, return false.
        visited[row][col]=true;												// Mark curr. index as visited.
        if(drn==0){															// If entered form top.
            if(v[row][col]==2 && iteratePath(v, visited, row+1, col, 0)) return true;// If target reached in fol. calls, we ret. true.
            if(v[row][col]==5 && iteratePath(v, visited, row, col-1, 1)) return true;
            if(v[row][col]==6 && iteratePath(v, visited, row, col+1, 3)) return true;
        }
        if(drn==1){															// If entered from right.
            if(v[row][col]==1 && iteratePath(v, visited, row, col-1, 1)) return true;
            if(v[row][col]==4 && iteratePath(v, visited, row+1, col, 0)) return true;
            if(v[row][col]==6 && iteratePath(v, visited, row-1, col, 3)) return true;
        }
        if(drn==2){															// If entered from bottom.
            if(v[row][col]==2 && iteratePath(v, visited, row-1, col, 2)) return true;
            if(v[row][col]==3 && iteratePath(v, visited, row, col-1, 0)) return true;
            if(v[row][col]==4 && iteratePath(v, visited, row, col+1, 3)) return true;
        }
        if(drn==3){															// If entered from left.
            if(v[row][col]==1 && iteratePath(v, visited, row, col+1, 3)) return true;
            if(v[row][col]==3 && iteratePath(v, visited, row+1, col, 0)) return true;
            if(v[row][col]==5 && iteratePath(v, visited, row-1, col, 2)) return true;
        }
        
        visited[row][col]=false;											// Mark as unvisited, as we are exploring other ways to iter.
        return false;														// Target not reached, return false.
    }
    
    bool hasValidPath(vector<vector<int>>& grid) {
        vector<vector<bool>>visited(grid.size(), vector<bool>(grid[0].size(), false));// Tracks visited indices.
        if(iteratePath(grid, visited, 0,0,0)) return true;					// Start iter. from [0,0] from 4 drns.
        if(iteratePath(grid, visited, 0,0,1)) return true;
        if(iteratePath(grid, visited, 0,0,2)) return true;
        if(iteratePath(grid, visited, 0,0,3)) return true;
        return false;														// If target not found, return false.
        
        // return findPath2(grid); 
    }
};

