/*
*
//******************************************************910. Smallest Range II.******************************************************

https://leetcode.com/problems/smallest-range-ii/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1]
0
[0,10]
2
[1,3,6]
3



// Time Complexity: O(nlogn).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(1).	
// This algorithm is Greedy based. If all the given points are placed on axis and for us to have min. gap b/w maxm and minm after the changes, the lower vals
// should be increasing v[low]+k, and higher indices vals should be dec. v[high]-k. If we consider two consec. vals a<b, a move such as a-k and b+k doesn't 
// make sense, if we assume this would is a must in determining ans that means these vals should be minm and maxm, but minm could have been increased if 
// we made it to a+k and maxm could have been dec. to b-k leading to smaller maxm-minm.
// If we observe a+k, b-k move is a better move as this might lead to smaller diff. else if both nums move in same dirn that might also lead to smaller diff.
// Using all above observations we see that i,i,i,i,i or d,d,d,d,d,d or i,i,i,i,d,d,d,d,d is a pattern which might give us correct answer which is created in 
// the iter and minm, maxm value are calc. for each combi and min. diff is tracked and returned at the end of iter.







class Solution {
public:
    int smallestRangeII(vector<int>& v, int k) {
        sort(v.begin(), v.end());
        int res=v.back()-v[0];												// Diff with all nums making move in same drn.
        for(int i=0;i+1<v.size();i++) {										// Iter. over array and forming all combi. of moves.
																			// All indices from [0,i] could inc. and [i+1, len-1] would dec. their value.
            int maxm=max(v[i]+k, v.back()-k);								// Calc. maxm val in curr. combi. of moves. 
            int minm=min(v[0]+k, v[i+1]-k);									// Calc. minm. val in curr. combi. of moves.
            if(maxm-minm<res) res=(maxm-minm);								// Tracking minm. dist. after the moves.
        }
        return res;															// Returning min. possible gap b/w maxm, minm after the moves.
    }
};

