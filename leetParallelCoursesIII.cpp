/*
*
//******************************************************2050. Parallel Courses III.******************************************************

https://leetcode.com/problems/parallel-courses-iii/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


3
[[1,3],[2,3]]
[3,2,5]
5
[[1,5],[2,5],[3,5],[3,4],[4,5]]
[1,2,3,4,5]



// Time Complexity: O(nodes+edges).
// Space Complexity: O(nodes+edges).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nodes+edges).
// Space Complexity: O(nodes+edges).	
// This algorithm is Topological Sorting based. Here, as we do a course once all pre reqs are done, which depends on the pre-req which takes max time from 
// start to finish as by that time rest all pre-reqs would be already finished. We store this max time as the time to reach the curr. node and add it to Queue.
// We continue the process, in this way we are storing max. time to reach every node and and updating res with the max of max. time of each node and return the 
// res at the end of process. This is for the BFS version of the Topological Sort.


// Here, the paths we consider brings the max. time to finish all pre-reqs before starting a ndoe and since we are tracking max. finish time so that all nodes 
// or courses are covered. For us to get max total time required, we also take max. time to finish all child courses of every node. We use this and approach the 
// problem in reverse, we do DFS and for every node we calc. max time to finish all it's child nodes, and return the max time add curr. course cost and update
// dp array so that it's parent can use this max total. It won't affect our final res cause, for every node of our RES path the RES path would provide max.
// from parents and child, so if we just pass the max total from the child nodes at every node this max total would >rest paths and get selected and we can 
// update RES path cost by taking max path to reach all nodes and return res at the end of process.







class Solution {
public:
    
    void dfsTopology(vector<vector<int>>&graph, int node, vector<int>&maxCost, vector<int>&time) {// Gets max time to finish all child nodes.
        if(maxCost[node]!=-1) return ;
        int maxm=0;
        for(int child: graph[node]) {
            if(maxCost[child]==-1) dfsTopology(graph, child, maxCost, time);
            if(maxCost[child]>maxm) maxm=maxCost[child];
        }
        maxCost[node]=maxm+time[node];										// Add curr. node cost and update dp array so that parents can use.
        return ;
    }
    
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int>maxCost(n,-1);
        vector<vector<int>>graph(n);
        int res=-1;
        for(vector<int>&rel:relations) {
            graph[rel[0]-1].push_back(rel[1]-1);							// Forming the Adjacency List.
        }
        for(int i=0;i<n;i++) {												// DFS cover all nodes and child nodes.
            if(maxCost[i]==-1) dfsTopology(graph, i, maxCost, time);		// Visit unvisited nodes.
            if(maxCost[i]>res) res=maxCost[i];								// Track max Cost/time to finish curr.+child nodes.
        }
        return res;															// Returning max cost/time to finish all courses.
    }
};

