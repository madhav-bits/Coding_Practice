/*
*
//****************************************2342. Max Sum of a Pair With Equal Sum of Digits.****************************************

https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[18,43,36,13,7]
[10,12,19,14]
[299,2]
[8,35,17,44,68,26,53,474]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration+Greedy based. We store the max num with a given digitSum in an array. We iter. over nums and calc. digitSum for every number,
// if we prev. came across a number with similar digitSum, max. num of those occurances would be stored in this array, we use that number+curr. num and try to
// update the res, we also try to update max. num with that digitSum during iteration. As, we track max. num with same digitSum from all prev. occurances, we
// are bound to add top two highest values irrespective of their order of occurance and must been used them to udpate res for max. sum of these two nums.







class Solution {
public:
    int maximumSum(vector<int>& v) {
        int res=-1;
        vector<int>maxNum(82,-1);
        for(int& num:v) {
            int digitSum=0, temp=num;
            while(temp) {
                digitSum+=temp%10;
                temp/=10;
            }
            if(maxNum[digitSum]!=-1 && maxNum[digitSum]+num>res) res=maxNum[digitSum]+num;// Trying to udpate max. sum of 2 nums with same digitSum.
            if(num>maxNum[digitSum]) maxNum[digitSum]=num;					// Trying to update max. num with same digitSum.
        }
        return res;															// Returning the maxSum of 2 nums with same digitSum.
    }
};

