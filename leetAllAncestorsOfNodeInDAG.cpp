/*
*
//*****************************************2192. All Ancestors of a Node in a Directed Acyclic Graph.**************************************

https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


8
[[0,3],[0,4],[1,3],[2,4],[2,7],[3,5],[3,6],[3,7],[4,6]]
5
[[0,1],[0,2],[0,3],[0,4],[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]



// Time Complexity: O(n*(n+m))=(n^3).										// n-#nodes in the graph, m=(n^2)-#edges in the graph.
// Space Complexity: O(n+m).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*(n+m))=(n^3).										// n-#nodes in the graph, m=(n^2)-#edges in the graph.
// Space Complexity: O(n+m).	
// This algorithm is DFS based. Rather than starting DFS from nodes and storing parents in a temp list and add adding them to map in each of the child, we do
// DFS starting from each of the node where  we fill start node in the list of parents of all it's children. We avoid duplicate visiting of nodes in DFS by 
// checking last appended value in res[node], as in a DFS we append same root value in all visited nodes, if we see the root value in a list of a node, that 
// means this node is already visited and we skip that node. In this way in each iter. every node is visited only once.







class Solution {
public:
    
    void dfs(vector<vector<int>>&graph, int node, int root, vector<vector<int>>&res) {
        for(int child:graph[node]) {
            if(!res[child].empty() &&  res[child].back()==root) continue;	// Avoids revisiting the nodes already visited in this DFS with same root node.
            res[child].push_back(root);										// Adding DFS start node as parent for all it's children.
            dfs(graph, child, root, res);									// DFS call given to children.
        }    
        return ;
    }
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>res(n), graph(n);
        for(vector<int>&v:edges) {											// Forming adjacency matrix for the graph.
            graph[v[0]].push_back(v[1]);
        }
        
       for(int i=0;i<n;i++) {	
           dfs(graph, i, i, res);											// Starting DFS from all the nodes.
       }
           
        return res;															// Returning array with parents of each node stored in it's corres. index.
    }
};

