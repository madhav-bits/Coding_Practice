/*
*
//******************************************************304. Range Sum Query 2D - Immutable.**********************************************

Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and 
lower right corner (row2, col2).

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
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12
Note:
You may assume that the matrix does not change.
There are many calls to sumRegion function.
You may assume that row1 ≤ row2 and col1 ≤ col2.


//This is the example which I had tweaked and worked on.
["NumMatrix","sumRegion","sumRegion","sumRegion"]
[[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[0,1,4,3],[0,1,0,2],[1,2,2,4]]

// Time Complexity: O(n^2).
// Space Complexity: O(n^2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/


//************************************************************Solution 1:************************************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n^2).
//The main logic is to calc. the sum of all values with index less than that particular index. And to gain the sum of all values in the given 
//range, subtract the values with lower(rows and clmns no.) than the row1, col1. and adding the common values to the deleted parts, as it's been
// deleted twice.

class NumMatrix {
private:
    vector<vector<int>> sum;
public:
    NumMatrix(vector<vector<int>> v) {
        int row=v.size();
        if(row==0)
            return ;
        int clmn=v[0].size();
        sum=vector<vector<int>>(row,vector<int>(clmn,0));		//Stores sum of all values with index(row, clmn) less than the curr. index.
        int temp=0;
        for(int i=0;i<clmn;i++){				//Storing the cumulattive sum of values in the first row.(Base case).
            temp+=v[0][i];
            sum[0][i]=temp;
        }
            
        for(int i=1;i<row;i++){					//Calc. and storing the cumulative sum for the entire matrix.
            int temp1=0;
            for(int j=0;j<clmn;j++){
                temp1+=v[i][j];
                sum[i][j]=sum[i-1][j]+temp1;
            }
        }
        
        /*
        for(int i=0;i<row;i++){
            for(int j=0;j<clmn;j++)
                cout<<sum[i][j]<<" ";
            cout<<endl;
        }
        */
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int result;
        int row_edge=(row1-1)<0?0:sum[row1-1][col2];
        int clmn_edge1=(col1-1)<0?0:sum[row2][col1-1];
        int clmn_edge2=(col1-1<0 || row1-1<0)?0:sum[row1-1][col1-1];
        result=sum[row2][col2]-row_edge-clmn_edge1+clmn_edge2;	//To get the sum in range, we need to sub top and left index values and
																//add the common values to accomodate double sub.
        //cout<<"1: "<<sum[row2][col2]<<" 2: "<<row_edge<<" 3: "<<clmn_edge1<<" 4: "<<clmn_edge2;
        return result;											//Return the sum of values in the given range.
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */