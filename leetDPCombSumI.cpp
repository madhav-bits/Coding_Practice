/*
*
//***********************************************************39. Combination Sum.*******************************************

Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the 
candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7, 
A solution set is: 
[
  [7],
  [2, 2, 3]
]


//These are the examples I had created, tweaked and worked on.
[2,3,6,7]
17

[2,3,6,7]
0

[2,3,6,7]
27

// Time Complexity: O(n^2).
// Space Complexity: O(n^2).			//Even more than this, it depends on the target value.

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
//*****************************************************DYNAMIC PROGRAMMING PARADIGM.*************************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n^2).			//Even more than this, it depends on the target value.
// This algorithm is same as the Combination Sum II problem. Here as duplicates are not allowed, first we will sort them. As unlimited no. of 
// occur. are allowed. We will start iterating from the index in this call same as index prev. call was iterating by the time this call was made.
// Once the required target is reached, we will push the elem. into result vector.

class Solution {
public:
vector<vector<int>> result;
    void printCombi(vector<int> dp, vector<int> v,int target, int index){
        if(target==0){
            result.push_back(dp);
            return ;
        }
        
        for(int i=index;i<v.size() ;i++){
            if(target-v[i]<0) break;						// Making sure the count doesn't exceed the target.
            dp.push_back(v[i]);
            printCombi(dp,v,target-v[i],i);			// Making a recur. call after taking in a digit.
            dp.pop_back();									// As, this may or may not be in the final result, we will remove it and try another.
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& v, int target) {
        if(v.size()==0) return {v};							// If the input vector is empty, no target can be achieved. So, return NULL.
        vector<int> dp;
        sort(v.begin(), v.end());							// Sort the input vector, as no duplicates are allowed.
        printCombi(dp,v,target,0);
        return result;										// Returning the result.
    }
};