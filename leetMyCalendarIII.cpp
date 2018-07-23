/*
*
//**********************************************************732. My Calendar III.***************************************************

Implement a MyCalendarThree class to store your events. A new event can always be added.

Your class will have one method, book(int start, int end). Formally, this represents a booking on the half open interval [start, end), the 
range of real numbers x such that start <= x < end.

A K-booking happens when K events have some non-empty intersection (ie., there is some time that is common to all K events.)

For each call to the method MyCalendar.book, return an integer K representing the largest integer such that there exists a K-booking in the 
calendar.

Your class will be called like this: MyCalendarThree cal = new MyCalendarThree(); MyCalendarThree.book(start, end)
Example 1:
MyCalendarThree();
MyCalendarThree.book(10, 20); // returns 1
MyCalendarThree.book(50, 60); // returns 1
MyCalendarThree.book(10, 40); // returns 2
MyCalendarThree.book(5, 15); // returns 3
MyCalendarThree.book(5, 10); // returns 3
MyCalendarThree.book(25, 55); // returns 3
Explanation: 
The first two events can be booked and are disjoint, so the maximum K-booking is a 1-booking.
The third event [10, 40) intersects the first event, and the maximum K-booking is a 2-booking.
The remaining events cause the maximum K-booking to be only a 3-booking.
Note that the last event locally causes a 2-booking, but the answer is still 3 because
eg. [10, 20), [10, 40), and [5, 15) are still triple booked.
Note:

The number of calls to MyCalendarThree.book per test case will be at most 400.
In calls to MyCalendarThree.book(start, end), start and end are integers in the range [0, 10^9].



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["MyCalendarThree","book","book","book","book","book","book"]
[[],[10,20],[50,60],[10,40],[5,15],[5,10],[25,55]]



["MyCalendarThree","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book"]
[[],[47,50],[1,10],[27,36],[40,47],[20,27],[15,23],[10,18],[27,36],[17,25],[8,17],[24,33],[23,28],[21,27],[47,50],[14,21],[26,32],[16,21],[2,7],[24,33],[6,13],[44,50],[33,39],[30,36],[6,15],[21,27],[49,50],[38,45],[4,12],[46,50],[13,21]]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Segment Tree based, but more easily done through HashMap. We store the edges of intervals in the map, where start of 
// the interval is indicated by inc. the value for that key by 1.End of interval by dec. the value for that key by 1. For every insert the 
// interval, we then count of number of active intervals for all the edges stored in map. We track the max #active intervals and return the max. num.








class MyCalendarThree {
public:
    map<int,int>m;															// Tracks the edges of the intervals.
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        int res=0;															// Tracks the max #active intervals.
        m[start]++;															// Inc. the #active intervals by one.
        m[end]--;															//Dec. the #active intervals by one.
        int count=0;														// Tracks #active intervals at any instant.
        for(auto it: m){
            count+=it.second;												// Sums the rep.(#active interval) of curr. edge of interval.
            res=max(res,count);												// Extracting max. #active interval.
            // if(it.second==end) break;
        }
        return res;															// Returning the max. #active intervals.
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(start,end);
 */