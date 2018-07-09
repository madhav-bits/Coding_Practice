/*
*
//**************************************************************490. The Maze.*******************************************************

There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up, down, left or right, but it won't 
stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

Given the ball's start position, the destination and the maze, determine whether the ball could stop at the destination.

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

Output: true
Explanation: One possible way is : left -> down -> left -> down -> right -> down -> right.

Example 2

Input 1: a maze represented by a 2D array

0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0

Input 2: start coordinate (rowStart, colStart) = (0, 4)
Input 3: destination coordinate (rowDest, colDest) = (3, 2)

Output: false
Explanation: There is no way for the ball to stop at the destination.

Note:
There is only one ball and one destination in the maze.
Both the ball and the destination exist on an empty space, and they will not be at the same position initially.
The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are 
all walls.
The maze contains at least 2 empty spaces, and both the width and height of the maze won't exceed 100.




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



[[0,0,0,0,1,0,0],
[0,0,1,0,0,0,0],
[0,0,0,0,0,0,0],
[0,0,0,0,0,0,1],
[0,1,0,0,0,0,0],
[0,0,0,1,0,0,0],
[0,0,0,0,0,0,0],
[0,0,1,0,0,0,1],
[0,0,0,0,1,0,0]]
[0,0]
[8,6]




// Time Complexity: O(n).  
// Space Complexity: O(n^2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n^2).	
// This algorithm is DFS based. At the ball only edge at walls or end of maze. We start from the source, in while loops, we travel to walls/
// edges of maze. Store them in a list, then do a DFS on all of them. If one of those members from the list is the target, we return true.
// We also don't travel to a already visited node. Thus, reducing #nodes to visit,at the end we won't have any nodes to visit, if target is not
// reachable.








class Solution {
public:
    
    bool findPath(vector<vector<int>>&maze, vector<int>&start,vector<int>&target,vector<vector<bool>>&visited){
        if(start[0]==target[0] && start[1]==target[1]) return true;			// IF target reached, return true.
        if(visited[start[0]][start[1]]==1) return false;					// IF it's already visited node, return false.
        // cout<<"Curr. row: "<<start[0]<<" and clmn: "<<start[1]<<endl;
        visited[start[0]][start[1]]=true;									// Mark curr. node as visited.
        vector<vector<int>>nextStep;
        findNext(start,maze, nextStep,target);								// Gather all possible next visiting nodes.
        // cout<<"nextstep size: "<<nextStep.size()<<endl;
        for(auto next: nextStep){											// Do DFS on all possible adj. nodes.
            // cout<<"Calling fn. with row: "<<next[0]<<" and clmn: "<<next[1]<<endl;
            if(findPath(maze,next,target,visited))
                return true;
        }
        // cout<<"Done with DFS of row: "<<start[0]<<" and clmn: "<<start[1]<<endl;
        return false;														// IF target not found, return false.
    }
    
    void findNext(vector<int>&start,vector<vector<int>>&maze, vector<vector<int>>&nextStep,vector<int>&target){
        int row=start[0], clmn=start[1];									// Extract next move if traversed downwards.
        for(row=start[0];row+1<maze.size()&& maze[row+1][clmn]==0 ;) row++;    
        
        nextStep.push_back({row,clmn});
        for(row=start[0];row-1>=0&& maze[row-1][clmn]==0;) row--;			// Extract next move if traversed upwards.
        nextStep.push_back({row,clmn});
        
        row=start[0];
        for(clmn=start[1];clmn+1<maze[0].size()&& maze[row][clmn+1]==0 ;) clmn++;// Extract next move if traversed rightwards.    
        nextStep.push_back({row,clmn});
        for(clmn=start[1];clmn-1>=0&& maze[row][clmn-1]==0;) clmn--;		// Extract next move if traversed leftwards.
        nextStep.push_back({row,clmn});
        
    }
    
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& target) {
        vector<vector<bool>>visited(maze.size(),vector<bool>(maze[0].size(),0));// Tracks nodes visited.
        return findPath(maze,start,target,visited);							// Call. fn. to find target reachable or not?
    }
};