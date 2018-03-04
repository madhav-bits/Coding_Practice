/*
*
//******************************************************************542. 01 Matrix.***********************************************************

Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.
Example 1: 
Input:

0 0 0
0 1 0
0 0 0
Output:
0 0 0
0 1 0
0 0 0
Example 2: 
Input:

0 0 0
0 1 0
1 1 1
Output:
0 0 0
0 1 0
1 2 1
Note:
The number of elements of the given matrix will not exceed 10,000.
There are at least one 0 in the given matrix.
The cells are adjacent in only four directions: up, down, left and right.





*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.

[[0,0,1],[1,1,0],[1,1,1]]
[[1,1,1],[1,1,1],[0,1,1]]




// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).	
// Space Complexity: O(n).	
// This algorithm is BREADTH FIRST SEARCH. If we do iterations from back and front directions. It covers all possibilities of reaching a non-zero
// index from index with zero value.(Need to put a deep thought into it to understand)ex- Dist. from row+1, clmn-1 drn is covered by combi. of 
// forware and backward iter. first update in right index and update up to reach row,clmn index.



class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& v) {
        vector<vector<int>> dp(v.size(),vector<int>(v[0].size(), v.size()+v[0].size()));
        
        for(int i=0;i<v.size();i++){													// From top left to bottom right drn.
            for(int j=0;j<v[0].size();j++){
                if(v[i][j]==0) dp[i][j]=0;
                else{
                    if(i-1>=0) dp[i][j]= min(dp[i][j], 1+dp[i-1][j]);            		// From the top.
                    if(j-1>=0) dp[i][j]= min(dp[i][j], 1+dp[i][j-1]);            		// From the left.
                }
            }
        }
        for(int i=v.size()-1;i>=0;i--){													// From bottom right to top left drn.
            for(int j=v[0].size()-1;j>=0;j--){
                if(v[i][j]==0) dp[i][j]=0;
                else{
                    if(i+1<v.size()) dp[i][j]= min(dp[i][j], 1+dp[i+1][j]);           	 // From the bottom.
                    if(j+1<v[0].size()) dp[i][j]= min(dp[i][j], 1+dp[i][j+1]);        	 // From the right.
                }
            }
        }
        
        return dp;																		// Return the dp, matrix with shortest dist. from zeroes.
    }
};