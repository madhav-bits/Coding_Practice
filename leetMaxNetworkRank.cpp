/*
*
//********************************************1615. Maximal Network Rank.************************************************

https://leetcode.com/problems/maximal-network-rank/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.

4
[[0,1],[0,3],[1,2],[1,3]]
5
[[0,1],[0,3],[1,2],[1,3],[2,3],[2,4]]
8
[[0,1],[1,2],[2,3],[2,4],[5,6],[5,7]]



// Time Complexity: O(n*m).  
// Space Complexity: O(n*m).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).
// Space Complexity: O(n*m).	
// This algorithm is iteration based. We create 2d array to keep track of edges between the nodes. We iter. over all
// possible edges and calculate rank for every combination by adding edges of both nodes, if there is an edge both those
// nodes we subtract 1. We try to maximize the rank, track it and return it.







class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int res=0;
        vector<int>edges(n,0);												// Counts #edges of all nodes.
        vector<vector<bool>>isEdge(n, vector<bool>(n, false));				// Stores edges between the nodes.
        for(auto v:roads){
            edges[v[0]]++;
            edges[v[1]]++;
            isEdge[v[0]][v[1]]=true;
            isEdge[v[1]][v[0]]=true;
        }
        // for(auto v:roads){
        //     int cnt=edges[v[0]]+edges[v[1]]-1;
        //     res=max(res, cnt);
        // }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                // if(i==j) continue;
                if(isEdge[i][j]) res=max(res, edges[i]+edges[j]-1);			// Calculating rank of each pair of nodes.
                else res=max(res, edges[i]+edges[j]);
            }
        }
        return res;															// Returning the maximal network rank.
    }	
};

