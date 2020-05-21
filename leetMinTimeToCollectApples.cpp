/*
*
//*******************************************1443. Minimum Time to Collect All Apples in a Tree.************************************

https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/description/


Given an undirected tree consisting of n vertices numbered from 0 to n-1, which has some apples in their vertices. You spend 1 
second to walk over one edge of the tree. Return the minimum time in seconds you have to spend in order to collect all apples in 
the tree starting at vertex 0 and coming back to this vertex.

The edges of the undirected tree are given in the array edges, where edges[i] = [fromi, toi] means that exists an edge connecting 
the vertices fromi and toi. Additionally, there is a boolean array hasApple, where hasApple[i] = true means that vertex i has an 
apple, otherwise, it does not have any apple.

 

Example 1:



Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,true,true,false]
Output: 8 
Explanation: The figure above represents the given tree where red vertices have an apple. One optimal path to collect all apples 
is shown by the green arrows.  
Example 2:



Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,false,true,false]
Output: 6
Explanation: The figure above represents the given tree where red vertices have an apple. One optimal path to collect all apples 
is shown by the green arrows.  
Example 3:

Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,false,false,false,false,false]
Output: 0




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


Worked with provided test cases only.

7
[[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]]
[false,false,true,false,true,true,false]


7
[[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]]
[false,false,true,false,false,true,false]


7
[[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]]
[false,false,false,false,false,false,false]





// Time Complexity: O(n).  
// Space Complexity: O(n).													// Space for adj. list and visited array.

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).													// Space for adj. list and visited array.
// This algorithm is iteration based. As, we have to get minm. distance, we have to make sure that a node in a path isn't counted twice.
// We make that happen by counting the path only when a node having apple is encountered and the path length is set to 1, while 
// iteating the child nodes. If an apple is found in any of the child nodes, the path dist is set to 1 while iter. rest of child nodes
// as common path till curr. node is already included in the path for apple containing child. Whenever an apple containing node is 
// encountered, we add 2* path length to the final result.







class Solution {
public:
    
    bool iterateTree(vector<vector<int>>&graph, int node, int depth, int&res, vector<bool>&hasApple, vector<bool>&visited){
        bool found=false;													// Tracks whether apples found in this subtree.
        visited[node]=true;													// Marks this node as visited.
        if(hasApple[node]){													// If this node has apple.
            res+=2*depth;													// Add to final dist.
            depth=1;														// Reset path length to 1 for child.
            found=true;														// Mark as apple found.
        }else depth++;														// ELse, inc. the path length.
        for(int i=0;i<graph[node].size();i++){								// Iterate through child.
            int adj=graph[node][i];
            if(visited[adj]) continue;										// Skip visiting parents.
            found|=iterateTree(graph, adj, depth, res, hasApple, visited);	// Update whether child has a apple or not.
            if(found) depth=1;												// If apple found, set path length to 1.
        }
        return found;														// Return whether apple found in this subtree.
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        int res=0;															// Total path length to collect all apples.
        vector<vector<int>>graph(n);										// Stores graph adj. rep.
        for(auto v: edges){													// Forming adjacency list.
            int node1=v[0], node2=v[1];
            graph[node1].push_back(node2);
            graph[node2].push_back(node1);
        }
        vector<bool>visited(n, false);										// Tracks visited nodes and prevents infi. loops.
        iterateTree(graph, 0, 0, res, hasApple, visited);					// Iterate Tree to find apple containing nodes.
        return res;
    }
};


