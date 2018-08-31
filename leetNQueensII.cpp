/*
*
//****************************************************************52. N-Queens II.*********************************************************

The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



Given an integer n, return the number of distinct solutions to the n-queens puzzle.

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
// This also entirely same as N QUEENS problem, except that instead of storing board pattern, we count the #combinations possible.


// Instead of checking for queens in 45/135 deg. and clmn wise for each index, we can imporve by marking all the effected indices by 1, whenever we 
// place a queen in any index.Such, that we are avoiding for queens in following iterations.




class Solution {
public:
    
    bool isValid(vector<vector<int>>&dp,int row,int clmn){
        
        // Checking for queens in that coloumn.
        for(int i=row;i>=0;i--) if(dp[i][clmn]==1) return false;

        // Diagonal from Top to Bottom.
        for(int dx=0;row+dx>=0&& clmn+dx>=0;dx--) if(dp[row+dx][clmn+dx]==1) return false;


        // Diagonal from bottom to top.
        for(int dx=0;row+dx>=0&& clmn-dx<dp.size();dx--) if(dp[row+dx][clmn-dx]==1) return false;
        return true;
    }
    
    
    void findCombi(int count,vector<vector<int>>&dp,int&res){
        int len=dp.size();
        if(count==len){														// IF all queens are placed on the board.
            res++;															// We inc. the count of #combinations.
            return ;														// Stop tht iter.
        }

        for(int j=0;j<dp.size();j++){
            if(isValid(dp,count,j)){
                dp[count][j]=1;
                findCombi(count+1,dp,res);
                dp[count][j]=0;
            }
        }
    }
    
    int totalNQueens(int n) {
        int res=0;
        vector<vector<int>>dp(n,vector<int>(n,0));
        findCombi(0,dp,res);
        return res;															// Return the count of #combinations of queens psns.
    }
};