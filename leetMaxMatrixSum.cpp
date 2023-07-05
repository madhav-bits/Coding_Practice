/*
*
//******************************************************1975. Maximum Matrix Sum.******************************************************

https://leetcode.com/problems/maximum-matrix-sum/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[1,-1],[-1,1]]
[[1,2,3],[-1,-2,-3],[1,2,3]]
[[1,-2,3],[-4,2,-3],[11,-12,-23]]
[[1,-2,-3],[-4,2,-3],[11,-12,-23]]



// Time Complexity: O(n*n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*n).
// Space Complexity: O(1).	
// This algorithm is observation based. Here, we use the observation that as we can apply the operation adj. row, col wise, we can convert all neg. vals to
// pos. vals if there are even odd. nums and one neg. val will be left if there are odd neg. nums, this neg. val can be a pos. value that's converted neg. too.
// As we are trying to get max. sum we track the least abs value among all the nums, so that we substract this val. from total if #negatives are odd to get 
// max. sum. and return the total.






class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& v) {
        long long int res=0;
        int minVal=INT_MAX;
        bool odd=false;
        for(int i=0;i<v.size();i++) {
            for(int j=0;j<v.size();j++) {
                res+=abs(v[i][j]);											// Adding abs. values of all nums.
                if(abs(v[i][j])<minVal) minVal=abs(v[i][j]);				// Tracking the least abs. value.
                if(v[i][j]<0) odd=!odd;										// Tracking whether the #neg. values are odd.
            }
        }
        if(odd) res-=2*minVal;												// Removing least abs. value if #neg. values are odd.
        return res;															// Returning the max. sum of the matrix.
    }
};

