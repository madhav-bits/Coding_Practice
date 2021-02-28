/*
*
//**********************************************************1765. Map of Highest Peak.***************************************************

https://leetcode.com/problems/map-of-highest-peak/


*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.

[[0,1],[0,0]]
[[0,0,1],[1,0,0],[0,0,0]]
[[0,0,1],[1,0,0],[0,0,0],[0,1,0],[0,0,1]]




// Time Complexity: O(n*m).  
// Space Complexity: O(n*m).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m*n).
// Space Complexity: O(m*n).	
// This algorithm is BFS based. Here, since we want the adjacent indices to be with values not distant by 1, assigning heights based on BFS would be a 
// nice strategy. So, we start it by taking all water cells as start indices and assigning rest indices to -1 to indicate that they are yet to be visited.








class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& v) {
        queue<pair<int,int>>q;
        for(int i=0;i<v.size();i++){										// Iter. over entire array.
            for(int j=0;j<v[0].size();j++){
                if(v[i][j]==1){												// Storing all well indices.
                    q.push({i,j});
                    v[i][j]=0;												// Init. these indices to 0.
                }
                else v[i][j]=-1;											// Marking rest indices to -1 to identify unvisited indices.
            }
        }
        
        vector<int>dirs({-1,0,1,0,-1});
        while(!q.empty()){													// Until all indices are visited.
            // cout<<"curr val: "<<val-1<<endl;
            int len=q.size();
            for(int i=0;i<len;i++){
                int x=q.front().first, y=q.front().second;
                // cout<<"x: "<<x<<" and y: "<<y<<" and val: "<<v[x][y]<<endl;
                q.pop();
                for(int i=0;i<4;i++){
                    int dx=dirs[i],dy=dirs[i+1];
                    if(x+dx<0 || x+dx>=v.size() || y+dy<0 || y+dy>=v[0].size() || v[x+dx][y+dy]>=0) continue;
                    q.push({x+dx,y+dy});									// Adding unvisited adj. indices to queue.
                    v[x+dx][y+dy]=v[x][y]+1;								// Assigning heights to indices to be visited in next round.
                }
            }
        }
        return v;															// Returning the matrix with heights assigned to all indices.
    }
};
