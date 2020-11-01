/*
*
//****************************************1353. Maximum Number of Events That Can Be Attended.*******************************************

1353. Maximum Number of Events That Can Be Attended


*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


Worked on test cases provided with the question.
[[1,2],[2,3],[3,4]]
[[1,2],[2,3],[3,4],[1,2]]
[[1,4],[4,4],[2,2],[3,4],[1,1]]
[[1,100000]]
[[1,1],[1,2],[1,3],[1,4],[1,5],[1,6],[1,7]]



// Time Complexity: O(k+nlogn).												// k- all possible times, n-#events.
// Space Complexity: O(n).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(k+nlogn).												// k- all possible times, n-#events.
// Space Complexity: O(n).	
// This algorithm is Sorting and Priority Queue based. Here, we sort events based on start times, we iter. over all possible times. 
// At each time, we store all events which start at that time. We pop out all events which end time is already finished, we count
// one of the rest events towards our result and pop it. Thus, we are counting all possibly available events at every possible time.








class Solution {
public:
    int maxEvents(vector<vector<int>>& u) {
        int res=0, open=0;
        sort(u.begin(), u.end());
        priority_queue<int, vector<int>, greater<int>>pq;					// Stores end times of current open events.
        int j=0;
        for(int i=1;i<=100000;i++){											// Iter. over all possible start times.
            while(!pq.empty() && pq.top()<i) pq.pop();						// Pop out all closed events.
            while(j<u.size() && u[j][0]==i)									// Store all events which start now.
                pq.push(u[j++][1]);
            if(!pq.empty()){												// If an event is not closed till now, cnt towards res.
                res++;
                pq.pop();
            }
            
        }
        return res;															// Returning attended events count.
    }
};
               
			   
			   
			   
			   
			   
			   
			   
			   
//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).												// n-#events.
// Space Complexity: O(n).			   
// This algorithm is Sorting and Priority Queue based. Here, we sort based on start times. We iter. over event's start times, we iter.
// over gap's between start times and count every possible every at a time towards res. Pop out events which are finished by then. If
// available. We take in events which are starting at psn time.
			   
			   
			   
			   
			   
			   
			   
class Solution {
public:
    int maxEvents(vector<vector<int>>& u) {
        int res=0, open=0;
        sort(u.begin(), u.end());
        priority_queue<int, vector<int>, greater<int>>pq;
        int psn=-1, j=0;
        while(!pq.empty() || j<u.size()){
            if(pq.size()==0)												// If no events avail. we jumpt to next avail. start time.
                psn=u[j][0];
            while(j<u.size() && u[j][0]==psn)								// Takes events which start at psn.
                pq.push(u[j++][1]);
            ++res;
            psn++;
            pq.pop();														// Counting avail. event towards res.
            while(!pq.empty() && pq.top()<psn)								// Pop events which are finished by then.
                pq.pop();
        }
        return res;															// Returns cnt of attended events.
    }
};
               