/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly.
 DO NOT allocate another 2D matrix and do the rotation.
 Example 1:

Given input matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
Example 2:

Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
 //*****************************************THIS IS LEET ACCEPTED SOLUTION.************************************************
*/
class Solution {
public:
    void rotate(vector<vector<int>>& v) {
        reverse(v.begin(), v.end());// This line reverse the contents of the matrix row wise(Ex:last row and first row gets swapped.)
        
        for(int i=0;i<v.size();i++){// This part transposes the matrix.
            for(int j=i;j<v.size();j++)
                swap(v[i][j], v[j][i]);
        }
    }
};