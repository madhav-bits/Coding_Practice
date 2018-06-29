/*
*
//**************************************************************252. Meeting Rooms.*******************************************************

Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could 
attend all meetings.

Example 1:

Input: [[0,30],[5,10],[15,20]]
Output: false
Example 2:

Input: [[7,10],[2,4]]
Output: true




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[4,7],[2,4]]


[[0,30],[15,20],[5,10]]


[[6,7],[2,4],[5,6]]



// Time Complexity: O(nlogn).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(1).	
// This algorithm is iteration based. For the person to attend all meetings, no meeting has to overlap with other. So, we sort the intervals
// based on the starting values. Then, we check if the prev. events end value is < curr. even't start value, it not then we return false, as they
// overlap.








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
    bool canAttendMeetings(vector<Interval>& v) {
																			// Sorting vector based on start values.
        sort(v.begin(), v.end(), [](const auto&lt, const auto&rt){
            return lt.start<rt.start;
        });
        // for(auto it: v)
        //     cout<<"start: "<<it.start<<" and end: "<<it.end<<endl;
        int prev=-1;														// Setting base value for prev. interval's end value.
        for(int i=0;i<v.size();i++){										// Iterating through all intervals.
            if(v[i].start<prev) return false;								// If prev. interval's end >curr. interval's start value, return false.
            prev=v[i].end;													// Updating the var.
        }
        return true;														// If no overlaping intervals found, then return true.
    }
};