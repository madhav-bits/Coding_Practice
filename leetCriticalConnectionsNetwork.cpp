/*
*
//**********************************************1192. Critical Connections in a Network.******************************************

There are n servers numbered from 0 to n-1 connected by undirected server-to-server connections forming a network where 
connections[i] = [a, b] represents a connection between servers a and b. Any server can reach any other server directly or 
indirectly through the network.

A critical connection is a connection that, if removed, will make some server unable to reach some other server.

Return all critical connections in the network in any order.

 

Example 1:



Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.
 

Constraints:

1 <= n <= 10^5
n-1 <= connections.length <= 10^5
connections[i][0] != connections[i][1]
There are no repeated connections.



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


4
[[0,1],[1,2],[2,0],[1,3]]


11
[[0,1],[1,2],[2,3],[3,4],[4,5],[4,6],[5,7],[6,7],[6,8],[8,9],[8,10]]


// Time Complexity: O(n).
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/


//************************************************************Solution 1:************************************************************
//********************************************************THIS IS LEET ACCEPTED CODE.************************************************
// Time Complexity: O(n).
// Space Complexity: O(n).
//The algorithm is slightly modified version of Tarjan's algorithm to find Critical Connections in the Graph. Here, we iterate over the
// graph, in the process we assign a number to each of the nodes visited till now. While we are at a node, we extract minm labelled
// node that you can reach through children. If the minm. reachable node is less than curr node's labelled value. Then there is a cycle 
// involving two edges of curr. node. So, the edge between parent and curr. node are part of cycle. 
// If the minm. value is >= curr. node's label, then curr. edge is not part of cycle. You can include curr. edge in final vector of
// edges. In the iteration if we reach a node, which is already visited, we return visited label. This visited label would be > parent
// node's label, if there is no cycle. It would be equal to parent label, if there is cycle, so there won't be any problem even if we
// haven't update visited label with minm. reachable label from that node. One exception is that we won't consider edges where parent
// node is -1, as this is duplicately created node.



// There are few resources to understand Tarjan's algorithm better in case of revision:
// https://leetcode.com/problems/critical-connections-in-a-network/discuss/382638/No-TarjanDFS-detailed-explanation-O(orEor)-solution-(I-like-this-question)
// https://leetcode.com/problems/critical-connections-in-a-network/discuss/382632/Java-implementation-of-Tarjan-Algorithm-with-explanation
// https://www.youtube.com/watch?v=TyWtx7q2D7Y&feature=emb_logo
// https://www.youtube.com/watch?v=2kREIkF9UAs
// Leetcode Discuss has nice articles and discussions on this algorithm.




class Solution {
public:
    
    int findConnections(vector<vector<int>>&graph, int curr, int par, int cnt, vector<int>&visited, vector<vector<int>>&res){
        if(visited[curr]!=-1) return visited[curr];							// If already visited, return visited label value.
        int currVal=cnt;													// Temp. storing curr. node's label.
        visited[curr]=cnt++;												// Updating the visited array's curr. node index with label.
        int minm=INT_MAX;													// Tracking minm. reachable label through children.
        for(int adj: graph[curr]){											// Iter. over adj. nodes.
            if(adj==par) continue;											// Skip the parent node from iter.
            minm=min(minm, findConnections(graph,adj, curr, cnt, visited, res));// Updating minm. reachable label value.
        }
        if(minm>=currVal && par!=-1) res.push_back({par, curr});			// If minm. reachable is >=curr. label, then push. curr. edge.
        return minm;														// Returning the minm. reachable label value.
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& v) {
        vector<vector<int>>res;												// Stores critical edges.
        vector<vector<int>>graph(n);										// Init. adj. matrix.		
        for(int i=0;i<v.size();i++){										// Iter. over edges and forming adj. matrix.
            int node1=v[i][0], node2=v[i][1];
            graph[node1].push_back(node2);
            graph[node2].push_back(node1);
        }
        vector<int>visited(n,-1);											// Tracks visited node's by storing labels.
        int cnt=1;															// Maintains label values.
        findConnections(graph, 0,-1, cnt, visited,res);						// Iter. the graph.
        return res;															// Returning the critical edges.
    }
};













//************************************************************Solution 2:************************************************************
//********************************************************THIS IS LEET ACCEPTED CODE.************************************************
// Time Complexity: O(n).
// Space Complexity: O(n).
// This is similar to previous algorithm, but only change is which edge we are focusing on in every step of DFS. Earlier we were
// deciding whether or not to include edge between parent and curr. node based on minm. reachable label through children, at the end
// of visiting all children. Here, we focus on edge between curr. and children., if the minm. reachable node from a children is >
// curr. label then it's not part of a cycle involving curr. and children and we take that edge. We also update the visited array
// with minm. reachable label, as we are making decisions per each children. If there is a cycle involving two children, if second
// child in cycle is revisited, it won't be added to result, if second child has minm. reachable label's value in visited vector rather
// than it's label.








class Solution {
public:
    
    int findConnections(vector<vector<int>>&graph, int curr, int cnt, vector<int>&visited, vector<vector<int>>&res){
        if(visited[curr]!=-1) return visited[curr];							// If revisited, then return minm. reachable label.
        int currVal=cnt;
        visited[curr]=cnt++;
        int minm=INT_MAX;
        for(int adj: graph[curr]){
            if(adj==par) continue;
            int rep=findConnections(graph,adj, cnt, visited, res);			// Getting the minm. reachable from this child.
            if(rep>currVal) res.push_back({curr,adj});						// If minm. reachable is >curr. label, then take this edge.
            minm=min(minm, rep);											// Updating the minm. reachable label from all children.
        }
        visited[curr]=minm;													// Updating the visited vec. with minm. reachable label.
        return minm;														// Returning the minm. reachable label.
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& v) {
        vector<vector<int>>res;
        vector<vector<int>>graph(n);
        for(int i=0;i<v.size();i++){
            int node1=v[i][0], node2=v[i][1];
            graph[node1].push_back(node2);
            graph[node2].push_back(node1);
        }
        vector<int>visited(n,-1);
        int cnt=1;
        findConnections(graph, 0, cnt, visited,res);
        return res;
    }
};
