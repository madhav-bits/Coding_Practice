/*
*
//**********************************************************Path in Directed Graph.***************************************************

https://www.interviewbit.com/problems/path-in-directed-graph/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.



5
6 2 1 2 4 1 2 4 3 4 5 2 1 3

5
4 2 1 2 2 3 3 4 4 5




// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is DFS based. Here, we are using bool array to make sure nodes are more than once by marking visited nodes. We start DFS from 1 and 
// traverse through the graph, if we encounter A, we return 1, if not we traverse through other connected nodes to curr. node. In this way we cover all
// reachable nodes from 1. If we aren't able to reach node A, we return 0.










int findNode(vector<vector<int>>&graph, int currNode, vector<bool>&visited){
    if(currNode==visited.size()-1) return 1;								// If node A is reached, return 1.
    visited[currNode]=true;
    for(int adj:graph[currNode]){
        if(visited[adj]==true) continue;									// Prevents duplicate visits to node.
        if(findNode(graph, adj, visited)==1) return 1;						// Traverse through unvisited connected nodes.
    }
    return 0;																// If A can't be reached through this node, return 0.
}

int Solution::solve(int A, vector<vector<int> > &v) {
    vector<vector<int>>graph(A+1);
    for(int i=0;i<v.size();i++){											// Creating Adj. list for the graph.
        graph[v[i][0]].push_back(v[i][1]);
    }
    vector<bool>visited(A+1, false);										// Keeps track of visited nodes.
    return findNode(graph, 1, visited);										// Starting graph traversal from node-1.
}

