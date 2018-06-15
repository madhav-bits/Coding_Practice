/*
*
//**************************************************************733. Flood Fill.******************************************************

An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as 
the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. 
Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image.

Example 1:
Input: 
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: 
From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
by a path of the same color as the starting pixel are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected
to the starting pixel.
Note:

The length of image and image[0] will be in the range [1, 50].
The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
The value of each color in image[i][j] and newColor will be an integer in [0, 65535].



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[1,1,1],[1,1,0],[1,0,1]]
1
1
2



[[0,0,0],[0,1,1]]
1
1
1


// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm id Depth First Search based. We start from the given index, if the old and newCOlor of the starting index is the same, we 
// return the vector. If not, we call the dfs fn., we traverse into those adjacent nodes which have same color as old color of starting index
// and the indices are legal.We change the colors of all indices which we visit traverse.








class Solution {
public:
    
    void fillColor(vector<vector<int>> &v, int row, int clmn, int newColor, int old){
        // cout<<"Inside the fn. with row: "<<row<<" and clmn: "<<clmn<<endl;
        if(row<0 ||  row>=v.size() || clmn<0 || clmn>=v[0].size() || v[row][clmn]!=old) return ;		// Index has to legal,Color has to be old.
        v[row][clmn]=newColor;																			// Change color of curr. index.
        fillColor(v,row-1, clmn, newColor, old);														// Traversing adj. indices.
        fillColor(v,row+1, clmn, newColor, old);
        fillColor(v,row, clmn-1, newColor, old);
        fillColor(v,row, clmn+1, newColor, old);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& v, int sr, int sc, int newColor) {
        if(v[sr][sc]==newColor) return v;																// If old and newColor is same, return v.
        fillColor(v,sr,sc,newColor,v[sr][sc] );															// Call. fn. to change colors.
        return v;																						// Return the updated vector.
    }
};