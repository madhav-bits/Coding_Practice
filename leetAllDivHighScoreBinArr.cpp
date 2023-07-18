/*
*
//*************************************2155. All Divisions With the Highest Score of a Binary Array.************************************

https://leetcode.com/problems/all-divisions-with-the-highest-score-of-a-binary-array/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[0,0,1,0]
[0,0,0]
[1,1]
[0,0,0,0,0,1,1,1,1,1,0,1,1,0,1,1,0,1,1,0,1,0,1,1,1,0]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, we first calc. the totalOnes in an iter. In second iter, we calc. #zeroes in the left part till index 'i' and
// dec. totalOnes if we enocunter 1 in left part, we add both these values and try to maximize their sum, gather indices if the maxm total repeats else reset
// maxm and value and the array of indices and return it at the end of iter.







class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        vector<int>res;
        int maxm=0, rightOnes=0, zeroes=0, ones=0;
        for(int&num:nums) {
            if(num==1) rightOnes++;											// Calc. total #ones in the array.
        }
        for(int i=0;i<=nums.size();i++) {
            if(zeroes+rightOnes>maxm) {										// If curr. division score is maxm.
                maxm=zeroes+rightOnes;
                res.clear();
                res.push_back(i);											// Rest array of indices with only curr. index.
            }else if(zeroes+rightOnes==maxm) res.push_back(i);				// If division score matches the maxm score add curr. index to res
            // cout<<"i: "<<i<<" zeroes: "<<zeroes<<" and ones: "<<ones<<endl;
            if(i==nums.size()) break;
            if(nums[i]==0) zeroes++;										// Inc. #zeroes for next iter. if curr. value is a zero.
            else rightOnes--;												// Dec. rightOnes for next iter. if curr. value is one.
        }
        return res;															// Returning an array with indices where division score is maxm.
    }
};

