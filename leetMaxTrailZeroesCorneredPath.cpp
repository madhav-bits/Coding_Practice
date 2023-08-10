/*
*
//*******************************************2245. Maximum Trailing Zeros in a Cornered Path.********************************************

https://leetcode.com/problems/maximum-trailing-zeros-in-a-cornered-path/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[23,17,15,3,20],[8,1,20,27,11],[9,4,6,2,21],[40,9,1,10,6],[22,7,4,5,3]]
[[4,3,2],[7,6,1],[8,8,8]]
[[23,17,15,25,20],[250,64,20,27,10],[9,100,6,32,210],[400,95,1000,10,64],[22,7,625,500,33],[54,64,16,9,33]]



// Time Complexity: O(n*m+k).												// m,n-rows, cols of the matrix, k-range of nums in the matrix.
// Space Complexity: O(n*m+k).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m+k).												// m,n-rows, cols of the matrix, k-range of nums in the matrix.
// Space Complexity: O(n*m+k).	
// This algorithm is Factors+PrefixSum based. For us to have trailing zeroes from out path, it depends on the total #2, 5s we get in factorization of all 
// the nums in the path, as there product is needed for us to get trailing zeroes. As we are allowed one corner, while iterating over matrix, we consider 
// each index as the corner and get prefixSum of 2,5s from 4 drns(Top, Bottom, Left, Right),we match Left/Right with each of the Top/Bottom prefixSums 
// for a cornered path which indirectly includes single path too where other other drn's contribution remains zero towards total #2, 5s. We use prefixSums
// to keep track of #2,5s from lef, right of curr. row to [i,j] and Top, Bottom to [i,j]. In the second iteration for every index, we combine each of the 
// Left/Right with Top/Bottom to get their total contribution of 2,5s and use the minimum of them to get #trailing zeroes and use it to update res with max.
// zeroes and return it at the end of iter. Here, since the range of nums is very small compared to the #nums in the matrix, we pre-calculate the #2,5s
// for each num in the range and use them in the algo.


// I had also come up with a similar algorithm but it got too complicated while writing the code, so I dropped it.



// This discussion forum link has a good explanation for this approach:
// https://leetcode.com/problems/maximum-trailing-zeros-in-a-cornered-path/discuss/1955515/Prefix-Sum-of-Factors-2-and-5






class Solution {
public:
    
    void fillNums(vector<int>&twos, vector<int>&fives) {					// Calc. #2,5s in the factorization of each num in the range.
        int val=2;
        while(val<=1000) {
            for(int i=val;i<=1000;i+=val) twos[i]++;						// Updating count in all nums which have powers of 2 in their factors.
            val<<=1;
        }
        
        val=5;
        while(val<=1000) {
            for(int i=val;i<=1000;i+=val) fives[i]++;						// Updating count in all nums which have powers of 5 in their factors.
            val*=5;
        }
        return ;
    }
    
    int maxTrailingZeros(vector<vector<int>>& grid) {
        vector<int>twos(1001,0), fives(1001,0);
        fillNums(twos, fives);
        int rows=grid.size(), cols=grid[0].size(), res=0;
        vector<vector<pair<int,int>>>prefixRows(rows, vector<pair<int,int>>(cols+1)), prefixCols(cols, vector<pair<int,int>>(rows+1));
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                prefixRows[i][j+1].first=prefixRows[i][j].first+twos[grid[i][j]];// Updating prefixSum #2s from the left.
                prefixRows[i][j+1].second=prefixRows[i][j].second+fives[grid[i][j]];// Updating prefixSum #5s from the left.
                
                prefixCols[j][i+1].first=prefixCols[j][i].first+twos[grid[i][j]];// Updating prefixSum #2s from the Top.
                prefixCols[j][i+1].second=prefixCols[j][i].second+fives[grid[i][j]];// Updating prefixSum #5s from the Top.
            }
        }
        
        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                // Top, Bottom Sums.
                int topTwo=prefixCols[j][i+1].first;						// Get prefixSum of #2s from Top to curr. row [0, i] for curr. col. 
                int topFive=prefixCols[j][i+1].second;
                
                int bottomTwo=prefixCols[j][rows].first-prefixCols[j][i].first;// Get prefixSum of #2s from Bottom to 'i' row [i, cols-1] for curr. col.
                int bottomFive=prefixCols[j][rows].second-prefixCols[j][i].second;
                
                
                // Left, Right sum.
                int leftTwo=prefixRows[i][j].first;							// Get prefixSum of #2s from Left to prev. col [0, j-1] for curr. row.
                int leftFive=prefixRows[i][j].second;
                
                
                int rightTwo=prefixRows[i][cols].first-prefixRows[i][j+1].first;// Get prefixSum of #2s from Right to next. col [j+1, rows-1] for curr. row.
                int rightFive=prefixRows[i][cols].second-prefixRows[i][j+1].second;
             
                res=max(res, min(topTwo+leftTwo, topFive+leftFive));		// Extracing min. of the {total #2, total #5} and try to update the res.
                res=max(res, min(topTwo+rightTwo, topFive+rightFive));		// These are the 4 possible corners at the curr. index.
                res=max(res, min(bottomTwo+leftTwo, bottomFive+leftFive));
                res=max(res, min(bottomTwo+rightTwo, bottomFive+rightFive));
                
            }
        }
        return res;															// Returning the max. #trailing zeroes possible in a cornered path.
    }
};

