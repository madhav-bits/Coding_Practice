/*
*
//******************************************************1749. Maximum Absolute Sum of Any Subarray.******************************************************

https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,-3,2,3,-4]
[2,-5,1,-4,3,-2]
[3,-4,9,5,-5,-6,8,3,-4,-6,7,5,-4,-1,3,6,2,3,-2,-5,6,3,4]
[5,4,6,4,3,2,7,7,7,4]
[-3,-4,-2,-5,-1]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is observation based. Max. subarray is something which has the greatest diff. in from it's max to min when we plot a prefix sum graph for the
// array. We observe the highest diff when the subarray starts/ends with one of maxm/minm prefixSum indices. So, we track maxm, minm prefixSum and return their
// diff.







class Solution {
public:
    int maxAbsoluteSum(vector<int>& v) {
        int maxm=0, minm=0, res=0, total=0;
        for(int&num:v) {
            total+=num;
            // if(total-minm>res) res=total-minm;
            // if(maxm-total>res) res=maxm-total;
            
            if(total<minm) minm=total;										// Tracks minm prefixSum.
            else if(total>maxm) maxm=total;									// Tracks maxm prefixSum.
        }
        return maxm-minm;													// Return the diff. b/w max, min prefixSums.
    }
};












//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Sliding Window, Kadane's Algorithm based. Here, as we are trying to get max. abs sum subarray, we try to max sum subarray and min sum
// subarray and apply modulus/ negate it and try to maximize the subarray value.









class Solution {
public:
    int maxAbsoluteSum(vector<int>& v) {
        int maxm=INT_MIN, minm=INT_MAX, total1=0, total2=0;
        for(int&num:v) {
            total1+=num;
            total2+=num;
            
            if(total1>maxm) maxm=total1;
            if(total2<minm) minm=total2;
            
            if(total1<0) total1=0;
            if(total2>0) total2=0;
        }
        return max(maxm, -minm);											// Returning the max of max, abs(min) sum subarray
    }
};


