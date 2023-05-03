/*
*
//******************************************************2660. Determine the Winner of a Bowling Game.******************************************************

https://leetcode.com/problems/determine-the-winner-of-a-bowling-game/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[4,10,7,9]
[6,5,2,3]
[3,5,7,6]
[8,10,10,2]
[2,3]
[4,1]
[4,9,8,10,3,4,10,10,5,6,10,2]
[6,8,4,3,10,8,10,10,2,9,6,4]
[3,6,10,8]
[9,9,9,9]
[4,10]
[10,2]
[1,2,1,10]
[3,3,3,5]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. While iterating over the array we maintain a variable which says whether we encounter a 10 score in the last two indices, if it set we count curr. score twice
// else we count the score only once. We get scores of both players and return the value accordingly.







class Solution {
public:
    
    int getScore(vector<int>&v) {
        int mult=0, res=0;
        for(int i=0;i<v.size();i++) {
            if(mult>0) res+=2*v[i];																		// There is a 10 score in the last two indices.
            else res+=v[i];
            if(v[i]==10) mult=2;																		// Marking the tracker so that it is valid for next two indices.
            else mult--;																				// Dec. the tracker value as curr. value is not 10.
        }
        return res;																						// Returing the score of the curr. player.
    }
    
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int score1=getScore(player1), score2=getScore(player2);											// Get scores of both players.
        if(score1>score2) return 1;																		// Return the value accordingly.
        else if(score2>score1) return 2;
        else return 0;
    }
};
