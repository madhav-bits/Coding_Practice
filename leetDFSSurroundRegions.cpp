/*
*
//**********************************************************130. Surrounded Regions.***************************************************

Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X





*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[["X","X","X","O","X"],[,"O""X","O","X","O"],[,"O""X","O","X","O"],[,"O""O","X","O","X"]]




// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).	
// Space Complexity: O(1).	
// This algorithm is DFS Oriented. We mark those 'O's which can be reached from the edges. We start from the corners and start iterating
// into the matrix, all mark those indices with 'O' and can be reached from the edges. In the second iteration, indices which have been marked will 
// be made as 'O' and the else will be 'X'.



class Solution {
public:
    
    void findCover(vector<vector<char>> &v, int row, int clmn){
        if(v[row][clmn]=='O'){											// If a index has 'O', marking it- changing the value to 'A'.
            v[row][clmn]='A';
            if(row-1>=0) findCover(v,row-1, clmn);						// To iterate through the matrix.
            if(clmn-1>=0) findCover(v,row, clmn-1);
            if(row+1<v.size()) findCover(v,row+1, clmn);
            if(clmn+1<v[0].size()) findCover(v,row, clmn+1);
        }    
        
    }
    
    void solve(vector<vector<char>>& v) {
        if(v.size()==0) return ;
        for(int i=0;i<v.size();i++){									// Starting the journey from the corners.
            if(i==0 || i==v.size()-1){									// Covers the first and last rows entirely.
                for(int k=0;k<v[0].size();k++)
                    if(v[i][k]=='O') findCover(v,i,k);					// Start DFS, iff the index has 'O'.
            }
            else{														// Covers the corners in all the rows except fisrt and last.
                if(v[i][0]== 'O') findCover(v,i,0);						// Start DFS, iff the index has 'O'.
                if(v[i][v[0].size()-1]== 'O') findCover(v,i,v[0].size()-1);
            }
            
        }
        
        for(int i=0;i<v.size();i++){									// Second iteration.
            for(int j=0;j<v[0].size();j++){
                //cout<<"The row is: "<<i<<" and clmn is: "<<j<<" the value is: "<<v[i][j]<<endl;
                if(v[i][j]=='O') v[i][j]='X';							// Orig. 'O's which can't be reached from corners,will be converted to 'X's.
                else if(v[i][j]=='A') v[i][j]='O';						// If a index is marked, then it made as 'O' in the final result.
            }
        }
        
        return ;														// Returning from the fn.
    }
};