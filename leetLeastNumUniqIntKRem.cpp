/*
*
//****************************************1481. Least Number of Unique Integers after K Removals.***************************************

https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/description/


Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.

Example 1:

Input: arr = [5,5,4], k = 1
Output: 1
Explanation: Remove the single 4, only 5 is left.
Example 2:
Input: arr = [4,3,1,1,3,3,2], k = 3
Output: 2
Explanation: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3 will be left.
 

Constraints:

1 <= arr.length <= 10^5
1 <= arr[i] <= 10^9
0 <= k <= arr.length




*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


Worked with the examples provided in the question.


// Time Complexity: O(nlogn).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(n).	
// This algorithm is Sorting based. Here, since we need max. uniq. values after removing k values, we remove nums with least frequency
// first, so that more uniq. nums are removed in the k deletions. To get the least freq. nums, we first store their occur. in a map,
// we store the #occur. in a arr., sort it and start removing least freqs until k becomes 0 and return the rem. freqs count.








class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        if(k==arr.size()) return 0;
        unordered_map<int,int>m;											// Stores #occur. of each num.
        for(auto num:arr)
            m[num]++;
        vector<pair<int,int>>v;
        for(auto it=m.begin();it!=m.end();it++){							// Store the #occur. of nums.
            v.push_back({it->second, it->first});
        }
        sort(v.begin(), v.end());											// Sort the #occur. of nums.
        int i=0;
        while(k>0 && k>=v[i].first){										// Remove least val. freqs until k becomes 0.
            k-=v[i].first;
            i++;
        }
        return (int)v.size()-i;												// Return the #rem. nums.
    }
};