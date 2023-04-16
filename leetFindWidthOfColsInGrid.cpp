/*
*
//******************************************************2639. Find the Width of Columns of a Grid.******************************************************

https://leetcode.com/problems/find-the-width-of-columns-of-a-grid/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[1],[22],[333]]
[[-15,1,3],[15,7,12],[5,6,-2]]
[[-15,1,3,0],[15,7,12,0],[5,6,-212,0]]



// Time Complexity: O(n*m).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, since we are gathering max. length for every column, we create a res array with #columns length. In iteration, we calc. length of number at every index
// and update the value in res array if needed. 







class Solution {
public:
    
    int calculateLength(int num) {																		// Calc. length of each number.
        if(num==0) return 1;
        int res=0;
        if(num<0) res++;
        while(num) {
            res++;
            num/=10;
        }
        return res;
    }
    
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        vector<int>res(grid[0].size(),0);																// Res array with #columns length.
        for(int i=0;i<grid.size();i++) {																// Iter. over  matrix.
            for(int j=0;j<grid[0].size();j++) {
                int len=calculateLength(grid[i][j]);													// Calc. length for each num.
                if(len>res[j]) res[j]=len;																// Updating res array if curr. length>stored max length value.
            }
        }
        return res;																						// Return array with max number length for all columns.
    }
};

