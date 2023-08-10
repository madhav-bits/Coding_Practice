/*
*
//******************************************************1861. Rotating the Box.******************************************************

https://leetcode.com/problems/rotating-the-box/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[["#",".","#"]]
[["#",".","*","."],["#","#","*","."]]
[["#","#","*",".","*","."],["#","#","#","*",".","."],["#","#","#",".","#","."]]
[["#","#",".",".",".","."],["#","#","#","*",".","."],["#","#","#",".","#","."]]



// Time Complexity: O(n*m).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).
// Space Complexity: O(1).	
// This algorithm is itration based. Here, we first iteratate over the given matrix and push the stones in each row as right as possible until they are 
// stopped by '*' or end of row. Later, we iter. and transform each index from orig. matrix to rotated matrix and return the rotated matrix.







class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int rows=box.size(), cols=box[0].size();
        vector<vector<char>>res(cols, vector<char>(rows,'.'));
        for(int i=0;i<rows;i++) {											// Iter. over orig. matrix and pushing stones to the right.
            for(int space=cols-1, j=cols-1;j>=0;j--) {						// We iter. from right to left.
                if(box[i][j]=='*') space=j-1;								// If curr. index has obstacle, we make next index as space to accept stones.
                else if(box[i][j]=='#') {									// If curr. index has a stone.
                    box[i][j]='.';											// We update this with empty space as this will be pushed right.
                    box[i][space--]='#';									// Update the rightmost empty space with the curr. stone.
                }
            }
        }
        
        for(int i=0;i<rows;i++) {											// Transforming indices from orig. matrix to rotated matrix.
            for(int j=0;j<cols;j++) {
                res[j][rows-1-i]=box[i][j];
            }
        }
        return res;															// Returning the rotated matrix.
    }
};

