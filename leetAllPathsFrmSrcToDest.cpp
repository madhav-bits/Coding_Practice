/*
*
//********************************************************797. All Paths From Source to Target.*************************************************

Given a directed, acyclic graph of N nodes.  Find all possible paths from node 0 to node N-1, and return them in any order.

The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  graph[i] is a list of all nodes j for which the edge (i, j) exists.

Example:
Input: [[1,2], [3], [3], []] 
Output: [[0,1,3],[0,2,3]] 
Explanation: The graph looks like this:
0--->1
|    |
v    v
2--->3
There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
Note:

The number of nodes in the graph will be in the range [2, 15].
You can print different paths in any order, but you should keep the order of nodes inside one path.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


// Don't remember the test cases used.

// Time Complexity: O(n^2).  
// Space Complexity: O(n^2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n^2).	
// This algorithm is DFS Oriented. Starting from the source node, we iterate all possible paths and check taget node is reached or not. If we
// reached we push the path travelled till now into result vector of vectors. As it's an acyclic graph, no need to worry about cycles being
// formed.




class Solution {
public:
    //vector<vector<int>> v;
    void findPaths(vector<vector<int>> &v, vector<vector<int>> u, int node, vector<int> path){
        path.push_back(node);												// Pushing the curr. node into path vector.
        if(node ==u.size()-1){ 												// Once dest. is reached, push it into final result vector of vectors.
            v.push_back(path);
            return ;
        }
        for(int i=0;i<u[node].size();i++)									// Iterating in all drns from the curr. node.
            findPaths(v, u,u[node][i],path);
        
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& u) {
        vector<vector<int>> v;												// To store all paths.
        vector<int> path;													// Tracks curr. path we are iterating.
        path.push_back(0);
        for(int i=0;i<u[0].size();i++)										// Iterate in all drns starting from adj. nodes of src node.
            findPaths(v, u, u[0][i],path);
        
        return v;															// Returning all possible paths from src to node.
    }
};