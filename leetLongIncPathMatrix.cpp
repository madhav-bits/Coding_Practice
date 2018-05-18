/*
*
//******************************************************329. Longest Increasing Path in a Matrix.***********************************************

Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the 
boundary (i.e. wrap-around is not allowed).

Example 1:

nums = [
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
Return 4
The longest increasing path is [1, 2, 6, 9].

Example 2:

nums = [
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
Return 4
The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.




[[3,4,5,4,3],[3,2,6,2,1],[2,2,1,4,1]]
[]
[[2,1,3,2,1]]




// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is DFS based. We start from a index, travel in four directions and extract the max possible inc. values length from all sides
// and extract the max value of it. At each step, we move in four directions if values are inc. in that drn. and assign the max. value for that 
// index and forward the max. value to the caller, and mark that index indicating that max. value for that index had been calculated. This way
// once travelled index won't be travelled once again. Thus, making Time Complexity O(n).
// If all conditions checks are counted, it will be O(n^2)-Time Complexity.



class Solution {
public:
    
    int findPath(vector<vector<int>> &matrix, vector<vector<int>> &path, int row, int clmn){
        int maxm=1;																				// Default max. len value.
        
        
        // Row wise movement.
        if(row+1<matrix.size()){																// If next index is legal index.
            if(path[row+1][clmn]!=-1 && matrix[row+1][clmn]>matrix[row][clmn]){					// If len of adj.index already calc.
                maxm=max(maxm, 1+path[row+1][clmn]);											// Just, take that value.
            }		
            else if(path[row+1][clmn]==-1 && matrix[row+1][clmn]>matrix[row][clmn]){			// If not calc., call fn to calc. len for that ind.
                maxm=max(maxm, 1+findPath(matrix, path, row+1, clmn));
            }
        }
        
        if(row-1>=0){
            if(path[row-1][clmn]!=-1 && matrix[row-1][clmn]>matrix[row][clmn]){
                maxm=max(maxm, 1+path[row-1][clmn]);
            }
            else if(path[row-1][clmn]==-1 && matrix[row-1][clmn]>matrix[row][clmn]){
                maxm=max(maxm, 1+findPath(matrix, path, row-1, clmn));
            }
        }
        
        
        
        
        
        //Clmn wise movement.
        if(clmn+1<matrix[0].size()){
            if(path[row][clmn+1]!=-1 && matrix[row][clmn+1]>matrix[row][clmn]){
                maxm=max(maxm, 1+path[row][clmn+1]);
            }
            else if(path[row][clmn+1]==-1 && matrix[row][clmn+1]>matrix[row][clmn]){
                maxm=max(maxm, 1+findPath(matrix, path, row, clmn+1));
            }
        }
        
        if(clmn-1>=0){
            if(path[row][clmn-1]!=-1 && matrix[row][clmn-1]>matrix[row][clmn]){
                maxm=max(maxm, 1+path[row][clmn-1]);
            }
            else if(path[row][clmn-1]==-1 && matrix[row][clmn-1]>matrix[row][clmn]){
                maxm=max(maxm, 1+findPath(matrix, path, row, clmn-1));
            }
        }
        
        path[row][clmn]=maxm;																	// Updating curr. index's max. inc. len value.											
        return maxm;																			// Returning the max. len to the caller.
        
    }
    
    
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size()==0 || matrix[0].size()==0) return 0;
        int maxm=1;
        vector<vector<int>> path(matrix.size(), vector<int>(matrix[0].size(), -1));				// DP, stores the max. path to that index.
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                //cout<<"calling fn with i: "<<i<<" and j: "<<j<<endl;
                if(path[i][j]==-1){																// If, curr index's max. len is not calc.
                    maxm=max(maxm, findPath(matrix, path,i,j));									// Tracking the max. value.
                }
                
                //cout<<"Ended. fn. call"<<endl;
            }
        }
        
        // for(auto nums:path){																	// Iterating the path vector, to check values.
        //     for(auto num:nums){
        //         cout<<num<<" ";
        //     }
        //     cout<<endl;
        // }
        
        return maxm;																			// Returning the max. inc. len value.
    }
};