/*
*
//***********************************1605. Find Valid Matrix Given Row and Column Sums.************************************

https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/


*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


Worked with the test cases provided.


// Time Complexity: O(n*m).  
// Space Complexity: O(n*m).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).
// Space Complexity: O(n*m).	
// This algorithm is observation and Greedy based. Since the sum of rows and cols array are same. We can employ a greedy
// approach where at each index we assign the minm. of both the array's resp. indices to curr. psn in final array and we 
// need not worry about that row/col's index. As we are assigning the minm. val from both ends, we would be able to 
// satisfy the curr. row's total at the end of iter. that row. By the last row, rows[i] and sum of cols arr. would be same
// so we would be assigning value in col array in the last row. This is greedy approach, after going through trial run,
// one would be able to understand it.






class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rows, vector<int>& cols) {
        vector<vector<int>>res(rows.size(), vector<int>(cols.size(),0));	// Final array.
        for(int i=0;i<rows.size();i++){
            for(int j=0;j<cols.size();j++){
                res[i][j]=min(rows[i], cols[j]);							// Get minm. of both arrays.
                rows[i]-=res[i][j];											// Subtracting minm/curr. value.
                cols[j]-=res[i][j];
            }
        }
        return res;
    }
};