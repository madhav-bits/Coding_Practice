/*
*
//********************************************2201. Count Artifacts That Can Be Extracted.****************************************

https://leetcode.com/problems/count-artifacts-that-can-be-extracted/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


2
[[0,0,0,0],[0,1,1,1]]
[[0,0],[0,1]]
2
[[0,0,0,0],[0,1,1,1]]
[[0,0],[0,1],[1,1]]
10
[[0,2,3,2],[2,4,3,5],[4,5,5,5],[8,0,8,0],[8,2,8,2],[8,3,8,4]]
[[0,2],[1,2],[2,2],[3,2],[4,5],[4,6],[5,4],[8,0],[8,1],[8,2],[8,4],[8,5],[5,7]]



// Time Complexity: O(m+n+l*l).												// m-#artifacts, n-#cells excavated, l-length/breadth of cells range.
// Space Complexity: O(l*l).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m+n+l*l).												// m-#artifacts, n-#cells excavated, l-length/breadth of cells range.
// Space Complexity: O(l*l).	
// This algorithm is iteration based. Here, we used this approach as the range of cells is small. We use an array to mark cells which are explored, later,
// we iter. over artifacts and since each artifact spreads over 4 cells at max., we iter. over all cells belonging to a artifact and count the artifact if 
// all cells it belongs to are excavated else we don't count this artifact. We return #artifacts fully excavated at the end of iteration.






class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        int res=0;
        bool grid[n][n];													// Cells range in consideration.
        memset(grid, false, sizeof(grid));											
        for(vector<int>&v:dig) grid[v[0]][v[1]]=true;						// Marking cells as excavated.
        for(vector<int>&v:artifacts) {										// Iter. over all artifacts.
            int r1=v[0],c1=v[1], r2=v[2], c2=v[3];
            bool valid=true;
            for(int i=r1;i<=r2;i++) {										// Iter. over all cells belonging to a artifact.
                for(int j=c1;j<=c2;j++) {
                    if(grid[i][j]==false) {									// If any cell not excavated, we don't count this artifact.
                        valid=false;
                        break;
                    }
                }
                if(!valid) break;
            }
            if(valid) res++;												// If all cells of artifact are excavated, we count it.
        }
        return res;															// Returning #artifacts which are fully excavated.
    }
};

