/*
*
//******************************************************1791. Find Center of Star Graph.***************************************************

https://leetcode.com/problems/find-center-of-star-graph/


There is an undirected star graph consisting of n nodes labeled from 1 to n. A star graph is a graph where there is one center node and exactly 
n - 1 edges that connect the center node with every other node.

You are given a 2D integer array edges where each edges[i] = [ui, vi] indicates that there is an edge between the nodes ui and vi. Return the 
center of the given star graph.

 

Example 1:


Input: edges = [[1,2],[2,3],[4,2]]
Output: 2
Explanation: As shown in the figure above, node 2 is connected to every other node, so 2 is the center.
Example 2:

Input: edges = [[1,2],[5,1],[1,3],[1,4]]
Output: 1
 

Constraints:

3 <= n <= 105
edges.length == n - 1
edges[i].length == 2
1 <= ui, vi <= n
ui != vi
The given edges represent a valid star graph.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


[[1,2],[5,1],[1,3],[1,4]]
[[1,2],[2,3],[4,2]]




// Time Complexity: O(1).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(1).	
// This algorithm is observation based. Here,since we are given a star topology graph. The center node appears in all the edges and rest of the edges
// appear in only one edge. So, we scan two edges and look for common node, that would be the center node.










class Solution {
public:
    int findCenter(vector<vector<int>>& v) {
        if(v[0][0]==v[1][0] || v[0][0]==v[1][1]) return v[0][0];			// If v[0][0] appears in two edges, it's the center node.
        if(v[0][1]==v[1][0] || v[0][1]==v[1][1]) return v[0][1];
        return -1;
    }
};

