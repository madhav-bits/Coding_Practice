/*
*
//******************************************************2778. Sum of Squares of Special Elements.******************************************************

https://leetcode.com/problems/sum-of-squares-of-special-elements/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,2,3,4]
[2,7,1,19,18,3]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. We iterate and determine whether curr. index is special, if true we add square of it's value to res.







class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int res=0, len=nums.size();
        for(int i=1;i<=len;i++) {
            if(len%i==0) res+=nums[i-1]*nums[i-1];
        }
        return res;
    }
};

