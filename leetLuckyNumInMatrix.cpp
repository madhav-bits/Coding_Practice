/*
*
//**************************************************1380. Lucky Numbers in a Matrix.*********************************************

https://leetcode.com/problems/lucky-numbers-in-a-matrix/description/



Given a m * n matrix of distinct numbers, return all lucky numbers in the matrix in any order.

A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.

 

Example 1:

Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
Output: [15]
Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column
Example 2:

Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
Output: [12]
Explanation: 12 is the only lucky number since it is the minimum in its row and the maximum in its column.
Example 3:

Input: matrix = [[7,8],[1,2]]
Output: [7]
 

Constraints:

m == mat.length
n == mat[i].length
1 <= n, m <= 50
1 <= matrix[i][j] <= 10^5.
All elements in the matrix are distinct.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[3,7,8],[9,11,13],[15,16,17]]


[[1,10,4,2],[9,3,8,7],[15,16,17,12]]

[[7,8],[1,2]]



// Time Complexity: O(n*m).  
// Space Complexity: O(n+m).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).
// Space Complexity: O(n+m).	
// This algorithm iterates the array, at each step finds the greater following value, also makes sure that duplicates are avoided. Thus includes
// a greater following value and calls the func. to find further greater following values. Thus ,we get increasing subsequences(include only
// whose length is >= 2).








class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& v) {
        vector<int>rows(v.size(), INT_MAX);									// Tracks minm. value in each row.
        vector<int>cols(v[0].size(), INT_MIN);								// Tracks minm. value in each col.
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[0].size();j++){
                rows[i]=min(rows[i], v[i][j]);								// Updating minm. value present in curr. row.
                cols[j]=max(cols[j], v[i][j]);								// Updating minm. valeu present in curr. col.
            }
        }
        vector<int>res;														// Stores the lucky numbers.
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[0].size();j++){
                if(v[i][j]==rows[i] && v[i][j]==cols[j]) res.push_back(v[i][j]);// If curr. index has minm. value in it's row and col.
            }
        }
        return res;															// Return the lucky numbers.
    }
};

