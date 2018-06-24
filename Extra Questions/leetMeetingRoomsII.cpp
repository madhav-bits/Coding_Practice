/*
*
//**********************************************************253. Meeting Rooms II.**************************************************

Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of c
onference rooms required.

Example 1:

Input: [[0, 30],[5, 10],[15, 20]]
Output: 2
Example 2:

Input: [[7,10],[2,4]]
Output: 1



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[0,30],[5,15],[15,20]]

[[0,30],[2,10],[7,15],[9,19],[14,17]]





// Time Complexity: O(nlogn).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(1).	
// This algorithm is Sorting and Pirority Queue based. First, we sort the Intervals array based on their start values. We, also create a Min Heap
// based on end values of intervals. We, start iterating from the index=1, with interval in index-0, already taken. If the interval with least
// end time is not less than start of first interval, then we can't accomodate this interval in any of the previous room's schedule, so, we need
// not to create new schedule for another conference room. If least value can accomodate(end value <curr. start), then we can accomodate this 
// meeting in that conference room. So, we update the last available time of that conference room by popping the previous end pushing the curr.
// interval's end time. We, inc. the count, when no room is found, new meeting room is chosen(also stack size at end of iteration can be given). 



// We can also use, range sum addn(inc. the count at the start of intervals and dec. the value at the end of intervals), get the max. valur from 
// all those instances, to make it number of Meeting rooms used.


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
    
    struct comparator{														// Min Heap with sort based interval's 
        bool operator()(const auto&lt, const auto& rt){
            return lt.start<rt.start;
        }  
    };
    
    
    int minMeetingRooms(vector<Interval>& v) {
        if(v.size()==0) return 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(v.begin(), v.end(), comparator());								// Sort interval array based on end values.
        // for(auto inter: v)
        //     cout<<inter.start<<" "<<inter.end<<endl;
        int count=1;														// Tracks #meeting rooms.
        pq.push(v[0].end);													// Pushing the first interval in the list.
        for(int i=1;i<v.size();i++){
            if(pq.top()<=v[i].start){										// If a meeting room can accomodate this curr. interval.
                pq.pop();
                
            }
            else count++;													// If the interval with least end time, can't accomodate curr. inter.
            pq.push(v[i].end);
        }
        return count;														// Return the #Meeting rooms used.
    }
};