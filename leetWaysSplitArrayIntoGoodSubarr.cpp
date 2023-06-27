/*
*
//******************************************************2750. Ways to Split Array Into Good Subarrays.******************************************************

https://leetcode.com/problems/ways-to-split-array-into-good-subarrays/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[0,1,0,0,1]
[0,1,0]
[1,0,0,1,1,1,0,0,0,1,0]
[0,0,0,0,0]
[1,1,1,1,1]
[1,0,1,0,1,0,1,0,1,0,1,0]
[1,0,1,0,1,0,1,0,1,0,1,0,1]
[0,1,0,1,0,1]
[0,1,0,1,0,1,0]
[0,0,1,1]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is observation based. Here, at every step we try to get #divisions in the array with curr. index being the end of the array. For indices storing '0' their
// #divisions ending at them would be equal to the #divisions to the #divisions to the latest '1' before them as each division has to be exactly single '1', this index divisions
// would be the same as latest one. We also keep on tracking #divisions till curr. index and remaining indices till next one belonging to next division.
// When we encounter '1', we calc. #divisions ending with that index which equals sum of #divisions ending at all zeroes from latest one to current one as the latest division
// involving current '1' would end at all these adjacent zeroes until prev. '1'.








class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& v) {
        int res=0, mod=1000000007;
        int prev=0, curr=0, last=0, i=0;
        while(i<v.size() && v[i]==0)  i++;
        if(i==v.size()) return 0;
        curr=1;
        for(;i<v.size();i++) {
            if(v[i]==1) {
                res=curr;													// #divisions with curr. index ending the last division.
                prev=curr;													// #divisions with curr. index being end of last bu 1 division and rest indices with zeroes 
																			// till next '1' part of last division.
            }else curr=(curr+prev)%mod;										// This is #divisions with last but 1 ending at curr. index and last one ends with next occuring '1'.
            // cout<<"i: "<<i<<" and res: "<<res<<" and prev: "<<prev<<endl;
        }
        return res;															// Returning total #divisions of the array.
    }
};
