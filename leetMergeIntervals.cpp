/*

//**********************************************************56. Merge Intervals.*****************************************************

Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].

// Examples cases I had worked on.
//[[1,3],[3,6],[8,10],[15,18], [2,4], [89,345]]

//Time Complexity: O(nlogn).
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************
*/



// Solution 1: 
// The idea is to Sort all intervals in inc. order of start. Merge those intervals which overlap, if not overlap then create a new temp. interval-
//- for comparing Intervals following it.

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
    static bool comparator(Interval a, Interval b){
        if(a.start<b.start)
            return 1;
        else
            return 0;
    }
	
    vector<Interval> merge(vector<Interval>& v) {
        vector<Interval> u;
        if(v.size()==0)
            return u;
        sort(v.begin(), v.end(), comparator);			//Sorting intervals based on their start time.
        //for(const auto& num: v)
        //    cout<<"start is: "<<num.start<<" and end is: "<<num.end<<endl;
        Interval* a=new Interval();						// Temporary Interval variable used in comparing whether intervals overlapped or not.
        a->start=v[0].start; a->end=v[0].end;
        //u.push_back(*a);
        for(int i=1;i<v.size();i++){
            if(v[i].start <= a->end && v[i].start >= a->start)// If Intervals overlap, updating the end pt. of Joint Interval.
                a->end=max(a->end, v[i].end);
            else{												// In case of no overlap, push the earlier one into Interval array.
                u.push_back(*a);								// Push the Interval value into temp. variable, for comparing following Intervals.
                a->start=v[i].start; a->end=v[i].end;
            }
        }
        u.push_back(*a);										// Pushing the last unpushed Interval.
        return u;												//Returning the array of intervals.
    }
};