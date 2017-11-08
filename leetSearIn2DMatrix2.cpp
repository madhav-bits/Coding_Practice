/*

//*********************************************240. Search a 2D Matrix II******************************************************

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
For example,

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.

//******************************************************THIS IS LEET ACCEPTED CODE.*********************************************
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int target) {
        if(v.size()==0 || v[0].size()==0)// We are starting from bottom left corner and scanning upwards towards the target.
            return false;
        int d=v[0].size()-1, i=v.size()-1, j=0;
        while(i>=0 && j<=d){// Iterating through rows and columns.
            if(v[i][j]==target)// Once elem. found it's returned.
                return true;
            if(v[i][j]>target)//If this Mart. elem is more than target then target can't be in that row's elements following this Matr. elem.
                i--;// So, leave this row and go upwards.
            else// If this Matr. elem. is less than target, then target might be in row's elem. following this Matr. elem.
                j++;// So, we  move right wards in that row.
        }
        return false;// If target not found in above scan, then it's not there in given matrix. So, false is returned.
    }
};