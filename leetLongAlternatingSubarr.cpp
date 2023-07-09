/*
*
//******************************************************2765. Longest Alternating Subarray.******************************************************

https://leetcode.com/problems/longest-alternating-subarray/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[2,1,2,1,2]
[2,3,4,3,4]
[4,5,6]
[1,4,6,8]
[31,32,31,32,33]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration+ Greedy based. We start a seq. once we find a diff=1, we iter. and check for diff. and keep increasing the seq. length if diff.
// condition is satisfied. If an index breaks this condition, we revisit that index if curr. diff =1, as this could be start of another seq. else we move to
// next index searching for new start of seq. A mismatch index can't be part of any seq. starting at any prev. index as if a seq. exists which expects curr.
// diff in this inex, then prev. index wouldn't satisfy the condition as both curr. and prev. diff would be same now. So, upon breaking the seq. we can safely
// start looking for seq. starting at later indices. At every step upon satisfying the condition, we try to maximize the seq. length and return it at the end 
// of iter.







class Solution {
public:
    int alternatingSubarray(vector<int>& v) {
        int res=-1, curr=1, diff=1;
        for(int i=1;i<v.size();i++) {
            int currDiff=v[i]-v[i-1];
            if(currDiff==diff) {											// If diff condition is satisfied.
                curr++;
                diff*=-1;
                if(curr>res) res=curr;										// Trying to maximize the seq. length.
            } else {														// If curr. diff doesn't satisfy the diff. condition.
                curr=1;
                diff=1;
                if(currDiff==1) i--;										// If curr. diff=1, we revisit index as this can be start of another seq.
            }
        }
        return res;															// Returning the max. seq. length
    }
};

