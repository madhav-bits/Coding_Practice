/*
*
//******************************************************2643. Row With Maximum Ones.******************************************************

https://leetcode.com/problems/row-with-maximum-ones/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[0,1],[1,0]]
[[0,0,0],[0,1,1]]
[[0,0],[1,1],[0,0]]



// Time Complexity: O(n*m).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).
// Space Complexity: O(1).	
// This algorithm is iteration based. We count #ones for each row and update the res if the curr. cnt>prev. maxOnes stored. We return res at the end of iter.







class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int>res({-1,-1});
        for(int i=0;i<mat.size();i++) {																	// Iter. over matrix.
            int cnt=0;
            for(int j=0;j<mat[0].size();j++) {
                if(mat[i][j]==1) cnt++;
            }
            if(cnt>res[1]) {																			// Updating res if curr. #ones count>stored max #ones.
                res[0]=i;
                res[1]=cnt;
            }
        }
        return res;																						// Returing res which has row number with max #ones, max #ones value.
    }
};

