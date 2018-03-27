/*
*
//******************************************************435. Non-overlapping Intervals.***********************************************

Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Note:
You may assume the interval's end point is always bigger than its start point.
Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other.
Example 1:
Input: [ [1,2], [2,3], [3,4], [1,3] ]

Output: 1

Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.
Example 2:
Input: [ [1,2], [1,2], [1,2] ]

Output: 2

Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.
Example 3:
Input: [ [1,2], [2,3] ]

Output: 0

Explanation: You don't need to remove any of the intervals since they're already non-overlapping.



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[1,10],[2,11],[4,12],[6,9]]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).	
// Space Complexity: O(1).	
//***********************************************************GREEDY ALGORITHM.********************************************************
// This algorithm is GREEDY ALGORITHM. At any point of time we keep a single interval deleting all it's overlapping intervals at any instant. The
// essence is that, we keep the interval with the shortest end, as the overlapping interval with the longer end might overlap with other intervals.
// Thus, optimizing the #intervals at any instant.



/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& v) {
        int count=0, curr=0;
        sort(v.begin(), v.end(), [](const auto& lt, const auto& rt){	//Sort the intervals based on starting times.
            return lt.start<rt.start;
        });
        
        int prev=0;
        for(int i=1;i<v.size();i++){
            if(v[i].start<v[prev].end){						// An overlapping interval.
                count++;									// Deletes one of the overlapping intervals.
                if(v[i].end < v[prev].end) prev=i;			// If the newly encountered interval has shorter end, then the intial inter. is deleted.
            }												// If not, newly encountered interval has longer end, then deleting it.
            else											// If a overlapping interval is not found, then just move focus onto next interval.
                prev=i;
                
        }
        
        return count;										// Returns #deleted intervals.
    }
};
