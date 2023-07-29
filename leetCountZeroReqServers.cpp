/*
*
//******************************************************2747. Count Zero Request Servers.******************************************************

https://leetcode.com/problems/count-zero-request-servers/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


3
[[1,3],[2,6],[1,5]]
5
[10,11]
3
[[2,4],[2,1],[1,2],[3,1]]
2
[3,4]
9
[[5,2],[3,1],[4,2],[4,3],[6,1],[8,10],[6,12],[7,2],[5,1],[3,2]]
4
[5,6,7,5,9,10,20,24,20,28,22]



// Time Complexity: O(nlogn+mlogm+m+n+l)=O(mlogm+nlogn).					// m-#queries, n-#logs, l-#servers.
// Space Complexity: O(m+l).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn+mlogm+m+n+l)=O(mlogm+nlogn).					// m-#queries, n-#logs, l-#servers.
// Space Complexity: O(m+l).	
// This algorithm is Sorting+Iteration based. We sort the queries, logs based on time, as we need queries orig. indices, we pair queries with their indices and sort them. We
// iter. over queries, for each query we take in all logs which are <curr. query time and pop out all logs which are <(curr. query-x) time. While taking and popping, we track 
// #times each server had been taken in and popped out and we make sure to count all the servers which are inside the [query-x, query] window once. We push the remServerCount 
// to curr. query's orig. index in res array. Similarly we process all the queries and we return res at the end of iter.







class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        vector<int>res(queries.size(), 0);
        vector<pair<int,int>>v;
        for(int i=0;i<queries.size();i++) v.push_back({queries[i], i});
        sort(logs.begin(), logs.end(), [](vector<int>&lt, vector<int>&rt) {	// Sort logs based on time.
            return lt[1]<rt[1];
        });
        sort(v.begin(), v.end());											// Sort queries based on time.
        int occur[n+1];
        memset(occur, 0, sizeof(occur));
        int i=0, j=0, uniqSignalCount=0;
        for(int k=0;k<v.size();k++) {										// Iter. over all queries.
            while(i<logs.size() && logs[i][1]<=v[k].first) {				// We take in/Count all logs which are<=query.
                if(occur[logs[i][0]]++==0) uniqSignalCount++;				// If this is first occur. of this server, we count it in and track #unique servers in the window.
                i++;
            }
            while(j<logs.size() && logs[j][1]<v[k].first-x) {				// We pop out logs which are<(query-x).
                if(--occur[logs[j][0]]==0) uniqSignalCount--;				// If this is last occur. of this server, we count it out.
                j++;
            }
            res[v[k].second]=n-uniqSignalCount;								// Updating the res array with #servers with no request in the query window.
        } 
        return res;															// Returning array with #servers with no req. for each of the given queries.
    }
};

