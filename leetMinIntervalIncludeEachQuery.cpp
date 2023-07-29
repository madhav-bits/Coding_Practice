/*
*
//*******************************************1851. Minimum Interval to Include Each Query.*********************************************

https://leetcode.com/problems/minimum-interval-to-include-each-query/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[1,4],[2,4],[3,6],[4,4]]
[2,3,4,5]
[[2,3],[2,5],[1,8],[20,25]]
[2,19,5,22]
[[2,3],[2,5],[10,15],[11,14],[16,17],[22,22],[20,25],[1,8],[20,25]]
[2,19,5,20,22,45,19,18,21,20,14,12,15]



// Time Complexity: O(m+n+nlogn+mlogm).											// n-#intervals, m-#queries.
// Space Complexity: O(m).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m+n+nlogn+mlogm).											// n-#intervals, m-#queries.
// Space Complexity: O(m).	
// This algorithm is Priority Queue based. Here, we first sort the given queries, intervals for processing. We iter. over query, and over intervals internally. For each query,
// we include we iter. over intervals and include which start before curr. query and overlap with it. We pop out all intervals from PQ which had closed before curr. query, so 
// now the PQ top entry is a interval which overlaps the curr. query and it has the least interval length, so we add this length to res based on curr. query's orig. psn else
// we put -1. We return res after processsing all queries.








class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int>res(queries.size(), -1);
        vector<pair<int,int>>u;
        for(int i=0;i<queries.size();i++) u.push_back({queries[i], i});		// Pair {query, i} as we need index while filling res array with interval lengths.
        sort(intervals.begin(), intervals.end());							// Sort intervals, queries in inc. order.
        sort(u.begin(), u.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>minPq;// {interval length, interval close}
        int j=0;
        for(int i=0;i<u.size();i++) {
            while(j<intervals.size() && intervals[j][0]<=u[i].first) {		// Add all intervals which overlaps with curr. query.
                if(intervals[j][1]>=u[i].first)								// Considers only overlapping intervals.
                    minPq.push({intervals[j][1]-intervals[j][0]+1, intervals[j][1]});
                j++;
            }
            while(!minPq.empty() && minPq.top().second<u[i].first) minPq.pop();// Pop intervals which completed before curr. query.
            if(!minPq.empty()) res[u[i].second]=minPq.top().first;			// If overlapping intervals exist, place the PQ top's length in res array's query's orig. index.
        }
        
        return res;															// Returning array with min. intervals which includes each query.
    }
};

