/*
*
//**************************************************************79. Word Search.******************************************************

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.


//These are the examples I had created, tweaked and worked on.
[["a","b"]]
"ba"



// Time Complexity: O(n).
// Space Complexity: O(n).			

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).			
// This is the best algorithm for this problem. This is dfs, going through all the possible cases, whenever it confirms answer can't be found
// in that path, it abandons that path and follows another possible path in search of correct answer.


class Solution {
private:
    bool dfs(vector<vector<char>>& board, int row, int col, const string &word,int start,int m, int n,int slen){
        char c=board[row][col];
        bool res=false;
        if(c!=word[start])
            return false;
        if(start==slen-1)
            return true;
        board[row][col]='*';//mark this char is visited
        if(row>0)
            res=dfs(board,row-1,col,word,start+1,m,n,slen);
        if(!res&&row<m-1)
            res=dfs(board,row+1,col,word,start+1,m,n,slen);
        if(!res&& col>0)
            res=dfs(board, row,col-1,word,start+1,m,n,slen);
        if(!res&& col<n-1)//if a word is found by ways above, so there is no need to excute this if
            res=dfs(board,row,col+1,word,start+1,m,n,slen);
        board[row][col]=c;
        return res;
    }
    public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(),n=board[0].size(),i,j,slen=word.size();
        if(m&&n&&slen){
            for(i=0;i<m;i++)
                for(j=0;j<n;j++)//two loops to find the start char
                    if(dfs(board,i,j,word,0,m,n,slen))
                        return true;
        }
        return false;
    }
};



////************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).			
// This is MY ALGORITHM for this problem. This is dfs, going through all the possible cases, whenever it confirms answer can't be found
// in that path, it abandons that path and follows another possible path in search of correct answer.
//***********************FOR SOME DAMN REASON , THIS CODE WORKS DEAD SLOW. SPENT LOT OF TIME ON THIS QUESTION, FOR THE REASON.*******************

class Solution {
public:
    int row, clmn;
    bool wordFound(vector<vector<char>> v, string word,int index, int i, int j){
        //cout<<"i: "<<i<<" j: "<<j<<" and length is: "<<word.length()<<endl;
        if(index==word.length())
            return true;
        if(i<0 || i>=row|| j<0 || j>=clmn || v[i][j]=='*')
            return false;
        
        char c=v[i][j];
        v[i][j]='*';
        if(word[index]!=c)
            return false;
        if(wordFound(v,word,index+1,i-1,j) ||wordFound(v,word,index+1,i+1,j)||wordFound(v,word,index+1,i,j-1)|| wordFound(v,word,index+1,i,j+1))
            return true;
        v[i][j]=c;
        
            
        return false;
    }
    
    bool exist(vector<vector<char>>& v, string word) {
        row=v.size();
        clmn=v[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<clmn;j++){
                //cout<<"char is: "<<v[i][j]<<endl;
                if( wordFound(v,word,0,i,j))//word.compare(0,1,to_stirng(v[i][j])==0 &&
                    return true;
            }
        }
        return false;
    }
};




