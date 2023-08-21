/*
*
//******************************************************2679. Sum in a Matrix.******************************************************

https://leetcode.com/problems/sum-in-a-matrix/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[7,2,1],[6,4,2],[6,5,3],[3,2,1]]
[[1]]
[[4,6,7,4,37,9],[5,7,6,4,8,6],[5,7,3,2,5,5],[9,2,7,5,3,2],[6,5,3,7,5,4]]



// Time Complexity: O(m*n*logn).  											// m-#rows, n-#cols in the matrix.
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m*n*logn).											// m-#rows, n-#cols in the matrix.
// Space Complexity: O(1).	
// This algorithm is Sorting based. We sort the array in each row to know which of the vals get deleted in each turn, also all values that get deleted in a turn
// will now be in same column. So, for each column we iter. over all rows and track the maxVal in that col and add it to res. We return res at the end of iter.







class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        for(vector<int>&v:nums) sort(v.begin(),v.end());					// Sort every row in the matrix.
        int res=0, rows=nums.size(), cols=nums[0].size();
        for(int j=0;j<cols;j++) {											// Iter. over cols.
            int maxm=0;
            for(int i=0;i<rows;i++) {										// Iter. over all rows for each col.
                if(nums[i][j]>maxm) maxm=nums[i][j];						// Track the max. val in curr. col.
            }
            res+=maxm;														// Adding the max. val in curr. col to res.
        }
        return res;															// Returning the total score.
    }
};

