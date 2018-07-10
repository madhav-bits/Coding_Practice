/*
*
//****************************************************************505. The Maze II.*********************************************************

There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up, down, left or right, but it won't 
stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

Given the ball's start position, the destination and the maze, find the shortest distance for the ball to stop at the destination. The distance 
is defined by the number of empty spaces traveled by the ball from the start position (excluded) to the destination (included). If the ball 
cannot stop at the destination, return -1.

The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space. You may assume that the borders of the maze are 
all walls. The start and destination coordinates are represented by row and column indexes.

Example 1

Input 1: a maze represented by a 2D array

0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0

Input 2: start coordinate (rowStart, colStart) = (0, 4)
Input 3: destination coordinate (rowDest, colDest) = (4, 4)

Output: 12
Explanation: One shortest way is : left -> down -> left -> down -> right -> down -> right.
             The total distance is 1 + 1 + 3 + 1 + 2 + 2 + 2 = 12.

Example 2

Input 1: a maze represented by a 2D array

0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0

Input 2: start coordinate (rowStart, colStart) = (0, 4)
Input 3: destination coordinate (rowDest, colDest) = (3, 2)

Output: -1
Explanation: There is no way for the ball to stop at the destination.





*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.




[[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]]
[0,4]
[4,4]



[[1,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]]
[0,1]
[4,4]



[[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]]
[0,4]
[1,2]



[[1,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]]
[0,4]
[0,1]


[[0,0,0,0,1,0,0],[0,0,1,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,0,1],[0,1,0,0,0,0,0],[0,0,0,1,0,0,0],[0,0,0,0,0,0,0],[0,0,1,0,0,0,1],[0,0,0,0,1,0,0]]
[0,0]
[8,6]





// Time Complexity: O(n^2).  												// As indices are revisited, if some other path reaches it in
// Space Complexity: O(n^2).												// -smaller distance compared to earlier time.

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).													// There can be lot of walls to work on.(Not sure abt. Time complexity).
// Space Complexity: O(n^2).	
// This algorithm is BFS based. We start from the source, extract next four stops by iterating until wall/end of matrix is reached. We push 
// them into queue, if the dist. to reach that index is shorter than earlier dist. needed to travel to it. In this way, we keep on updating
// the min. dist to all indices where ball can stop(If target is reachable we update it's index), if not distance to it remains unchanged to 
// INT_MAX, in which case we return -1, if reachable, we return the value in that index.








class Solution {
public:
    bool isValid(int row, int clmn, vector<vector<int>>&maze){				// Check whether ball can flow in this index or not?
        if(row<0 || row>=maze.size() || clmn<0 || clmn>=maze[0].size() || maze[row][clmn]==1) return false;
        return true;
    }
    
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& target) {
        vector<vector<int>>visited(maze.size(),vector<int>(maze[0].size(),INT_MAX));
        int rowIndex=target[0], clmnIndex=target[1];						// Target's row and clmn.
        queue<pair<int,int>>q;												// Stores indices where ball can reach from source and stop.
        q.push(make_pair(start[0],start[1]));								// We will start from source.
        visited[start[0]][start[1]]=0;										// Mark the source as visited.
        vector<int>dirs({0,-1,0,1,0});										// Useful in iterating in four drns from a stoppable index.
        while(!q.empty()){													// Iterate till queue is empty.
            pair<int,int>curr=q.front();									// Extracting the curr. index.
            q.pop();
            int x,y,step=0;
            for(int i=0;i<4;i++){											// Iterate in all four drns.
                x=curr.first+dirs[i];										// Update the row value.
                y=curr.second+dirs[i+1];									// Update the clmn value.
                step=0;														// Steps taken to reach curr. index from curr. stop index.
                while(isValid(x,y,maze)){									// Iterates until wall/end of maze is reached.
                    x+=dirs[i];												// Updating the row value.
                    y+=dirs[i+1];
                    step++;													// Updating the distance.
                }
                x-=dirs[i];													// Moving a step back to get reachable&stoppable index.
                y-=dirs[i+1];

                if(visited[curr.first][curr.second]+step<visited[x][y]){	// If new dist is <prev. reachable dist. then push it into queue.
                    // cout<<"Curr. pushing row: "<<x<<" and clmn: "<<y<<endl;
                    q.push({x,y});											// Push into queue.
                    visited[x][y]=visited[curr.first][curr.second]+step;	// Update the index with new distance.
                }
            }
            
        }
        
        return visited[rowIndex][clmnIndex]==INT_MAX?-1:visited[rowIndex][clmnIndex];// Return the min. distance needed to reach target index.
    }
};