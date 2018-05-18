/*
*
//**********************************************************118. Pascal's Triangle.***************************************************

Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]





*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


0
1
2
5
16
17


// Time Complexity: O(n).  
// Space Complexity: O(n^2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n^2).	
// This algorithm is Dynamic Programming Based. If we set the base case value(first row value), we use the values from previous in getting the
// values for the curr. row.(curr[i]=prev[i-1]+prev[i]) and corner indices for each row are set to 1.



class Solution {
public:
    vector<vector<int>> generate(int rows) {
        vector<vector<int>> res;
        if(rows==0) return res;													// If rows=0, return empty vector.
        res.push_back({1});														// If rows=1, return an vector with single row and single value.
        if(rows==1) return res;
        for(int i=1;i<rows;i++){
            res.push_back({1});													// Setting the corner indices values for each row.
            for(int j=1;j<i;j++){
                res[i].push_back(res[i-1][j-1]+res[i-1][j]);					// Setting curr. row values based on prev. row's values.
            }
            res[i].push_back(1);												// Setting the corner indices values for each row.
        }
        return res;																// Returning the vector of vectors.
    }
};