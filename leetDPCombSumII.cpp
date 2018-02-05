/*
*
//***********************************************************40. Combination Sum II.*******************************************

Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
A solution set is: 
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]


//These are the examples I had created, tweaked and worked on.
[10,1,2,7,6,1,5,2,7]
19

[4,5,2,7,2,1,9,1,5,8,9]
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
// Smart logic in the for loop-line 59, preventing occurence of duplicates.

class Solution {
public:
    vector<vector<int>> result;
    void printCombi(vector<int> dp, vector<int> v,int target, int index){
        if(target==0){
            result.push_back(dp);
            return ;
        }
        
        for(int i=index+1;i<v.size() ;i++){
            if(target-v[i]<0) break;						// Making sure the count doesn't exceed the target.
            if(i>index+1  && v[i-1]==v[i] )                 //Makes sure that duplicates are not allowed.***********Nice logic.*************
                continue;
            dp.push_back(v[i]);
            printCombi(dp,v,target-v[i],i);			// Making a recur. call after taking in a digit.
            dp.pop_back();							// As, this may or may not be in the final result, we will remove it and try another.
        
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& v, int target) {
        if(v.size()==0) return {v};							// If the input vector is empty, no target can be achieved. So, return NULL.
        vector<int> dp;
        sort(v.begin(), v.end());							// Sort the input vector, as no duplicates are allowed.
        printCombi(dp,v,target,-1);
        return result;										// Returning the result.
    }
};