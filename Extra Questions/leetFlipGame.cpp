/*
*
//****************************************************************293. Flip Game.*********************************************************

You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, you and your friend 
take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other person will be 
the winner.

Write a function to compute all possible states of the string after one valid move.

Example:

Input: s = "++++"
Output: 
[
  "--++",
  "+--+",
  "++--"
]
Note: If there is no valid move, return an empty list [].




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"+++-+--++++++-++"

""





// Time Complexity: O(n).  
// Space Complexity: O(n^2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n^2).	
// This algorithm iterates the array. At each step, it checks curr. and next index for '++' and replaces them with '--' and add the transfomred
// temp. string to final result vector.








class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string>res;
        if(s.length()<2) return res;										// If length<2, return empty vector.
        for(int i=0;i<s.length()-1;i++){									// Iterates the entire array.
            if(s[i]=='+' && s[i+1]=='+') res.push_back(s.substr(0,i)+"--"+s.substr(i+2,s.length()-i-1));// Form transfomred array and push into vec.
			//if(s[i]=='+' && s[i+1]=='+') res.push_back(s.substr(0,i)+"--"+s.substr(i+2));
        }
        return res;															// Return the vector of strings.
    }
};