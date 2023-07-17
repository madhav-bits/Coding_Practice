/*
*
//*********************************2316. Count Unreachable Pairs of Nodes in an Undirected Graph.************************************

https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


3
[[0,1],[0,2],[1,2]]
7
[[0,2],[0,5],[2,4],[1,6],[5,4]]
17
[[0,1],[0,2],[3,4],[3,5],[3,6],[7,8],[7,9],[7,10],[10,11]]




// Time Complexity: O(n+m).													// n-#nodes in the graph, m-#edges in the graph.
// Space Complexity: O(n+m).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n+m).													// n-#nodes in the graph, m-#edges in the graph.
// Space Complexity: O(n+m).	
// This algorithm is DFS based. We first form Adjacency Matrix based on the edges provided. We do DFS on the graph, each time we start DFS call we mark them 
// visited and cnt #nodes in it, indicating that these nodes can be interreachable. We multiply the #nodes in this group with total #nodes in all prev. grps,
// all the nodes in this group can't reach each of the nodes in all prev. groups. We do this multiplication every time we get #nodes from DFS function thus
// we cover all possible pairs of non-interreachable nodes.


// This problem can also be solved using Union-Find method.




class Solution {
public:
    
    int iterateGraph(vector<vector<int>>&graph, int node, vector<bool>&visited) {// DFS call to visit all interreachable nodes and mark them visited.
        int res=1;
        visited[node]=true;
        for(int adj: graph[node]) {
            if(visited[adj]) continue;
            res+=iterateGraph(graph, adj, visited);
        }
        return res;															// Returning #nodes in this group.
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long int res=0, unconnected=0;
        vector<vector<int>>graph(n);
        for(vector<int>&v:edges) {											// Forming Adjacency Matrix for the graph.
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }
        vector<bool>visited(n, false);
        for(int i=0;i<n;i++) {
            if(visited[i]) continue;
            int currGroup=iterateGraph(graph, i, visited);
            res=res+currGroup*unconnected;									// Each node in curr. group forming pairs with each node in all prev. groups.
            unconnected+=currGroup;											// Inc. the #nodes in prev. groups count.
        }
        return res;															// Returning the total #non-interreachable node pairs.
    }
};

