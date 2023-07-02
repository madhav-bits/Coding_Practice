/*
*
//******************************************************6909. Longest Even Odd Subarray With Threshold.******************************************************

https://leetcode.com/problems/longest-even-odd-subarray-with-threshold/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[3,2,5,4]
5
[1,2]
2
[2,3,4,5]
4
[1,1,1,1,1,1,1]
2
[3,3,4,5,2,7,10,7,6,7,6,7,7,2]
9
[4,10,3]
10



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. During iteration we maintain the state whether we started subarray or not, if yes we check %2 values for curr. and prev.
// index. If subarray haven't started and curr. value has %2==0, we mark start of subarray. If curr. value>threshold we mark end of subarr irrespective of
// whether we started a subarray or not. If two nums hav %2 values we mark the subarray as closed, but since this index can be start of another subarray, 
// we revisit this index if curr. val is even and <=threshold. We try to maximize the res value for every inc. in curr. subarray length.







class Solution {
public:
    int longestAlternatingSubarray(vector<int>& v, int threshold) {
        int res=0, curr=0;
        bool start=false;
        for(int i=0;i<v.size();i++) {
            if(v[i]<=threshold && 											// Conditions for the subarray to start/continue.
               ((start==false && v[i]%2==0) || 
              (start && (v[i]%2)!=(v[i-1]%2)))) {
                start=true;
                curr++;
                if(curr>res) res=curr;										// Tracks the max. subarray length.
            }else {
                if(v[i]<=threshold && v[i]%2==0) i--;						// If curr. value can be start of another subarray, we revisit it.
                start=false;												// Marking subarray as closed, reset it's length to 0.
                curr=0;
            }
        }
        return res;															// Returning the max. length of the subarray.
    }
};

