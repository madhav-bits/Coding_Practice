/*
*
//****************************************************************361. Bomb Enemy.*********************************************************

Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or empty '0' (the number zero), return the maximum enemies you can kill using 
one bomb.
The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since the wall is too strong to be 
destroyed.
Note that you can only put the bomb at an empty cell.

Example:
For the given grid

0 E 0 0
E 0 W E
0 E 0 0

return 3. (Placing a bomb at (1,1) kills 3 enemies)
Credits:
Special thanks to @memoryless for adding this problem and creating all test cases.






*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[["0","E","0","0"],["E","0","W","E"],["0","E","0","0"]]


[["0","E","0","E","0"],["E","0","W","0","E"],["0","E","E","W","0"],["E","W","0","E","0"],["E","0","W","E","0"]]


[["0","E","0","E"],["E","0","W","0"],["0","E","E","W"],["E","W","0","E"],["E","0","W","E"]]

[["0","E","0","E","0"]]


[[],[]]


[]

[[]]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Dynamic Programming based. As, we need to find no. of Enemies reachable in 4 drns from an empty space. We travel from 4 drns
// first from left->right, Top->Bottom, we inc. the count whenever we encounter Enemies and assign the count to index, where we have '0'. We 
// do this iteration from 4 drns and sum up all values extracted from 4 drns.








class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& v) {
        int res=0, sum1=0,sum2=0;
        if(v.size()==0 || v[0].size()==0) return 0;
        vector<vector<int>>dp(v.size(),vector<int>(v[0].size(),0));			// Stores #enemies reachable from an index.
        int len=max(v.size(),v[0].size());									// Max. len of rows& clmns.
        for(int i=0;i<len;i++){												// This iterates from Left->Right, Top->Botttom.
            sum1=0; sum2=0;													//Tracks summation in two drns.
            for(int j=0;j<len;j++){											
                if(i<v.size() && j<v[0].size()){							// If the index is valid.
                    if(v[i][j]=='E') sum1++;								// If enemy enocuntered, inc. the count of enemies.
                    else if(v[i][j]=='W') sum1=0;							// If wall encountered, renew the count.
                    else dp[i][j]+=sum1;									// If empty encountered, add the count to that index in DP vector.
                }
                
                if(j<v.size() && i<v[0].size()){
                    if(v[j][i]=='E') sum2++;
                    else if(v[j][i]=='W') sum2=0;
                    else dp[j][i]+=sum2;
                }
                
            }
        }
        
        // for(int i=0;i<v.size();i++){
        //     for(int j=0;j<v[0].size();j++){
        //         cout<<dp[i][j]<<" ";
        //         res=max(res,dp[i][j]);
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        
        for(int i=len-1;i>=0;i--){											// This iterates from Left->Right, Top->Botttom. 
            sum1=0; sum2=0;
            for(int j=len-1;j>=0;j--){
                if(i<v.size() && j<v[0].size()){
                    if(v[i][j]=='E') sum1++;
                    else if(v[i][j]=='W') sum1=0;
                    else dp[i][j]+=sum1;
                }
                
                if(j<v.size() && i<v[0].size()){
                    if(v[j][i]=='E') sum2++;
                    else if(v[j][i]=='W') sum2=0;
                    else dp[j][i]+=sum2;
                }
                
            }
        }
        
        
        for(int i=0;i<v.size();i++){										// Iterate the entire DP array and extract max value.
            for(int j=0;j<v[0].size();j++){
                // cout<<dp[i][j]<<" ";
                res=max(res,dp[i][j]);
            }
            // cout<<endl;
        }
        
        return res;															// Return the max. value.
        
    }
};











//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Dynamic Programming based. We iterate from curr. index in Right, Bottom Drns if we have wall beind that index/it's index(R/C)
// is '0'. We count #enemies we encounter, if we iterate in both Right, Bottom drn. We sum those values to update the curr. index. Even, if we 
// don't have walls behind curr. index, prev. accumulated sum would be useful in getting the enemies reachable from this index.









class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) { // O(2mn) time!
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        int result = 0, rowhits = 0, colhits[n] = {0};						// Stores enemies reachable in Hori, and vertically for various clmns.
        for (int i=0; i < m; i++) {
            for (int j=0; j < n; j++) {
                if (j == 0 || grid[i][j-1] == 'W') {
                    rowhits = 0;
                    // a Wall will break this loop, can only run until next non-Wall, so this loop will only run completely for once
                    for (int k = j; k < n && grid[i][k] != 'W'; k++) 
                        rowhits += grid[i][k] == 'E';
                }
                if (i == 0 || grid[i-1][j] == 'W') {
                    colhits[j] = 0;
                    for (int k = i; k < m && grid[k][j] != 'W'; k++)
                        colhits[j] += grid[k][j] == 'E';
                }
                if (grid[i][j] == '0')
                    result = max(result, rowhits + colhits[j]);
            }
        }
        return result;
    }
};