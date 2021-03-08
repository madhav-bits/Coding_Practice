/*
*
//**************************************************************542. 01 Matrix.*******************************************************

https://leetcode.com/problems/01-matrix/



Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

 

Example 1:

Input:
[[0,0,0],
 [0,1,0],
 [0,0,0]]

Output:
[[0,0,0],
 [0,1,0],
 [0,0,0]]
Example 2:

Input:
[[0,0,0],
 [0,1,0],
 [1,1,1]]

Output:
[[0,0,0],
 [0,1,0],
 [1,2,1]]
 

Note:

The number of elements of the given matrix will not exceed 10,000.
There are at least one 0 in the given matrix.
The cells are adjacent in only four directions: up, down, left and right.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[0,0,0],[0,1,0],[0,0,0]]
[[0,0,0],[0,1,0],[1,1,1]]
[[0,0,1,0],[0,1,1,0],[1,0,1,0]]



// Time Complexity: O(n*m).  
// Space Complexity: O(n*m).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).
// Space Complexity: O(n*m).	
// This algorithm is BFS based. Here, we store all the indices with zero in the queue and mark rest indices with -1 indicating non-visited indices in 
// BFS. We start BFS, the first instant we reach any index would be it's closest distance from any zero.










class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& v) {
        queue<pair<int,int>>q;
        for(int i=0;i<v.size();i++){										// Storing indices with zero, marking non-zero non-visited indices with -1.
            for(int j=0;j<v[0].size();j++){
                if(v[i][j]==0) q.push({i,j});
                else v[i][j]=-1;
            }
        }
        
        vector<int>dirs({-1,0,1,0,-1});
        int dist=0;
        while(!q.empty()){													// Starting BFS from the indices with zero value.
            dist++;
            int len=q.size();
            for(int i=0;i<len;i++){
                int row=q.front().first, col=q.front().second;
                q.pop();
                for(int j=0;j<4;j++){
                    int dx=dirs[j], dy=dirs[j+1];
                    if(row+dx<0 || row+dx>=v.size() || col+dy<0 || col+dy>=v[0].size() || v[row+dx][col+dy]>=0) continue;
                    v[row+dx][col+dy]=dist;
                    q.push({row+dx, col+dy});
                }
            }
        }
        return v;															// Returning matrix where each index stores it's closest dist. to zeroes.
    }
};