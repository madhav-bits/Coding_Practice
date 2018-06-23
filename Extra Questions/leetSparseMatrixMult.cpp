/*
*
//******************************************************311. Sparse Matrix Multiplication.***********************************************

Given two sparse matrices A and B, return the result of AB.

You may assume that A's column number is equal to B's row number.

Example:

Input:

A = [
  [ 1, 0, 0],
  [-1, 0, 3]
]

B = [
  [ 7, 0, 0 ],
  [ 0, 0, 0 ],
  [ 0, 0, 1 ]
]

Output:

     |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
                  | 0 0 1 |




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[1,0,0],[-1,0,3]]
[[7,0,0,2],[0,0,0,1],[0,0,1,2]]



// Time Complexity: O(m*n*o).  
// Space Complexity: O(m*n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m*n*o).
// Space Complexity: O(m*n).	
// This algorithm is observation based. We iterate through the first matrix, if the curr. value in first matrix is 0, we skip calculation. We 
// update the final result vector at first matrix's curr. index's row and second matrix's curr. index's coloumn index.








class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& u, vector<vector<int>>& v) {
        vector<vector<int>>res(u.size(),vector<int>(v[0].size(),0));		// Initializing the final result vector.
        for(int i=0;i<u.size();i++){										// Iterating through the first matrix.
            for(int j=0;j<v.size();j++){
                if(u[i][j]==0) continue;									// If first matrix has 0, we skip calculation.
                for(int k=0;k<v[0].size();k++){								// Iterating through the second coloumn.
                    res[i][k]+=(u[i][j]*v[j][k]);
                        
                }
            }
        }
        // for(auto nums:res){
        //     for(auto num:nums)
        //         cout<<num<<" ";
        //     cout<<endl;
        // }
        return res;															// Returning the result vector.
    }
};