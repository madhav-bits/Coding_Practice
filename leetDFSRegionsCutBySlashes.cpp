/*
*
//**********************************************************959. Regions Cut By Slashes.***************************************************

In a N x N grid composed of 1 x 1 squares, each 1 x 1 square consists of a /, \, or blank space.  These characters divide the square into 
contiguous regions.

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


["/\\","\\/"]


["//","/ "]




// Time Complexity: O(n^2).  
// Space Complexity: O(n^2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n^2).	
// This algorithm is DFS and Scaling based. Here, we upscale the grid to 9*n^2, so that clearly differentiate parts of a index covered by line
// and empty space and also we can cleanly join the areas connecting two indices. If a line is found, three indices in upscaled grid is marked
//  as 1. If an index has empty space, then whole 9 pixels is left empty. Once, it is upscaled, this problem becomes a Finding Islands 
// in the upscaled graph problem.




// The approach of scaling by 3 times on both dimensions is from this link:
// https://leetcode.com/problems/regions-cut-by-slashes/discuss/205674/C++-with-picture-DFS-on-upscaled-grid

// This problem can also be solved by using Union-Find method. Below link has explanation for the method.
// https://leetcode.com/problems/regions-cut-by-slashes/discuss/205680/JavaC++Python-Split-4-parts-and-Union-Find






class Solution {
public:
    
    void fillRegion(vector<vector<int>>&scaled, int row, int clmn, int val){
        queue<pair<int,int>>q;
        q.push({row, clmn});
        scaled[row][clmn]=val;
        if(row-1>=0 && scaled[row-1][clmn]==0) fillRegion(scaled, row-1, clmn, val);
        if(row+1<scaled.size() && scaled[row+1][clmn]==0) fillRegion(scaled, row+1, clmn, val);
        if(clmn-1>=0 && scaled[row][clmn-1]==0) fillRegion(scaled, row, clmn-1, val);
        if(clmn+1<scaled[0].size() && scaled[row][clmn+1]==0) fillRegion(scaled, row, clmn+1, val);
    }
    
    int regionsBySlashes(vector<string>& v) {
        int res=1;
        vector<vector<int>>scaled(v.size()*3, vector<int>(v[0].length()*3, 0));	// Upscaled grid.
        for(int i=0;i<v.size();i++){										// Converting given grid to Upscaled Grid.
            for(int j=0;j<v[0].length();j++){
                if(v[i][j]=='\\') scaled[3*i+0][3*j+0]=scaled[3*i+1][3*j+1]=scaled[3*i+2][3*j+2]=1;// A line is indicated by marking 3 indices.
                if(v[i][j]=='/') scaled[3*i+0][3*j+2]=scaled[3*i+1][3*j+1]=scaled[3*i+2][3*j+0]=1;
            }
        }
        
        for(int i=0;i<scaled.size();i++){									// Performing Finding islands DFS on new grid.
            for(int j=0;j<scaled[0].size();j++){
                if(scaled[i][j]==0) fillRegion(scaled, i,j,res++);			// DFS call to fill all indices belonging to curr. group/island.
            }
        }
        return res-1;														// Returning the #islands.
    }
};