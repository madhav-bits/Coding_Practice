/*
*
//*****************************************1253. Reconstruct a 2-Row Binary Matrix.****************************************

https://leetcode.com/problems/reconstruct-a-2-row-binary-matrix/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.



2
1
[1,1,1]
2
3
[2,2,1,1]
5
5
[2,1,2,0,1,0,1,2,0,1]
9
2
[0,1,2,0,0,0,0,0,2,1,2,1,2]





// Time Complexity: O(n).													// n- #cols in the matrix.
// Space Complexity: O(n).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// n- #cols in the matrix.
// Space Complexity: O(n).	
// This algorithm is observation based. We first check #1s in rows and colsum are same, if different we return empty array
// for the wrong data. We will also focus 2s in colsum first as it requires in both rows, if a row don't have that many
// ones, then we return empty array for wrong data. Now, we focus on 1s in colsum, where one of the two rows can have 
// the 1s in them. We will try to fill the upper row first followed by second row and return the final array. Once, we 
// finish filling the 2s from colsum, it means that given data is right and we need not focus on checkng for wrong data.








class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int total=0;
        for(auto num:colsum) total+=num;
        if(total!=upper+lower) return vector<vector<int>>();				// #ones in rows and cols don't match.
        
        vector<vector<int>>res(2, vector<int>(colsum.size(),0));
        for(int j=0;j<colsum.size();j++){							// As 2s require 1s in both rows we fill them first. 
            if(colsum[j]!=2) continue;
            res[0][j]=1;res[1][j]=1;
            if(upper<0 || lower<0) return vector<vector<int>>();	// Row don't have sufficient 1 means wrong data given.
            upper--;lower--;
        }
        for(int j=0;j<colsum.size();j++){							// Filling ones in the rows.
            if(colsum[j]!=1) continue;
            if(upper>0){											// If upper row still needs ones in it, we fill it.
                res[0][j]=1;
                upper--;
            }else{													// If upper row ones are filled now we fill lower row.
                res[1][j]=1;
                lower--;
            }
        }
        return res;													// Return the constructed 2D matrix.
    }
};
