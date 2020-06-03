/*
*
//******************************************************1462. Course Schedule IV.***********************************************

https://leetcode.com/problems/course-schedule-iv/description/


There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have direct prerequisites, for example, to take course 0 you have first to take course 1, which is expressed as a 
pair: [1,0]

Given the total number of courses n, a list of direct prerequisite pairs and a list of queries pairs.

You should answer for each queries[i] whether the course queries[i][0] is a prerequisite of the course queries[i][1] or not.

Return a list of boolean, the answers to the given queries.

Please note that if course a is a prerequisite of course b and course b is a prerequisite of course c, then, course a is a 
prerequisite of course c.

 

Example 1:


Input: n = 2, prerequisites = [[1,0]], queries = [[0,1],[1,0]]
Output: [false,true]
Explanation: course 0 is not a prerequisite of course 1 but the opposite is true.
Example 2:

Input: n = 2, prerequisites = [], queries = [[1,0],[0,1]]
Output: [false,false]
Explanation: There are no prerequisites and each course is independent.
Example 3:


Input: n = 3, prerequisites = [[1,2],[1,0],[2,0]], queries = [[1,0],[1,2]]
Output: [true,true]
Example 4:

Input: n = 3, prerequisites = [[1,0],[2,0]], queries = [[0,1],[2,0]]
Output: [false,true]
Example 5:

Input: n = 5, prerequisites = [[0,1],[1,2],[2,3],[3,4]], queries = [[0,4],[4,0],[1,3],[3,0]]
Output: [true,false,true,false]
 

Constraints:

2 <= n <= 100
0 <= prerequisite.length <= (n * (n - 1) / 2)
0 <= prerequisite[i][0], prerequisite[i][1] < n
prerequisite[i][0] != prerequisite[i][1]
The prerequisites graph has no cycles.
The prerequisites graph has no repeated edges.
1 <= queries.length <= 10^4
queries[i][0] != queries[i][1]




*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


2
[[1,0]]
[[0,1],[1,0]]


2
[]
[[1,0],[0,1]]


3
[[1,2],[1,0],[2,0]]
[[1,0],[1,2]]



3
[[1,0],[2,0]]
[[0,1],[2,0]]



5
[[0,1],[1,2],[2,3],[3,4]]
[[0,4],[4,0],[1,3],[3,0]]




// Time Complexity: O(n^3).													// n- number of nodes in the graph.
// Space Complexity: O(n^2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^3).													// n- number of nodes in the graph.
// Space Complexity: O(n^2).	
// This algorithm is Floyd Warshall algorithm. Here, we have to find the pre-req gap between the nodes/courses in the queries. So, we
// build a graph based on pre-reqs, if we have a directed edge from a->b, it means a is a pre-req to b, and each edge is assigned a 
// value of 1. As they are many queries where each one inquiring about subpath of a prev. query, a good way to keep track of all path
// lengths is a 2D Matrix. So, we run Floyd Warshall and store dist. b/w all pair of nodes. If there is no path b/w two nodes, then
// the dist. is maxm #nodes possible.







class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        vector<vector<int>>dist(n, vector<int>(n,100));						// Init. the 2D matrix.
        for(int i=0;i<pre.size();i++){										// Including the given edges.
            int node1=pre[i][0], node2=pre[i][1];
            dist[node1][node2]=1;
        }
        for(int i=0;i<n;i++) dist[i][i]=0;									// Base Cases.
        for(int k=0;k<n;k++){												// Floyd Warshall algorithm.
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][j]>dist[i][k]+dist[k][j])
                        dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
        vector<bool>res;													// Store results for all queries.
        for(int i=0;i<queries.size();i++){									// Iter. over queries.
            int node1=queries[i][0], node2=queries[i][1];
            if(dist[node1][node2]==100) res.push_back(false);				// If no path exists, store false.
            else res.push_back(true);										// If path exists, store true.
        }
        return res;															// Return result array.
    }
};
