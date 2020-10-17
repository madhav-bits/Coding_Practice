/*
*
//*************************************1283. Find the Smallest Divisor Given a Threshold.***********************************************

https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,2,5,9]
6
[2,3,5,7,11]
11
[19]
5
[4,5,9,2,5,43,53,64,94,83,43,92,19,34,45,63,65]
20





// Time Complexity: O(nlogm).												// m-#maxm. num in array, n-length of the array.
// Space Complexity: O(1).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogm).												// m-#maxm. num in array, n-length of the array.
// Space Complexity: O(1).	
// This algorithm is Binary Search based. In order to reduce the range of nums over we do Bin. Search. We iter. over array to find
// maxm. which would be higher end for Bin. Search. For a mid val, if the total of dividends is<=threshold, as there can be lower nums
// which can give dividends total even closer(<=) to threshold, we search in lower half. If dividends total is> threshold, the greater
// nums can give dividends total<=threshold, so we search in lower half. At the end we return the start of search range as answer.








class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1, high=-1;
        for(auto num:nums) high=max(high, num);								// Find the maxm. divisor satisfying given cdn.
        while(low<high){
            int mid=(low+high)/2;											// Calc. the divisor for this round.
            int total=0;
            for(auto num:nums){												// Calc. total of dividends for this divisor.
                total+=num/mid;
                if(num%mid!=0) total+=1;
            }
            if(total<=threshold) high=mid;								// If curr. dividends are<=threshold, we search is lower half.
            else low=mid+1;												// If curr. dividends>threshold, we search in upper half.
        }
        return low;															// Returning the num. satisfying dividends total cdn.
    }
};