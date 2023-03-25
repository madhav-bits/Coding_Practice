/*
*
//******************************************************1786. Number of Restricted Paths From First to Last Node.******************************************************

https://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


5
[[1,2,3],[1,3,3],[2,3,1],[1,4,2],[5,2,2],[3,5,1],[5,4,10]]
7
[[1,3,1],[4,1,2],[7,3,4],[2,5,3],[5,6,1],[6,7,2],[7,5,3],[2,6,4]]



// Time Complexity: O(m+n+mlogn).																		// m-#edges in the graph, n-#nodes in the graph.				
// Space Complexity: O(m+n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m+n+mlogn).																		// m-#edges in the graph, n-#nodes in the graph.				
// Space Complexity: O(m+n).	
// This algorithm is Dijkstra based. Here, we run Dijkstra to calculate the smallest dist. to target node(n). As the #paths has a condition where the nodes later in the path has a greater dist. from
// target node(n), which is the direction in which Dijkstra works, so we can tweak the dijkstra and also populate the dp array with #ways at the same time. Whenever we extract a node in dijkstra,
// we update the #ways to all those adj. nodes which have a GREATER DIST. from target node than curr. node, this works as the best possible dist. of adj. node from target node can be >dist. of curr.
// node from target node. We can ignore the equal to case as that edge wont be part of paths because of same dist. from target node. We only populate the #ways to adj. nodes from the ones picked from
// PQ to avoid duplicate updates.







class Solution {
public:
    int mod=1000000007;
    
    void dijkstra(vector<vector<vector<int>>>&graph, int source, vector<int>&dist, vector<int>&dp) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        dp[source]=1;
        dist[source]=0;
        pq.push({0, source});
        
        while(!pq.empty()) {
            pair<int,int>curr=pq.top();
            pq.pop();
            if(dist[curr.second]<curr.first) continue;
            for(vector<int>&edge:graph[curr.second]) {
                if(dist[curr.second]<dist[edge[0]]) dp[edge[0]]=(0ll+dp[edge[0]]+dp[curr.second])%mod;	// Updating the #ways to a node with greater dist. than curr. node from target node.
                
                if(curr.first+edge[1]>=dist[edge[0]]) continue;											// Skip the longer paths from target node.
                dist[edge[0]]=curr.first+edge[1];														// Updating the dist. from target node.
                pq.push({dist[edge[0]], edge[0]});														// Pushing new entry with lesser dist. in PQ.
            }
            
        }
        return ;
    }
    
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<vector<int>>>graph(n+1);
        for(vector<int>&edge:edges) {																	// Forming a adjacency list for graph.
            graph[edge[1]].push_back({edge[0], edge[2]});
            graph[edge[0]].push_back({edge[1], edge[2]});
        }
        vector<int>distToLast(n+1,INT_MAX);																// Stores the least dist. of nodes from target node.
        vector<int>dp(n+1, 0);																			// #Ways to a node from target node.
        dijkstra(graph, n, distToLast, dp);																// Call to run Dijkstra Algorithm.
        return dp[1];																					// Returning #ways from node-1 to node-n.
    }
};













//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m+n+mlogn).																		// m-#edges in the graph, n-#nodes in the graph.				
// Space Complexity: O(m+n).	
// This algorithm is based on Dijkstra+DFS+Memoization based. Here, we do Dijkstra to get the least dist. from all nodes to target node. Later we do a DFS from node-1 where we only move to adj. nodes
// which are at a lesser dist from target node, since there wont be any cycles, we can use DFS, we use Memoization to avoid repetition of DFS from a node when reached from some other adj. node.
// When at a node, we call DFS on all suitable adj. nodes, get their #ways to target node updated in the recursive DFS call, we add all those #ways values and update the curr. node's #ways, we return
// #ways form node-1 after the completion of the DFS.










class Solution {
public:
    int mod=1000000007;
    
    void dijkstra(vector<vector<vector<int>>>&graph, int source, vector<int>&dist) {					// Calc. the minm. dist from all nodes to target node.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        pq.push({0, source});
        
        while(!pq.empty()) {
            pair<int,int>curr=pq.top();
            pq.pop();
            if(dist[curr.second]<curr.first) continue;
            dist[curr.second]=curr.first;
            for(vector<int>&edge:graph[curr.second]) {
                if(curr.first+edge[1]>=dist[edge[0]]) continue;
                dist[edge[0]]=curr.first+edge[1];
                pq.push({dist[edge[0]], edge[0]});
            }
            
        }
        return ;
    }
    
    void dfs(vector<vector<vector<int>>>&graph, int node, vector<int>&dp, vector<int>&dist) {
        // cout<<"curr. node: "<<node<<endl;
        if(dp[node]!=-1) return ;																		// If a node is already visited, return the #ways form DP array.
        int total=0;																					// Tracks #ways from all suitable adj. nodes to target node and adds them.
        for(vector<int>&edge:graph[node]) {
            int adj=edge[0], gap=edge[1];
            if(dist[node]<=dist[adj]) continue;															// Skip DFS to those nodes whose dist. is >= curr. node from target node.
            dfs(graph, adj, dp, dist);
            total=(0ll+total+dp[adj])%mod;																// Add #ways of all adj. nodes.
        }
        dp[node]=total;																					// Add #ways of all adj. nodes. and assign it to curr. node.
        return ;
    }
    
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<vector<int>>>graph(n+1);
        for(vector<int>&edge:edges) {
            graph[edge[1]].push_back({edge[0], edge[2]});
            graph[edge[0]].push_back({edge[1], edge[2]});
        }
        vector<int>distToLast(n+1,INT_MAX);
        dijkstra(graph, n, distToLast);																	// DFS to calc. the least dist. of all nodes to target node.
        // for(int i=0;i<=n;i++)
        //     cout<<"node: "<<i<<" and dist: "<<distToLast[i]<<endl;
        
        vector<int>dp(n+1, -1);
        dp[n]=1;
        dfs(graph, 1, dp, distToLast);																	// DFS to calc. the #ways from all nodes to target node.
        return dp[1];																					// Returning #ways from node-1 to node-n.
    }
}

