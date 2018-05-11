/*
*
//******************************************************417. Pacific Atlantic Water Flow.***********************************************

Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, the "Pacific ocean" touches the left 
and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.

Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.

Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.

Note:
The order of returned grid coordinates does not matter.
Both m and n are less than 150.
Example:

Given the following 5x5 matrix:

  Pacific ~   ~   ~   ~   ~ 
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * Atlantic

Return:

[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
[]
[[1,4,2,4,1,4]]
[[[1,2,2,3,5],[3,2,3,4,4]]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is DFS Oriented, we start from the edges and reach all those indices from where water can be reached onto the starting edge. We 
// will mask the already visited indices by placing values in those indices to prevent unnecc. iterations. After all iterations we iterate over
// the reach matrix and push those indices which can be reached from both Oceans into the result pair vector.



class Solution {
public:
    
    void fillHeight(vector<vector<int>> &matrix, vector<vector<int>> &reach, int row, int clmn,int ocean){
        //cout<<"The row is: "<<row<<" and clmn is: "<<clmn<<endl;
        if(ocean==0)
            reach[row][clmn]+=10;
        else
            reach[row][clmn]+=20;
        
        // Handles Pacific Ocean related flow.
        if(ocean==0 && row+1<reach.size() && matrix[row+1][clmn]>=matrix[row][clmn] && reach[row+1][clmn]<10) fillHeight(matrix, reach, row+1, clmn,0);
        if(ocean==0 && clmn+1<reach[0].size() && matrix[row][clmn+1]>=matrix[row][clmn] && reach[row][clmn+1]<10) fillHeight(matrix, reach, row, clmn+1,0);
        if(ocean==0 && row-1>=0 && matrix[row-1][clmn]>=matrix[row][clmn] && reach[row-1][clmn]<10) fillHeight(matrix, reach, row-1, clmn,0);
        if(ocean==0 && clmn-1>=0 && matrix[row][clmn-1]>=matrix[row][clmn] && reach[row][clmn-1]<10) fillHeight(matrix, reach, row, clmn-1,0);
        
        
        
        // Handles Atlantic Ocean related flow.
        if(ocean==1 && row+1<reach.size() && matrix[row+1][clmn]>=matrix[row][clmn] && reach[row+1][clmn]<20) fillHeight(matrix, reach, row+1, clmn,1);
        if(ocean==1 && clmn+1<reach[0].size() && matrix[row][clmn+1]>=matrix[row][clmn] && reach[row][clmn+1]<20) fillHeight(matrix, reach, row, clmn+1,1);
        if(ocean==1 && row-1>=0 && matrix[row-1][clmn]>=matrix[row][clmn] && reach[row-1][clmn]<20) fillHeight(matrix, reach, row-1, clmn,1);
        if(ocean==1 && clmn-1>=0 && matrix[row][clmn-1]>=matrix[row][clmn] && reach[row][clmn-1]<20) fillHeight(matrix, reach, row, clmn-1,1);
        
        
        return ;
    }
    
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int>> res;												// Holds the reachable indices.
        if(matrix.size()==0) return res;										// If no cells present , return empty pair vector.
        vector<vector<int>>reach(matrix.size(),vector<int>(matrix[0].size(),0));
        
        for(int i=0;i<matrix[0].size();i++){                                    //Top Row- Pacific Ocean.
            if(reach[0][i]<10) fillHeight(matrix, reach,0,i,0);
        }
        
        //cout<<"End of first row."<<endl;
        for(int i=0;i<matrix.size();i++){                                       // Left Coloumn- Pacific OCean.
            //cout<<"The clmn is: "<<i<<endl;
            if(reach[i][0]<10) fillHeight(matrix, reach, i,0,0);
        }
        //cout<<"End of pacific iteratoins."<<endl;
        
        for(int i=0;i<matrix[0].size();i++){                                    //Bottom Row- Atlantic Ocean.
            if(reach[matrix.size()-1][i]<20) fillHeight(matrix, reach,matrix.size()-1,i,1);
        }
        
        for(int i=0;i<matrix.size();i++){                                       // Right Coloumn- Atlantic Ocean.
            //cout<<"The clmn is: "<<i<<endl;
            if(reach[i][matrix[0].size()-1]<20) fillHeight(matrix, reach, i,matrix[0].size()-1,1);
        }
        // End of Atlantic Iterations.
        
        
        
        for(int i=0;i<reach.size();i++){
            for(int j=0;j<reach[0].size();j++){
                //cout<<reach[i][j]<<" ";
                if(reach[i][j]==30)												// Indices reachable from both oceans.
                    res.push_back(make_pair(i,j));
            }
            //cout<<endl;
        }
        
        return res;																// Returning the reachable indices.
    }
};