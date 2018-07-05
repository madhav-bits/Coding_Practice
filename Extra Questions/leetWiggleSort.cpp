/*
*
//************************************************************280. Wiggle Sort.*****************************************************

Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....

Example:

Input: nums = [3,5,2,1,6,4]
Output: One possible answer is [3,5,1,6,2,4]




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[3,5,2,1,6,4]

[1,5,3,2]

[1]


// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is iteration based. At each index, we make sure that wiggle sort condition is satisfied, it not we swap curr. and previous 
// index's values to satisfy the condition. At even index, curr. value has to be <prev. index's value. At odd index, curr. value>prev. index's 
// value.


// I was focusing on setting the nums[i]<=nums[i+1]>=nums[i+2] condition, working on three indices, but the number of cases were more(4), so, I 
// went to discussions forum and learnt to work on two indices instead.




class Solution {
public:
    void wiggleSort(vector<int>& v) {
        if(v.size()<=1) return ;											// If array has 0/1 elem. return .
        for(int i=1;i<v.size();i++){
            cout<<"Curr. index: "<<i<<endl;
            if(i%2==0){														// If condition not satisfied, swap ints to satisfy it.
                cout<<"Curr. value: "<<v[i]<<" prev. value: "<<v[i-1]<<endl;
                if(v[i]>v[i-1]) swap(v[i],v[i-1]);
            }
            else if(i%2==1 && v[i]<v[i-1]) swap(v[i],v[i-1]);				// Checking condition at odd indices.
        }
        return ;															// Returning from fn.
    }
};