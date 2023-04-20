/*
*
//******************************************************2536. Increment Submatrices by One.******************************************************

https://leetcode.com/problems/increment-submatrices-by-one/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


3
[[1,1,2,2],[0,0,1,1]]
2
[[0,0,1,1]]
10
[[1,3,4,6],[0,2,3,4],[6,6,8,9],[2,2,5,5],[5,6,7,9],[1,6,4,6],[7,7,7,7]]
10
[[1,3,4,6],[0,2,3,4],[6,6,8,9],[2,2,5,5],[5,6,7,9],[1,6,4,6]]



// Time Complexity: O(n*n+k).																			// n-#rows, #cols of the matrix, k-#queries.														
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*n+k).																			// n-#rows, #cols of the matrix, k-#queries.														
// Space Complexity: O(1).	
// This algorithm is prefixSum based. Here, we iter. over all queries, as we are using prefixSum, we modify the values of matrix on the boundaries of the submatrix in the query, so that when we do
// prefixSum it would reflect in those indices which are supposted to be affected because of queries. For query [r1, c1, r2, c2], we inc. the value of index [r1][c1] by 1 and dec. [r1][c2+1] by 1,
// so that on using prefixSum the increased value would only work from c1 to c2. We dec. the value of [r2][c1] by 1 and inc. [r2][c2+1] by 1, so that the negating affect would only work from c1 to c2.
// We reverse the inc. dec. process in the r2 row because when we do prefixSum b/w the rows, the affected indices should be only from r1 to r2. 
// Column wise prefixSum ensures indices b/w c1 to c2 gets affected.
// Row wise prefixSum ensures indices b/w r1 and r2  gets affected.







class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>res(n, vector<int>(n,0));													// Result matrix.
        for(vector<int>&v:queries) {																	// Iterating over queries.
            res[v[0]][v[1]]++;																			// Modifying values on the boundary indices so that prefixSum reflect only in affected indices.
            if(v[2]+1<n)res[v[2]+1][v[1]]--;															// Modify by -1 to negate the row wise prefixSum whose affect is from [row1][col1]
            if(v[3]+1<n) {																				// Reversing the modify pattern to negate the row wise prefixSum.
                res[v[0]][v[3]+1]--;
                if(v[2]+1<n) res[v[2]+1][v[3]+1]++;
            }
        }
        
        for(int i=0;i<n;i++) {																			// Rowwise prefixSum.
            for(int j=1;j<n;j++) res[i][j]+=res[i][j-1];
        }
        
        for(int i=1;i<n;i++) {																			// Columnwise prefixSum.
            for(int j=0;j<n;j++) res[i][j]+=res[i-1][j];
        }
        return res;																						// Returing the res matrix after processing all queries.
    }
};

