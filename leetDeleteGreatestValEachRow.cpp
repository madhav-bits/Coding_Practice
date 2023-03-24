/*
*
//******************************************************2500. Delete Greatest Value in Each Row.******************************************************

https://leetcode.com/problems/delete-greatest-value-in-each-row/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[1,2,4],[3,3,1]]
[[10]]
[[1,2,4,5,3],[1,2,5,6,3],[1,2,4,5,4]]



// Time Complexity: O(m*logn).  																		// m-#rows, n-#cols.
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m*logn).																			// m-#rows, n-#cols.
// Space Complexity: O(1).	
// This algorithm is Sorting based. Here, since at the each step we take maxm. of all rows and use the max. among them and remove all the maxm. values, we are essentially gathering max values of 
// all columns if all rows are sorted. We sort all rows, get maxm in each col and add them and return the total.







class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int res=0;
        for(vector<int>&v:grid) {																		// Sorting all rows.
            sort(v.begin(), v.end());
        }
        
        for(int j=0;j<grid[0].size();j++) {																// Iterating over all columns.
            int maxm=1;
            for(int i=0;i<grid.size();i++) {															// Extracting max. in curr. column across all rows.
                if(grid[i][j]>maxm) maxm=grid[i][j];
            }
            res+=maxm;																					// Adding max. value to res.
        }
        return res;																						// Returning the total of max values of all columns.
    }
};

