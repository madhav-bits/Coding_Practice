/*
*
//******************************************************1424. Diagonal Traverse II.***********************************************

https://leetcode.com/problems/diagonal-traverse-ii/description/


Given a list of lists of integers, nums, return all elements of nums in diagonal order as shown in the below images.
 

Example 1:



Input: nums = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,4,2,7,5,3,8,6,9]
Example 2:



Input: nums = [[1,2,3,4,5],[6,7],[8],[9,10,11],[12,13,14,15,16]]
Output: [1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16]
Example 3:

Input: nums = [[1,2,3],[4],[5,6,7],[8],[9,10,11]]
Output: [1,4,2,5,3,8,6,9,7,10,11]
Example 4:

Input: nums = [[1,2,3,4,5,6]]
Output: [1,2,3,4,5,6]
 

Constraints:

1 <= nums.length <= 10^5
1 <= nums[i].length <= 10^5
1 <= nums[i][j] <= 10^9
There at most 10^5 elements in nums.





***************************************************************TEST CASES:********************************************************
//These are the examples I had tweaked and worked on.


[[1,2,3],[4,5,6],[7,8,9]]


[[1,2,3,4,5],[6,7],[8],[9,10,11],[12,13,14,15,16]]

[[1,2,3,4,5,6]]


[[1,2,3],[4],[5,6,7],[8],[9,10,11]]



// Time Complexity: O(n*m).  												// n- rows, m-avg. col size in matrix.
// Space Complexity: O(n*m).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).													// n- rows, m-avg. col size in matrix.
// Space Complexity: O(n*m).												
// This algorithm is observation based. Here, as the #cols in each row differs, most of the cols are of smaller lengths when compared 
// to other cols making it Sparse Matrix. So, instead of iteating over diagonals and pushing the values to result array, we iter. over
// matrix and temp. push into dp array, we utilize an observation that all the indices belonging to same diagonal have their row+col
// to be same value, so we use this total as index in dp array and push the values into dp array. Now, we iter. over dp array and push
// the values the values diagonal wise into the final result array.







class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& v) {
        vector<int>res;														// Final result array.
        if(v.size()==0) return res;											// Base Case.
        int maxCol=0;
        for(int i=0;i<v.size();i++){										// Calc. maxCol size, useful in deciding dp array size.
            maxCol=max(maxCol, (int)v[i].size());
        }
        // for(int a=0;a<v.size()+maxCol-1;a++){
        //     int x=min((int)v.size()-1, a), y=(a-x);
        //     while(x>=0 && y<maxCol){
        //         if(y<v[x].size()) res.push_back(v[x][y]);
        //         x--;y++;
        //     }
        // }
        // return res;
        vector<vector<int>>dp((int)v.size()+maxCol-1);						// Init. DP array.
        for(int i=v.size()-1;i>=0;i--){										// Iter. matrix and pushing into DP array.
            for(int j=0;j<v[i].size();j++)
                dp[i+j].push_back(v[i][j]);
        }
        for(int i=0;i<dp.size();i++){										// Iter. over DP array.
            for(int j=0;j<dp[i].size();j++)									// Pushing vals from each DP row into result array.
                res.push_back(dp[i][j]);
        }
        return res;															// Returning the result array.
    }
};

