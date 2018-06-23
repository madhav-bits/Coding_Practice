/*
*
//**********************************************************348. Design Tic-Tac-Toe.***************************************************

Design a Tic-tac-toe game that is played between two players on a n x n grid.

You may assume the following rules:

A move is guaranteed to be valid and is placed on an empty block.
Once a winning condition is reached, no more moves is allowed.
A player who succeeds in placing n of their marks in a horizontal, vertical, or diagonal row wins the game.
Example:
Given n = 3, assume that player 1 is "X" and player 2 is "O" in the board.

TicTacToe toe = new TicTacToe(3);

toe.move(0, 0, 1); -> Returns 0 (no one wins)
|X| | |
| | | |    // Player 1 makes a move at (0, 0).
| | | |

toe.move(0, 2, 2); -> Returns 0 (no one wins)
|X| |O|
| | | |    // Player 2 makes a move at (0, 2).
| | | |

toe.move(2, 2, 1); -> Returns 0 (no one wins)
|X| |O|
| | | |    // Player 1 makes a move at (2, 2).
| | |X|

toe.move(1, 1, 2); -> Returns 0 (no one wins)
|X| |O|
| |O| |    // Player 2 makes a move at (1, 1).
| | |X|

toe.move(2, 0, 1); -> Returns 0 (no one wins)
|X| |O|
| |O| |    // Player 1 makes a move at (2, 0).
|X| |X|

toe.move(1, 0, 2); -> Returns 0 (no one wins)
|X| |O|
|O|O| |    // Player 2 makes a move at (1, 0).
|X| |X|

toe.move(2, 1, 1); -> Returns 1 (player 1 wins)
|X| |O|
|O|O| |    // Player 1 makes a move at (2, 1).
|X|X|X|
Follow up:
Could you do better than O(n2) per move() operation?




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["TicTacToe","move","move","move","move","move","move","move"]
[[4],[0,0,1],[0,2,2],[2,2,1],[1,2,2],[1,1,1],[1,0,2],[3,3,1]]


["TicTacToe","move","move","move","move","move","move","move"]
[[4],[0,3,1],[0,2,2],[1,2,1],[2,2,2],[2,1,1],[1,0,2],[3,0,1]]


["TicTacToe","move","move","move"]
[[3],[1,1,2],[0,2,2],[2,0,1],[2,1,2],[1,0,1],[2,2,2],[0,0,1]]







// Time Complexity: O(row+clmn).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(row+clmn).
// Space Complexity: O(1).	
// This algorithm takes the moves as input, we maintain three vectors, to tracks num. of moves corresponding to players in each row, clmn, two
// types of diagonals. If the move is made by player 1, we inc./dec. the count in those vector's index representing curr. index's row and clmn,
// also if curr. index falls on any of diagonals, we inc. that count also. If we get the sum(abs) of either curr. index's row/ clmn/ 2 diag. 
// values to be length of TicTacToe, then we return the curr. player, else we return 0.







class TicTacToe {
public:
    /** Initialize your data structure here. */
    // TicTacToe game;
    vector<int>u,v,w;
    int len;													// Stores the size of TicTacToe.
    TicTacToe(int n) {
        // game=new TicTacToe(n);
        len=n;													// Stores size of TicTacToe.
        u=vector<int>(n,0);                                     // Tracks row wise moves of both players.   
        v=vector<int>(n,0);                                     // Tracks clmn wise moves of both players.
        w=vector<int>(2,0);                                     // Tracks diagonal moves of both players.
        
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int clmn, int player) {
        if(player==1){											// If it's player 1's turn.
            u[row]++;											// Inc. curr move's row's count.
            v[clmn]++;											// Inc. curr move's clmn's count.
            if(clmn==row) w[0]++;								// If curr. index falls on top left to bottom right diag., inc. diag's count.
            if(clmn+row==len)w[1]++;							// If curr. index falls on top right to bottom left diag., inc. diag's count.
            if(u[row]==len || v[clmn]==len || w[0]==len || w[1]==len) return 1;// If winning condition achieved, return player.
        }
        else if(player==2){										// If it's player 2's turn.
            u[row]--;											// In case of player 2, we dec. the count at row/clmns/ diag. if any.
            v[clmn]--;
            if(clmn==row) w[0]--;
            if(clmn+row==(len-1))w[1]--;
            if(u[row]==-(len) || v[clmn]==-(len) || w[0]==-(len) || w[1]==-(len)) return 1;// If winning condition achieved, return player.
        }
        for(auto num:u) cout<<num<<endl;
        for(auto num:v) cout<<num<<endl;
        for(auto num:w) cout<<num<<endl;
        cout<<"End of insert."<<endl;
        return 0;												// If winning cdn not acheived, return 0.
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */