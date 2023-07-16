/*
*
//******************************************************2368. Reachable Nodes With Restrictions.******************************************************

https://leetcode.com/problems/reachable-nodes-with-restrictions/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


7
[[0,1],[1,2],[3,1],[4,0],[0,5],[5,6]]
[4,5]
7
[[0,1],[0,2],[0,5],[0,4],[3,2],[6,5]]
[4,2,1]



// Time Complexity: O(n).
// Space Complexity: O(n).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is DFS based. Here, we first mark all nodes which are restricted, while forming adjacency matrix, we dont populate them in it these nodes 
// restricted nodes and the other nodes reachable via them from '0' can't be used for iteration and can't count towards final reachable nodes, so we won't
// include any edges involving backlisted nodes. We start DFS from '0' and count the #nodes visited and return them.







class Solution {
public:
    
    int iterateGraph(int node, vector<vector<int>>&graph, vector<bool>&allowed) {// Iterating the graph and counting the #nodes reachable.
        int res=1;
        allowed[node]=false;
        for(int adj:graph[node]) {
            if(allowed[adj]==false) continue;
            res+=iterateGraph(adj, graph, allowed);
        }
        return res;
    }
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        int res=0;
        vector<bool>allowed(n, true);
        for(int node:restricted) allowed[node]=false;						// Marking the restricted nodes.
        
        vector<vector<int>>graph(n);
        for(vector<int>&u:edges) {
            if(allowed[u[0]]==false || allowed[u[1]]==false) continue;		// Avoiding edges involving restriced nodes as they can't be used in iteration.
            graph[u[0]].push_back(u[1]);									// Forming adjacency matrix.
            graph[u[1]].push_back(u[0]);
        }
        
        return iterateGraph(0, graph, allowed);								// Func. call to calc. reachable nodes.
        
    }
};





//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).												// logn time for each getParent call, can be optimized by joining by rank.
// Space Complexity: O(n).	
// This solutionis Union-Find based. Here, we use Union-Find to join the connected groups, while connecting them we make sure that the least valued core parent
// remains the core parent of the resulting joint group, so that zero would remain the core parent of all connected/reachable nodes, we iter. over all edges
// in the process and ignore all edges involving restriced nodes as they aren't helpful in iteration/reaching other nodes. We return size of the group for
// which zero is the core parent, this group indicates all the nodes reachable from zero node.








class Solution {
public:
    
    int getParent(vector<int>&parent, int node) {							// Get core parent for a node.
        if(parent[node]!=node) parent[node]=getParent(parent, parent[node]);
        return parent[node];
    }
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        int res=0;
        vector<bool>allowed(n, true);
        vector<int>parent(n,0), sze(n,1);
        for(int node:restricted) allowed[node]=false;
        for(int i=0;i<n;i++) parent[i]=i;
        
        vector<vector<int>>graph(n);
        for(vector<int>&u:edges) {
            if(allowed[u[0]]==false || allowed[u[1]]==false) continue;
            int parA=getParent(parent, u[0]), parB=getParent(parent, u[1]);	// Get core parent for the two nodes of the edge.
            if(parA<parB) {													// If parA is the lesser valued core parent.
                sze[parA]+=sze[parB];										// Inc. the size of the group for which parA is the core parent.
                parent[parB]=parA;											// Marking parA as the core parent of the resulting merged group.
            }else {															// If parB is the lesser valued core parent.
                sze[parB]+=sze[parA];
                parent[parA]=parB;
            }
        }
        
        return sze[0];														// Return the size of the group for which zero is the core parent.
        
    }
};

