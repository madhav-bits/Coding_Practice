/*
*
//**********************************************************729. My Calendar I.***************************************************

Implement a MyCalendar class to store your events. A new event can be added if adding the event will not cause a double booking.

Your class will have the method, book(int start, int end). Formally, this represents a booking on the half open interval [start, end), the 
range of real numbers x such that start <= x < end.

A double booking happens when two events have some non-empty intersection (ie., there is some time that is common to both events.)

For each call to the method MyCalendar.book, return true if the event can be added to the calendar successfully without causing a double 
booking. Otherwise, return false and do not add the event to the calendar.

Your class will be called like this: MyCalendar cal = new MyCalendar(); MyCalendar.book(start, end)
Example 1:
MyCalendar();
MyCalendar.book(10, 20); // returns true
MyCalendar.book(15, 25); // returns false
MyCalendar.book(20, 30); // returns true
Explanation: 
The first event can be booked.  The second can't because time 15 is already booked by another event.
The third event can be booked, as the first event takes every time less than 20, but not including 20.
Note:

The number of calls to MyCalendar.book per test case will be at most 1000.
In calls to MyCalendar.book(start, end), start and end are integers in the range [0, 10^9].




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["MyCalendar","book","book","book"]
[[],[10,20],[15,20],[20,30]]

["MyCalendar","book","book","book"]
[[],[10,20],[15,20],[5,12]]

["MyCalendar","book","book","book"]
[[],[10,20],[15,20],[15,25]]

["MyCalendar","book","book","book"]
[[],[10,20],[15,20],[6,9]]

["MyCalendar","book","book","book"]
[[],[10,20],[15,20],[16,20]]

["MyCalendar","book","book","book"]
[[],[10,20],[15,20],[10,19]]




// Time Complexity: O(n^2).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).	
// Space Complexity: O(n).	
// This algorithm is straightforward, compares all the intervals present till then newly proposed interval, checks whether it's overlapping or not,
// One way is to compare the begin and end of the previously saved intervals and the proposed interval. Other way is that, we find the overlap
// by getting the max. of both the begin and min. of both the ends, if the max. of begin< min. of end, then there is overlap. Based on two models
// two algorithms are presented here.



class MyCalendar {
public:
    vector<vector<int>> v;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(int i=0;i<v.size();i++){
            if((start>=v[i][0] && end<v[i][1]) || (start>=v[i][0] && start<v[i][1]) || (end>v[i][0] && end<v[i][1]) || (v[i][0]>=start && v[i][1]<end)|| (v[i][0]>=start && v[i][0]<end) || (v[i][1]>start && v[i][1]<end)){
                //if(start>=v[i][0] && end<v[i][1]) cout<<"1"<<endl;	// The first three comparisions are in previous intervals perspective, 
                //if(start>=v[i][0] && start<v[i][1]) cout<<"2"<<endl;	// checks, new interval overlaps it or not.
                //if(end>v[i][0] && end<v[i][1]) cout<<"3"<<endl;		// The last three comparisions are in new intervals perspective,
                //if(v[i][0]>=start && v[i][1]<end) cout<<"4"<<endl;	// checks, old intervals overlaps it or not.
                //if(v[i][0]>=start && v[i][0]<end) cout<<"5"<<endl;
                //if(v[i][1]>start && v[i][1]<end) cout<<"6"<<endl;
                
                return false;											// If overlap detected, return false.
            } 
        }
        v.push_back({start,end});										// If no overlap is detected, then push into list of inter. and return true.
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */
 
 
 
 
 
 
//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).	
// Space Complexity: O(n).	
// This algorithm is straightforward, compares all the intervals present till then newly proposed interval, checks whether it's overlapping or not,
// One way is to compare the begin and end of the previously saved intervals and the proposed interval. Other way is that, we find the overlap
// by getting the max. of both the begin and min. of both the ends, if the max. of begin< min. of end, then there is overlap. Based on two models
// two algorithms are presented here.
 
 
 
 
 
 class MyCalendar {
public:
    vector<vector<int>> v;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(int i=0;i<v.size();i++){
            if(max(v[i][0], start)<min(v[i][1],end)){			// Getting the max. of starts and min. of ends.
                return false;									// If the max. of begin< min. of ends, then there is overlap.
            }
        }
        v.push_back({start,end});								// If any overlap isn't detected, then return true.
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */