/*
*
//**************************************************************749. Contain Virus.*********************************************************

A virus is spreading rapidly, and your task is to quarantine the infected area by installing walls.

The world is modeled as a 2-D array of cells, where 0 represents uninfected cells, and 1 represents cells contaminated with the virus. A wall 
(and only one wall) can be installed between any two 4-directionally adjacent cells, on the shared boundary.

Every night, the virus spreads to all neighboring cells in all four directions unless blocked by a wall. Resources are limited. Each day, you can 
install walls around only one region -- the affected area (continuous block of infected cells) that threatens the most uninfected cells the 
following night. There will never be a tie.

Can you save the day? If so, what is the number of walls required? If not, and the world becomes fully infected, return the number of walls used.

Example 1:
Input: grid = 
[[0,1,0,0,0,0,0,1],
 [0,1,0,0,0,0,0,1],
 [0,0,0,0,0,0,0,1],
 [0,0,0,0,0,0,0,0]]
Output: 10
Explanation:
There are 2 contaminated regions.
On the first day, add 5 walls to quarantine the viral region on the left. The board after the virus spreads is:

[[0,1,0,0,0,0,1,1],
 [0,1,0,0,0,0,1,1],
 [0,0,0,0,0,0,1,1],
 [0,0,0,0,0,0,0,1]]

On the second day, add 5 walls to quarantine the viral region on the right. The virus is fully contained.
Example 2:
Input: grid = 
[[1,1,1],
 [1,0,1],
 [1,1,1]]
Output: 4
Explanation: Even though there is only one cell saved, there are 4 walls built.
Notice that walls are only built on the shared boundary of two different cells.
Example 3:
Input: grid = 
[[1,1,1,0,0,0,0,0,0],
 [1,0,1,0,1,1,1,1,1],
 [1,1,1,0,0,0,0,0,0]]
Output: 13
Explanation: The region on the left only builds two new walls.
Note:
The number of rows and columns of grid will each be in the range [1, 50].
Each grid[i][j] will be either 0 or 1.
Throughout the described process, there is always a contiguous viral region that will infect strictly more uncontaminated squares in the next 
round.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



[[0,1,0,0,0,0,0,1],[0,1,0,0,0,0,0,1],[0,0,0,0,0,0,0,1],[0,0,0,0,0,0,0,0]]



[[1,1,1],[1,0,1],[1,1,1]]



[[1,1,1,0,0,0,0,0,0],[1,0,1,0,1,1,1,1,1],[1,1,1,0,0,0,0,0,0]]




[[0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,1,0,0],[1,0,0,0,0,0,0,0,0,0],[0,0,1,0,0,0,1,0,0,0],[0,0,0,0,0,0,1,0,0,0],[0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,1,0],[0,0,0,0,1,0,1,0,0,0],[0,0,0,0,0,0,0,0,0,0]]




[[0,1,1,1,1,0,1,1,0,0],[0,0,0,0,0,0,1,1,0,0],[0,0,0,0,0,1,0,0,0,1],[0,0,1,0,0,0,0,1,0,0],[1,0,0,0,0,0,1,0,0,0],[0,0,1,1,0,1,0,0,1,0],[0,0,0,0,0,0,0,0,0,1],[0,0,0,0,0,1,1,0,0,0],[0,0,0,1,0,1,0,0,0,0],[0,0,1,0,0,0,0,0,1,0]]







// Time Complexity: O(k*n^2).  												// Not a constant value 'k', but a value certainly less than n.
// Space Complexity: O(n^2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(k*n^2).												// Not a constant value 'k', but a value certainly less than n.
// Space Complexity: O(n^2).	
// This algorithm is DFS based. Here, we iterate until we find no more uninfected cells adjacent to infected cells. In every iteration, we iterate
// over all infected groups(Not conatined by wall) and find the group that effects the most, and calculate #walls required to block it and mark
// them with -1/2 value, so that they won't be considered once again. We expands rest of infected areas by one step in 4 drns. To perform various
// tasks such as calculating #uninfected cells adj. to each group of infected cells. Build wall around a group and mark them as blocked cells, 
// expanding infected cells groups by 1 step in 4 drns, we had written separate functions for each of them.








class Solution {
public:
    
    vector<int>dirs{-1,0,1,0,-1};
    int findNeighbor(vector<vector<int>>& v, int row, int clmn, vector<vector<bool>>& visited){// Calc. #uninfected cells adj. to each group.
        int ans=0;
        queue<pair<int,int>>q;
        q.push({row, clmn});
        visited[row][clmn]=true;
        unordered_set<string>st;
        while(!q.empty()){													// Until all cells of curr. group are visited.
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<=3;i++){
                int dx=dirs[i], dy=dirs[i+1];
                if(x+dx<0 || x+dx>=v.size() || y+dy<0 || y+dy>=v[0].size()) continue;
                string temp=to_string(x+dx)+"#"+to_string(y+dy);
                if(v[x+dx][y+dy]==1 && visited[x+dx][y+dy]==false){
                    q.push({x+dx, y+dy});
                    visited[x+dx][y+dy]=true;
                }else if(v[x+dx][y+dy]==0 && st.count(temp)==0){			// When a adj. cell with '0' for first time.
                    ans++;							
                    st.insert(temp);
                }
            }
        }
        return ans;															// Returning #adj. cells with value '0' for curr. group.
    }
    
    int buildWalls(vector<vector<int>>& v, int row, int clmn, vector<vector<bool>>&visited){// Building walls around curr. group and counting #walls.
        int walls=0;
        queue<pair<int,int>>q;
        q.push({row, clmn});
        v[row][clmn]=2;
        visited[row][clmn]=true;
        while(!q.empty()){													// Until all cells in curr. group are visited.
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<=3;i++){
                int dx=dirs[i], dy=dirs[i+1];
                if(x+dx<0 || x+dx>=v.size() || y+dy<0 || y+dy>=v[0].size()) continue;
                if(v[x+dx][y+dy]==1 && visited[x+dx][y+dy]==false){
                    visited[x+dx][y+dy]=true;
                    v[x+dx][y+dy]=2;
                    q.push({x+dx, y+dy});
                }else if(v[x+dx][y+dy]==0) walls++;
            }
        }
        return walls;														// Returning #walls used to block this group.
    }
    
    void expandInfection(vector<vector<int>>& v, int row, int clmn, vector<vector<bool>>&visited){// Expanding curr. group by 1 step on 4 sides.
        queue<pair<int,int>>q;
        q.push({row, clmn});
        visited[row][clmn]=true;
        while(!q.empty()){													// Until all cells in curr. group are visited.
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<=3;i++){
                int dx=dirs[i], dy=dirs[i+1];
                if(x+dx<0 || x+dx>=v.size() || y+dy<0 || y+dy>=v[0].size()) continue;
                if(visited[x+dx][y+dy]==false){
                    visited[x+dx][y+dy]=true;
                    if(v[x+dx][y+dy]==1) q.push({x+dx, y+dy});
                    else if(v[x+dx][y+dy]==0) v[x+dx][y+dy]=1;				// Changing adj. cell with value '0' to value '1'.
                }
            }
        }
            
    }
    
    int buildWallsAndInfection(vector<vector<int>>& v, int row, int clmn){	// Handles building walls and expanding infected regions.
        int walls=0;
        vector<vector<bool>>visited(v.size(), vector<bool>(v[0].size(), false));// Tracking visited cells.
        walls=buildWalls(v,row, clmn, visited);								// Call to build walls around most infecting group.
        for(int i=0;i<v.size();i++){										// Iter. over all cells and expanding each group by 1.
            for(int j=0;j<v[0].size();j++){
                if(v[i][j]==1 && visited[i][j]==false) expandInfection(v,i,j, visited);
            }
        }
        return walls;														// Returning #walls required to block curr. group.
    }
    
    int containVirus(vector<vector<int>>& v) {
        int res=0;
        int walls=0;
        while(true){														// Until there are uninfected cells prone to infection.
            res=0;															// Tracks max. #uninfected cells prone to infection.
            int row=-1, clmn=-1;											// Tracks row, clmn of dangerous group.
            // cout<<"The val. in this state: "<<endl;
            // for(auto nums: v){
            //     for(auto num:nums)
            //         cout<<num<<"\t";
            //     cout<<endl;
            // }
            vector<vector<bool>>visited(v.size(), vector<bool>(v[0].size(), false));// Tracks visited indices.
            for(int i=0;i<v.size();i++){									// Iter. over all indices looking for all infected groups.
                for(int j=0;j<v[0].size();j++){
                    if(v[i][j]==1 && visited[i][j]==false){					// If unvisited group found, start iteration.
                        int ans=findNeighbor(v,i,j, visited);				// Get #uninfected adj. cells to curr. group.
                        // cout<<"THe adj: "<<ans<<endl;
                        if(ans>res){										// If has greater #uninfected cells, update index of group values.
                            row=i; clmn=j;
                            res=ans;
                        }
                    }
                    
                }
            }
            // cout<<"The infected regions: "<<res<<endl;
            if(res==0) return walls;										// If no effecting cells found, return #walls build till then.
            // cout<<"Deleting row: "<<row<<" and clmn: "<<clmn<<endl;
            int temp=buildWallsAndInfection(v,row, clmn);					// Call to Build wall and expand else groups by 1 step.
            // cout<<"The walls: "<<temp<<endl;
            walls+=temp;													// Adding #walls built in each step.
        }
        
    }
};