/*
*
//********************************************2257. Count Unguarded Cells in the Grid.********************************************

https://leetcode.com/problems/count-unguarded-cells-in-the-grid/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


4
6
[[0,0],[1,1],[2,3]]
[[0,1],[2,2],[1,4]]
3
3
[[1,1]]
[[0,1],[1,0],[2,1],[1,2]]



// Time Complexity: O(n*m).  
// Space Complexity: O(n*m).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).
// Space Complexity: O(n*m).	
// This algorithm is iteration based. We create an array to represent the matrix and mark wells and guards first. Since a guard can cover in 4 drns, we do four 
// sweeps in each drn and change and keep on changing all free/uncovered indices based on whether we encountered guard or wall recently. If we visit a guard
// recently in this iter, that means curr. index will be covered by guard, so mark it as covered(-1), if we met a wall recently that means no guard covers 
// this index in curr. drn. We do this in all 4 drns and mark uncovered indices as covered based on above conditions. We later iter. over entire array and 
// count all uncovered indices and return their count.







class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int res=0;
        int arr[m][n];
        memset(arr, 0, sizeof(arr));
        for(vector<int>&guard:guards) arr[guard[0]][guard[1]]=1;			// Marking both guards and walls.
        for(vector<int>&wall:walls) arr[wall[0]][wall[1]]=2;
        for(int i=0;i<m;i++) {
            int left=0, right=0;
            for(int j=0, k=n-1;j<n;j++, k--) {								// We sweep in both drns for each row.
                if(arr[i][j]==0) arr[i][j]=left;							// If curr. index is uncovered, assign value based on recent visited guard/wall.
                else if(arr[i][j]==1) left=-1;								// If latest visited is guard, updated the marker to covered to update next indices.
                else if(arr[i][j]==2) left=0;								// If latest visited is wall, updated the marker to uncovered to update next indices.
                
                if(arr[i][k]==0) arr[i][k]=right;
                else if(arr[i][k]==1) right=-1;
                else if(arr[i][k]==2) right=0;
            }
        }
        
        for(int j=0;j<n;j++) {
            int left=0, right=0;
            for(int i=0,k=m-1;i<m;i++,k--) {								// We sweep in both drns for each coloumn.
                if(arr[i][j]==0) arr[i][j]=left;
                else if(arr[i][j]==1) left=-1;
                else if(arr[i][j]==2) left=0;
                
                if(arr[k][j]==0) arr[k][j]=right;
                else if(arr[k][j]==1) right=-1;
                else if(arr[k][j]==2) right=0;
            }
            for(int i=0;i<m;i++) {											// Iter. over curr. coloumn and counting uncovered indices.
                if(arr[i][j]==0) res++;
            }
        }
        return res;															// Returning the total #uncovered indices.
    }
};








//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).
// Space Complexity: O(n*m).	
// This algorithm is iteration based. We mark guards and walls for the array. We iter. over guards and for each guard we iter. in 4 drns and update indices
// which are covered and stop updating if we reach a guard or a wall, we stop for a guard because later indices in same drn would be covered by the guard we 
// encountered now. We stop for a wall as prevents us guarding the later indices in same drn. Thus, we visit each index 4 times in 4 drns iter., in case of 
// an index which have guards in all 4 drns. We later iter. over array and count #uncovered indices and return their count.









class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int res=0;
        int arr[m][n];
        memset(arr, -1, sizeof(arr));
        vector<int>dirs({-1,0,1,0,-1});
        for(vector<int>&guard:guards) arr[guard[0]][guard[1]]=1;			// Marking both guards and walls.
        for(vector<int>&wall:walls) arr[wall[0]][wall[1]]=2;
        for(vector<int>&guard:guards) {										// Iter. over all guards.
            for(int i=0;i<4;i++) {											// Sweep indices in 4 drns for each guard.
                int row=guard[0], col=guard[1];
                int dx=dirs[i], dy=dirs[i+1];
                while(row+dx>=0 && row+dx<m && col+dy>=0 && col+dy<n && arr[row+dx][col+dy]<1) {// Mark indices as covered until we reach guard/wall.
                    arr[row+dx][col+dy]=0;
                    row+=dx;
                    col+=dy;
                }
            }
        }
        for(int i=0;i<m;i++) {												// Iter. over array and counting all uncovered indices.
            for(int j=0;j<n;j++) 
                if(arr[i][j]==-1) res++;
        }
        return res;															// Returning the total #uncovered indices.
    }
};






