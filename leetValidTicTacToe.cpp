/*
*
//******************************************************794. Valid Tic-Tac-Toe State.***********************************************

A Tic-Tac-Toe board is given as a string array board. Return True if and only if it is possible to reach this board position during the 
course of a valid tic-tac-toe game.

The board is a 3 x 3 array, and consists of characters " ", "X", and "O".  The " " character represents an empty square.

Here are the rules of Tic-Tac-Toe:

Players take turns placing characters into empty squares (" ").
The first player always places "X" characters, while the second player always places "O" characters.
"X" and "O" characters are always placed into empty squares, never filled ones.
The game ends when there are 3 of the same (non-empty) character filling any row, column, or diagonal.
The game also ends if all squares are non-empty.
No more moves can be played if the game is over.
Example 1:
Input: board = ["O  ", "   ", "   "]
Output: false
Explanation: The first player always plays "X".

Example 2:
Input: board = ["XOX", " X ", "   "]
Output: false
Explanation: Players take turns making moves.

Example 3:
Input: board = ["XXX", "   ", "OOO"]
Output: false

Example 4:
Input: board = ["XOX", "O O", "XOX"]
Output: true
Note:

board is a length-3 array of strings, where each string board[i] has length 3.
Each board[i][j] is a character in the set {" ", "X", "O"}.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["XXX","X  ","XOO"]
["XXO","X O","XOO"]
["X  ","X O","XOO"]




// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).	
// Space Complexity: O(n).	
// This algorithm iterates the array and counts the numbers of winning designs for both the teams and check few conditions for valid tic tac toe.
// This algo. is inspired/obtained from the discussion forum in the Leetocde.



class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
    bool wony = false, wonx = false;
    int rows = board.size();
    int cols = rows ? board[0].size() : 0;
    int diax = 0, diay = 0, xdiax = 0, xdiay = 0, xx = 0, yy = 0;
    for(int i = 0; i < rows; i++) {
        int rowsx = 0, rowsy = 0;
        int colsx = 0, colsy = 0;
        for(int j = 0; j < cols; j++) {
            // see current row
            if(board[i][j] == 'X')
                rowsx++,xx++;
            if(board[i][j] == 'O')
                rowsy++, yy++;
            // see ith column
            if(board[j][i] == 'X')
                colsx++;
            if (board[j][i] == 'O')
                colsy++;
        }
        
        // see both the diagonals
        if(board[i][i] == 'X')
            diax++;
        if(board[i][i] == 'O')
            diay++;
        if(board[i][cols - 1 - i] == 'X')
            xdiax++;
        if(board[i][cols - 1 - i] == 'O')
            xdiay++;
        
        if(rowsx == 3 || colsx == 3 || diax == 3 || xdiax == 3)
            wonx = true;
        
         if(rowsy == 3 || colsy == 3 || diay == 3 || xdiay == 3)
            wony = true;
    }
    
    if(xx < yy || !(xx == yy || xx == yy + 1))
        return false;
    
    if((wonx && wony) || (wonx && xx == yy) || (wony && xx != yy))
        return false;
    
    return true;
    }
};






//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS NOT A LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).	
// Space Complexity: O(n).	
// This algorithm is mine. Almost, got the algo, but failed to include the fact that, whenever "X" wins, he has to have 1 symbol extra than "O"s.
// Passed 103/108 test cases.






class Solution {
public:
    bool validTicTacToe(vector<string>& v) {
        int count1=0, count2=0, team1=0, team2=0, c0=0, c1=0, c2=0;
        vector<vector<int>>u(2,{0,0});
        for(int i=0;i<3;i++){
            int rx=0, ro=0;
            for(int j=0;j<3;j++){
                if(i==0 && j==0 && (v[i][j]!= ' ')) {c0=1; }//(v[i][j]== "X" || v[i][j]== "O")
                if(i==0 && j==1 && (v[i][j]!= ' ')) c1=1;//(v[i][j]== "X" || v[i][j]== "O")
                if(i==0 && j==2 && (v[i][j]!= ' ')) c2=1;//(v[i][j]== "X" || v[i][j]== "O")
                if(i>0 && v[i][j]==v[i-1][j]) if(j==0) c0++; else if(j==1) c1++; else if(j==2) c2++;
                if(v[i][j]=='X') {count1++; rx++;}
                if(v[i][j]=='O') {count2++; ro++;}
            }
            if(rx==3) team1++;
            if(ro==3) team1++;//team2++;
            if(team1>1) return false;
        }
        team1=0;
        //cout<<"c0: "<<c0<<" and c1: "<<c1<<" and c2: "<<c2<<endl;
        if((c0==3 && c1==3) || (c1==3 && c2==3) || (c0==3 && c2==3)) return false;
        if(c0==3) team1++;
        if(c1==3) team1++;
        if(c2==3) team1++;
        team1=0;
        if(v[0][0]==v[1][1] && v[1][1]==v[2][2] && ( v[2][2]=='X' || v[2][2]=='O')) team1++;               //Calc. diagonal pattern matching.
        else if(v[0][2]==v[1][1] && v[1][1]==v[2][0] && ( v[2][2]=='X' || v[2][2]=='O')) team1++;              //Calc. diagonal pattern matching.
                  
        //cout<<"Count1: "<<count1<<" and count2: "<<count2<<endl;
        if(!(count1==count2 || count1==count2+1)) return false;
        //cout<<"Team1 is: "<<team1<<" and team2 is: "<<team2<<endl;
        if(team1>1) return false;
        return true;
    }
};



//************************************************************Solution 3:************************************************************
//*****************************************************THIS IS NOT A LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).	
// Space Complexity: O(n).	
// This algo. is in improvisation to the above code, it has become very verbose and failed to include few edge cases but 104/108 are passed. 
// So, stopped working on this, will work sometime later.




class Solution {
public:
    bool validTicTacToe(vector<string>& v) {
        int count1=0, count2=0, team1=0, team2=0, c0=0, c1=0, c2=0, winx=0, winy=0;
        vector<vector<int>>u(2,{0,0});
        for(int i=0;i<3;i++){
            int rx=0, ro=0;
            for(int j=0;j<3;j++){
                if(i==0 && j==0 && (v[i][j]!= ' ')) {if(v[i][j]=='X')c0=1; if(v[i][j]=='O')c0=2; }//(v[i][j]== "X" || v[i][j]== "O")
                if(i==0 && j==1 && (v[i][j]!= ' ')) {if(v[i][j]=='X')c1=1; if(v[i][j]=='O')c1=2; }//(v[i][j]== "X" || v[i][j]== "O")
                if(i==0 && j==2 && (v[i][j]!= ' ')) {if(v[i][j]=='X')c2=1; if(v[i][j]=='O')c2=2; }//(v[i][j]== "X" || v[i][j]== "O")
                if(i>0 && v[i][j]==v[i-1][j]) if(j==0) c0++; else if(j==1) c1++; else if(j==2) c2++;//Need Modification in this line.
                if(v[i][j]=='X') {count1++; rx++;}
                if(v[i][j]=='O') {count2++; ro++;}
            }
            if(rx==3) {team1++; winx=1;}
            if(ro==3) {team2++; winy=1;}//team2++;
            if(team1+team2>1 ) return false;
        }
        team1=0; team2=0;
        cout<<"c0: "<<c0<<" and c1: "<<c1<<" and c2: "<<c2<<endl;
        //if((c0>=3 && c1>=3) || (c1>=3 && c2>=3) || (c0>=3 && c2>=3)) return false;
        if(c0==3) {team1++; winx=1;} else if(c0==6) {team2++; winy=1;}
        if(c1==3) {team1++; winx=1;} else if(c1==6) {team2++; winy=1;}
        if(c2==3) {team1++; winx=1;} else if(c2==6) {team2++; winy=1;}
        if(team1+team2>1 ) return false;
        team1=0; team2=0;
        
        if(v[0][0]==v[1][1] && v[1][1]==v[2][2]){                       //Calc. diagonal pattern matching.
            if(v[2][2]=='X') {team1++; winx=1;}
            if(v[2][2]=='O') {team2++; winy=1;}
        }
        
        if(v[0][2]==v[1][1] && v[1][1]==v[2][0] ){                       //Calc. diagonal pattern matching.
            if(v[2][0]=='X') {team1++; winx=1;}
            if(v[2][0]=='O') {team2++; winy=1;}
        }
                  
        cout<<"Winx: "<<winx<<" and the winy: "<<winy<<endl;
        cout<<"Count1: "<<count1<<" and count2: "<<count2<<endl;
        if(winx==1 && count1!=count2+1) return false;
        else if(winy==1 && count1!=count2) return false;
        //if(!(count1==count2 || count1==count2+1)) return false;
        else if(count1!=count2+1) return false;
        //cout<<"Team1 is: "<<team1<<" and team2 is: "<<team2<<endl;
        //if(team1>1) return false;
        return true;
    }
};