/*
*
//******************************************************797. All Paths From Source to Target.***********************************************

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

[[1,2],[3],[3],[]]
[[1,2],[4],[1,3],[1,4],[]]




// Time Complexity: O(n!).  
// Space Complexity: O(n*n!).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n!).	
// Space Complexity: O(n*n!).	
// This algorithm is Depth First Search can also be done using BFS(needs slightly tweaked version, we push path till that node(adj) from source 
//node in Queue, instead the adj. node. In DFS, we start travelling from source node, thorugh it's adj nodes, for each adj. node, we travel in it's 
// adj. nodes recursively(Depth wise). Once, we reach the dest. node, we push the path from source node to that node in the result vector.

// ***************************************************************OBSERVATION:***************************************************************
// In discussion, I had observed, that few slns, mark whether a node is travelled or not in the curr. path. But, in the question, it's mentioned
// that it's  acyclic graph. So, there won't be any cirlce in a path. So, need to maintained a visited array.




class Solution {
public:
    //vector<vector<int>> v;
    void findPaths(vector<vector<int>> &v, vector<vector<int>> u, int node, vector<int> path){
        path.push_back(node);										// Pushing the curr. node into path vector.
        if(node ==u.size()-1){ 
            v.push_back(path);										// If, desti. node reached, then push path into final ans.
            return ;
        }
        for(int i=0;i<u[node].size();i++)
            findPaths(v, u,u[node][i],path);						// Travelling in it's adj. nodes.
        
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& u) {
        vector<vector<int>> v;										// Which stores all the possible paths.
        vector<int> path;											// Which stores path.
        path.push_back(0);											// As, we start from source node, that's part of path.
        for(int i=0;i<u[0].size();i++)
            findPaths(v, u, u[0][i],path);							// Travelling the adj. nodes.
        
        return v;													// Return all possible paths from source node to dest. node.
    }
};