/*

//********************************************************36. Valid Sudoku***************************************************

Determine if a Sudoku is valid, according to Link: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

//Solution 3: is accepted.
//Time Complexity: O(9^2).
// Space Complexity: O(9).

//****************************************************THIS IS LEET ACCEPTED CODE.**********************************************
*/

//************************Hash Maps.************

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& v) {
        map<int, int> m;
        //***************************************** Checking rows.
        for(int i=0;i<9;i++){// Checking rows.
            m.clear();
            for(int j=0;j<9;j++){// "i" and "j" indicates the row  and column values respectively.
                if(m.find(v[i][j])!=m.end())
                    return false;// Indicates it's not a valid sudoku.
                if(v[i][j]!='.')
                    m[v[i][j]]=1;
            }
        }
        
        //***************************************** Checking Columns.
        for(int i=0;i<9;i++){
            m.clear();
            for(int j=0;j<9;j++){// "j" and "i" indicates the row  and column values respectively.
                if(m.find(v[j][i])!=m.end())
                    return false;// Indicates it's not a valid sudoku.
                if(v[j][i]!='.')
                    m[v[j][i]]=1;
            }
        }
        //***************************************** Checking 3X3 regions.
        for(int i=0;i<9;i+=3){// Moving the region's rows- 3 rows downwards in every iteration.
            for(int j=0;j<9;j+=3){// Moving the region's columns- 3 columns rightwards in every iteration.
                m.clear();
                for(int a=i;a<i+3;a++){
                    for(int b=j;b<j+3;b++){
                        if(m.find(v[a][b])!=m.end())
                            return false;// Indicates it's not a valid sudoku.
                        if(v[a][b]!='.')
                            m[v[a][b]]=1;
                    }
                }
            }
        }
        
        return true;// Indicates a it's a valid sudoku.
    }
};	