/*
*
//******************************************************410. Split Array Largest Sum.***********************************************

https://leetcode.com/problems/split-array-largest-sum/




Given an array nums which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays.

Write an algorithm to minimize the largest sum among these m subarrays.

 

Example 1:

Input: nums = [7,2,5,10,8], m = 2
Output: 18
Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.
Example 2:

Input: nums = [1,2,3,4,5], m = 2
Output: 9
Example 3:

Input: nums = [1,4,4], m = 3
Output: 4
 

Constraints:

1 <= nums.length <= 1000
0 <= nums[i] <= 106
1 <= m <= min(50, nums.length)



*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


[1,2,3,4,5,6,7,8,9,10]
5
[3,2,2,4,1,4]
3
[1,2,3,1,1]
4
[3,4,2,3,5,5,,7]
5


// Time Complexity: O(nlogm).												// n-#elem. in array, m-sum of elem. in array  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogm).												// n-#elem. in array, m-sum of elem. in array  
// Space Complexity: O(1).
// This algorithm in Binary Search based. Here, in the possible range of weight cap for a day, we check for min. value using Bin. Search. If the cnt
// for a day cap is >D, this indicates that curr. cap is producing more days than required and we would have to inc. the cap to decrease the #days. If
// the cnt is <=D, it indicates that we satisfy given requirement and now we are checking for least possible values and we search in lower half. We return 
// the low value at the end of the search.


// This question is modified version of Question: 1011, Capacity to Ship Packages Within D days. So, I had used the exact soluion here.
// Here is the link to 1011 question.
// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/







class Solution {
public:
    int shipWithinDays(vector<int>& v, int m) {
        int low=v[0], high=v[0];
        for(int num:v) low=max(low, num), high+=num;
        while(low<high){
            // cout<<"low: "<<low<<" and high: "<<high<<endl;
            int mid=(low+high)/2;											// Calc. the trial day cap value.
            int cnt=0, temp=0;
            for(int num:v){
                temp+=num;
                if(temp>mid){
                    cnt++;
                    temp=num;
                }
            }
            cnt++;
            // cout<<"mid: "<<mid<<" and cnt: "<<cnt<<endl;
            if(cnt>m) low=mid+1;											// If cnt>D, we inc. the cap to dec. the cnt(#days).
            else high=mid;													// If cnt<=D, we search in lower half for least possible day cap.
        }
        return low;															// Returning the least possible day cap.
    }
};

