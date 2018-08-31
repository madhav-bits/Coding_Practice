/*
*
//****************************************************************51. N-Queens.*********************************************************

The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space 
respectively.

Example:

Input: 4
Output: [
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


4

5

1




// Time Complexity: O(n^(n+1)).  
// Space Complexity: O(n^2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^(n+1)).
// Space Complexity: O(n^2).	
// This algorithm is Hashing/Backtracking based. As, we have to put N queens in N*N board, a row can accomodate only 1 queen. We iter. over all 
// rows, in each row, for each clmn, we check for queens in that clmn, two 45deg,153deg lines passing through that index from the top till 
// that index. If we don't find any, then we place the queen in that index. Then we recursive search in following rows to place the rem. queens.
// We maintain the count of queens placed, if the queens placed is N, then we push the board into final result vector.



// Instead of checking for queens in 45/135 deg. and clmn wise for each index, we can imporve by marking all the effected indices by 1, whenever we 
// place a queen in any index.Such, that we are avoiding for queens in following iterations.




class Solution {
public:
    
    
    bool isValid(vector<vector<int>>&dp,int row,int clmn){					// Checking whether we can place queen in curr. index.
        // for(int j=0;j<dp.size();j++) if(dp[row][j]==1) return false;
        
        // Checking for queens in that coloumn.
        for(int i=row;i>=0;i--) if(dp[i][clmn]==1) return false;

        // Diagonal from Top to Bottom.
        // for(int dx=0;row+dx<dp.size()&& clmn+dx<dp.size();dx++) if(dp[row+dx][clmn+dx]==1) return false;
        for(int dx=0;row+dx>=0&& clmn+dx>=0;dx--) if(dp[row+dx][clmn+dx]==1) return false;// We search from top till curr. index.


        // Diagonal from bottom to top.
        // for(int dx=0;row+dx<dp.size()&& clmn+dx>=0;dx++) if(dp[row+dx][clmn-dx]==1) return false;
        for(int dx=0;row+dx>=0&& clmn-dx<dp.size();dx--) if(dp[row+dx][clmn-dx]==1) return false;// We search from top till curr. index.
        return true;														// If queen not found, return true.
    }
    
    void findCombi(vector<string>&board,int count,vector<vector<int>>&dp,vector<vector<string>>&res){
        int len=board.size();							
        if(count==len){														// If all queens are placed, we place the board into final result vec.
            res.push_back(board);
            return ;														// Stop iter.
        }

        for(int j=0;j<board.size();j++){									// Iter. in curr. row.
            if(isValid(dp,count,j)){										// Checking whether we can place Queen in curr. index.
                board[count][j]='Q';										// Changing the board value.
                dp[count][j]=1;												// Marking curr. index with 1.
                findCombi(board,count+1,dp,res);							// Calling recur. to place further queens.
                dp[count][j]=0;												// Unmarking in Hashing vector.
                board[count][j]='.';										// Removing queen from curr. psn to accomodate other combinations.
            }
        }
    }
    
    
    vector<vector<string>> solveNQueens(int n) {
        string temp="";
        for(int i=0;i<n;i++) temp+='.';
        vector<string>board(n,temp);										// Init. state of board.
        vector<vector<string>>res;											// Init. final result vector.
        vector<vector<int>>dp(n,vector<int>(n,0));							// Init. Hashing Vector.
        findCombi(board,0,dp,res);											// Calling fn. to find all combinations of queens psns.
        return res;															// Returning final result vector.
    }
};