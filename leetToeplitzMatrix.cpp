/*
*
//*********************************************************766. Toeplitz Matrix.**************************************************

A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same element.

Now given an M x N matrix, return True if and only if the matrix is Toeplitz.
 

Example 1:

Input: matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
Output: True
Explanation:
1234
5123
9512

In the above grid, the diagonals are "[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]", and in each diagonal all 
elements are the same, so the answer is True.
Example 2:

Input: matrix = [[1,2],[2,2]]
Output: False
Explanation:
The diagonal "[1, 2]" has different elements.
Note:

matrix will be a 2D array of integers.
matrix will have a number of rows and columns in range [1, 20].
matrix[i][j] will be integers in range [0, 99].

// Time Complexity: O(n).
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/


//************************************************************Solution 1:************************************************************
// Time Complexity: O(n).
// Space Complexity: O(1).
// This algorithm check whether diagonal elements are same or not. Appraoches the comparision row wise. Whenever diagonal elem. are not equal
// return false. If it passes the entire loop without any issues, then it returns true.


class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& v) {
        int rows=v.size(), clmn=v[0].size();
        for(int i=1;i<rows;i++){
            for(int j=1;j<clmn;j++)
                if(v[i][j]!=v[i-1][j-1])				//Checking whether diagonal elem. are equal or not row wise(elem. of row "i" and row "i-1".
                    return false;
        }
        return true;
    }
};