/*
*
//******************************************2144. Minimum Cost of Buying Candies With Discount.******************************************

https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,2,3]
[6,5,7,9,2,2]
[5,5]
[4,6,4,3,2,7,6,5,4,8,8,8,4,3,6,6,6,5,4,2,1,9,9,11,12,8,4,12]
[1,2,3,4,5,6,7]



// Time Complexity: O(nlogn).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(1).	
// This algorithm is Greedy approach based. Here, we pick the candies in a way we get max. possible valued candies for free. For every pairs of candies we buy,
// greedily pick the largest value candy not yet purchased greedily, then move to next greatest unpurchased candies and pick top 2 and buy the third highest.
// We substract the free candies value from the total of all candies and return the result.







class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());										// Sort the candies based on costs.
        int res=accumulate(cost.begin(), cost.end(),0);						// Sum of costs of all candies.
        for(int i=cost.size()-1;i-2>=0;i-=3) {
            res-=cost[i-2];													// Skip/Get free every third candy from right to left.
        }
        return res;															// Returning the least amount spent to buy all candies.
    }
};

