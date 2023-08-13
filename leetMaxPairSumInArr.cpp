/*
*
//******************************************************2815. Max Pair Sum in an Array.******************************************************

https://leetcode.com/problems/max-pair-sum-in-an-array/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[51,71,17,24,42]
[1,2,3,4]
[51,63,16,76,49]
[84,91,18,59,27,9,81,33,17,58]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, at every step, we breakdown given num and extract all it's digits and track the maxDigit, we store the maxNum
// with any maxDgit in an array, so we check if any maxDigit[currMaxDigit] occurred in prev. indices, if yes, we add both these value and try to max. total.
// We also try to update max. num with curr. maxDigit in the array. We return the maxTotal at the end of iter.







class Solution {
public:
    int maxSum(vector<int>& v) {
        int maxDigit[10], res=-1;
        memset(maxDigit, -1, sizeof(maxDigit));
        for(int num:v) {
            int currMax=0, temp=num;
            while(num) {													// Breaking down given num and tracking maxm digit in it.
                if(num%10>currMax) currMax=num%10;
                num/=10;
            }
            if(maxDigit[currMax]!=-1 && maxDigit[currMax]+temp>res) res=maxDigit[currMax]+temp;// If any prev. num with same maxDigit occurred,max their total.
            if(maxDigit[currMax]<temp) maxDigit[currMax]=temp;				// Update maxNum with curr. max Digit.
        }
        return res;															// Returning maxTotal of pair of nums with same maxDigit.
    }
};

