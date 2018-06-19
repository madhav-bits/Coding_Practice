/*
*
//**************************************************************566. Reshape the Matrix.*****************************************************

In MATLAB, there is a very useful function called 'reshape', which can reshape a matrix into a new one with different size but keep its 
original data.

You're given a matrix represented by a two-dimensional array, and two positive integers r and c representing the row number and column number 
of the wanted reshaped matrix, respectively.

The reshaped matrix need to be filled with all the elements of the original matrix in the same row-traversing order as they were.

If the 'reshape' operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.

Example 1:
Input: 
nums = 
[[1,2],
 [3,4]]
r = 1, c = 4
Output: 
[[1,2,3,4]]
Explanation:
The row-traversing of nums is [1,2,3,4]. The new reshaped matrix is a 1 * 4 matrix, fill it row by row by using the previous list.
Example 2:
Input: 
nums = 
[[1,2],
 [3,4]]
r = 2, c = 4
Output: 
[[1,2],
 [3,4]]
Explanation:
There is no way to reshape a 2 * 2 matrix to a 2 * 4 matrix. So output the original matrix.
Note:
The height and width of the given matrix is in range [1, 100].
The given r and c are all positive.





*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[1,2],[3,4],[5,6]]
2
4


[[1,2],[3,4],[5,6]]
2
3



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm iterates the array, it first checks the #elem. in new matrix is same as old matrix. If not return given matrix. If matches we
// create a new matrix with given shape, we also take two vars, which iterates in orig. array row wise, whenever end of row is reached, we move
// to next row and start iterating from the first coloumn. Thus, we iterate the entire array.








class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& v, int r, int c) {
        if(r*c!=v.size()*v[0].size()) return v;							// If the #elem. doesn't match in old and new matrix, return orig. array.
        vector<vector<int>> res(r,vector<int>(c,0));						// Final result array.
        int row=0, clmn=0;													// Iterators in the orig. array.
        for(int i=0;i<r;i++){												// Iterate in the new array.
            for(int j=0;j<c;j++){
                res[i][j]=v[row][clmn];										// Assign values in new array.
                clmn++;														// Inc. the iterator in the orig. array.
                if(clmn==v[0].size()){										// If end of row is reached, move to next row, first coloumn.
                    clmn=0;row++;
                }
            }
        }
        
        // for(auto nums: res){
        //     for(auto num:nums)
        //         cout<<num<<" ";
        //     cout<<endl;
        // }
        return res;															// Return the final result vector.
    }
};