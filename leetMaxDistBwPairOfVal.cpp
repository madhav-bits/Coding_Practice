/*
*
//************************************************1855. Maximum Distance Between a Pair of Values.***********************************************

https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/




You are given two non-increasing 0-indexed integer arrays nums1​​​​​​ and nums2​​​​​​.

A pair of indices (i, j), where 0 <= i < nums1.length and 0 <= j < nums2.length, is valid if both i <= j and nums1[i] <= nums2[j]. The distance of the 
pair is j - i​​​​.

Return the maximum distance of any valid pair (i, j). If there are no valid pairs, return 0.

An array arr is non-increasing if arr[i-1] >= arr[i] for every 1 <= i < arr.length.

 

Example 1:

Input: nums1 = [55,30,5,4,2], nums2 = [100,20,10,10,5]
Output: 2
Explanation: The valid pairs are (0,0), (2,2), (2,3), (2,4), (3,3), (3,4), and (4,4).
The maximum distance is 2 with pair (2,4).
Example 2:

Input: nums1 = [2,2,2], nums2 = [10,10,1]
Output: 1
Explanation: The valid pairs are (0,0), (0,1), and (1,1).
The maximum distance is 1 with pair (0,1).
Example 3:

Input: nums1 = [30,29,19,5], nums2 = [25,25,25,25,25]
Output: 2
Explanation: The valid pairs are (2,2), (2,3), (2,4), (3,3), and (3,4).
The maximum distance is 2 with pair (2,4).
Example 4:

Input: nums1 = [5,4], nums2 = [3,2]
Output: 0
Explanation: There are no valid pairs, so return 0.
 

Constraints:

1 <= nums1.length <= 105
1 <= nums2.length <= 105
1 <= nums1[i], nums2[j] <= 105
Both nums1 and nums2 are non-increasing.





*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


[55,30,5,4,2]
[100,20,10,10,5]
[2,2,2]
[10,10,1]
[30,29,19,5]
[25,25,25,25,25]
[5,4]
[3,2]
[12,2,2]
[10,10,1]



// Time Complexity: O(n+m).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n+m).
// Space Complexity: O(1).	
// This algorithm is Observation based. Here, since the arrays are sorted in non-decreasing order. While trying to find the u[i]<=v[j] pair we take
// pointers starting from beginning on both arrays. If we found a pair, we extend j value in search of v[j] which still is more than u[i], thus we are
// trying to maximize the j-i dist for the u[i] value. If v[j]>u[i], we inc. i to find the u[i] for which u[i]<=v[j], we can ignore all curr. u[i] which are >
// curr. v[j] as all the prev. j would form j-i values to less than curr. max pair diff. In this way we are covering all possible pairs and returning
// the max. diff.











class Solution {
public:
    int maxDistance(vector<int>& u, vector<int>& v) {
        int res=0, i=0,j=0;													// Tracks max. pair diff, pointers on both the arrays.
        while(i<u.size() && j<v.size()){									// Until all values in both arrays are compared
            if(u[i]<=v[j]){													// Satisfied condition, update res val with curr. j-i, inc. j trying to max res
                res=max(res, j-i);
                j++;
            }else i++;														// In search of lower u[i] value to form pairs.
        }
        return res;															// Returning the max. j-i value.
    }
};

