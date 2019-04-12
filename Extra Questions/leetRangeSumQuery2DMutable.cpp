/*
*
//******************************************************308. Range Sum Query 2D - Mutable.***********************************************

Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right 
corner (row2, col2).

Range Sum Query 2D
The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.

Example:
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
update(3, 2, 2)
sumRegion(2, 1, 4, 3) -> 10
Note:
The matrix is only modifiable by the update function.
You may assume the number of calls to update and sumRegion function is distributed evenly.
You may assume that row1 ≤ row2 and col1 ≤ col2.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["NumMatrix","sumRegion","update","sumRegion"]
[[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[2,1,4,3],[3,2,2],[2,1,4,3]]



// Time Complexity: O(logm*logn).											// For each query.  O(m*n*logm*logn) for setting init. values.  
// Space Complexity: O(m*n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logm*logn).											// For each query.  O(m*n*logm*logn) for setting init. values.  
// Space Complexity: O(m*n).	
// This algorithm is Binary Indexed Tree based. Here, since we are working on 2D matrix, we use 2D BIT. Were, in each row which includes
// values of curr. row, we update all indices which include particular col j's value. In this way we iter. over all indices and update BIT matrix.
// While querying, we iter. over all rows to get sum till row2, we extract sum till col2 from all those rows getSum(row2, col2), we extract three
// other matrix blocks and manipulate them to get required box's sum.











class NumMatrix {
public:
    
    void updateBIT(int row, int col, int val){
        while(row<tree.size()){												// Iter. over rows including curr. row
            int y=col;
            while(y<tree[0].size()){										// Updating cols including curr. row.
                tree[row][y]+=val;
                y=y+(y&(-y));
            }
            row=row+(row&(-row));
        }
    }
    
    
    
    int getSum(int row, int col){
        int res=0;
        while(row>0){														// Iter. over rows to get sum till given row.
            int y=col;
            while(y>0){														// Iter. over cols in these rows to get sum till given col.
                res+=tree[row][y];
                y=y-(y&(-y));
            }
            row=row-(row&(-row));
        }
        return res;
    }
    
    vector<vector<int>>tree, matr;
    NumMatrix(vector<vector<int>>& matrix) {
        matr=matrix;
        if(matrix.size()>0) tree=vector<vector<int>>(matrix.size()+1, vector<int>(matrix[0].size()+1,0));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                updateBIT(i+1, j+1, matrix[i][j]);
            }
        }
        
    }
    
    void update(int row, int col, int val) {
        updateBIT(row+1, col+1, val-matr[row][col]);
        matr[row][col]=val;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(matr.size()==0 || matr[0].size()==0) return 0;
        return getSum(row2+1, col2+1)-getSum(row2+1, col1)-getSum(row1,col2+1)+getSum(row1,col1);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */