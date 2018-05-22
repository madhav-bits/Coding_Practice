/*
*
//**********************************************************463. Island Perimeter.***************************************************

You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are connected 
horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more 
connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a 
square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

Example:

[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Answer: 16
Explanation: The perimeter is the 16 yellow stripes in the image below:





*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[]
[[1,0,0],[1,0,0],[1,1,1]]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is DFS based. This is all extravagant coding. Going to each node and checking it's neighbours and calc. the perim by that node
// (4- non water neighbours). We mark the already visited node with -1 to prevent loops after checking out all neighbors we update the index
// with it's contirbution to the perimeter value. In the second iteration, we sum all indices which have >0 values(As Non-beach land would have=-1)
// in it.





class Solution {
public:
    
    void findPeri(vector<vector<int>> &grid, int row, int clmn){
        int rem=4;
        grid[row][clmn]=-1;														// Preventing reiterating the curr. node.
        if(row-1>=0 && grid[row-1][clmn]!=0){									// Checking whether adj. nodes are water or not.
            rem--;																// Dec. the water adj. count(perimeter count).
            if(grid[row-1][clmn]==1)											// If adj. node not visited, then visit.
                findPeri(grid, row-1, clmn);
        }
        if(clmn-1>=0 && grid[row][clmn-1]!=0){
            rem--;
            if(grid[row][clmn-1]==1)
                findPeri(grid, row, clmn-1);
        }
        if(row+1<grid.size() && grid[row+1][clmn]!=0){
            rem--;
            if(grid[row+1][clmn]==1)
                findPeri(grid,row+1,clmn);
        }
        if(clmn+1<grid[0].size() && grid[row][clmn+1]!=0){
            rem--;
            if(grid[row][clmn+1]==1)
                findPeri(grid,row,clmn+1);
        }
        grid[row][clmn]=(rem==0)?-1:rem;										// If it's a non-beach land, we assign it -1.
        
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int a=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){												// Reaching just one index to island to call fn.
                    a=1;
                    findPeri(grid,i,j);
                    break;
                } 
            }
            if(a==1) break;
        }
        int res=0;																// Perimater value.
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                //cout<<grid[i][j]<<" ";
                if(grid[i][j]>0)												// Summing >0 values.
                    res+=grid[i][j];
            }
            //cout<<endl;
        }
        return res;																// Returning the overall perimeter.
    }
};





//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteraton based. We go to each index, check all it's adj. indices to be land or not to calc. it's contribution to perimeter 
// and add it to final perimter value.









class Solution {
public:
	
    int islandPerimeter(vector<vector<int>>& grid) {
        int res=0, rem;
        for(int row=0;row<grid.size();row++){
            for(int clmn=0;clmn<grid[0].size();clmn++){
                int rem=4;
                if(grid[row][clmn]==1){												// Reaching all land parts.
                    //rem=4;
                    res+=4;															// Inc. the perimeter by 4(Default perim.=4)
                    if(row-1>=0 && grid[row-1][clmn]==1) res--;						// If adj. index is land, dec. the perim. value by 1.
                    if(clmn-1>=0 && grid[row][clmn-1]==1) res--;
                    if(row+1<grid.size() && grid[row+1][clmn]==1) res--;
                    if(clmn+1<grid[0].size() && grid[row][clmn+1]==1) res--;
                    //res+=rem;
                }
                
            }
        }
        return res;																	// Returning the final perimter value.
    }
};






