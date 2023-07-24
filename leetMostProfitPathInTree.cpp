/*
*
//******************************************************2467. Most Profitable Path in a Tree.******************************************************

https://leetcode.com/problems/most-profitable-path-in-a-tree/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[0,1],[1,2],[1,3],[3,4]]
3
[-2,4,2,-4,6]
[[0,1]]
1
[-7280,2350]
[[0,1],[0,2],[1,3],[1,4],[1,5],[2,6],[2,7],[4,8],[6,9]]
6
[4,-8,6,-4,6,2,-6,10,6,4]
[[0,1],[0,2],[1,3],[1,4],[1,5],[2,6],[2,7],[4,8],[6,9]]
9
[4,-8,6,-4,6,2,-6,10,6,4]
[[0,1],[0,2],[1,3],[1,4],[1,5],[2,6],[2,7],[4,8],[6,9]]
2
[4,-8,6,-4,6,2,-6,10,6,4]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Tree Traversal+BFS based. Here, the path b/w '0' and bob has different conditions for the cost associated with them. So, we first form the 
// adjacency list and traversed tree and marked the path from root to bob and also got it's path length. We do BFS to iterate the tree, we use costs of onPath
// nodes as per their dist from root and bob, if a node is at same dist. we use half of it's vlaue, if it's closer to root, we use it's actual value else we use
// zero value as it would have been already visited by bob. We gather sum of node values/income till leaves and return the max. possible income among them.


// Using DFS for iteration also works.
// We can avoid using visited array by setting dist[node]=INT_MAX after visiting them.





class Solution {
public:
    
    int getPathLength(vector<vector<int>>&graph, int node, int bob, vector<bool>&onPath) {
        onPath[node]=true;
        if(node==bob) return 1;												// If bob found, return 1.
        for(int child:graph[node]) {
            if(onPath[child]) continue;										// Avoid visiting parents.
            int len=getPathLength(graph, child, bob, onPath);				// Get dist. from curr. node to bob.
            if(len!=-1) return len+1;										// If bob found in path, return 1+dist. from curr. node to bob.
        }
        onPath[node]=false;													// If bob not found in curr. path, return -1 and rest onPath[node]=false.
        return -1;
    }
    
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int res=INT_MIN, nodes=edges.size()+1;
        vector<vector<int>>graph(nodes);
        for(vector<int>&v:edges) {											// Form Adjacency list.
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }
        vector<bool>onPath(nodes, false), visited(nodes, false);
        int bobPath=getPathLength(graph, 0, bob, onPath);					// Mark path from root to bob and get path length.
        int bobMeet=(bobPath%2==1)?(bobPath+1)/2:-1;
        queue<pair<int,int>>q;
        q.push({0, amount[0]});
        visited[0]=true;
        
        int dist=1;
        while(!q.empty()) {
            dist++;
            int sz=q.size();
            for(int i=0;i<sz;i++) {
                int node=q.front().first, income=q.front().second;
                q.pop();
                int cnt=0;
                for(int adj:graph[node]) {
                    if(visited[adj]) continue;
                    cnt++;
                    if(onPath[adj]) {
                        if(bobMeet==dist) q.push({adj, income+amount[adj]/2});// If node is at equidist. from root and bob, use half value.
                        else if(dist>bobPath/2) q.push({adj, income});		// If node closer to bob, use zero value as bob had already visted them.
                        else q.push({adj, income+amount[adj]});				// If node is closer to root, use their actual val as Alice visits them first.
                    } else q.push({adj, income+amount[adj]});				// Use actual values for nodes not in bobPath.
                    visited[adj]=true;
                }
                // cout<<"node: "<<node<<" and cnt: "<<income<<endl;
                if(cnt==0 && income>res) res=income;						// Tracking max. income by the time Alice reaches leaf node.
            }
        }
        return res;															// Returning max. income by the time Alice reaches leaf node.
    }
};

