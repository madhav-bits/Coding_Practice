/*
*
//************************************************1798. Maximum Number of Consecutive Values You Can Make.***********************************************


https://leetcode.com/problems/maximum-number-of-consecutive-values-you-can-make/



You are given an integer array coins of length n which represents the n coins that you own. The value of the ith coin is coins[i]. You can make 
some value x if you can choose some of your n coins such that their values sum up to x.

Return the maximum number of consecutive integer values that you can make with your coins starting from and including 0.

Note that you may have multiple coins of the same value.

 

Example 1:

Input: coins = [1,3]
Output: 2
Explanation: You can make the following values:
- 0: take []
- 1: take [1]
You can make 2 consecutive integer values starting from 0.
Example 2:

Input: coins = [1,1,1,4]
Output: 8
Explanation: You can make the following values:
- 0: take []
- 1: take [1]
- 2: take [1,1]
- 3: take [1,1,1]
- 4: take [4]
- 5: take [4,1]
- 6: take [4,1,1]
- 7: take [4,1,1,1]
You can make 8 consecutive integer values starting from 0.
Example 3:

Input: nums = [1,4,10,3,1]
Output: 20
 

Constraints:

coins.length == n
1 <= n <= 4 * 104
1 <= coins[i] <= 4 * 104




*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


[1,1,2,9]
[11,12,13,14]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is observation based. Here, we keep track max integer until which we form integers by adding nums. While iterating we add curr. nums
// to max integer as we can improve the range of reachable nums including curr. digit. We stop iter. when we found an integer which is >curr. max integer,
// as it can form nums which are atleast cur. integer which won't result in continuous range of integers starting 0.


// This link has a good explanation of the approach.
// https://leetcode.com/problems/maximum-number-of-consecutive-values-you-can-make/discuss/1118766/C%2B%2BJavaPython-with-picture






class Solution {
public:
    int getMaximumConsecutive(vector<int>& v) {
        int maxVal=1;
        sort(v.begin(),v.end());
        for(int i=0;i<v.size() && v[i]<=maxVal;i++){
            maxVal+=v[i];
        }
        return maxVal;
    }
};

