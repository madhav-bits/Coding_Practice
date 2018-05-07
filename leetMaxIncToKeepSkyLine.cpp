/*
*
//******************************************************807. Max Increase to Keep City Skyline.***********************************************

In a 2 dimensional array grid, each value grid[i][j] represents the height of a building located there. We are allowed to increase the 
height of any number of buildings, by any amount (the amounts can be different for different buildings). Height 0 is considered to be a 
building as well. 

At the end, the "skyline" when viewed from all four directions of the grid, i.e. top, bottom, left, and right, must be the same as the 
skyline of the original grid. A city's skyline is the outer contour of the rectangles formed by all the buildings when viewed from a 
distance. See the following example.

What is the maximum total sum that the height of the buildings can be increased?

Example:
Input: grid = [[3,0,8,4],[2,4,5,7],[9,2,6,3],[0,3,1,0]]
Output: 35
Explanation: 
The grid is:
[ [3, 0, 8, 4], 
  [2, 4, 5, 7],
  [9, 2, 6, 3],
  [0, 3, 1, 0] ]

The skyline viewed from top or bottom is: [9, 4, 8, 7]
The skyline viewed from left or right is: [8, 7, 9, 3]

The grid after increasing the height of buildings without affecting skylines is:

gridNew = [ [8, 4, 8, 7],
            [7, 4, 7, 7],
            [9, 4, 8, 7],
            [3, 3, 3, 3] ]

Notes:

1 < grid.length = grid[0].length <= 50.
All heights grid[i][j] are in the range [0, 100].
All buildings in grid[i][j] occupy the entire grid cell: that is, they are a 1 x 1 x grid[i][j] rectangular prism.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[3,0,8,4],[2,4,5,7],[9,2,6,3],[0,3,1,0]]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm iterates through all indices and calc. the skyline each row and clmn. and in the second iteration we inc. the building at each
// index to min(row skyline, clmn skyline) such that it wonn't effect the skyline from any drn(row and clmn wise). We count all these inc. 
// and return the overall inc.



class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& v) {
        vector<int> top(v[0].size(),0), left(v.size(),0);
        for(int i=0;i<v.size();i++){                										//Effects left,right.
            for(int j=0;j<v[i].size();j++){            										//Effects top, bottom.
                left[i]=max(left[i], v[i][j]);												// Maintains max. height of each row.
                top[j]= max(top[j], v[i][j]);												// Maintains max. height of each clmn.
            }
        }
        
        int count=0;
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i].size();j++){
                count+=min(left[i], top[j])-v[i][j];										// Calc. the inc. in height of buil. at each index.
            }
        }
        //cout<<"The answer is: "<<count<<endl;
        return count;																		// Returning the total inc. in height.
    }
};