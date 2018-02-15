/*
*
//*************************************************************289. Game of Life.****************************************************

According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British 
mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors 
(horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state.

Follow up: 
Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and 
then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the 
active area encroaches the border of the array. How would you address these problems?
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.

9
300000

4
9

9
37

2
3

// Time Complexity: O(n).
// Space Complexity: O(n).			

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).			
// We update the pixels acc. to conditons given in question, and maintain second state for each pixel which had been visited(Value. inc by 2 
// pixel is alive after scanning it's neighbours). When scanning for other elem. to get original value of already visited pixel, we dec. value by
// 2 if value is >1). else check the value as it is. After the complete iteration, we change the values to required formate(1's and 0's).



class Solution {
public:
    void gameOfLife(vector<vector<int>>& v) {
        int row=v.size(), clmn=v[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<clmn;j++){
                //cout<<" row is: "<<i<<" and clmn is: "<<j<<endl;
                int count=0;
                for(int a=max(0,i-1);a<min(i+2,row);a++){				//Checking all the neighbors of the curr. pixel.
                    for(int b=max(0,j-1);b<min(j+2,clmn);b++)
                        count+=v[a][b]>1?v[a][b]-2:v[a][b];				//If updated alive is encoun., orig. is obtained by "-2" or check as it is.
                }
                if(count==3 || count-v[i][j]==3) v[i][j]+=2;            //Pixel is alive in the next stage, satisfying the conditions in qsn.
            }
        }
        for(int i=0;i<row;i++)
            for(int j=0;j<clmn;j++)
                v[i][j]=v[i][j]>1?1:0;									// If value>1, means it's alive in the second stage.
        return ;
    }
};


