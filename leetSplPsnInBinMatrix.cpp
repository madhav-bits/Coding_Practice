/*
*
//****************************************1582. Special Positions in a Binary Matrix.**************************************

https://leetcode.com/problems/special-positions-in-a-binary-matrix/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


I worked on test cases provided with the question.
[[1,0,0],[0,0,1],[1,0,0]]
[[0,0,0,1],[1,0,0,0],[0,1,1,0],[0,0,0,0]]
[[1,0,0],[0,1,0],[0,0,1]]
[[0,0,0,0,0],[1,0,0,0,0],[0,1,0,0,0],[0,0,1,0,0],[0,0,0,1,1]]




// Time Complexity: O(n*m).  
// Space Complexity: O(n+m).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).
// Space Complexity: O(n+m).	
// This algorithm is array based. We store #ones in every row and col in two arrays representing rows and cols count. 
// While iter. at every index, if the value is 1 and val. in rows[currRow] and cols[currCol] is 1, that is it's the 
// only one in that row and column, as it meets all cdns, we inc. the count. At the end of iter. we return the count. 







class Solution {
public:
    int numSpecial(vector<vector<int>>& v) {
        vector<int>rows(v.size(),0), cols(v[0].size(),0);
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[0].size();j++){
                if(v[i][j]==0) continue;
                rows[i]++;cols[j]++;
            }
        }
        int res=0;
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[0].size();j++){
                if(v[i][j]==0) continue;
                if(rows[i]==1 && cols[j]==1) res++;
            }
        }
        return res;
    }
};
