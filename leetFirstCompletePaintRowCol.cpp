/*
*
//******************************************************2661. First Completely Painted Row or Column.******************************************************

https://leetcode.com/problems/first-completely-painted-row-or-column/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,3,4,2]
[[1,4],[2,3]]
[2,8,7,4,1,3,5,6,9]
[[3,2,5],[1,4,6],[8,7,9]]
[6,4,8,7,3,5,11,12,9,1,10,2]
[[1,4,6,11],[9,7,5,12],[2,3,8,10]]



// Time Complexity: O(n*m).
// Space Complexity: O(n*m).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).
// Space Complexity: O(n*m).	
// This algorithm is Map/Array based. Here, we use two arrays to store the row, col values of each num in the matrix as the range of values in the matrix is small. We use two more arrays to how many
// nums from specific row/col by extracting row, col values from numToRow/numToCol arrays. While iterating we update the values in the rows/cols arrays and once the values to return we return the
// corresponding index.







class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        vector<int>numToRow(arr.size(),0), numToCol(arr.size(),0);										// Arrays to link nums to their row, col.
        for(int i=0;i<mat.size();i++) {
            for(int j=0;j<mat[0].size();j++) {
                numToRow[mat[i][j]-1]=i;																// Storing the row of the num.
                numToCol[mat[i][j]-1]=j;																// Storing the col of the num.
            }
        }
        vector<int>rows(mat.size(), mat[0].size()), cols(mat[0].size(), mat.size());					// Tracks #nums from specific row/col are visited.
        for(int i=0;i<arr.size();i++) {
            // cout<<"num: "<<arr[i]<<endl;
            if(--rows[numToRow[arr[i]-1]]==0) return i;													// If all nums in a row are visited, we return curr. index.
            if(--cols[numToCol[arr[i]-1]]==0) return i;													// If all nums in a col are visited, we return curr. index.
        }
        return -1;																						// Default/random return value.
    }
};

