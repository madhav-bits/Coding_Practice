/*
*
//******************************************************851. Loud and Rich.******************************************************

https://leetcode.com/problems/loud-and-rich/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[1,0],[2,1],[3,1],[3,7],[4,3],[5,3],[6,3]]
[3,2,5,4,6,1,7,0]
[]
[0]



// Time Complexity: O(nodes+edges).  
// Space Complexity: O(nodes+edges).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nodes+edges).
// Space Complexity: O(nodes+edges).	
// This algorithm is DFS based. Here, we first form graphs were edges would from poor->rich person, we iterate from poorer to richer people in DFs, if we 
// are at node 'i', we use DFS to cover all richer people than curr. node and extract the quitest person among them and store in res[adj] and we track the 
// quietest person among them and update res[node] and return from DFS. We avoid revisiting nodes if res[node] is (!=-1), which means it's visiteed already.
// Thus, we visit all nodes and extract quitest richer person when compared to each of the nodes resp.



// The solution is DFS version of Topological Sorting.
// This can also be using BFS version of Topological Sorting, where edge would be from richer persons to relatively poorer persons. We first cover all 
// people richer than curr. poor person and cover all the edges connecting them and update the quietest richer person when compared to poor person before
// pushing it into Queue, thus we cover all nodes.







class Solution {
public:
    
    void dfs(vector<vector<int>>&graph, int node, vector<int>&res, vector<int>&v) {
        if(res[node]!=-1) return;
        int minNode=node;													// Initialize minNode to track quitest richer node.
        for(int& adj: graph[node]) {
            if(res[adj]==-1) dfs(graph, adj, res, v);						// DFS only if adj node is unvisited.
            if(v[res[adj]]<v[minNode]) minNode=res[adj];					// Track the quitest richer node.
        }
        res[node]=minNode;													// Updating res with quitest richer node.
        return ;
    }
    
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int len=quiet.size();
        vector<int>res(len, -1);
        vector<vector<int>>graph(len);
        for(vector<int>&v:richer) graph[v[1]].push_back(v[0]);				// Forming graph with edges from poor->rich.
        for(int i=0;i<len;i++) {											// DFS to find quitest richer node to all nodes.
            dfs(graph, i, res, quiet);
        }
        return res;															// Returning an array with quitest richer node to all nodes resp.
    }
};

