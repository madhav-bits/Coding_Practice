/*
*
//******************************************************491. Increasing Subsequences.***********************************************

https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/


A conveyor belt has packages that must be shipped from one port to another within D days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order 
given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within D days.

 

Example 1:

Input: weights = [1,2,3,4,5,6,7,8,9,10], D = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts 
like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.
Example 2:

Input: weights = [3,2,2,4,1,4], D = 3
Output: 6
Explanation: A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
1st day: 3, 2
2nd day: 2, 4
3rd day: 1, 4
Example 3:

Input: weights = [1,2,3,1,1], D = 4
Output: 3
Explanation:
1st day: 1
2nd day: 2
3rd day: 3
4th day: 1, 1
 

Constraints:

1 <= D <= weights.length <= 5 * 104
1 <= weights[i] <= 500



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









class Solution {
public:
    int shipWithinDays(vector<int>& v, int D) {
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
            if(cnt>D) low=mid+1;											// If cnt>D, we inc. the cap to dec. the cnt(#days).
            else high=mid;													// If cnt<=D, we search in lower half for least possible day cap.
        }
        return low;															// Returning the least possible day cap.
    }
};


