/*
*
//******************************************************352. Data Stream as Disjoint Intervals.***********************************************

Given a data stream input of non-negative integers a1, a2, ..., an, ..., summarize the numbers seen so far as a list of disjoint intervals.

For example, suppose the integers from the data stream are 1, 3, 7, 2, 6, ..., then the summary will be:

[1, 1]
[1, 1], [3, 3]
[1, 1], [3, 3], [7, 7]
[1, 3], [7, 7]
[1, 3], [6, 7]
Follow up:
What if there are lots of merges and the number of disjoint intervals are small compared to the data stream's size?




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



["SummaryRanges","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals"]
[[],[1],[],[-1],[],[7],[],[2],[],[6],[]]





["SummaryRanges","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","addNum","getIntervals"]
[[],[1],[],[-1],[],[7],[],[2],[],[6],[9],[]]




["SummaryRanges","addNum","getIntervals","addNum","addNum","addNum","getIntervals"]
[[],[1],[],[0],[2],[1],[]]



["SummaryRanges","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","addNum","addNum","getIntervals"]
[[],[1],[],[-1],[],[7],[],[2],[],[6],[-3],[-2],[]]



["SummaryRanges","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","addNum","addNum","addNum","getIntervals"]
[[],[1],[],[-1],[],[7],[],[2],[],[6],[-3],[-2],[-2],[]]




// Time Complexity: O(logn).  												// O(logn) for inserting, O(n) for returning vector.
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logn).												// O(logn) for inserting, O(n) for returning vector.
// Space Complexity: O(n).	
// This algorithm is HashMap(Sorted) based. Here, we place the intervals in the Map, where keys are the start of the intervals and values are
// close of the intervals. Whenever a interval is inserted, we first check whether that's start of a interval, if it's we ignore insertion.
// If not we create a new key, with val as key, values. We find the ptr to it, merge it in inside it's left interval if curr. interval overlaps
// or touches it, we also merge the right interval into curr. interval if it touches curr. interval. While returning intervals, we iterate over
// map and push all the intervals into the vector.







/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    map<int,int>m;															// Stores all the intervals.
    SummaryRanges() {
        m=map<int,int>();
    }
    
    void addNum(int val) {
        if(m.size()==0){													// If it's the first interval to be pushed.
            m[val]=val;
            return ;
        }
        auto it=m.upper_bound(val);											// Reaching interval whose start>curr. inteval.
        if(it==m.begin()){													// Edge case, if curr. interval is the leftmost interval.
            m[val]=val;
            it=m.find(val);													// Find ptr to curr. inteval.
            if(val+1==next(it)->first){										// If curr. and next interval touches, merge next into curr. interval.
                m[val]=next(it)->second;
                m.erase(next(it));
            }
            return ;
        }else if(it==m.end()){												// Edge case if curr. interval is the rightmost interval.
            it--;															// Reaching interval whose start<curr. value.
            if(it->second+1==val) it->second=val;							// If val is touching it's right end, merge val into interval.
            else if(it->second+1<val) m[val]=val;							// If val isn't touching interval, then create new interval.
        }else{																// If curr. would be some middle interval.
            it--;															// Reaching interval whose start<curr. value.
            if(it->second>=val) return ;									// If curr. value is already contained in that interval, skip process.
            m[val]=val;
            it=m.find(val);
            if(val<=prev(it)->second+1){									// If val touching right of curr. interval merge it.
                it--;
                it->second=val;
                m.erase(val);												// Remove the newly created interval.
            }
            if(val+1==next(it)->first){										// If inteval whose start>curr. val touches curr. val.
                it->second=next(it)->second;								// Update the curr. interval's right end.
                m.erase(next(it));											// Delete it next interval.
            }
        }
    }
    
    vector<Interval> getIntervals() {
        vector<Interval>v;
        for(auto it=m.begin();it!=m.end();it++){							// Iter. over map and forming vector.
            v.push_back(Interval(it->first, it->second));
        }
        return v;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<Interval> param_2 = obj->getIntervals();
 */
 
 
 
 
 
 
 
 
 
 
 
 //************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logn).												// O(logn) for inserting, O(n) for returning vector.
// Space Complexity: O(n).	
// This algorithm is HashMap(Sorted) based. Here, we place the intervals in the Map, where keys are the start of the intervals and values are
// close of the intervals. Whenever a interval is inserted, we first check whether that's start of a interval, if it's we ignore insertion.
// If not we create a new key, with val as key, values. We find the ptr to it, merge it in inside it's left interval if curr. interval overlaps
// or touches it, we also merge the right interval into curr. interval if it touches curr. interval. While returning intervals, we iterate over
// map and push all the intervals into the vector.


 
 // This algo. is same as above one, except that, it is simplified in adding interval part(Merging left, right interval specifically).
 
 
 
 
 /**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    map<int,int>m;															// Stores all the intervals.
    SummaryRanges() {
        m=map<int,int>();
    }
    
    void addNum(int val) {
        if(m.size()==0){													// If this is the first interval to be pushed.
            m[val]=val;
            return ;
        }
        if(m.count(val)) return ;											// If this val is already start of a interval, skip process.
        m[val]=val;															// Form interval.
        // cout<<"Inserting val: "<<val<<endl;
        auto it=m.find(val);												// Find it's ptr.
        if(it!=m.begin() && prev(it)->second+1>=val){						// If left interval touches/contains curr. val.
            it--;
            it->second=max(it->second, val);								// Update the right end of left interval.
            m.erase(val);													// Delete the newly created interval.
        }
        if(it!=m.end() && val+1==next(it)->first){							// If right interval touches curr. interval.
            it->second=next(it)->second;									// Update the right end of curr. interval.
            m.erase(next(it));												// Delete the right interval.
        }
    }
    
    vector<Interval> getIntervals() {	
        vector<Interval>v;													// Stores all the intervals.
        for(auto it=m.begin();it!=m.end();it++){							// Iter. over map and forming vector.
            v.push_back(Interval(it->first, it->second));
        }
        return v;															// Returning all the intervals.
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<Interval> param_2 = obj->getIntervals();
 */