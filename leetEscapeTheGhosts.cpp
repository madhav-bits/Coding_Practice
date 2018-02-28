/*
*
//**********************************************************789. Escape The Ghosts.***************************************************

You are playing a simplified Pacman game. You start at the point (0, 0), and your destination is (target[0], target[1]). There are several 
ghosts on the map, the i-th ghost starts at (ghosts[i][0], ghosts[i][1]).

Each turn, you and all ghosts simultaneously *may* move in one of 4 cardinal directions: north, east, west, or south, going from the previous 
point to a new point 1 unit of distance away.

You escape if and only if you can reach the target before any ghost reaches you (for any given moves the ghosts may take.)  If you reach any 
square (including the target) at the same time as a ghost, it doesn't count as an escape.

Return True if and only if it is possible to escape.

Example 1:
Input: 
ghosts = [[1, 0], [0, 3]]
target = [0, 1]
Output: true
Explanation: 
You can directly reach the destination (0, 1) at time 1, while the ghosts located at (1, 0) or (0, 3) have no way to catch up with you.
Example 2:
Input: 
ghosts = [[1, 0]]
target = [2, 0]
Output: false
Explanation: 
You need to reach the destination (2, 0), but the ghost at (1, 0) lies between you and the destination.
Example 3:
Input: 
ghosts = [[2, 0]]
target = [1, 0]
Output: false
Explanation: 
The ghost can reach the target at the same time as you.
Note:

All points have coordinates with absolute value <= 10000.
The number of ghosts will not exceed 100.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.

[[0,2],[3,1]]
[1,2]


// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).	
// Space Complexity: O(1).	
// This algorithm calculates the distance of all ghosts and the person to the final target. Instead of move around in all possible directions, tries
// to reach target, such that it can block the person from reaching the target. 



class Solution {
public:
    
    bool escapeGhosts(vector<vector<int>>& v, vector<int>& target) {
        int dist=abs(target[0])+abs(target[1]);									// The person's distance from target.
        for(int i=0;i<v.size();i++){
            int ghost_dist=abs(v[i][0]-target[0])+abs(v[i][1]-target[1]);		// Each ghost's distance from target.
            if(ghost_dist<=dist)												// If ghost and person reach target at same time, it's a failure.
                return false;
        }
        return true;															// If all ghost's disance is > person's then, he reached target.
    }
};