/*
*
//**********************************************************Merge Overlapping Intervals.***************************************************

https://www.interviewbit.com/problems/merge-overlapping-intervals/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


5 1 5 2 4 6 9 7 10 10 14




// Time Complexity: O(nlogn).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(n).	
// This algorithm is Custom sorting based. We first sort the given intervals in the order of their starting values. We then iterate over all
// intervals and merge overlapping intervals into one. We check for overlapping by comparing the start and end of curr. interval with the resulting
// interval. If the curr. interval's start is >resulting interval, we create a new interval of resulting array's values and push the interval
// into final interval array. We init. a new resulting array with the curr. interval's values. If the curr. interval's start>resulting array's close
// and curr. interval's close>resulting array's close, then update the resulting arrray's close and iter. the intervals array. At the end of iter. 
// we also push the final resulting array.








/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
struct comp{																// Sort the given array based on start values of intervals.
    bool operator()(const Interval &a, const Interval&b){					// If starts are equal, sort based on end values(not req. actually).
        return (a.start<b.start||(a.start==b.start && a.end<b.end));
    }
    
}; 


void sortArray(vector<Interval>&v,vector<Interval>&res){
    
    int close=v[0].end,begin=v[0].start;									// Init. the resulting array.
    
    for(int i=1;i<v.size();i++){
        if(close<v[i].start){												// If there is no overlapping b/w curr. and resulting array.
            res.push_back(*(new Interval(begin,close)));					// Push the resulting array into final result array.
            begin=v[i].start; close=v[i].end;								// Init. the new resulting array for following intervals.
        }
        else if(close<v[i].end) close=v[i].end;								// If there is overlap, and curr. close>result close, then update it.
        
    }    
    res.push_back(*(new Interval(begin,close)));							// Push the final resulting interval into final result array.
}

vector<Interval> Solution::merge(vector<Interval> &v) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    sort(v.begin(),v.end(),comp());											// Sort intervals based on starting values.
    //for(auto Inter:v)
    //    cout<<"first: "<<Inter.start<<" and end: "<<Inter.end<<endl;
        
    vector<Interval>res;													// Final result vector.
    sortArray(v,res);														// Calling. fn. to get merged intervals.
    return res;																// Returning the merged intervals.
    
}
