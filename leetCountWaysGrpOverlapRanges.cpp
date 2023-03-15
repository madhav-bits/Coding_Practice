/*
*
//************************************************2580. Count Ways to Group Overlapping Ranges.***********************************************

https://leetcode.com/problems/count-ways-to-group-overlapping-ranges/


*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


[[6,10],[5,15]]
[[1,3],[10,20],[2,5],[4,8]]
[[1,1],[2,2],[3,3],[4,4],[5,5]]
[[1,1],[1,2],[3,3],[4,4],[5,5]]
[[3,8],[4,6],[1,4],[7,9],[3,6],[13,19],[23,29],[38,53]]




// Time Complexity: O(nlogn).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(1).	
// This algorithm is Sorting based. Here, first we sort the provided ranges based on start values, which would be useful in grouping the overlapping ranges. While iterating we track the close 
// value of the curr. set of overlapping ranges, when we reach a range whose start>curr. set close value, we multiply curr. overlapping range's two possibilities to final result and start a new 
// overlapping range as all the following ranges would start after the curr. range thus prev. closed overlapping range won't be affected anymore. Thus as the end of iter. we return the final result
// which is the total #ways of splitting the overlapping ranges into two possible groups.









class Solution {
public:
    int countWays(vector<vector<int>>& v) {
        int mod=1000000007;
        int res=2, grps=0;
        sort(v.begin(), v.end());												// Sorting the provided list of intervals.
        int currClose=v[0][1];
        for(int i=0;i<v.size();i++) {
            if(v[i][0]>currClose) {												// As curr. set of overlapping ranges doesn't overlap ith range, we start a new set of overlapping ranges.
                res=(1ll*res*2)%mod;											// Multiply the curr. range's two possibilities to the final result.
                currClose=v[i][1];												// Set the end of the new set of ranges.
            }else if(v[i][1]>currClose) currClose=v[i][1];						// Updating the curr. set of overlapping ranges.
        }
        return res;																// Returning the final #ways of splitting ranges.
    }
};




