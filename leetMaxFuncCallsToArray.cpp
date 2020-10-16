/*
*
//******************************1558. Minimum Numbers of Function Calls to Make Target Array.******************************

https://leetcode.com/problems/minimum-numbers-of-function-calls-to-make-target-array/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


[1,5]
[2,2]
[4,2,5]
[3,2,2,4]
[2,4,8,16]
[1000000000]



// Time Complexity: O(nlogk).  												// n- #elem. in array, k-maxm. num allowed.
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogk).												// n- #elem. in array, k-maxm. num allowed.
// Space Complexity: O(1).	
// This algorithm is Bit Manipulation based. Here,  in order to achieve the target array, we pick nums in dec. order of 
// value and start forming them, pick lesser value in the process at steps so that all the nums would reach close to 
// their (int)log2(num) and we will add rem. value by inc. by 1 step. We also track maxm. log2(num) and add it to res, as
// this is the #steps we take to reach (int)log2(maxm) for all nums. 







class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res=0, maxBits=0;
        for(auto num:nums){
            int bits=0;
            while(num>0){
                res+=(num&1);												// Adding #inc. by 1 steps to res.
                bits++;
                num>>=1;
            }
            maxBits=max(maxBits,bits);									// Tracking maxm. steps to power 2 of(int)log2(num)
        }
        if(maxBits) res+=maxBits-1;											// Adding double steps to res.
        return res;
    }
};
