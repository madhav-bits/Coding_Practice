/*
*
//********************************************1572. Matrix Diagonal Sum.*********************************************

https://leetcode.com/problems/matrix-diagonal-sum/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


Worked on test cases provided with the question.

[[1,2,3],[4,5,6],[7,8,9]]
[[1,1,1,1],[1,1,1,1],[1,1,1,1],[1,1,1,1]]
[[5]]
[[1,2,3],[4,5,6],[7,8,9]]




// Time Complexity: O(n).  													// n- #rows in the matrix.
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// n- #rows in the matrix.
// Space Complexity: O(n).	
// This algorithm is iteration based. We iter. over rows and all [i,i] indices and [i,mat.size()-1-i] indices and remove
// duplicate count where i=mat.size()-1-i.






class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int res=0;
        for(int i=0;i<mat.size();i++){
            res+=mat[i][i];
            if(i!=mat.size()-1-i) res+=mat[i][mat.size()-1-i];				// Avoids duplicate counting.
        } 
        return res;
    }
};