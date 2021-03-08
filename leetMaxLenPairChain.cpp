/*
*
//******************************************************646. Maximum Length of Pair Chain.***********************************************

https://leetcode.com/problems/maximum-length-of-pair-chain/



You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.

Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. Chain of pairs can be formed in this fashion.

Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order.

Example 1:
Input: [[1,2], [2,3], [3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4]
Note:
The number of given pairs will be in the range [1, 1000].




*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


[[1,2], [2,3], [3,4]]
[[1,2],[1,3],[2,3],[1,3],[2,5],[3,4],[3,6],[4,6],[2,6]]
[[-10,-8],[8,9],[-5,0],[6,10],[-6,-4],[1,7],[9,10],[-4,7]]



// Time Complexity: O(nlogn).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(1).	
// This algorithm is Sorting and Greedy approach based. As we want to get the max length of chain, we have to pick pairs whose end are least as possible
// so that we can accomodate more pairs after the curr. pair. We sort the pairs based on their end values, we skip all pairs whose start<=curr. pair end,
// when are in pair whose start>curr. pair end, we inc. the cnt of intervals and update the curr. end to curr. pair end. We return the cnt of intervals 
// at the end.











class Solution {
public:
    
    struct comp{
        bool operator()(vector<int>&lt, vector<int>&rt){					// Sorting intervals based on end values.
            return lt[1]<rt[1];
        }    
    };
    
    int findLongestChain(vector<vector<int>>& v) {
       sort(v.begin(), v.end(), comp());
        int res=1, prev=v[0][1];											// Tracking curr. pair's end value.
        for(int i=1;i<v.size();i++){
            if(v[i][0]>prev){												// Inc. the cnt if the present pair's start>curr. pair's end.
                res++;
                prev=v[i][1];												// Update the curr. pair's end value.
            }
        }
        return res;															// Returning the #non-overlapping increasing pairs count.
    }
};

