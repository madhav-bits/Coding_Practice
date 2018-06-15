/*
*
//************************************************************657. Judge Route Circle.***********************************************

Initially, there is a Robot at position (0, 0). Given a sequence of its moves, judge if this robot makes a circle, which means it moves back 
to the original place.

The move sequence is represented by a string. And each move is represent by a character. The valid robot moves are R (Right), L (Left), 
U (Up) and D (down). The output should be true or false representing whether the robot makes a circle.

Example 1:
Input: "UD"
Output: true
Example 2:
Input: "LL"
Output: false




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"DDRR"
"ULRD"
"UULRRRLDD"







// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm iterates the array, classifies the moves into two types L,R and Up and Down. If the movement in both the drns is 0, then 
// return true, else return false.



class Solution {
public:
    bool judgeCircle(string moves) {
        vector<int> dir(2);             									// Index->0 deals with L,R and index->1,deals with UP and DOWN.
        for(int i=0;i<moves.length();i++){
            if(moves[i]=='L') dir[0]--;
            else if(moves[i]=='R') dir[0]++;
            else if(moves[i]=='U') dir[1]++;
            else if(moves[i]=='D') dir[1]--;
        }
        //for(int i=0;i<=1;i++){											// If any one of directional moves doesn't make zero, return false.
        //    if(dir[i]!=0) return false;
        //}
        return dir[0]==0 && dir[1]==0;										// If both directinal moves are zero, return true.
    }
};
