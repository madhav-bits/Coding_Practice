/*
*
//******************************************************959. Regions Cut By Slashes.***********************************************

In a N x N grid composed of 1 x 1 squares, each 1 x 1 square consists of a /, \, or blank space.  These characters divide the square 
into contiguous regions.

(Note that backslash characters are escaped, so a \ is represented as "\\".)

Return the number of regions.

 

Example 1:

Input:
[
  " /",
  "/ "
]
Output: 2
Explanation: The 2x2 grid is as follows:

Example 2:

Input:
[
  " /",
  "  "
]
Output: 1
Explanation: The 2x2 grid is as follows:

Example 3:

Input:
[
  "\\/",
  "/\\"
]
Output: 4
Explanation: (Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.)
The 2x2 grid is as follows:

Example 4:

Input:
[
  "/\\",
  "\\/"
]
Output: 5
Explanation: (Recall that because \ characters are escaped, "/\\" refers to /\, and "\\/" refers to \/.)
The 2x2 grid is as follows:

Example 5:

Input:
[
  "//",
  "/ "
]
Output: 3
Explanation: The 2x2 grid is as follows:

 

Note:

1 <= grid.length == grid[0].length <= 30
grid[i][j] is either '/', '\', or ' '.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[" /","/ "]


[" /","  "]


["\\/","/\\"]


["/\\","\\/"]


["//","/ "]



// Time Complexity: O(n*n).  
// Space Complexity: O(n*n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*n).
// Space Complexity: O(n*n).	
// This algorithm is DFS based. Here, we have to find #groups. As splitted each index is smaller to consider, we upscale it to n*n*9.
// Based on '/' or '\' we mask the diagonal indices from TR to BL or TL to BR respectively. Now, we iter. over this upscaled matrix
// using DFS and color all indices which are visited. Inc. the cnt of groups at the start of each DFS call. We return the cnt at the
// end of iteration.







class Solution {
public:
    
    void dfs(vector<vector<int>>&v, int row, int col){						// DFS call to iterate 4 adj. indices.
        v[row][col]=1;
        vector<int>dirs({-1,0,1,0,-1});
        for(int i=0;i<4;i++){
            int dx=dirs[i], dy=dirs[i+1];
            if(row+dx<0 || row+dx>=v.size() || col+dy<0 || col+dy>=v[0].size() || v[row+dx][col+dy]==1) continue;
            dfs(v, row+dx, col+dy);
        }
        return ;
    }
    
    int regionsBySlashes(vector<string>& grid) {
        vector<vector<int>>v(grid.size()*3, vector<int>(grid[0].size()*3,0));	// Upscaled by 9 times of init. matrix.
        for(int i=0;i<grid.size();i++){										// Iter. over given matrix.
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==' ') continue;
                if(grid[i][j]=='/'){										// We mask the diagonal from TL to BR.
                    v[i*3][j*3+2]=1;v[i*3+1][j*3+1]=1;v[i*3+2][j*3]=1;
                }
                else{														// We mask the diagonal from TR to BL.
                    v[i*3][j*3]=1;v[i*3+1][j*3+1]=1;v[i*3+2][j*3+2]=1;
                }
            }
        }
        int res=0;
        for(int i=0;i<v.size();i++){										// Iter. over upscaled matrix.
            for(int j=0;j<v[0].size();j++){
                if(v[i][j]==1) continue;
                res++;														// Counting the curr. group.
                dfs(v, i, j);												// Give DFS call to color indices belonging to same group.
            }
        }
        return res;															// Returning the total #groups.
    }
};


