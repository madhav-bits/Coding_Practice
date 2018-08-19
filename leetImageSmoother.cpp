/*
*
//************************************************************661. Image Smoother.*****************************************************

Given a 2D integer matrix M representing the gray scale of an image, you need to design a smoother to make the gray scale of each cell becomes 
the average gray scale (rounding down) of all the 8 surrounding cells and itself. If a cell has less than 8 surrounding cells, then use as many 
as you can.

Example 1:
Input:
[[1,1,1],
 [1,0,1],
 [1,1,1]]
Output:
[[0, 0, 0],
 [0, 0, 0],
 [0, 0, 0]]
Explanation:
For the point (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
For the point (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
For the point (1,1): floor(8/9) = floor(0.88888889) = 0
Note:
The value in the given matrix is in the range of [0, 255].
The length and width of the given matrix are in the range of [1, 150].




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[1,1,1],[1,0,1],[1,1,1]]




// Time Complexity: O(n^2).  
// Space Complexity: O(n^2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n^2).	
// This algorithm is iteration based. For each index, we calc. valid adj. indices count, and their sum. We divide the sum and count of valid adj.
// nodes to get the avg. for that index. We iterate through the entire array this way to get the result vector.








class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& v) {
        vector<vector<int>>res(v.size(),vector<int>(v[0].size(),0));		// Final result vector.
        int sum=0,count=0;													// Tracks sum of adj. nodes values and #valid adj. nodes.
        for(int i=0;i<v.size();i++){										// Iter. through the entire array.
            for(int j=0;j<v[0].size();j++){
                sum=0;count=0;												// Init. the sum=0, #valid adj. nodes=0.
                for(int dx=-1;dx<=1;dx++){									// Iter. through the adj. nodes.
                    for(int dy=-1;dy<=1;dy++){
                        if(i+dx>=0 && i+dx<v.size() && j+dy>=0 && j+dy<v[0].size()){// Adding values of valid adj. nodes.
                            sum+=v[i+dx][j+dy];
                            count++;										// Inc. the count of valid adj. nodes.
                        }
                    }
                }
                res[i][j]=sum/count;										// Calc. the avg. of sum of valid adj. nodes.
            }
        }
        
        return res;															// Returning the final result vector.
    }
};