/*
*
//******************************************************303. Range Sum Query - Immutable.***********************************************

Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["NumArray","sumRange","sumRange","sumRange"]
[[[-2,0,3,-5,2,-1]],[0,2],[2,5],[0,0]]


["NumArray","sumRange","sumRange","sumRange"]
[[[-2,0,3,-5,2,-1]],[0,2],[2,5],[5,5]]


["NumArray","sumRange","sumRange","sumRange"]
[[[-2,0,3,-5,2,-1]],[0,2],[0,5],[0,0]]



// Time Complexity: O(1).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(n).	
// This algorithm is iteration and Summation based. We first iterate through the entire array, at each index->i in new array, we store sum of 
// values of given array starting from index->0 to that array. When sum of subarray is asked for, we subtract sum of values in till "j"-sum of 
// values till "i-1" to get the required result.







class NumArray {

private:
    vector<int> v;															// Stores summation of values from start till that index in that index.
	
	
public:
    NumArray(vector<int> nums) {
        v=vector<int>(nums.size());
        int sum=0;
        for(int i=0;i<v.size();i++){											// Storing sum of values till "i" in index "i".
            sum+=nums[i];
            v[i]=sum;
        }
            
    }
    
    int sumRange(int i, int j) {
        if(i==0) return v[j];													// If "i" is 0, return v[j] directly.
        else return v[j]-v[i-1];												// Else, return v[j]-v[i-1].
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */