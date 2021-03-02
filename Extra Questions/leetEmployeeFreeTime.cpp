/*
*
//**********************************************************759. Employee Free Time.***************************************************

https://leetcode.com/problems/employee-free-time/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[[1,2],[5,6]],[[1,3]],[[4,10]]]
[[[1,3],[6,7]],[[2,4]],[[2,5],[9,12]]]



// Time Complexity: O(mlogn).												// m-total #time slots for all employees, n- total #employees.
// Space Complexity: O(n).	


//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(mlogn).												// m-total #time slots for all employees, n- total #employees.
// Space Complexity: O(n).	
// This algorithm is Priority Queue and Custom Sorting based. Here, as we want time slots in which everyone if free, we iterate over the sorted slots,
// If we find a gap between curr. interval and prev. interval which is a result of overlapping intervals, we take this interval as all employees are 
// free in this interval. Since, we have to comapre slots of all employees and pick the minm. start slot, we push least intervals of all employees into 
// PQ, we extract least interval every time.








/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
}
*/

class Solution {
public:
    
    struct comp{
        bool operator()(Interval lt, Interval rt){
            return lt.start<=rt.start;
        }    
    };
    
    struct Data{
        int row, col;
        
        Data(int x, int y){
            row=x;
            col=y;
        }
    };
    
    vector<Interval> employeeFreeTime(vector<vector<Interval>> u) {
        auto comp=[&u](Data lt, Data rt){									// Defining custom comparator for Priority Queue.
            return u[lt.row][lt.col].start>=u[rt.row][rt.col].start;		// Time slot with minm. start time stays on top of PQ.
        };
        priority_queue<Data,vector<Data>,decltype(comp)>pq(comp);
        int maxEnd=INT_MAX;
        for(int i=0;i<u.size();i++){
            pq.push(Data(i,0));
            maxEnd=min(maxEnd, u[i][0].start);								// Getting end of prev. overlap of intervals(Setting sensible value).
        }
        vector<Interval>res;
        while(!pq.empty()){
            Data curr=pq.top();
            pq.pop();
            if(maxEnd<u[curr.row][curr.col].start){							// No overlap b/w prev. overlap and curr. interval.
                res.push_back(Interval(maxEnd,u[curr.row][curr.col].start));
                maxEnd=u[curr.row][curr.col].end;
            }else maxEnd=max(maxEnd, u[curr.row][curr.col].end);			// Maximize end of prev. overlap of intervals.
            if(curr.col+1<u[curr.row].size()) pq.push(Data(curr.row, curr.col+1));// If next time slot exists for curr. employee, push into PQ.
        }
        return res;															// Return all employees free time slots.
    }
};














//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(mlogm).												// m-total #time slots for all employees, n- total #employees.
// Space Complexity: O(m).	
// This algorithm is Sorting based. We have a entry for both entry, exit into new array, we maintain a var which keeps track of #time slots which are 
// yet opened. If all opened intervals are closed and there is a gap b/w prev. end of overlapping intervals and curr. intervals, we push the gap into 
// result. This way we gather all employees common free time slots.








/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
}
*/

class Solution {
public:
    
    struct comp{															
        bool operator()(Interval lt, Interval rt){
            return lt.start<=rt.start;
        }    
    };
    
    vector<Interval> employeeFreeTime(vector<vector<Interval>> u) {
        // vector<Interval>v;
        vector<vector<int>>v;
        for(int i=0;i<u.size();i++){
            for(int j=0;j<u[i].size();j++){
                v.push_back({u[i][j].start,1}); //v.push_back(u[i][j]);
                v.push_back({u[i][j].end,-1});
            }
        }
        // sort(v.begin(), v.end(), comp());
        sort(v.begin(), v.end());											// Sorting based on start, end values.
        vector<Interval>res;
        // Interval curr=v[0];
        int open=0, prev=0;
        for(int i=0;i<v.size();i++){
            // if(curr.end<v[i].start){
            //     curr.start=curr.end;
            //     curr.end=v[i].start;
            //     res.push_back(curr);
            //     curr=v[i];
            // }else curr.end=max(curr.end, v[i].end);
            if(open==0 && prev && prev<v[i][0]){
                res.push_back(Interval(prev,v[i][0]));
            }
            open+=v[i][1];
            if(open==0) prev=v[i][0];
        }
        return res;
    }
};

