/*
*
//******************************************************1992. Find All Groups of Farmland.******************************************************

https://leetcode.com/problems/find-all-groups-of-farmland/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.






// Time Complexity: O(n*m).
// Space Complexity: O(n*m).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).
// Space Complexity: O(n*m).	
// This algorithm is DFS based. Here, while iter. over given array, when we encounter 1, we start a DFS from that index to cover all adjacent farmland and mark them as '0' and track the maxRow, maxCol of those adjacent indices,
// which makes the bottom right indices of the farmland. Upon returing from DFS, we push this maxRow, maxCol into res and return the res at the end of iter.







class Solution {
public:
    vector<int>dirs;
    void dfs(vector<vector<int>>&v, int row, int col, int& maxRow, int& maxCol) {
        v[row][col]=0;
        if(row>maxRow) maxRow=row;																		// Tracking the maxRow, maxCol of this farmland.
        if(col>maxCol) maxCol=col;																		
        for(int i=0;i<4;i++) {																			// DFS in all 4 drns.
            int dx=dirs[i], dy=dirs[i+1];
            if(row+dx<0 || row+dx>=v.size() || col+dy<0 || col+dy>=v[0].size() || v[row+dx][col+dy]!=1) continue;
            dfs(v, row+dx, col+dy, maxRow, maxCol);
        }
        return ;
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& v) {
        dirs=vector<int>({-1,0,1,0,-1});
        vector<vector<int>>res;
        int color=2;
        for(int i=0;i<v.size();i++) {																	// Iter. over given matrix.
            for(int j=0;j<v[0].size();j++) {
                if(v[i][j]!=1) continue;
                int maxRow=i, maxCol=j;																	// Tracks maxRow, maxCol of this farmland.
                dfs(v, i, j, maxRow, maxCol);															// DFS when and farmland index is encoutered.
                res.push_back({i, j, maxRow, maxCol});													// Pushing top left, bottom right indices of this farmland.
            }
        }
        return res;																						// Returning the coordinates of the farmland.
    }
};











//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).
// Space Complexity: O(n*m).	
// This algorithm is DFS based, it is similar to the above one, except that it changes how DFS is done, here since the farmland is rectangle/square in shape, it first finds maxRow, maxCol by moving right, downwards to cover
// the farmland indices and iter. over the farmland specifically and mark them as visited.













class Solution {
public:
    vector<int>dirs;
    
    void dfs2(vector<vector<int>>&v, int row, int col, int&maxRow, int&maxCol) {
        while(maxRow<v.size() && v[maxRow][col]==1) maxRow++;											// Finding the maxRow, maxCol of this farmland.
        while(maxCol<v[0].size() && v[row][maxCol]==1) maxCol++;										
        maxRow--;maxCol--;
        for(int i=row;i<=maxRow;i++) {																	// Iter. over farmland specifically and marking them as visited.
            for(int j=col;j<=maxCol;j++) {
                v[i][j]=0;
            }
        }
        return ;
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& v) {
        dirs=vector<int>({-1,0,1,0,-1});
        vector<vector<int>>res;
        int color=2;
        for(int i=0;i<v.size();i++) {
            for(int j=0;j<v[0].size();j++) {
                if(v[i][j]!=1) continue;
                int maxRow=i, maxCol=j;
                dfs2(v, i, j, maxRow, maxCol);
                res.push_back({i, j, maxRow, maxCol});													// Pushing top left, bottom right indices of this farmland.
            }
        }
        return res;																						// Returning the coordinates of the farmland.
    }
};