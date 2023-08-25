/*
*
//******************************************************2831. Find the Longest Equal Subarray.******************************************************

https://leetcode.com/problems/find-the-longest-equal-subarray/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,3,2,3,1,3]
3
[1,1,2,2,1,1]
2
[4,3,8,2,3,5,7,6,5,4,3,4,7,8,9,8,9,6,4,3,2,2]
5



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Sliding Window based. Here, we keep extending window to the right until the nums other than maxFreq>k, now we only remove the first char
// in the window, thus we maintain the length and we don't update the maxFreq even it may change as we remove the first char in window, it won't affect our 
// final result whether we track max window length or maxFreq becuase maxFreq is already updated to res when the window is valid, in it's current state 
// window is invalid and we CAN'T increase res anyways. If we add and remove non maxFeq chars from front and back it won't affect maxFreq and len is valid but 
// as earlier mentioned it won't improve the res, so we avoid updating res in case we len-maxFreq>k(it doesn't matter even if we try to update using max compare).
// In this way we maintain the same length and same maxFreq until we find an instance where freq. of newly added num>maxFreq and as a resut len-maxFreq=k, which
// meets the condition, since maxFreq is updated with the latest valid value and len var is valid always, as now all parameters are valid and window is 
// valid now, so we can try to update res now.




// This discussion forum link has some description and links to other similar questions.
// https://leetcode.com/problems/find-the-longest-equal-subarray/discuss/3934172/JavaC++Python-One-Pass-Sliding-Window-O(n)





class Solution {
public:
    int longestEqualSubarray(vector<int>& v, int k) {
        int start=0, res=0, maxFreq=0;
        int occur[v.size()+1];
        memset(occur, 0, sizeof(occur));
        for(int i=0;i<v.size();i++) {
            if(++occur[v[i]]>maxFreq) maxFreq=occur[v[i]];					// Tracking maxFreq.
            if(i-start+1-maxFreq>k) occur[v[start++]]--;					// If we don't meet condition, we remove start of index, maintain len, maxFreq.
            else if(maxFreq>res) res=maxFreq;								// If we meet condition, we try to update res with maxFreq.
            // cout<<"i: "<<i<<" and start: "<<start<<" and len: "<<maxFreq<<endl;
        }
        return res;															// Returning maxFreq/longest possible equal subarray length.
    }
};

