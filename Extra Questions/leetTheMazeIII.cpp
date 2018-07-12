/*
*
//**************************************************************499. The Maze III.*********************************************************

There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up (u), down (d), left (l) or right (r), 
but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction. There is also a hole in this maze. The 
ball will drop into the hole if it rolls on to the hole.

Given the ball position, the hole position and the maze, find out how the ball could drop into the hole by moving the shortest distance. The 
distance is defined by the number of empty spaces traveled by the ball from the start position (excluded) to the hole (included). Output the 
moving directions by using 'u', 'd', 'l' and 'r'. Since there could be several different shortest ways, you should output the lexicographically 
smallest way. If the ball cannot reach the hole, output "impossible".

The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space. You may assume that the borders of the maze are all 
walls. The ball and the hole coordinates are represented by row and column indexes.

Example 1

Input 1: a maze represented by a 2D array

0 0 0 0 0
1 1 0 0 1
0 0 0 0 0
0 1 0 0 1
0 1 0 0 0

Input 2: ball coordinate (rowBall, colBall) = (4, 3)
Input 3: hole coordinate (rowHole, colHole) = (0, 1)

Output: "lul"
Explanation: There are two shortest ways for the ball to drop into the hole.
The first way is left -> up -> left, represented by "lul".
The second way is up -> left, represented by 'ul'.
Both ways have shortest distance 6, but the first way is lexicographically smaller because 'l' < 'u'. So the output is "lul".

Example 2

Input 1: a maze represented by a 2D array

0 0 0 0 0
1 1 0 0 1
0 0 0 0 0
0 1 0 0 1
0 1 0 0 0

Input 2: ball coordinate (rowBall, colBall) = (4, 3)
Input 3: hole coordinate (rowHole, colHole) = (3, 0)
Output: "impossible"
Explanation: The ball cannot reach the hole.

Note:
There is only one ball and one hole in the maze.
Both the ball and hole exist on an empty space, and they will not be at the same position initially.
The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are all 
walls.
The maze contains at least 2 empty spaces, and the width and the height of the maze won't exceed 30.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.




[[0,0,0,0,0],[1,1,0,0,1],[0,0,0,0,0],[0,1,0,0,1],[0,1,0,0,0]]
[4,3]
[0,1]




[[0,0,0,0,1,0,0],[0,0,1,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,0,1],[0,1,0,0,0,0,0],[0,0,0,1,0,0,0],[0,0,0,0,0,0,0],[0,0,1,0,0,0,1],[0,0,0,0,1,0,0]]
[0,0]
[8,6]



[[0,1,0,0,1,0,0,1,0,0],[0,0,1,0,0,1,0,0,1,0],[0,0,0,0,0,0,1,0,0,1],[0,0,0,0,0,0,1,0,0,1],[0,1,0,0,1,0,0,1,0,0],[0,0,1,0,0,1,0,0,0,0],[0,0,0,0,0,0,1,0,0,0],[1,0,0,1,0,0,0,0,0,1],[0,1,0,0,1,0,0,1,0,0],[0,0,0,0,0,1,0,0,1,0]]
[2,4]
[7,6]



[[0,1,0,0,1,0,0,1,0,0],[0,0,1,0,0,0,0,0,0,0],[0,0,0,1,0,0,1,0,0,1],[0,0,0,1,0,0,1,0,0,1],[0,1,0,0,1,0,0,1,0,0],[0,0,0,0,0,1,0,0,0,0],[0,0,0,0,0,0,1,0,0,1],[0,0,0,1,0,0,0,0,0,0],[0,1,0,0,1,0,0,1,0,0],[0,0,1,0,0,1,0,0,1,0]]
[1,5]
[5,1]






// Time Complexity: O((n^2)!).  											// Not so sure about time complexity.
// Space Complexity: O(n^2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O((n^2)!).												// Not so sure about time complexity.
// Space Complexity: O(n^2).	
// This algorithm is DFS based. We start from the source, since we want a lexicographically smallest path.We iterate in d,l,r,u order. At each 
// stop, we iterate in 4 drns, to the next 4 psns, where
// ball can stop, and do DFS on all those 4 locations. If we reach a already reached psn with smaller distance from source, then we once again 
// do a DFS from that index. If we reach the target with a smaller sum, then only we change the result string.



// Due to it's recursive nature. It takes a lot of time to execute.




class Solution {
public:
    // string res="z";
    
    bool isValid(vector<vector<int>>&maze, int row, int clmn){				// Check whether index is valid or not?
        if(row<0 || row>=maze.size() || clmn<0 || clmn>=maze[0].size()|| maze[row][clmn]==1) return false;
        return true;
    }
    
    void findMinPath(vector<vector<int>>&maze, vector<vector<int>>&visited, vector<int>&start,vector<int>&target,string &str, string &res){
        // cout<<"Inside the fn. with row: "<<start[0]<<" and clmn: "<<start[1]<<endl;
        vector<int>dirs({1,0,0,-1,0,1,-1,0});//0,1,0,-1,0
        for(int i=0;i<=6;i+=2){												// Iterate in all 4 drns.
            string str2;													// New updated path from source till next move.
            if(i==0) str2=str+"d";											// Updating the path variable.
            else if(i==2) str2=str+"l";
            else if(i==4) str2=str+"r";
            else  str2=str+"u";
            
            int x=start[0], y=start[1];
            int dx=dirs[i],dy=dirs[i+1];
            int step=0;
            while(isValid(maze, x+dx,y+dy)){								// Iteration in 4 drns in valid indices.
                x+=dx;y+=dy;
                step++;
                if(x==target[0]&& y==target[1] ){							// If target reached.
                    // cout<<"Target reached."<<"with dist: "<<visited[start[0]][start[1]]+step<<"orig: "<<visited[target[0]][target[1]]<<endl;
                    // cout<<"Str is: "<<str2<<endl;
                    if(visited[start[0]][start[1]]+step<visited[target[0]][target[1]]){// If smaller length is obtained, then change result str.
                        res=str2;
                        visited[x][y]=visited[start[0]][start[1]]+step;      // Update the distance. 
                    } 
                    break ;													// We stop further iteration.
                }
                
                
            }
            if((x==start[0] && y==start[1]) ||(x==target[0] && y==target[1])) continue;// If target, still at curr. index, we skip processing them.
            if(visited[start[0]][start[1]]+step<visited[x][y]){				// If next stop is reached in samller time than prev. time.
                visited[x][y]=visited[start[0]][start[1]]+step;				// Update the distance.
                vector<int>temp({x,y});				
                findMinPath(maze,visited,temp,target,str2,res);				// DO a DFS in that direction.
            }
        }
    }
    
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        vector<vector<int>>visited(maze.size(),vector<int>(maze[0].size(),INT_MAX));
        string st="";														// Default path travelled.
        string res="z";														// Default path.
        visited[ball[0]][ball[1]]=0;
        findMinPath(maze,visited,ball,hole,st,res);							// Calling fn. to extract smallest path.
        return (res=="z")?"impossible":res;									// Return extracted path.
    }
};














//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O((n^2)!).												// Not so sure about time complexity.
// Space Complexity: O(n^2).	
// This algorithm is BFS based. We start from the source. At each stop, we iterate in 4 drns, to the next 4 psns, where
// ball can stop and do BFS on them. If we reach a already reached psn with smaller distance from source, then we once again 
// do a BFS from that index. As it's BFS, iterating a particular fashion(d,l,r,u) would be of no use. If we reach the target with a smaller 
// sum/ a lexicographically smaller path with prev. reachable smallest path, then only we change the result string. 










class Solution {
public:
    
    bool isValid(vector<vector<int>>&maze, int row, int clmn){
        if(row<0 || row>=maze.size() || clmn<0 || clmn>=maze[0].size()|| maze[row][clmn]==1) return false;
        return true;
    }
    
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& target) {
        vector<vector<int>>visited(maze.size(),vector<int>(maze[0].size(),INT_MAX));// Tracks index's smallest dist. from source.
        vector<vector<string>>path(maze.size(),vector<string>(maze[0].size(),""));// Store the path to each index from start.
        visited[ball[0]][ball[1]]=0;
        path[target[0]][target[1]]="z";										// Default path.
        queue<pair<int,int>>q;
        q.push({ball[0],ball[1]});											// Push source into queue.
        vector<int>dirs({1,0,0,-1,0,1,-1,0});
        while(!q.empty()){
            pair<int,int>curr=q.front();
            // cout<<"Curr. row: "<<curr.first<<" and clmn: "<<curr.second<<endl;
            q.pop();
            for(int i=0;i<=6;i+=2){											// Iterate in 4 drns.
                int x=curr.first,y=curr.second;
                int dx=dirs[i], dy=dirs[i+1], step=0;
                string str2;
                if(i==0) str2=path[curr.first][curr.second]+"d";
                else if(i==2) str2=path[curr.first][curr.second]+"l";
                else if(i==4) str2=path[curr.first][curr.second]+"r";
                else  str2=path[curr.first][curr.second]+"u";
                
                while(isValid(maze, x+dx,y+dy)){							// Travel in 1 drn in valid indices.
                    x+=dx;y+=dy;
                    step++;
                    if(x==target[0]&& y==target[1] ){						// If target reached.
                        // cout<<"Target reached."<<"with dist: "<<visited[curr.first][curr.second]+step<<"orig: "<<visited[target[0]][target[1]]<<endl;
                        // cout<<"Str is: "<<str2<<endl;
                        if(visited[curr.first][curr.second]+step<visited[target[0]][target[1]]){// If reached in smaller dist. than prev.
                            // res=str2;
                            path[x][y]=str2;								// Update path.
                            visited[x][y]=visited[curr.first][curr.second]+step;// Update the distance.        
                        }													// If reached with same dist. but lexically small, then update path.
                        else if(visited[curr.first][curr.second]+step==visited[target[0]][target[1]] && str2<path[x][y]) path[x][y]=str2;
                        break ;												// Stop further iteration.
                    }
                }
                if((x==curr.first && y==curr.second) ||(x==target[0] && y==target[1])) continue;// If target, still at curr. index, we skip processing them.
                // cout<<"End of iteration row: "<<x<<" and clmn: "<<y<<endl;
                // cout<<"Dist: "<<visited[curr.first][curr.second]+step<<" old dist: "<<visited[x][y]<<endl;
                if(visited[curr.first][curr.second]+step<=visited[x][y]){	// If next stop is reached is smaller or equal dist. than prev.
                    visited[x][y]=visited[curr.first][curr.second]+step;	//  Update the distance.
                    path[x][y]=str2;										// Update the path.
                    // cout<<"Pushing row: "<<x<<" and clmn: "<<y<<endl;
                    q.push({x,y});                                  		// Push into queue.
                }
            }
        }
        return (path[target[0]][target[1]]=="z")?"impossible":path[target[0]][target[1]];// Return the lexically smallest dist. from source.
    }
};