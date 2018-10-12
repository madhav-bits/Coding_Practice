/*
*
//**********************************************************598. Range Addition II.***************************************************


Given an m * n matrix M initialized with all 0's and several update operations.

Operations are represented by a 2D array, and each operation is represented by an array with two positive integers a and b, which means 
M[i][j] should be added by one for all 0 <= i < a and 0 <= j < b.

You need to count and return the number of maximum integers in the matrix after performing all the operations.

Example 1:
Input: 
m = 3, n = 3
operations = [[2,2],[3,3]]
Output: 4
Explanation: 
Initially, M = 
[[0, 0, 0],
 [0, 0, 0],
 [0, 0, 0]]

After performing [2,2], M = 
[[1, 1, 0],
 [1, 1, 0],
 [0, 0, 0]]

After performing [3,3], M = 
[[2, 2, 1],
 [2, 2, 1],
 [1, 1, 1]]

So the maximum integer in M is 2, and there are four of it in M. So return 4.
Note:
The range of m and n is [1,40000].
The range of a is [1,m], and the range of b is [1,n].
The range of operations size won't exceed 10,000.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



6
7
[[3,4],[1,6],[3,4]]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Observation based. Here, if observed the least values of row, clmn would be included in all the other ranges also, so 
// those range of values would be increased the most.









class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& v) {
        int row=m, clmn=n;													// USed to track min. row, clmn.
        for(int i=0;i<v.size();i++){										// ITer. through all operations.
            row=min(row, v[i][0]);											// Extracting the minm. row.
            clmn=min(clmn, v[i][1]);										// Extracting the minm. clmn.
        }
        return row*clmn;													// Reutrning the max. effected indices count.
    }
};