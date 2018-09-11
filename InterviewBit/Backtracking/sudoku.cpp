/*
*
//******************************************************************Sudoku.***********************************************************

https://www.interviewbit.com/problems/sudoku/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


9 9 53…7… 6…195… .98…6. 8…6…3 4…8.3…1 7…2…6 .6…28. …419…5 …8…79


[["1",".",".",".",".",".",".",".","."],[".","2",".",".",".",".",".",".","."],[".",".","3",".",".",".",".",".","."],[".",".",".","4",".",".",".",".","."],[".",".",".",".","5",".",".",".","."],[".",".",".",".",".","6",".",".","."],[".",".",".",".",".",".","7",".","."],[".",".",".",".",".",".",".","8","."],[".",".",".",".",".",".",".",".","9"]]



// Time Complexity: O(9^72).  												// Not so sure.
// Space Complexity: O(9*9).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(9^72).												// Not so sure.
// Space Complexity: O(9*9).	
// This algorithm is DFS based. We keep track of nums present in each row, clmn, in each box using three vars.(We store the presence of num 'i' in 
// a row by setting 'i+1'the bit of that row's index in corresponding variable. In the iteration, if we encounter, an index with '.', we iter.
// through 1-9, check for these nums in row, clmn, that block, if not presnt we assign that box that value and do DFS on following index. If we
// end of column, we reach next row. In this way, if we reach 9th row, then it means all the previous bits are set without any clashes(i.e full 
// sudoku).








class Solution {
public:
    
	bool fillSudoku(vector<vector<char>>&v, int x, int y, vector<int>&rows, vector<int>&clmns, vector<vector<int>>&blocks){
		if(x==9) return true;   											// If we reach 9th row, 8 rows are set prop. so return true.							
		// cout<<" x: "<<x<<" and y: "<<y<<endl;
		int newX=0,newY=0;													// Next row, clmn values.
		if(y==8){															// If clmn end is reached, moving to next row in next DFS search.
			newX=x+1;
			newY=0;
		}
		else{																// Else, just move to next column.
			newX=x;
			newY=y+1;
		}

		if(v[x][y]!='.' ){													// If this index already has num provided.
			// cout<<"INside pres."<<endl;
			return fillSudoku(v,newX,newY, rows, clmns, blocks) ;			// Go the next DFS call.
		} 
		
		// cout<<"Changing nums"<<endl;
		// cout<<"bits of rows: "<<bitset<10>(rows[x])<< " clmns: "<<bitset<10>(clmns[y])<<" and blocks: "<<bitset<10>(blocks[x/3][y/3])<<endl;
		for(int i=1;i<=9;i++){												// Iter. over all possible nums for this box.
			
			if((rows[x]&(1<<i))==0 && (clmns[y]&(1<<i))==0 && (blocks[x/3][y/3]&(1<<i))==0){// If this num isn't present in row, clmn, box.
				// cout<<"Changed i: "<<i<<endl;
				rows[x]|=(1<<i);											// Mark that, that row has curr. num it by setting 'i+1'th bit.
				clmns[y]|=(1<<i);											// Marking that column.
				blocks[x/3][y/3]|=(1<<i);									// Marking that box.
				v[x][y]=i+48;												// Setting the char in that index.
				if(fillSudoku(v, newX,newY, rows, clmns, blocks)==true) return true;// Giving DFS call on next index.
				rows[x]^=(1<<i);											// Reverting to orig. state as we need to work on other possible vals.
				clmns[y]^=(1<<i);
				blocks[x/3][y/3]^=(1<<i);
				v[x][y]='.';							
			}
		}
		return false;														// No suitable num in this index with the setup of Sudoku till now.
	}
    
    void solveSudoku(vector<vector<char>>& v) {
        vector<int>rows(9,0);												// Tracks each row.
        vector<int>clmns(9,0);												// Trackk each clmn with the nums it has.
        vector<vector<int>>blocks(3,vector<int>(3,0));						// Tracks 9 boxes.
        for(int i=0;i<9;i++){												// Iter. over sudoku.
            for(int j=0;j<9;j++){
                if(v[i][j]!='.'){											// If curr. index has num in it.
                    // cout<<"int: "<<i<<" j: "<<j<<" ";
                    rows[i]=rows[i]|(1<<(v[i][j]-48));						// Marking the curr. num in curr. row.
                    clmns[j]=clmns[j]|(1<<(v[i][j]-48));					// Marking in curr. clmn.
                    blocks[i/3][j/3]=blocks[i/3][j/3] |(1<<(v[i][j]-48));	// Marking curr. box.
                } 
            }
        }

        fillSudoku(v,0,0,rows,clmns, blocks);								// Giving DFS calls to get the solved Sudoku.
        return;									
    }
};