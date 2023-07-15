/*
*
//******************************************************2363. Merge Similar Items.******************************************************

https://leetcode.com/problems/merge-similar-items/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[1,1],[4,5],[3,8]]
[[3,1],[1,5]]
[[1,1],[3,2],[2,3]]
[[2,1],[3,2],[1,3]]



// Time Complexity: O(n+m).													// n,m-lengths of both arrays.
// Space Complexity: O(1).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n+m).													// n,m-lengths of both arrays.
// Space Complexity: O(1).	
// This algorithm is Map based. We use an array to store the weights related to the values. We iter. over both arrays and add the weights in their corres. 
// value indices. We later iterate over weights array and add all those {values, total weights} pairs into res whose weights are non-empty, implying such values 
// exist.







class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& u, vector<vector<int>>& v) {
        vector<vector<int>>res;
        vector<int>weights(1001,0);
        for(int i=0;i<u.size();i++) weights[u[i][0]]+=u[i][1];				// Adding weights to their corres. value indices.
        for(int i=0;i<v.size();i++) weights[v[i][0]]+=v[i][1];
        
        for(int i=1;i<=1000;i++) {
            if(weights[i]) res.push_back({i, weights[i]});					// Adding {value, total weight} pairs with non-empty weight to res.
        }
        return res;															// Returning the final {value, weight} pairs after addition.
    }
};

