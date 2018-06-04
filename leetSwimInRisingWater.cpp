/*
*
//******************************************************778. Swim in Rising Water.***********************************************

On an N x N grid, each square grid[i][j] represents the elevation at that point (i,j).

Now rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 4-directionally adjacent 
square if and only if the elevation of both squares individually are at most t. You can swim infinite distance in zero time. Of course, you 
must stay within the boundaries of the grid during your swim.

You start at the top left square (0, 0). What is the least time until you can reach the bottom right square (N-1, N-1)?

Example 1:

Input: [[0,2],[1,3]]
Output: 3
Explanation:
At time 0, you are in grid location (0, 0).
You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.

You cannot reach point (1, 1) until time 3.
When the depth of water is 3, we can swim anywhere inside the grid.
Example 2:

Input: [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
Output: 16
Explanation:
 0  1  2  3  4
24 23 22 21  5
12 13 14 15 16
11 17 18 19 20
10  9  8  7  6

The final route is marked in bold.
We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
Note:

2 <= N <= 50.
grid[i][j] is a permutation of [0, ..., N*N - 1].




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[21,17,18,19,20],[10,9,8,7,26]]
[[1,2],[2,0]]


// Time Complexity: O(n^2).  
// Space Complexity: O(n^2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n^2).	
// This algorithm is BFS based. We start from the starting index, we extract adjacent unvisted nodes and store their values in the priority_queue
// while pushing values into pq,we also push their indices(pq is sorted by index's content/value), if adj. node's to be pushed value< curr. 
// node's val, we push the curr. node's value, if the adj. node's val. > curr. node's val, we push adj node's val. When we encounter value
// with target's indices, we return the value.








class Solution {
public:
    
    int swimInWater(vector<vector<int>>& grid) {
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));			// Tracks the visited nodes.
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;			// We push values into priority_queue.
        pq.push({grid[0][0], 0,0});															// Pushing the starting val., index into pq.
        visited[0][0]=1;																	// Marking the starting index as visited.
        while(!pq.empty()){
            vector<int> temp=pq.top();
            //cout<<"Extracted node with val: "<<temp[0]<<endl;
            if(temp[1]==grid.size()-1 && temp[2]==grid[0].size()-1) return temp[0];
            pq.pop();
            int row=temp[1], col=temp[2];													// Row,Col value of curr. node.
            if(row-1>=0 && visited[row-1][col]==0){											// Pushing all possible adj. nodes values.
                //cout<<"pushed val with row: "<<row-1<<" and col: "<<col<<endl;
                pq.push({max(temp[0],grid[row-1][col]), row-1, col});						// Pushing the max. value into pq.
                visited[row-1][col]=1;
            } 
            if(row+1<grid.size() && visited[row+1][col]==0){
                //cout<<"pushed val with row: "<<row+1<<" and col: "<<col<<endl;
                pq.push({max(temp[0],grid[row+1][col]), row+1, col});
                visited[row+1][col]=1;
            } 
            if(col-1>=0 && visited[row][col-1]==0){
                //cout<<"pushed val with row: "<<row<<" and col: "<<col-1<<endl;
                pq.push({max(temp[0],grid[row][col-1]), row, col-1});
                visited[row][col-1]=1;
            } 
            if(col+1<grid[0].size() && visited[row][col+1]==0){
                //cout<<"pushed val with row: "<<row<<" and col: "<<col+1<<endl;
                pq.push({max(temp[0],grid[row][col+1]), row, col+1}); 
                visited[row][col+1]=1;
            } 
        }
        return -1;																				// When you can't reach dest. return -1.
        
    }
};







//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS NOT A LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^4).
// Space Complexity: O(n^2).	
// This algorithm is DFS based. It goes through all possible scenarios, while maintaining the least possible value at each index, after the 
// iteration, we return the value at the rightmost bottom index.








class Solution {
public:
    void calcTime(vector<vector<int>> &grid, vector<vector<int>>& dp, int row, int clmn, int val){
        //cout<<"Inside fn. with row; "<<row<<" and clmn: "<<clmn<<"with val: "<<val<<endl;
        int change=0;
        if(dp[row][clmn]==INT_MAX ){													// Changing form defualt INT_MAX to grid's value.
            //dp[row][clmn]=max(grid[row][clmn],val);
            change=1;
            dp[row][clmn]=grid[row][clmn];
        }
        else if(dp[row][clmn]==grid[row][clmn] && val>grid[row][clmn]){					// Changing from grid's value to a greater value.
            dp[row][clmn]=val;
            //pass=dp[row][clmn];
            change=1;
        }
        else if(val<dp[row][clmn] && val > grid[row][clmn]){							// Choosing the smallest value greater than grid's value.
            dp[row][clmn]=val;
            change=1;
        }
        
        if(change==1){																	//If time updated, then call adj.nodes.
            // dp[row][clmn]=val;
            if(row-1>=0) calcTime(grid, dp, row-1, clmn, dp[row][clmn]);
            if(row+1<grid.size()) calcTime(grid, dp, row+1, clmn, dp[row][clmn]);
            if(clmn-1>=0) calcTime(grid, dp, row, clmn-1, dp[row][clmn]);
            if(clmn+1<grid[0].size()) calcTime(grid, dp, row, clmn+1, dp[row][clmn]);
        }
        
        
    }
    
    int swimInWater(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), INT_MAX));
        //dp=grid;
        calcTime(grid, dp,0,0, 0);														// Calling the dfs. function.
        for(auto nums: dp){
            for(auto num:nums)
                cout<<num<<" ";
            cout<<endl;
        }
        
        return dp[grid.size()-1][grid[0].size()-1];										// Return the time in rightmost bottom index.
    }
};
