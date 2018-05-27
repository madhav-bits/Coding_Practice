/*
*
//******************************************************840. Magic Squares In Grid.***********************************************

A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.

Given an grid of integers, how many 3 x 3 "magic square" subgrids are there?  (Each subgrid is contiguous).

 

Example 1:

Input: [[4,3,8,4],
        [9,5,1,9],
        [2,7,6,2]]
Output: 1
Explanation: 
The following subgrid is a 3 x 3 magic square:
438
951
276

while this one is not:
384
519
762

In total, there is only one magic square inside the given grid.
Note:

1 <= grid.length <= 10
1 <= grid[0].length <= 10
0 <= grid[i][j] <= 15



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.





// Time Complexity: O(n*m).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).
// Space Complexity: O(n).	
// This algorithm is iteration based. One observation is that all summations would make upto 15. Middle one must be 5. We make all the summations
// and check whether it's =15 or not. If it's not 15, return false.





class Solution {
public:
    
    bool findMagicSq(vector<vector<int>> &v, int row, int clmn){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++)
                if(v[row+i][clmn+j]<1 || v[row+i][clmn+j]>9) return false;
        }
        
        if(v[row][clmn]+v[row][clmn+1]+v[row][clmn+2]!=15) return false;			// Row wise summations.
        if(v[row+1][clmn]+v[row+1][clmn+1]+v[row+1][clmn+2]!=15) return false;
        if(v[row+2][clmn]+v[row+2][clmn+1]+v[row+2][clmn+2]!=15) return false;
        
        if(v[row][clmn]+v[row+1][clmn]+v[row+2][clmn]!=15) return false;			// Clmn wise summations.
        if(v[row][clmn+1]+v[row+1][clmn+1]+v[row+2][clmn+1]!=15) return false;
        if(v[row][clmn+2]+v[row+1][clmn+2]+v[row+2][clmn+2]!=15) return false;
        
        if(v[row][clmn]+v[row+1][clmn+1]+v[row+2][clmn+2]!=15) return false;		// Diagonal wise summations.
        if(v[row][clmn+2]+v[row+1][clmn+1]+v[row+2][clmn]!=15) return false;
        
        return true;
        
    }
    
    int numMagicSquaresInside(vector<vector<int>>& v) {
        if(v.size()<3 || v[0].size()<3) return false;								// If the size<3, return false.
        int count=0;																// Counts no. of Magic Squares.
        
        for(int i=0;i<v.size()-2;i++){
            for(int j=0;j<v[0].size()-2;j++){
                if(v[i+1][j+1]==5)													// The middle one has to be 5.
                 count+=(findMagicSq(v,i,j))?1:0;									// If Magic Sq. formed, then. inc. the count.
            }
        }
        
        //cout<<"The total count is: "<<count<<endl;
        return count;																// Number of Magic Squares formed.
    }
};