/*
*
//******************************************************980. Unique Paths III.***********************************************

On a 2-dimensional grid, there are 4 types of squares:

1 represents the starting square.  There is exactly one starting square.
2 represents the ending square.  There is exactly one ending square.
0 represents empty squares we can walk over.
-1 represents obstacles that we cannot walk over.
Return the number of 4-directional walks from the starting square to the ending square, that walk over every 
non-obstacle square exactly once.

 

Example 1:

Input: [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
Output: 2
Explanation: We have the following two paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
Example 2:

Input: [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
Output: 4
Explanation: We have the following four paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
Example 3:

Input: [[0,1],[2,0]]
Output: 0
Explanation: 
There is no path that walks over every empty square exactly once.
Note that the starting and ending square can be anywhere in the grid.
 

Note:

1 <= grid.length * grid[0].length <= 20
*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[1,0,0,0],[0,0,0,0],[0,0,2,-1]]

[[1,0,0,0],[0,0,0,0],[0,0,0,2]]

[[1,0,0,0],[0,0,0,0],[0,0,2,-1]]

[[1,0,0,0],[0,0,0,0],[0,0,0,2]]

[[0,0,0,0,0,0,2,0,0,0],[0,0,0,0,0,0,0,0,1,0]]

[[0,2,-1,-1],[1,-1,0,0],[-1,0,0,-1],[-1,-1,-1,-1],[-1,-1,0,-1]]


[[1,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,2]]




// Time Complexity: O(row*col*2^(row*col)).  
// Space Complexity: O(row*col*2^(row*col)).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(row*col*2^(row*col)).
// Space Complexity: O(row*col).	
// This algorithm is DFS based solution. Here, we keep count of all indices that are supposed to be visited in the process of
// reaching destination index. We do a DFS traversal over all indices, we keep track of visited indices in a bool array. 
// By the time we reachd dest. index, if we reached dest. index, we inc. the count of possibilities to reach by 1. 



class Solution {
public:
    
    void traverseArray(vector<vector<int>>& v, int row, int col, vector<vector<bool>>&visited, int covered, int&res, int target){
        if(visited[row][col]) return ;
        covered++;
        visited[row][col]=true;
        if(v[row][col]==2){
            if(covered==target) res++;
            visited[row][col]=false;
            return ;
        }
        vector<int>dirs({-1, 0, 1, 0, -1});
        for(int i=0;i<4;i++){
            int dx=dirs[i], dy=dirs[i+1];
            if(row+dx<0 || row+dx>=v.size() || col+dy<0 || col+dy>=v[0].size() || visited[row+dx][col+dy] || v[row+dx][col+dy]==-1) continue;
            traverseArray(v, row+dx, col+dy, visited, covered, res, target);
        }
        visited[row][col]=false;
        return; 
    }
    
    
    
    int uniquePathsIII(vector<vector<int>>& v) {
        int target=0, startRow=-1, startCol=-1, endRow=-1;
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[0].size();j++){
                if(v[i][j]!=-1) target++;
                if(v[i][j]==1){
                    startRow=i;startCol=j;
                }
                if(v[i][j]==2) endRow=i;
            }
        }
        if(startCol==-1 || endRow==-1) return 0;
        vector<vector<bool>>visited(v.size(), vector<bool>(v[0].size(), false));
        int covered=0, res=0;
        traverseArray(v, startRow, startCol, visited, covered, res, target);
        return res;
    }
};













//*****************************************************Solution 2:*********************************************************
//***********************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(row*col*2^(row*col)).
// Space Complexity: O(row*col*2^(row*col)).	
// This algorithm is DFS and Bit Manipulation Memoization based solution. Here, we keep track of all indices to be visited
// in the target variable. We maintain the memo array to avoid duplicate traversals aiming for same missing indices from
// that index. Here, since #indices are less than 32, we used Bit Manipulation to keep track of visited indices. At every
// index, we update the covered var by current index rep. and update that index of dp array with the total combinations 
// starting from that index for remaining indices. By the time of reaching dest. index, if covered is target, we return 1.
// We return value stored at starting index.

// It has to be Assymptotically lesser complex, but because of smaller test cases, it's taking longer time when compared to
// the above DFS algorithm.








class Solution {
public:
    
    int traverseArray(vector<vector<int>>& v, int row, int col, vector<vector<vector<int>>>&dp, int covered, int target){
        int code=encode(row, col, v[0].size());
        covered=covered|(code);
        if(dp[row][col][covered]!=0) return dp[row][col][covered];		// If this indices are prev. covered, avoid dup. traversal.
        if(v[row][col]==2) return (covered==target)?1:0;
        vector<int>dirs({-1, 0, 1, 0, -1});
        for(int i=0;i<4;i++){
            int dx=dirs[i], dy=dirs[i+1];
            if(row+dx<0 || row+dx>=v.size() || col+dy<0 || col+dy>=v[0].size() || v[row+dx][col+dy]==-1) continue;
            if((covered&encode(row+dx, col+dy, v[0].size()))==0) dp[row][col][covered]+=traverseArray(v, row+dx, col+dy, dp, covered, target);
        }
        return dp[row][col][covered]; 
    }
    
    int encode(int row, int col, int cols){
        return 1<<(row*cols+col);
    }
    
    int uniquePathsIII(vector<vector<int>>& v) {
        int target=0, startRow=-1, startCol=-1, endRow=-1;
        int rows=v.size(), cols=v[0].size();
        vector<vector<vector<int>>>dp(rows, vector<vector<int>>(cols, vector<int>(encode(rows, 0, cols), 0)));
        // dp[rows][cols][encode[rows, 0, cols]]
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[0].size();j++){
                if(v[i][j]!=-1) target=target|(encode(i,j, cols));
                if(v[i][j]==1){
                    startRow=i;startCol=j;
                }
                if(v[i][j]==2) endRow=i;
            }
        }
        // cout<<"Target: "<<target<<endl;
        if(startCol==-1 || endRow==-1) return 0;
        int covered=0, res=0;
        traverseArray(v, startRow, startCol, dp, covered, target);
        return dp[startRow][startCol][encode(startRow, startCol, cols)];
    }
};

