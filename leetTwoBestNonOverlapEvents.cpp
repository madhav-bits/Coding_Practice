/*
*
//******************************************************2054. Two Best Non-Overlapping Events.******************************************************

https://leetcode.com/problems/two-best-non-overlapping-events/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[1,3,2],[4,5,2],[2,4,3]]
[[1,3,2],[4,5,2],[1,5,5]]
[[1,5,3],[1,5,1],[6,6,5]]
[[66,97,90],[98,98,68],[38,49,63],[91,100,42],[92,100,22],[1,77,50],[64,72,97]]



// Time Complexity: O(nlogn).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(n).	
// This algorithm is Sorting+Priority Queue based. Here, we sort the intervals based on start values. As,we iter. over array, we collect interval end values in PQ, when we are 
// at 'i', we pop all interval close values<curr. interval start and track the max. interval value, we add this max. interval value with curr. interval value and track the 
// maxm. sum. We add curr. interval close value also into PQ and we move to next index. If we didnt' any prev. interval close<curr. interval start, we use 0 value, indicating
// we only used the curr. interval value and tracked max. sum.(This works as we can pick ATMOST two intervals). We return max. sum at the end of iter.







class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& v) {
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        sort(v.begin(),v.end());
        int res=0, maxm=0;
        for(vector<int>&u:v) {
            while(!pq.empty() && pq.top().first<u[0]) {						// We pop intervals whose close<curr. start.
                if(pq.top().second>maxm) maxm=pq.top().second;				// Tracking max. value of those intervals.
                pq.pop();
            }
            pq.push({u[1], u[2]});											// Adding curr. close to PQ.
            if(maxm+u[2]>res) res=maxm+u[2];								// Tracking max. sum of values of two non-overlap intervals.
        }
        return res;															// Returning max. sum of values of two non-overlapping intervals.
    }
};












//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(n).	
// This solution is Sorting based. Here, instead of using PQ to track intervals with start>curr. close,we iter. in reverse order and keep updating dp array with max. value of
// all intervals from here to end in dp[i], when at 'i', we find the least index where interval start>curr. close and get max. value of intervals from here to end and add it 
// with curr. interval value and track max. sum. We also update dp[i] with dp[i+1] and curr. interval value which can be used by intervals lower start values. We return res at 
// the end of iter.







class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& v) {
        sort(v.begin(),v.end());
        vector<int>u;
        for(vector<int>&m:v) u.push_back(m[0]);								// Collect interval start values for easier binary search on interval starts.
        vector<int>dp(v.size(),v.back()[2]);								// Stores max. interval value from [i, v.size()] in dp[i].
        int res=v.back()[2];
        for(int i=v.size()-2;i>=0;i--) {
            auto it=upper_bound(u.begin(), u.end(), v[i][1]);				// Least index with start>curr. close.
            int val=(it==u.end())?0:dp[it-u.begin()];						// Get max. interval value with start>curr. close.
            if(val+v[i][2]>res) res=val+v[i][2];							// Tracking sum of interval values.
            dp[i]=max(dp[i+1], v[i][2]);									// Updating max. interval value from [i, v.size()] in dp[i].
        }
        return res;															// Returning max. sum of values of two non-overlapping intervals.
    }
};

