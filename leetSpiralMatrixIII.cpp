/*
*
//**********************************************************889. Spiral Matrix III.***************************************************

On a 2 dimensional grid with R rows and C columns, we start at (r0, c0) facing east.

Here, the north-west corner of the grid is at the first row and column, and the south-east corner of the grid is at the last row and column.

Now, we walk in a clockwise spiral shape to visit every position in this grid. 

Whenever we would move outside the boundary of the grid, we continue our walk outside the grid (but may return to the grid boundary later.) 

Eventually, we reach all R * C spaces of the grid.

Return a list of coordinates representing the positions of the grid in the order they were visited.

 

Example 1:

Input: R = 1, C = 4, r0 = 0, c0 = 0
Output: [[0,0],[0,1],[0,2],[0,3]]


 

Example 2:

Input: R = 5, C = 6, r0 = 1, c0 = 4
Output: [[1,4],[1,5],[2,5],[2,4],[2,3],[1,3],[0,3],[0,4],[0,5],[3,5],[3,4],[3,3],[3,2],[2,2],[1,2],[0,2],[4,5],[4,4],[4,3],[4,2],[4,1],[3,1],[2,1],[1,1],[0,1],[4,0],[3,0],[2,0],[1,0],[0,0]]



Note:

1 <= R <= 100
1 <= C <= 100
0 <= r0 < R
0 <= c0 < C




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



1
4
0
0



10
12
3
4


1
1
0
0




5
5
1
3



// Time Complexity: O(n^2).  
// Space Complexity: O(n^2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n^2).	
// This algorithm is based on iteration. We can work on max, min indices of rows and clmns iterated. For every drn of iteration, I am iter. till
// one of extreme indices(rows/clmns). Then , inc the extreme index for next iteration. We only push legal indices into final result. We stop
// iteration, when all indices are covered.








class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int row, int clmn) {
        int i=row,j=clmn;													// Tracks curr. row and clmn.
        int minRow=row,maxRow=row,maxClmn=clmn,minClmn=clmn;				// Stores extreme indices values.
        vector<vector<int>>res;												// Stores the final result.
        while(res.size()<R*C){												// Iter. till all indices are covered.
            // cout<<"Rightwards."<<endl;
            while(j<=maxClmn+1){    										// Iter. rightwards till maxClmn+1 
                if(res.size()==R*C) break;									// Once, we cover all indices break from loop.
                if(j<C && j>=0 && i>=0 && i<R){
                    // cout<<"CUrr. pushing row: "<<i<<" and clmn: "<<j<<endl;
                    res.push_back({i,j});
                }
                j++;
                
            }
            maxClmn++; 														// Inc. the maxClmn for next iteration.
			j--;															// Taking to step back, as we moved past maxClmn index.
			i++;															// Setting the index for moving downwards, as curr. is already convered.
            // cout<<"Downwards."<<endl;
            while(i<=maxRow+1){     //Downwards.	
                if(res.size()==R*C) break;
                if(j<C && j>=0 && i>=0 && i<R){
                    // cout<<"CUrr. pushing row: "<<i<<" and clmn: "<<j<<endl;
                    res.push_back({i,j});
                }
                i++;
                
            }
            maxRow++; i--;j--;
            // cout<<"Backwards."<<endl;
            while(j>=minClmn-1){    // Backwards.
                if(res.size()==R*C) break;
                if(j<C && j>=0 && i>=0 && i<R){
                    // cout<<"CUrr. pushing row: "<<i<<" and clmn: "<<j<<endl;
                    res.push_back({i,j});
                }
                j--;
                
            }
            minClmn--;j++;i--;
            // cout<<"Upwards."<<endl;
            while(i>=minRow-1){     // Upwards
                if(res.size()==R*C) break;
                if(j<C && j>=0 && i>=0 && i<R){
                    // cout<<"CUrr. pushing row: "<<i<<" and clmn: "<<j<<endl;
                    res.push_back({i,j});
                }
                i--;
                
            }
            minRow--;i++;j++;
        }
        // cout<<"res size: "<<res.size()<<endl;
        return res;															// Returning the final result.
    }
};