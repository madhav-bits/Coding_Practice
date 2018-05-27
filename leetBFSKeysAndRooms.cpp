/*
*
//**********************************************************841. Keys and Rooms.***************************************************

There are N rooms and you start in room 0.  Each room has a distinct number in 0, 1, 2, ..., N-1, and each room may have some keys to 
access the next room. 

Formally, each room i has a list of keys rooms[i], and each key rooms[i][j] is an integer in [0, 1, ..., N-1] where N = rooms.length.  A 
key rooms[i][j] = v opens the room with number v.

Initially, all the rooms start locked (except for room 0). 

You can walk back and forth between rooms freely.

Return true if and only if you can enter every room.

Example 1:

Input: [[1],[2],[3],[]]
Output: true
Explanation:  
We start in room 0, and pick up key 1.
We then go to room 1, and pick up key 2.
We then go to room 2, and pick up key 3.
We then go to room 3.  Since we were able to go to every room, we return true.
Example 2:

Input: [[1,3],[3,0,1],[2],[0]]
Output: false
Explanation: We can't enter the room with number 2.
Note:

1 <= rooms.length <= 1000
0 <= rooms[i].length <= 1000
The number of keys in all rooms combined is at most 3000.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[]
[0]
[[0],[2],[1]]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is BFS based. We start iterating from the room-"0". At each room we push into queue only those room numbers which are not visited
// till then. We visit all the rooms in the sequence they have been pushed into queue. We stop iterating till queue is empty(all possible rooms
// starting from room-"0" are visited. If after the iteration the visited rooms size= total #rooms, then return true else return false.





class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& v) {
        //if(v.size()==0) return true;
        set<int> visited;															// Stores the rooms viisted at any point of time.
        queue<int> q;																// Stores the rooms to be visited and can be reached from "0".
        q.push(0);																	// Starting from room-"0".
        visited.insert(0);															// Marking room-"0" as visited.
        while(!q.empty()){
            int temp=q.front();														// Extracting the front room. no. from queue.
            q.pop();
            int len = v[temp].size();
            for(int i=0;i<len;i++){													// Storing all unvisited rooms, that can be reached from. curr.
                if(visited.count(v[temp][i])==0){									// Storing unvisited rooms into queue.	
                    q.push(v[temp][i]);				
                    visited.insert(v[temp][i]);										// Marking the stored rooms as visited.
                    //cout<<"Room being pushed into set: "<<v[temp][i]<<endl;
                }
            }
        }
        //cout<<"The set size is: "<<visited.size()<<endl;
        return (visited.size()==v.size())? true:false;								// If all rooms are visited return true else return false.
        
            
    }
};