/*
*
//******************************************************2373. Largest Local Values in a Matrix.******************************************************

https://leetcode.com/problems/largest-local-values-in-a-matrix/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[9,9,8,1],[5,6,2,6],[8,2,6,4],[6,2,2,2]]
[[1,1,1,1,1],[1,1,1,1,1],[1,1,2,1,1],[1,1,1,1,1],[1,1,1,1,1]]



// Time Complexity: O(n*n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*n).
// Space Complexity: O(1).	
// This algorithm is iteration based. For every index in the res matrix, we specifically iterate in it's related indices in the orig. matrix and assign the 
// max. value among those indices to curr. index in res. We return res at the end of iteration.







class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int len=grid.size();
        vector<vector<int>>res(len-2, vector<int>(len-2,0));
        for(int i=0;i<res.size();i++) {
            for(int j=0;j<res.size();j++) {
                for(int dx=0;dx<=2;dx++) {									// Iterating in all related indices to curr. index [i,j].
                    for(int dy=0;dy<=2;dy++) {
                        res[i][j]=max(res[i][j], grid[i+dx][j+dy]);			// Tracking max. value in the related indices and assign it to [i,j] index in res.
                    }
                }
            }
        }
        return res;															// Returning the res matrix with max. values.
    }
};

