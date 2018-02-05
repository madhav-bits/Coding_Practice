/*
*
//**************************************************************90. Subsets II.**************************************************

Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

//These are the examples I had created, tweaked and worked on.
[1,2,2,5,7,6,7,9,45,4,4,7]
[]



// Time Complexity: O(n^2).
// Space Complexity: O(2^n).			//Even more than this, it depends on the target value.

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(2^n).			//Even more than this, it depends on the target value.
// 

class Solution {
public:
    vector<vector<int>> result;									//Decl. the final result as global var. to avoid time compl. in passing into func.
    void powerSet(vector<int> v, vector<int> &dp, int index){
        for(int i=index;i<v.size();i++){
            if(i>index && v[i]==v[i-1])							//Making sure, that aren't duplicates aren't allowed because of dup elem. in vector.
                continue;
            dp.push_back(v[i]);									//Pushing elem. into temp. dp vector.
            result.push_back(dp);								//Pushing dp formed till then has been pushed into final vector.As it is unique.
            powerSet(v,dp,i+1);									// Calling the next recursive call.	
            dp.pop_back();										// Removing, As this elem. might not be part of some other combination of subsets.
        }    
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& v) {
        sort(v.begin(), v.end());
        vector<int> dp;
        result.push_back(dp);									//Pushing the null set into the result vector.
        powerSet(v,dp, 0);
        return result;											//Returning the result vector.
    }
};