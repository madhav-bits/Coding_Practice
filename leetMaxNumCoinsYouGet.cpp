/*
*
//*************************************1561. Maximum Number of Coins You Can Get.********************************************

https://leetcode.com/problems/maximum-number-of-coins-you-can-get/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


[2,4,1,2,7,8]
[2,4,5]
[4,6,4,3,6,5,3,2,5,3,2,6,4,3,7]


// Time Complexity: O(nlogn).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(1).	
// This algorithm is Greedy based. Here, we pick n triplets, in which we pick the second largest value every time. We are
// greedily picking values here, so the least value in each pick would be from the least n/3 values of sorted array. We try
// to maximize the number we choose each time, as we can't pick the maxm. value of array we pick the second largest then, 
// similarly we choose every alternate value starting from second highest to n/3rd value in sorted array and collect them.







class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int res=0;
        sort(piles.begin(), piles.end());
        for(int i=piles.size()/3;i<piles.size();i+=2){						// Picking every alter. val starting n/3 index.
            res+=piles[i];
        }
        return res;															// Returning the maxm. coins collected.
    }
};