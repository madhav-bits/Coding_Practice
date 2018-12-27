/*
*
//****************************************************************715. Range Module.*********************************************************

A Range Module is a module that tracks ranges of numbers. Your task is to design and implement the following interfaces in an efficient manner.

addRange(int left, int right) Adds the half-open interval [left, right), tracking every real number in that interval. Adding an interval that 
partially overlaps with currently tracked numbers should add any numbers in the interval [left, right) that are not already tracked.
queryRange(int left, int right) Returns true if and only if every real number in the interval [left, right) is currently being tracked.
removeRange(int left, int right) Stops tracking every real number currently being tracked in the interval [left, right).
Example 1:
addRange(10, 20): null
removeRange(14, 16): null
queryRange(10, 14): true (Every number in [10, 14) is being tracked)
queryRange(13, 15): false (Numbers like 14, 14.03, 14.17 in [13, 15) are not being tracked)
queryRange(16, 17): true (The number 16 in [16, 17) is still being tracked, despite the remove operation)
Note:

A half open interval [left, right) denotes all real numbers left <= x < right.
0 < left < right < 10^9 in all calls to addRange, queryRange, removeRange.
The total number of calls to addRange in a single test case is at most 1000.
The total number of calls to queryRange in a single test case is at most 5000.
The total number of calls to removeRange in a single test case is at most 1000.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



["RangeModule","addRange","addRange","removeRange","queryRange","addRange","queryRange"]
[[],[10,20],[24,30],[14,16],[10,14],[8,9],[16,17]]



["RangeModule","addRange","removeRange","queryRange","addRange","queryRange"]
[[],[10,20],[14,16],[10,14],[8,9],[16,17]]



// Time Complexity: O(logn).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logn).
// Space Complexity: O(n).	
// This algorithm is HashMap based. Here, we form the intervals as hashmap entries. Once, a new interval is added, we call removeRange fn. 
// to remove all removable interval in the newly added range from already existing intervals. Once, deleted, we create a new interval from 
// [left, right) and join it to it's adjacent intervals if touching. While querying we will find the interval the curr. interval might be by
// upper_bound and check if the req. intervals is contained in that interval or not?






// The algorithm is explained here in the link:
// https://leetcode.com/problems/range-module/discuss/156284/C++-using-map-O(log-N)-per-operation


// A similar algo. with good explanation is given here.
// https://leetcode.com/problems/range-module/discuss/108923/C++-O(nlogn)-based-on-disjoint-intervals-data-structure








class RangeModule {
public:
    map<int,int>m;															// Map to store intervals, where [key,value] are both ends of intervals.
    RangeModule() {
        m=map<int,int>();
    }
    
    void addRange(int left, int right) {
        removeRange(left, right);											// Remove the already existing intevals with overlapping part.
        m[left]=right;														// Create a new interval with this range.
        auto it=m.find(left);												// Find the interval.
        if(it != m.begin() && prev(it)->second == left){					// We check curr. interval touches prev. interval.
            it--;
            it->second=right;												// If touches, make curr. intervals's right prev. interval's right.
            m.erase(left);													// Delete curr.(newly created) interval.
        }
        if(it!=prev(m.end())  && next(it)->first==right){					// We check if curr. interval touches next interval.
            it->second=next(it)->second;									// If touches, make next interval's right curr. interval's right.
            m.erase(next(it));												// Delete next interval.
        }
    }
    
    bool queryRange(int left, int right) {
        auto it=m.upper_bound(left);										// Finds interval with greater start value than required start.
        if(m.empty() || it==m.begin()) return false;						// If prev. interval doesn't exist, return false.
        it--;
        return (it->second>=right);											// If curr. interval's right is >=req. interval's right, return true.
    }
    
    void removeRange(int left, int right) {
        if(m.empty()) return ;
        auto it=m.lower_bound(left);										// Moving to interval with start>req. start.
        if(it!=m.begin()) it--;												// If smaller interval exists, we move to it.
        vector<int>v;														// Stores all deletable nodes.
        while(it!=m.end() && it->first<right){								// Iter. all intevals till we reach end of overlap.
            if(it->first<left && it->second>left){							// This is when deletable interval is inside another interval.
                int temp=it->second;										
                it->second=left;											// Form interval from prev. interval start to deletable interval's start.
                if(temp>right)												// Form interval from deleted interval's right to curr. interval's right.
                    m[right]=temp;
            }else if(it->first>=left){										// All intervals whose starts are in deleting range.
                v.push_back(it->first);										// Store completely overlapped intervals to delete them later.
                if(it->second>right){										// The last overlapping(partially) inteval with deleting range.
                    m[right]=it->second;									// Form new interval from deleting right to curr. intervals' right.
                }
            }
            it++;
        }
        for(auto num:v) m.erase(num);										// Removing all the deletable intervals.
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule obj = new RangeModule();
 * obj.addRange(left,right);
 * bool param_2 = obj.queryRange(left,right);
 * obj.removeRange(left,right);
 */