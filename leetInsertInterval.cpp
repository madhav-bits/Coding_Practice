/*
*
//************************************************************57. Insert Interval.*****************************************************

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[1,2],[3,5],[6,7],[8,10],[12,16]]
[-2,-1]


[[3,4],[4,5],[6,8],[9,10],[12,15]]
[7,9]


[[3,4],[4,5],[6,8],[9,10],[12,15]]
[17,19]


[[3,4],[4,5],[6,8],[9,10],[12,15]]
[6,7]


[[3,4],[4,5],[6,8],[9,10],[12,15]]
[1,21]

[[3,4],[4,5],[6,8],[9,10],[12,15]]
[3,9]




// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm iterates the array, at each step we check for overlap of given interval and curr. scan interval. In case of first overlap, we 
// create a new Interval with dummy values in it, we go through all overlapping intervals without pushing interavls into result vector. After
// the iteration, as we know the index where this combined overlap is locate, we place max, min values of overlap intervals there. In case of 
// non-overlap of intervals, we push a new interval just before where the first interval, whose interval beginning is larger than given interval's
// end. If after the entire interval, the interval haven't beeen pushed anywhere, then it has to be appended to the result vector.

// In order to handle corner cases easily, I had padded the vector with two Intervals one at beginning(with INT_MIN. values) and 
// one at end(with INT_MAX values.)





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
    vector<Interval> insert(vector<Interval>& v, Interval given) {
        if(v.size()==0) return vector<Interval>(1,given);							//If empty array is given, return given interval.
        vector<Interval>res;
        int index=-1;																// Index, where the new interval has to be pushed.
        v.insert(v.begin(), *new Interval(INT_MIN, INT_MIN+1));						// Padding with corner Intervals.
        v.push_back(*new Interval(INT_MAX-1, INT_MAX));								// Padding with corner Intervals.
        for(int i=1;i<v.size()-1;i++){
            if(max(v[i].start,given.start)<=min(v[i].end, given.end)){				// In case of overlapping inter. calc. max and min. of edges.
                if(index==-1){														// In First overlap inter. push dummy interval to replace all
                    res.push_back(*new Interval(0,0));								// overlapping intervals.
                    index=i-1;														// Updating index to know where to push final minm, maxm val.
                }
                given.start=min(given.start,v[i].start);							// Getting minm, maxm. of overlapping intervals.
                given.end=max(given.end, v[i].end);
            }
            else if(max(v[i].start,given.start)>min(v[i].end, given.end)){          // Non-overlapping intervals b/w two nodes.
                if(v[i-1].end<given.start && given.end<v[i].start){					// First Interval with start>given inter. end.
                    index=i-1;														// To mark that inter. has been pushed at index "i-1".
                    res.push_back(*new Interval(given.start,given.end));			// Push the given interval.
                    res.push_back(v[i]);											// Push the curr. scanning interval.
                }
                else
                    res.push_back(v[i]);											// Push the curr. scanning interval.
            }
            
        }
         
        // for(auto it: res)
        //     cout<<"start: "<<it.start<<" and end: "<<it.end<<endl;
        
        if(index>=0){																// Update the overlapping inter. start and end values.
            res[index].start=given.start; 
            res[index].end=given.end;
        }
        else if(index==-1) res.push_back(*new Interval(given.start, given.end));	// If any inter. not pushed, then it's that given inter.'s 
																					//	start> all edges in the vector. 		
        // for(auto it: res)
        //     cout<<"start: "<<it.start<<" and end: "<<it.end<<endl;
        
        return res;																	// Returning the Final state of intervals.
    }
};