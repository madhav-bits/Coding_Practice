/*
*
//**********************************************************731. My Calendar II.***************************************************

Implement a MyCalendarTwo class to store your events. A new event can be added if adding the event will not cause a triple booking.

Your class will have one method, book(int start, int end). Formally, this represents a booking on the half open interval [start, end), the range 
of real numbers x such that start <= x < end.

A triple booking happens when three events have some non-empty intersection (ie., there is some time that is common to all 3 events.)

For each call to the method MyCalendar.book, return true if the event can be added to the calendar successfully without causing a triple 
booking. Otherwise, return false and do not add the event to the calendar.

Your class will be called like this: MyCalendar cal = new MyCalendar(); MyCalendar.book(start, end)
Example 1:
MyCalendar();
MyCalendar.book(10, 20); // returns true
MyCalendar.book(50, 60); // returns true
MyCalendar.book(10, 40); // returns true
MyCalendar.book(5, 15); // returns false
MyCalendar.book(5, 10); // returns true
MyCalendar.book(25, 55); // returns true
Explanation: 
The first two events can be booked.  The third event can be double booked.
The fourth event (5, 15) can't be booked, because it would result in a triple booking.
The fifth event (5, 10) can be booked, as it does not use time 10 which is already double booked.
The sixth event (25, 55) can be booked, as the time in [25, 40) will be double booked with the third event;
the time [40, 50) will be single booked, and the time [50, 55) will be double booked with the second event.
Note:

The number of calls to MyCalendar.book per test case will be at most 1000.
In calls to MyCalendar.book(start, end), start and end are integers in the range [0, 10^9].




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


// No test cases created and worked on.



// Time Complexity: O(n^2).  
// Space Complexity: O(n^2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).	
// Space Complexity: O(n^2).	
// This algorithm is that it first checks whether current interval is part of any other interval which had already occured twice, if true returned
// false. If not, it checks whether the curr. interval has overlapped with any previous interval which occured only once. If overlapped, then
// push the overlapped interval part into the vector with intervals occuring twice.



class MyCalendarTwo {
public:
    vector<pair<int,int>> second;											// Contains intervals which had occured twice.
    vector<pair<int, int>> once;											// Contains intervals which had occured once.
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for(int i=0;i<second.size();i++){
            if(max(second[i].first, start)<  min(second[i].second, end)){//Overlapped with an already existing twice occured interval.
                return false;										// Return false, as this interval is leading to triple booking.
            }   
        }
        
        for(int i=0;i<once.size();i++){
            if(max(once[i].first, start)<  min(once[i].second, end)){//Overlapped with an already existing once occured interval.
                pair<int, int> p;
                p=make_pair(max(once[i].first, start), min(once[i].second, end));
                second.push_back(p);
            }
        }
        once.push_back(make_pair(start,end));						// Pushing the interval into vector with only once occured intervals.
        return true;												// Return true, as the interval had been added to list of once occur. intervals.
        
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */