/*
*
//*************************************************************529. Minesweeper.******************************************************

https://leetcode.com/problems/minesweeper/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


[["E","E","E","E","E"],["E","E","M","E","E"],["E","E","E","E","E"],["E","E","E","E","E"]]
[3,0]
[["B","1","E","1","B"],["B","1","M","1","B"],["B","1","1","1","B"],["B","B","B","B","B"]]
[1,2]



// Time Complexity: O(m*n).  
// Space Complexity: O(n*m).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m*n).
// Space Complexity: O(m*n).	
// This algorithm is DFS based. Here, at every unvisited index if it's 'M' we change it to 'x'. If it's 'E' we count the #mines in adjacent indices,
// if it's zero, we make it 'B' and do DFS on all unvisited adjacent indices. In this way each index is visited atmost 16 times, time complexity is:
// O(m*n), 2 times from each adjacent side, of which 1 is for BFS Mine count and other is for adjacent indices DFS.








class Solution {
public:
    
    int getMineCount(vector<vector<char>>&board, int row, int col){
        int res=0;
        for(int dx=-1;dx<=1;dx++){											// Counting #mines in adjacent indices.
            for(int dy=-1;dy<=1;dy++){
                if(row+dx<0 || row+dx>=board.size() || col+dy<0 || col+dy>=board[0].size()) continue;
                if(board[row+dx][col+dy]=='M' || board[row+dx][col+dy]=='X') res++;
            }
        }
        return res;
    }
    
    void dfs(vector<vector<char>>&board, int row, int col){
        if(board[row][col]!='M' && board[row][col]!='E') return ;			// Allows visits only for unvisited indices.
        if(board[row][col]=='M'){											// If Mine is found.
            board[row][col]='X';
            return ;
        }
        int cnt=getMineCount(board, row, col);
        if(cnt==0){															// If #adjacent Mines=0.
            board[row][col]='B';
            for(int dx=-1;dx<=1;dx++){
                for(int dy=-1;dy<=1;dy++){
                    if(row+dx<0 || row+dx>=board.size() || col+dy<0 || col+dy>=board[0].size()) continue;
                    dfs(board, row+dx, col+dy);
                }
            }
        }else{																// Non-zero adjacent mines.
            board[row][col]='0'+cnt;
        }
        return ;
    }
    
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        dfs(board, click[0], click[1]);										// DFS call to initiate the game.
        return board;
    }
};

