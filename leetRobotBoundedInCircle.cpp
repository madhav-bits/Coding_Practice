/*
*
//**********************************************************1041. Robot Bounded In Circle.***************************************************

https://leetcode.com/problems/robot-bounded-in-circle/



On an infinite plane, a robot initially stands at (0, 0) and faces north. The robot can receive one of three instructions:

"G": go straight 1 unit;
"L": turn 90 degrees to the left;
"R": turn 90 degrees to the right.
The robot performs the instructions given in order, and repeats them forever.

Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.

 

Example 1:

Input: instructions = "GGLLGG"
Output: true
Explanation: The robot moves from (0,0) to (0,2), turns 180 degrees, and then returns to (0,0).
When repeating these instructions, the robot remains in the circle of radius 2 centered at the origin.
Example 2:

Input: instructions = "GG"
Output: false
Explanation: The robot moves north indefinitely.
Example 3:

Input: instructions = "GL"
Output: true
Explanation: The robot moves from (0, 0) -> (0, 1) -> (-1, 1) -> (-1, 0) -> (0, 0) -> ...
 

Constraints:

1 <= instructions.length <= 100
instructions[i] is 'G', 'L' or, 'R'.



*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


"GGLLGG"
"GL"
"GGGRGRGRGGG"
"GLRLLGLL"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is observation based. Here, since we are repeating the instructions, we have to check whether the robot reaches initial psn by 
// end of first instruction or it faces any other direction, so that it can reach the initital position in the following instructions.
// If it faces north at the end of instruction and not at start position, it indicates it keeps moving forward after every instruction and doesn't form
// any loop.




// This link has good explanation for the below approach.
// https://leetcode.com/problems/robot-bounded-in-circle/discuss/290856/JavaC%2B%2BPython-Let-Chopper-Help-Explain






class Solution {
public:
    bool isRobotBounded(string s) {
        vector<int>dirs({-1,0,1,0,-1});										// Directions vector.
        int x=0,y=0,j=0;													// Tracks curr. psn and direction.
        for(int i=0;i<s.length();i++){
            if(s[i]=='L') j--;												// Changing direction as per instructions.
            else if(s[i]=='R') j++;
            else{
                x+=dirs[j];
                y+=dirs[j+1];
            }
            if(j==4) j=0;													// Adj. direction indices to make indices within range.
            else if(j<0) j=3;
        }
        // cout<<"j: "<<j<<endl;
        return ((x==0 && y==0) || (j!=0));									// Checking whether it reaches initial psn or facing other direction.
    }
};
