/*
*
//**************************************************************45. Jump Game II.*******************************************************


Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

Example:

Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.
Note:

You can assume that you can always reach the last index.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1]


[2,1,3,2,1,2,1,1,2,3]


// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Iteration/Greedy based. Here, at every step, we track the max. index reachable under next step. We also make sure we are
// within max. index possible with curr. dist from that start. Once, we move past max. index possible with curr. dist, we move to next step, and
// inc. the dist from start and update the next var. If in the process of calculating next max. index, if we moved past/reached last index, we 
// return curr. dist from start+1.


// As, this is my first thought, I had used some unnecessary vars, which I had polished in the second algo.








class Solution {
public:
    int jump(vector<int>& v) {
        if(v.size()<=1) return 0;											// Base case(As, we are already at last index). 
        pair<int,int>curr,next;												// Stores max. index under curr. dist from start. Also of next step.
        curr={0,0};															// Init. curr. max index and curr. steps from start.
        next={0,1};															// Init. next max. index and next steps from start.
        for(int i=0;i<v.size();i++){										// Iter. through array.
            if(i>curr.first){												// If curr. index is not within max. index with curr. dist from start.
                curr=next;													// Updating to next max. index with inc. dist from start.
                next={-1, curr.second+1};									// Init, the next move.
            }
            if(i+v[i]>=v.size()-1) return next.second;						// If target reached, return dist. from start.
            next.first=max(i+v[i], next.first);								// Updating max. index covered under next step.
        }
    }
};











//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Iteration/Greedy based. At each step, we try to update the max. index reachable under next step. We also make sure we are
// under max. index reachable under curr. step.






class Solution {
public:
    int jump(vector<int>& v) {	
        if(v.size()<=1) return 0;											// Base case(As, we are already at last index).
        int moves=0;														// Min. Dist. of curr. index from the start.
        int curr=0,next=0;													// Max. index reachable under curr. step and next step.
        for(int i=0;i<v.size();i++){
            if(i>curr){														// If we moved past max. index reachable under curr. dist.
                curr=next;													// We move to next step.
                moves++;													// Inc. the dist. of curr. index from start var.
            }
            if(i+v[i]>=v.size()-1) return moves+1;
            next=max(next, i+v[i]);											// Trying to update the max. index reachable under next step.
        }
    }
};