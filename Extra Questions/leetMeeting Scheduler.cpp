/*
*
//************************************************************1229. Meeting Scheduler.*****************************************************

https://leetcode.com/problems/meeting-scheduler/

Finding the common time slot between two sets of intervals with target length of period and return the earliest possible time slot.


*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


[[10,12]]
[[11,13]]
1
[[10,50],[60,120],[140,210]]
[[0,15],[60,70]]
8
[[10,50],[60,120],[140,210]]
[[0,15],[60,70]]
12



// Time Complexity: O(nlogn+mlogm).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn+mlogm).
// Space Complexity: O(1).	
// This algorithm is Sorting based. We sort both the arrays based on their start times. We iter. over them using two ptrs, if there is overlap and 
// it satisfies requirement, we return the interval, if not we inc. the iter. of the array whose curr. end is <= other array's curr. end, this way we 
// inc. any of the iter. in every step. The first interval we find satisfying given requirement would be the earliest time slot.











class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& u, vector<vector<int>>& v, int duration) {
        sort(u.begin(), u.end());											// Sorting intervals based on start times.
        sort(v.begin(), v.end());
        int i=0,j=0;
        while(i<u.size() && j<v.size()){									// Finding the earliest time slot.
            int start=max(u[i][0],v[j][0]), close=min(u[i][1], v[j][1]);	// Calc. start, end of overlap.
            if(close-start>=duration) return vector<int>({start, start+duration});// If target duration is found, return it.
            if(u[i][1]<=v[j][1]) i++;										// If u's end is smaller, we move to next interval as it may overlap with v's interval.
            else j++;
        }
        return vector<int>();												// No interval found which meets requirements.
    }
};
