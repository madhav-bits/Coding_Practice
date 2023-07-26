/*
*
//*********************************************2194. Cells in a Range on an Excel Sheet.*********************************************

https://leetcode.com/problems/cells-in-a-range-on-an-excel-sheet/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"K1:L2"
"A1:F1"
"Z9:Z9"
"A1:Z9"
"C3:D9"



// Time Complexity: O(n*m).													// n, m-range of rows, cols in Excel Sheet.
// Space Complexity: O(1).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).													// n, m-range of rows, cols in Excel Sheet.
// Space Complexity: O(1).	
// This algorithm is iteration based. Extract corners of the matrix of cells of concern from the stirng provided, iter. over concerned cells and add their 
// rep to res and return res at the end of iter.







class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string>res;
        char c1=s[0], c2=s[3];												// Corners of the matrix of cells.
        char r1=s[1], r2=s[4];
        
        for(char i=c1;i<=c2;i++) {											// Iter. over range of cols.
            string temp=string(1,i);
            for(char j=r1;j<=r2;j++) {										// Iter. over range of rows.
                res.push_back(temp+j);										// Adding index's rep to res.
            }
        }
        return res;															// Returning arr with rep of cells within given range.
    }
};

