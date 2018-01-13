/*

//**********************************************************486. Predict the Winner.*******************************************************

Given an array of scores that are non-negative integers. Player 1 picks one of the numbers from either end of the array followed 
by the player 2 and then player 1 and so on. Each time a player picks a number, that number will not be available for the next player. 
This continues until all the scores have been chosen. The player with the maximum score wins.

Given an array of scores, predict whether player 1 is the winner. You can assume each player plays to maximize his score.

Example 1:
Input: [1, 5, 2]
Output: False
Explanation: Initially, player 1 can choose between 1 and 2. 
If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, then player 1 will be left with 1 (or 2). 
So, final score of player 1 is 1 + 2 = 3, and player 2 is 5. 
Hence, player 1 will never be the winner and you need to return False.
Example 2:
Input: [1, 5, 233, 7]
Output: True
Explanation: Player 1 first chooses 1. Then player 2 have to choose between 5 and 7. No matter which number player 2 choose, player 1 
can choose 233.
Finally, player 1 has more score (234) than player 2 (12), so you need to return True representing player1 can win.
Note:
1 <= length of the array <= 20.
Any scores in the given array are non-negative integers and will not exceed 10,000,000.
If the scores of both players are equal, then player 1 is still the winner.


//Time Complexity: O(n^2).
// Space Complexity: O(n^2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/


//************************************************************Solution 1:************************************************************

//This algorithm is inspired by some other persons, every player has two possibilities choose the one that would bring the max score to him,
//choosing the side whose combination with the remaining subarray after next person chooses is the maximum.


class Solution {
public:
    bool PredictTheWinner(vector<int>& v) {
        int len= v.size();
        vector<vector<int>> diff(len,vector<int>(len));
        for(int i=0; i<len;i++) diff[i][i]=v[i];
        
        for(int i=1;i<len;i++){                         //Length of the subarray under consideration.
            for(int j=0;j+i<len;j++){                    //Beginning of the subarray.
                diff[j][j+i]=max(v[j+i]-diff[j][j+i-1], v[j]-diff[j+1][i+j]);//diff[i][j] says the diff in score of the first to second person
            }																// for the subarray i to j index.	
        }													//Here diff[j][j+i-1] is subtracted as Player 2 would be choosing first in the subarray.
        //cout<<"The result is: "<<diff[0][len-1]<<endl;	//Stores the diff b/w players for the array i to j.
        return diff[0][len-1]>=0?true:false;
        
    }
};