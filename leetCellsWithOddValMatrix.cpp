/*
*
//***************************************1252. Cells with Odd Values in a Matrix.******************************************

https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


2
3
[[0,1],[1,1]]
2
2
[[1,1],[0,0]]
5
8
[[1,1],[0,0],[4,7],[3,1],[4,2],[1,0]]




// Time Complexity: O(n+m+p).												// n-rows, m-cols of matrix, p-udpates.
// Space Complexity: O(n+m).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n+m+p).												// n-rows, m-cols of matrix, p-udpates.
// Space Complexity: O(n+m).	
// This algorithm is observation based. Here, we iter. over all update queries. For each query we update the #inc. in 
// that row, col. After iter. all updates, we multiply rows with even updates with cols with odd updates to get #indices
// with odd updates. We also multiply rows with odd udpates with cols with even updates and add them and return.








class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        int res=0, evenRows=0, oddRows=0, evenCols=0, oddCols=0;
        vector<int>rows(n,0), cols(m,0);									// Stores #updates in each row and col.
        for(auto v:indices){												//  Iter. over updates.
            rows[v[0]]++;
            cols[v[1]]++;
        }
        for(int i=0;i<n;i++){												// To get rows with even updates.
            if(rows[i]%2==0) evenRows++;
        }
        for(int i=0;i<m;i++){												// To get cols with even updates.
            if(cols[i]%2==0) evenCols++;
        }
        oddRows=n-evenRows;													// Calc. rows, cols with odd updates.
        oddCols=m-evenCols;
        return evenRows*oddCols+oddRows*evenCols;							// Calc. #indices with odd updates.
    }
};