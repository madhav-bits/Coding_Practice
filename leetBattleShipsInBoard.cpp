/*
*
//******************************************************419. Battleships in a Board.***********************************************

Given an 2D board, count how many battleships are in it. The battleships are represented with 'X's, empty slots are represented with '.'s. You 
may assume the following rules:
You receive a valid board, made of only battleships or empty slots.
Battleships can only be placed horizontally or vertically. In other words, they can only be made of the shape 1xN (1 row, N columns) or Nx1 
(N rows, 1 column), where N can be of any size.
At least one horizontal or vertical cell separates between two battleships - there are no adjacent battleships.
Example:
X..X
...X
...X
In the above board there are 2 battleships.
Invalid Example:
...X
XXXX
...X
This is an invalid board that you will not receive - as battleships will always have a cell separating between them.
Follow up:
Could you do it in one-pass, using only O(1) extra memory and without modifying the value of the board?




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.

[["X",".",".","X"],[".","X","X","."],["X",".",".","X"]]

[["X",".",".","X"],[".",".",".","X"],["X",".",".","X"]]

[["X",".",".","X"],["X",".",".","X"],["X",".",".","X"]]


// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).	
// Space Complexity: O(1).	
// ***************************************************THIS SOLUTION MEETS FOLLOW UP'S REQUIREMENTS.*********************************************
// This algorithm iterates the array, at each step it eliminates those scenarios which are either Board or battleships which are already accounted
// for( Where curr. indices are 'X' and either upward or left indices are also 'X', if those indices exist.

// This also can be done using DFS. But, as this is a simple case, can be optimized to below mentioned algorithm of looking for beginning indices
// of a Battleship.



class Solution {
public:
    int countBattleships(vector<vector<char>>& v) {
        int count=0;
        
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i].size();j++){
                
                if(v[i][j]=='.') continue;										// Index contains Board.
                //if(i-1>=0 && j-1>=0 &&  v[i][j]=='X' && v[i-1][j]=='X' && v[i][j-1]=='X')
                //    continue;
                else if(i-1>=0  && v[i-1][j]=='X' )								// Upward index has Battleship's index, which is already counted.
                    continue;
                else if(j-1>=0  && v[i][j-1]=='X')								// Leftward index has Battleship's index, which is already counted.
                    continue;
                //cout<<"Updated with i: "<<i<<" and j: "<<j<<endl;
                count++;														// If it's a first index of a Battleship, then counted.
            }
        }
        return count;															// Returning the total number of Battleships.
    }
};


