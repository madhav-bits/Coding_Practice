/*
*
//*********************************************1594. Maximum Non Negative Product in a Matrix.********************************************

https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/





*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


[[-1,-2,-3],[-2,-3,-3],[-3,-3,-2]]
[[1,-2,1],[1,-2,1],[3,-4,1]]
[[ 1, 4,4,0],[-2, 0,0,1],[ 1,-1,1,1]]
[[1, 3],[0,-4]]



// Time Complexity: O(n*m).													// n- #rows in the matrix.
// Space Complexity: O(m).													// m- #cols in the matrix.	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).													// n- #rows in the matrix.
// Space Complexity: O(m).													// m- #cols in the matrix.	
// This algorithm is Dynamic Programming based. Here, since we have neg. values in the matrix. We maintain two dp matrices where we 
// maintain the minm. and maxm. product to reach that index. This is useful, as dpMin[i-1][j]*v[i][j] could turn out be maxm. until i,j.
// If curr. val is neg. dpMax is influenced by dpMin of adj. indices, if curr. val is posi. dpMax is influenced by dpMax of adj. indices.
// Same goes for dpMin also. So, we employ diff logics if curr. value is neg/pos. At the end of iter. we take the dpMax value, if 
// it is<0, we return -1 else we return the actual value.






class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        vector<vector<long long int>>dpMin(grid.size(), vector<long long int>(grid[0].size(),INT_MAX));
        vector<vector<long long int>>dpMax(grid.size(), vector<long long int>(grid[0].size(),INT_MIN));
    
        dpMin[0][0]=dpMax[0][0]=grid[0][0];
        for(int j=1;j<grid[0].size();j++){
            dpMin[0][j]=dpMax[0][j]=dpMin[0][j-1]*grid[0][j];
            // dpMax[0][j]=dpMax[0][j-1]*grid[0][j];
        }

        for(int i=1;i<grid.size();i++){
            dpMin[i%2][0]=dpMax[i%2][0]=dpMin[(i-1)%2][0]*grid[i][0];
            for(int j=1;j<grid[0].size();j++){
                if(grid[i][j]>=0){											// Diff. logics based on sign of curr. value.
                    dpMax[i%2][j]=max(dpMax[(i-1)%2][j], dpMax[i%2][j-1])*grid[i][j];
                    dpMin[i%2][j]=min(dpMin[(i-1)%2][j], dpMin[i%2][j-1])*grid[i][j];
                }else{
                    dpMax[i%2][j]=min(dpMin[(i-1)%2][j], dpMin[i%2][j-1])*grid[i][j];
                    dpMin[i%2][j]=max(dpMax[(i-1)%2][j], dpMax[i%2][j-1])*grid[i][j];
                }
                // dpMax[i%2][j]=
                // cout<<"i: "<<i<<" and j: "<<j<<" and minm: "<<dpMin[i%2][j]<<" and maxm: "<<dpMax[i%2][j]<<endl;
            }
        }
        dpMax[(grid.size()-1)%2][grid[0].size()-1]=dpMax[(grid.size()-1)%2][grid[0].size()-1]%1000000007;
        return dpMax[(grid.size()-1)%2][grid[0].size()-1]<0?-1:dpMax[(grid.size()-1)%2][grid[0].size()-1];
    }
};
