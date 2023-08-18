/*
*
//************************************************2317. Maximum XOR After Operations.************************************************

https://leetcode.com/problems/maximum-xor-after-operations/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[3,2,4,6]
[1,2,3,9,2]
[554,36,7,748,56,334,7843,23,8890,8,67,4,323,4,708,67868,9,349,5,3,3,44,9,6066,7,0,9,87]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is observation based. For every num's nums[i] AND (nums[i] XOR x) oper, as x can be any non-neg number (nums[i] XOR x) can be made any number
// as we wish nums[i] AND (any number we wish), would let use retain any combination of set bits in the number. We perform XOR on all these remainders, for us 
// to maximize the we need a set bits in all possible psns and odd number of times, so that XOR won't cancel them-> we make it only time for convenience.
// So, as we can retain any combination of set bits for all nums we selectively set any occurring bit only once and XOR all nums, which can be obtained by 
// OR of all nums as it tracks all set bits which is set atleast once, which is what need, we return res at the end of iter.







class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int res=0;
        for(int&num:nums) res|= num;										// Tracking all bits which is set atleast once.
        return res;															// Returning XOR of all nums after oper.
    }
};

