/*
*
//******************************************************2022. Convert 1D Array Into 2D Array.******************************************************

https://leetcode.com/problems/convert-1d-array-into-2d-array/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,2,3,4]
2
2
[1,2,3]
1
3
[1,2]
1
1



// Time Complexity: O(n*m).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).
// Space Complexity: O(1).	
// This algorithm is iteration based. This is standard 1D to 2D array conversion.







class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& v, int rows, int cols) {
        if(v.size()!=rows*cols) return vector<vector<int>>();
        vector<vector<int>>res(rows, vector<int>(cols,0));												// Defining the dimensions of 2D array.
        for(int i=0;i<v.size();i++) {																	// Iter. over orig. array and converting it to 2D array.
            res[i/cols][i%cols]=v[i];
        }
        return res;																						// Returning the 2D array.
    }
};

