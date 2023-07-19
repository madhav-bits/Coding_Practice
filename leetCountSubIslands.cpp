/*
*
//******************************************************1905. Count Sub Islands.******************************************************

https://leetcode.com/problems/count-sub-islands/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]]
[[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
[[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]]
[[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]
[[1,1,1,0,0],[0,1,0,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]]
[[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]




// Time Complexity: O(n*m).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).
// Space Complexity: O(1).	
// This algorithm is iteration based. We do DFS on islands based on connectivity of indices on grid2, if we observe any of the indices we visit in the process 
// to be 0 in grid1, we mark that this island is not covered by returning false from the DFS call, yet we cover all connected indices as per grid2 and mark 
// them visited. If we return true from DFS, we inc. the res by 1, we return res at the end of iter.







class Solution {
public:
    vector<int>dirs;
    bool dfsCover(vector<vector<int>>&grid1, vector<vector<int>>&grid2, int row, int col) {
        bool res=(grid1[row][col]==1);										// If grid1 value is 0, we set flag=false.
        grid2[row][col]=0;
        for(int i=0;i<4;i++) {												// DFS call to all adj. connected indices.
            int dx=dirs[i], dy=dirs[i+1];
            if(row+dx<0 || row+dx>=grid1.size() || col+dy<0 || col+dy>=grid1[0].size() || grid2[row+dx][col+dy]==0) continue;
            if(!dfsCover(grid1, grid2, row+dx, col+dy)) res=false;			// If we get false from any DFS calls, we carry it to parent of DFS call.
        }
        return res;															// Returning whether indice visited in this DFS call are covered in grid1.
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        dirs=vector<int>({-1,0,1,0,-1});
        int res=0;
        for(int i=0;i<grid1.size();i++) {
            for(int j=0;j<grid1[0].size();j++) {
                if(grid2[i][j]==0) continue;
                if(dfsCover(grid1, grid2, i ,j)) res++;						// If all indices of island are covered, we inc. res by 1.
                // cout<<"i: "<<i<<" and j: "<<j<<" and res: "<<res<<endl;
            }
        }
        
        return res;															// Returning the total #covered islands.
    }
};

