/*
*
//******************************************************2055. Plates Between Candles.******************************************************

https://leetcode.com/problems/plates-between-candles/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"**|**|***|"
[[2,5],[5,9]]
"***|**|*****|**||**|*"
[[1,17],[4,5],[14,17],[5,11],[15,16]]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is prefixSum based. Here, we store the prefixSum of "*". Since we have to only include '*'s which are enclosed b/w plates. We maintain two array to store the indices of next, prev.
// occuring indices of plates. For a given interval[left, right], we extract the #candles until the prev. plate to the right index and next #candles until next. plate from left index. We subtract
// left prefixTotal from right prefixTotal and return it.







class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int>res;
        vector<int>enclosed(s.length(), 0), prevClose(s.length(), 0), nextClose(s.length(), 0);
        int close=0;
        for(int i=0;i<s.length();i++) {
            if(s[i]=='*') enclosed[i]=1;
            if(i>0) enclosed[i]+=enclosed[i-1];															// Storing prefixTotal of candles.
            
            if(s[i]=='|') close=i;																		// Updating the tracker to latest plate index.
            prevClose[i]=close;																			// Storing prev. occuring plate index for each of the indices.
        }
        
        close=s.length()-1;
        for(int i=s.length()-1;i>=0;i--) {
            if(s[i]=='|') close=i;																		// Updating the tracker to latest plate index from right.
            nextClose[i]=close;																			// Storing next occuring plate index for each of the indices.
        }
        for(vector<int>&query:queries) {
            int left=nextClose[query[0]], right=prevClose[query[1]];
            // cout<<"left: "<<left<<" and right: "<<right<<endl;
            res.push_back(left>right?0:enclosed[right]-enclosed[left]);									// Subtract prefixTotal of left from right and append to res.
        }
        return res;																						// Returning the #candles for all the queries.
    }
};

