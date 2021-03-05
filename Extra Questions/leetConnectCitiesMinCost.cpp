/*
*
//******************************************************1135. Connecting Cities With Minimum Cost.***********************************************

https://leetcode.com/problems/connecting-cities-with-minimum-cost/


Connect all the cities by using minimum-cost/ edges.

*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


3
[[1,2,5],[1,3,6],[2,3,1]]
4
[[1,2,3],[3,4,4]]



// Time Complexity: O(mlogn).  												// m-#connections in the graph, n-#cities in the graph.
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(mlogn).												// m-#connections in the graph, n-#cities in the graph.
// Space Complexity: O(n).	
// This algorithm is Minimum Spanning Tree based. This is Kruskal's algorithm. We sort the edges based on the connections cost. We iter. over edges, 
// we try to join the nodes of each edge, if they are already from a group, ignore this edge, if they are from different groups, join them and add the 
// cost to result. If by the end, we have >1 groups, then we didn't form MST, if not we return the cost involved in the process.











class Solution {
public:
    
    struct comp{															// Sort edges based on edge costs.
        bool operator()(vector<int>&lt, vector<int>&rt){
            return lt[2]<=rt[2];
        }    
    };
    
    
    int getParent(vector<int>&parent, int node){							// Finding the core parent of the node.
        if(parent[node]!=node)
            parent[node]=getParent(parent, parent[node]);
        return parent[node];
    }
    
    int minimumCost(int N, vector<vector<int>>& connections) {
        int res=0;
        sort(connections.begin(), connections.end(), comp());
        int groups=N;
        vector<int>parent(N,0);
        for(int i=0;i<N;i++) parent[i]=i;
        for(int i=0;i<connections.size() && groups>1;i++){					// Iterating the edges.
            int node1=connections[i][0]-1, node2=connections[i][1]-1;
            int parA=getParent(parent, node1), parB=getParent(parent, node2);
            if(parA==parB) continue;										// If nodes are already part of a group, ignore the edge.
            res+=connections[i][2];											// Add the connection cost to the result.
            parent[parB]=parA;												// Join both the groups.
            groups--;
        }
        return (groups==1)?res:-1;											// Return the cost involved in forming MST.
    }
};