/*
*
//***************************************1277. Count Square Submatrices with All Ones.****************************************

https://leetcode.com/problems/count-square-submatrices-with-all-ones/description/


Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

 

Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
Example 2:

Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.
 

Constraints:

1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[0,1,1,1],[1,1,1,1],[0,1,1,1]]


[[1,0,1],[1,1,0],[1,1,0]]

[[0,1,1,1,1,0],[1,1,1,1,1,1],[0,1,1,1,1,1]]

[[0,1,1,1,1,0],[1,1,1,1,1,0],[0,1,1,1,1,1]]


[[0,1,0,1,0,0],[1,1,1,1,1,1],[0,1,1,0,1,1]]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is based on Prefix Sum. Here, at every index, we check how many consecutive ones do we have to the left, top and 
// diagonally. We take the minm. value among them, then add 1 and assign it to current index. We add the assigned value to result,
// as a square with side of 'x' with curr. index as bottom right can form x different side length squares with curr. index as bottom
// right. If curr. index has zero, we skip it. At the end of iter. we return the total count of squares.






class Solution {
public:
    int countSquares(vector<vector<int>>& v) {
        
        int res=0;															// Tracks total number of possible squares.
        for(int i=0;i<v.size();i++){										// Iter. over matrix.
            for(int j=0;j<v[0].size();j++){
                if(v[i][j]==0) continue;									// If it is zero, skip it.
                if(i==0 || j==0){											// If it is in first row or first column, it will have only square size of 1.
                    res++;
                    continue;
                }
                int minm=min({v[i-1][j], v[i][j-1], v[i-1][j-1]})+1;		// Get minm of three sides, add 1 and assign it to curr. index.
                v[i][j]=minm;
                res+=minm;													// Add the square size to final result, as it can produce
            }																// minm number of diff. len sqs with curr idx as bottom right.
        }
        return res;															// Returning total number of sqauares possible.
    }
};

