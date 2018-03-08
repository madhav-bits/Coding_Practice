/*
*
//**************************************************************529. Minesweeper.*************************************************

Let's play the minesweeper game (Wikipedia, online game)!

You are given a 2D char matrix representing the game board. 'M' represents an unrevealed mine, 'E' represents an unrevealed empty square, 'B' 
represents a revealed blank square that has no adjacent (above, below, left, right, and all 4 diagonals) mines, digit ('1' to '8') represents 
how many mines are adjacent to this revealed square, and finally 'X' represents a revealed mine.

Now given the next click position (row and column indices) among all the unrevealed squares ('M' or 'E'), return the board after revealing this 
position according to the following rules:

If a mine ('M') is revealed, then the game is over - change it to 'X'.
If an empty square ('E') with no adjacent mines is revealed, then change it to revealed blank ('B') and all of its adjacent unrevealed squares 
should be revealed recursively.
If an empty square ('E') with at least one adjacent mine is revealed, then change it to a digit ('1' to '8') representing the number of adjacent 
mines.
Return the board when no more squares will be revealed.
Example 1:
Input: 

[['E', 'E', 'E', 'E', 'E'],
 ['E', 'E', 'M', 'E', 'E'],
 ['E', 'E', 'E', 'E', 'E'],
 ['E', 'E', 'E', 'E', 'E']]

Click : [3,0]

Output: 

[['B', '1', 'E', '1', 'B'],
 ['B', '1', 'M', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']]

Explanation:

Example 2:
Input: 

[['B', '1', 'E', '1', 'B'],
 ['B', '1', 'M', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']]

Click : [1,2]

Output: 

[['B', '1', 'E', '1', 'B'],
 ['B', '1', 'X', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']]

Explanation:

Note:
The range of the input matrix's height and width is [1,50].
The click position will only be an unrevealed square ('M' or 'E'), which also means the input board contains at least one clickable square.
The input board won't be a stage when game is over (some mines have been revealed).
For simplicity, not mentioned rules should be ignored in this problem. For example, you don't need to reveal all the unrevealed mines when 
the game is over, consider any cases that you will win the game or flag any squares.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.

[["E","E","E","E","X"],["E","E","M","X","E"],["E","E","X","X","E"],["E","E","E","X","E"]]
[3,0]





// Time Complexity: O(n).  // Not exactly.
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).	// Not exactly.
// Space Complexity: O(n).	
// This algorithm is BFS.




class Solution {
public:
    
    
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        deque<pair<int, int>> q({ { click[0], click[1] } });
    while (!q.empty()) {
        auto c = q.front().first, r = q.front().second, mines = 0;
        vector<pair<int, int>> neighbours;
        if (board[c][r] == 'M') board[c][r] = 'X';
        else for (auto i = -1; i <= 1; ++i) {
            for (auto j = -1; j <= 1; ++j) {
                if (c + i >= 0 && r + j >= 0 && c + i < board.size() && r + j < board[0].size()) {
                    if (board[c + i][r + j] == 'M') ++mines;
                    else if (mines == 0 && board[c + i][r + j] == 'E') neighbours.push_back({ c + i, r + j});
                }
            }
        }
        if (mines > 0) board[c][r] = '0' + mines;
        else for (auto n : neighbours) {
            board[n.first][n.second] = 'B';
            q.push_back(n);
        }
        q.pop_front();
    }
    return board;
    }
};









//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS NOT LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).	// Not exactly.
// Space Complexity: O(n).	
// This algorithm is BFS. I wrote this based on the fact, that in the question recursive approach was asked. But, still it doesn't work fine. Don't
// know why, maybe some issues with dealing 'B' and 'E' containing indices.







class Solution {
public:
    
    void findUpdate(vector<vector<char>> &v, pair<int, int> p){
        queue<pair<int, int>> q;
        q.push(p);
        //while(!q.empty()){
            int row=q.front().first;
            int clmn=q.front().second;
            cout<<"Current focusing indices are: "<<row<<" and j: "<<clmn<<endl;
            q.pop();
            if(v[row][clmn]== 'M') {
                v[row][clmn]='X';
                //return ;
            }
            else {//if(v[row][clmn]=='E')
                int count=0;
                int len=v.size();
                int wid=v[0].size();
                for(int i=max(0,row-1);i<=min(len-1,row+1);i++){
                    for(int j=max(0,clmn-1);j<=min(wid-1,clmn+1);j++){
                        cout<<"Curently scanning indices are i: "<<i<<" and j: "<<j<<endl;
                        if(i!=row || j!=clmn){
                            if(v[i][j]=='M' || v[i][j]=='X')// 
                                count++;
                            cout<<" Curr. count is: "<<count<<endl;
                            if(v[i][j]=='E')
                                q.push(make_pair(i,j));
                                
                        }
                    }
                }
                cout<<"The count is: "<<count<<endl;
                if(count!=0){
                    v[row][clmn]=count+'0';
                }
                else{
                    v[row][clmn]='B';
                    cout<<" queue size is: "<<q.size()<<endl;
                    while(!q.empty()){
                        cout<<"Calling fn.from indices i: "<<q.front().first<<" and j: "<<q.front().second<<endl;
                        findUpdate(v,q.front());
                        q.pop();
                    }
                }
            }
                
        //}
        
    }
    
    vector<vector<char>> updateBoard(vector<vector<char>>& v, vector<int>& click) {
        pair<int, int> p;
        p=make_pair(click[0], click[1]);
        findUpdate(v,p);
        
        return v;
    }
};