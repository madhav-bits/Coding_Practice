/*
*
//****************************************************************79. Word Search.*********************************************************

https://leetcode.com/problems/word-search/


Given an m x n board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where "adjacent" cells are horizontally or vertically neighboring. The 
same letter cell may not be used more than once.

 

Example 1:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 200
1 <= word.length <= 103
board and word consists only of lowercase and uppercase English letters.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
"ABCCED"
[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
"SEE"
[["A","B","C","E"],["S","A","C","S"],["A","C","C","E"]]
"ABCB"



// Time Complexity: O(n*m*l).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m*l).
// Space Complexity: O(1).	
// This algorithm is DFS(Backtracking). Here, when we are searching for word in the matrix. At every step of searching for a word, we check whether next
// char is adj. to current index or not, if true we move to next index, if we reached last index, we return true.









class Solution {
public:
    
    bool findWord(vector<vector<char>>&v, string &word, int row, int col, int index){
        if(index==word.length()-1) return true;								// If word found, return true.
        
        vector<int>dirs({-1,0,1,0,-1});
        char ch=v[row][col];
        v[row][col]='*';													// Coloring curr. index so that it's not revisited once again.
        for(int i=0;i<4;i++){
            int dx=dirs[i], dy=dirs[i+1];
            if(row+dx<0 || row+dx>=v.size() || col+dy<0 || col+dy>=v[0].size() || v[row+dx][col+dy]!=word[index+1]) continue;
            if(findWord(v, word, row+dx, col+dy, index+1)) return true;		// If word found in recursive call, we return true.
        }
        v[row][col]=ch;
        return false;														// If word not found, return false.
    }
    
    bool exist(vector<vector<char>>& v, string word) {
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[0].size();j++){
                if(v[i][j]!=word[0]) continue;
                if(findWord(v, word, i, j, 0)) return true;					// DFS call to find the given word.
            }
        }
        return false;														// If word not found, return false.
    }
};