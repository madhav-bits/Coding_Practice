/*
*
//******************************************************2100. Find Good Days to Rob the Bank.******************************************************

https://leetcode.com/problems/find-good-days-to-rob-the-bank/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[5,3,3,3,5,6,2]
2
[1,1,1,1,1]
0
[1,2,3,4,5,6]
2
[2,2,2,2,2,2,2]
3
[5,5,5,5,5,5,4,4,4,4,4,6,6,6,6,6]
4
[1]
5



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Observation based. Here, first an index to be part of res, it needs to have time indices to left with non-increasing values and time 
// non-decreasing vals to right, we can collect count of consec. non-increasing vals to an index 'i' as part of iter. and we prefill the non-dec. vals to right
// count using another iter. from last to first index.  When we are at an index 'i' during second iter., we have #consec. non-inc. vals upto 'i' in a var and
// #non-dec. count starting 'i' in incCount[i], if both values are>=time+1(as we include current index too), we add curr. index to res. We return res at the
// end of iter.







class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& v, int time) {
        vector<int>res;
        if((int)v.size()<2*time-1) return res;
        vector<int>incCount(v.size(), 1);
        for(int i=v.size()-2;i>=0;i--) if(v[i]<=v[i+1]) incCount[i]+=incCount[i+1];// Collecting #consec. non-dec. values starting index 'i'.
        
        int decCount=0;
        for(int i=0;i<(int)v.size()-time;i++) {
            if(i>0 && v[i-1]>=v[i]) decCount++;								// Tracking #consec. non-inc. values upto index 'i'.
            else decCount=1;
            if(decCount>=time+1 && incCount[i]>=time+1) res.push_back(i);	// If curr. index satisfies the condition, we add 'i' to res.
        }
        return res;															// Returning all indices which satisfies the Good Day condition.
    }
};

