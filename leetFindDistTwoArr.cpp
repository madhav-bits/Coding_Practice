/*
*
//********************************************1385. Find the Distance Value Between Two Arrays.*******************************************

https://leetcode.com/problems/find-the-distance-value-between-two-arrays/description/


Given two integer arrays arr1 and arr2, and the integer d, return the distance value between the two arrays.

The distance value is defined as the number of elements arr1[i] such that there is not any element arr2[j] where |arr1[i]-arr2[j]| <= d.

 

Example 1:

Input: arr1 = [4,5,8], arr2 = [10,9,1,8], d = 2
Output: 2
Explanation: 
For arr1[0]=4 we have: 
|4-10|=6 > d=2 
|4-9|=5 > d=2 
|4-1|=3 > d=2 
|4-8|=4 > d=2 
For arr1[1]=5 we have: 
|5-10|=5 > d=2 
|5-9|=4 > d=2 
|5-1|=4 > d=2 
|5-8|=3 > d=2
For arr1[2]=8 we have:
|8-10|=2 <= d=2
|8-9|=1 <= d=2
|8-1|=7 > d=2
|8-8|=0 <= d=2
Example 2:

Input: arr1 = [1,4,2,3], arr2 = [-4,-3,6,10,20,30], d = 3
Output: 2
Example 3:

Input: arr1 = [2,1,100,3], arr2 = [-5,-2,10,-3,7], d = 6
Output: 1
 

Constraints:

1 <= arr1.length, arr2.length <= 500
-10^3 <= arr1[i], arr2[j] <= 10^3
0 <= d <= 100




*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


[4,5,8]
[10,9,1,8]
2



[1,4,2,3]
[-4,-3,6,10,20,30]
3



// Time Complexity: O(nlogn+m).												// m- len. of first arr., n- len. of second arr.
// Space Complexity: O(1).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn+m).												// m- len. of first arr., n- len. of second arr.
// Space Complexity: O(1).	
// This algorithm is Sorting based. Here, we sort the second array. We iter. over first array, use lower_bound to find int with closest
// greater value to curr. num, if it is not v.end() and if diff is <=d, we skip curr. num, we also go lesser val. to curr. num by
// prev(it) and calc. diff, if it is <=d we skip curr. num else, we include the curr. num in the final result.








class Solution {
public:
    int findTheDistanceValue(vector<int>& u, vector<int>& v, int d) {
        sort(v.begin(), v.end());											// Sorting the second arr.
        int res=0;
        for(auto num:u){													// Iter. over first arr.
            // if(abs(v[0]-num)<=d || abs(v.back()-num)<=d) continue;
            auto it=lower_bound(v.begin(), v.end(), num);					// Finding closest greater value to curr. num.
            if(it!=v.end() && *it-num<=d) continue;							// If gap<=d, we skip curr. num.
            if(it!=v.begin() && num-*(prev(it))<=d) continue;				// If smaller num's diff is <=d, we skip curr. num.
            res++;															// If there is suff. gap, we include curr. num in final res.
        }
        return res;															// Returning the final count of nums.
    }
};
