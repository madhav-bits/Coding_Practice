/*
*
//**********************************1466. Reorder Routes to Make All Paths Lead to the City Zero.***********************************

https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/description/


There are n cities numbered from 0 to n-1 and n-1 roads such that there is only one way to travel between two different cities 
(this network form a tree). Last year, The ministry of transport decided to orient the roads in one direction because they are too 
narrow.

Roads are represented by connections where connections[i] = [a, b] represents a road from city a to b.

This year, there will be a big event in the capital (city 0), and many people want to travel to this city.

Your task consists of reorienting some roads such that each city can visit the city 0. Return the minimum number of edges changed.

It's guaranteed that each city can reach the city 0 after reorder.

 

Example 1:



Input: n = 6, connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
Output: 3
Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).
Example 2:



Input: n = 5, connections = [[1,0],[1,2],[3,2],[3,4]]
Output: 2
Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).
Example 3:

Input: n = 3, connections = [[1,0],[2,0]]
Output: 0
 

Constraints:

2 <= n <= 5 * 10^4
connections.length == n-1
connections[i].length == 2
0 <= connections[i][0], connections[i][1] <= n-1
connections[i][0] != connections[i][1]




*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


6
[[0,1],[1,3],[2,3],[4,0],[4,5]]

5
[[1,0],[1,2],[3,2],[3,4]]


3
[[1,0],[2,0]]

5
[[3,1],[1,0],[2,0],[4,2]]



// Time Complexity: O(n).  													// n- #nodes in the graph.
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// n- #nodes in the graph.
// Space Complexity: O(n).	
// This algorithm is DFS based. Here, we have to swap nodes to make all nodes facing towards node zero. So, we store edge's both nodes
// and it's direction. We start DFS process from node zero, we visit all edges in DFS fashion, if the curr. edge is pointing outwards,
// then we have to reverse it, we inc. the cnt. If it is inwards, then the edge is towards node zero. In this way we iter. over 
// entire graph.








class Solution {
public:
    
    void iterateTree(vector<vector<int>>&inEdges, vector<vector<int>>&outEdges, int node, int parent, int&res){
        
        for(int i=0;i<outEdges[node].size();i++){							// Iter. over outward edges and continue DFS.
            int child=outEdges[node][i];
            if(child==parent) continue;
            res++;															// As edge is pointed outwards, we reverse it, so inc. the cnt.
            iterateTree(inEdges, outEdges, child, node, res);				// Continue DFS on the node, on the other side of the edge.
        }
        
        for(int i=0;i<inEdges[node].size();i++){							// Iter. over inward edges and continue DFS.
            int child=inEdges[node][i];
            if(child==parent) continue;
            iterateTree(inEdges, outEdges, child, node, res);				// Continue DFS on the node, on the other side of the edge.
        }
        return ;
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>>inEdges(n);										// Edge pointed towards node.
        vector<vector<int>>outEdges(n);										// Edge pointed outwards other node.
        for(int i=0;i<connections.size();i++){								// Iter. over edges.
            int node1=connections[i][0], node2=connections[i][1];
            inEdges[node2].push_back(node1);								// Storing that edge pointing towards node2.
            outEdges[node1].push_back(node2);								// Storing that edge pointing outwards from node1.
        }
        int res=0;															// # Edge rotations needed.
        iterateTree(inEdges, outEdges,0,-1, res);							// Iter. the graph starting node zero.
        return res;															// Return the rotations made.
    }
};

