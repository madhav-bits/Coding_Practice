/*
*
//******************************************************1926. Nearest Exit from Entrance in Maze.******************************************************

https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[["+","+",".","+"],[".",".",".","+"],["+","+","+","."]]
[1,2]
[["+","+","+"],[".",".","."],["+","+","+"]]
[1,0]
[[".","+"]]
[0,0]
[[".",".","+",".","."],["+",".",".",".","."],["+","+","+",".","+"],["+","+","+",".","+"]]
[0,0]




// Time Complexity: O(n*m).  
// Space Complexity: O(m+n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).
// Space Complexity: O(m+n).	
// This algorithm is BFS based. To find the closest exit from the start, we do BFS and use the given array to mark the visited indices with '+' to prevent revisiting. The 
// moment we visit any empty index on any of the 4 boundaries,we return dist. to that index. We mark the start with '+' so that it won't be considered as empty space.
// If we are not able to reach any of the 4 boundaries, we return -1.







class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int steps=0;
        vector<int>dirs({-1,0,1,0,-1});
        queue<pair<int,int>>q;
        maze[entrance[0]][entrance[1]]='+';
        q.push({entrance[0], entrance[1]});									// Starting BFS from start index.
        while(!q.empty()) {
            int len=q.size();
            steps++;														// Tracking the min. dist from start index.
            for(int i=0;i<len;i++) {										// Move in all 4 drns.
                int x=q.front().first, y=q.front().second;
                q.pop();
                for(int j=0;j<4;j++) {
                    int dx=dirs[j],dy=dirs[j+1];
                    if(x+dx<0 || x+dx>=maze.size() || y+dy<0 || y+dy>=maze[0].size() || maze[x+dx][y+dy]=='+') continue;
                    if(x+dx==0 || x+dx==(maze.size()-1) || y+dy==0 || y+dy==(maze[0].size()-1)) return steps;// If boundary index reached, we return the dist.
                    q.push({x+dx, y+dy});									// Add unvisited empty index to queue.
                    maze[x+dx][y+dy]='+';									// Mark the index as visited.
                }
            }
        }
        return -1;															// Returning -1 if we are not able to reach boundaries.
    }
};

