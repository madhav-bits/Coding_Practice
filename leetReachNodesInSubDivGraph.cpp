/*
*
//**************************************************882. Reachable Nodes In Subdivided Graph.*******************************************

Starting with an undirected graph (the "original graph") with nodes from 0 to N-1, subdivisions are made to some of the edges.

The graph is given as follows: edges[k] is a list of integer pairs (i, j, n) such that (i, j) is an edge of the original graph,

and n is the total number of new nodes on that edge. 

Then, the edge (i, j) is deleted from the original graph, n new nodes (x_1, x_2, ..., x_n) are added to the original graph,

and n+1 new edges (i, x_1), (x_1, x_2), (x_2, x_3), ..., (x_{n-1}, x_n), (x_n, j) are added to the original graph.

Now, you start at node 0 from the original graph, and in each move, you travel along one edge. 

Return how many nodes you can reach in at most M moves.

 

Example 1:

Input: edges = [[0,1,10],[0,2,1],[1,2,2]], M = 6, N = 3
Output: 13
Explanation: 
The nodes that are reachable in the final graph after M = 6 moves are indicated below.

Example 2:

Input: edges = [[0,1,4],[1,2,6],[0,2,8],[1,3,1]], M = 10, N = 4
Output: 23
 

Note:

0 <= edges.length <= 10000
0 <= edges[i][0] < edges[i][1] < N
There does not exist any i != j for which edges[i][0] == edges[j][0] and edges[i][1] == edges[j][1].
The original graph has no parallel edges.
0 <= edges[i][2] <= 10000
0 <= M <= 10^9
1 <= N <= 3000
A reachable node is a node that can be travelled to using at most M moves starting from node 0.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[0,1,4],[1,2,6],[0,2,8],[1,3,1]]
10
4



[[0,1,10],[0,2,1],[1,2,2]]
10
4



[[0,1,0],[0,2,1],[1,2,2]]
10
4




[[0,1,0],[0,2,0],[1,2,0]]
10
4



[[0,3,8],[0,1,4],[2,4,3],[1,2,0],[1,3,9],[0,4,7],[3,4,9],[1,4,4],[0,2,7],[2,3,1]]
8
5





[[0,7,8],[3,4,25],[1,2,25],[5,6,5],[1,3,14],[4,6,8],[3,5,25],[2,4,24],[2,6,15],[2,3,18],[4,7,17],[0,2,9],[3,7,23],[0,5,23],[2,5,8],[0,1,19],[1,6,0],[1,5,21],[4,5,14],[0,6,24],[3,6,9],[5,7,16],[0,3,8],[6,7,20],[2,7,15]]
25
8







// Time Complexity: O(EdgeslogEdges).  
// Space Complexity: O(Edges).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(EdgeslogEdges).
// Space Complexity: O(Edges).	
// This algorithm is Dijkstra, Priority Queue based. Here, as, we are added extra nodes in b/w the given nodes of graph, we create a graph, where
// we also track the num. of new nodes reachable. If the rem. steps>new nodes in b/w orig. nodes, we push that node into PQ, as we don't know
// which path leads to shortest  path till node from source. We pop node with shortest dist. from source, at this moment, we can cover max. 
// nodes starting from this node. If we pop encounter same node in future, as we calculated reachable in the best scenario(First time it's been
// popped from PQ). At the end, we iterate over graph, we get min(No. of new nodes, nodes coverable from both ends) and also add no. of reachable
// nodes from source and return the sum.








class Solution {
public:
    
    struct compare{															// Comparator to get node with Min. second elem. of pair.
        bool operator()(pair<int,int>lt, pair<int,int>rt){
            return lt.second>rt.second;
        }
    };
    
    
    int reachableNodes(vector<vector<int>>& edges, int M, int N) {
        if(N==1) return 1;
        vector<unordered_map<int,pair<int,int>>>graph(N);					// Init. vector of size N.
        for(int i=0;i<edges.size();i++){									// Constructing graph from given infor(Storing #new nodes on edges)
            int curr=edges[i][0], fol=edges[i][1], dist=edges[i][2];
            graph[curr][fol]={dist,0};
            graph[fol][curr]={dist,0};
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>,compare>q;		// Init. Priority Queue.
        q.push({0,0});														// Start from root 0, dist. from source=0.
        // unordered_map<int,int>visited;
        unordered_set<int>visited;
        while(!q.empty()){
            pair<int,int>pr=q.top();										// Get Node with least dist. from PQ.
            q.pop();
            // visited[pr.first]=1;
            if(visited.count(pr.first)==1) continue;						// If this had been already visited, then ignore curr. journey.
            visited.insert(pr.first);
            int curr=pr.first, dist=pr.second;
            int rem=M-dist;
            for(auto it=graph[curr].begin();it!=graph[curr].end();it++){	// Iter. over curr. node's edges.
                int fol=it->first, gap=it->second.first;					// Next node, Gap b/w curr. and next node.
                if(rem>gap && visited.count(fol)==0) q.push({fol,dist+gap+1});// If not visited and reachable, push into PQ.
                if(rem<=gap) it->second.second=max(it->second.second, rem);	// If new nodes reachable, then try to maximize reachable new nodes.
                else if(rem>gap) it->second.second=gap;						// If all new nodes reachable, then mark all as reachable.
            }
        }
        int res=visited.size();												// No. of nodes reachable from source.
        // cout<<"temp res: "<<res<<endl;
        int cover=0;
        //for(int i=0;i<N;i++){												// Iter. over built graph to get reachable new nodes on each edge.
        //    for(auto it=graph[i].begin();it!=graph[i].end();it++){
        //        int fol=it->first;
        //        int l1=it->second.second, l2=graph[fol][i].second;			// We take into account, nodes from both sides.
        //        // res+=min(it->second.first+,it->second.second);
        //        cover+=min(l1+l2, it->second.first);						// Get min. of reachable new nodes b/w curr. nodes.
        //    }
        //}
		for(int i=0;i<edges.size();i++){									// Iter. over provided edges.
            int curr=edges[i][0], fol=edges[i][1], dist=edges[i][2];
            res+=min(graph[curr][fol].second+graph[fol][curr].second,dist);	// Get min. of reachable new nodes b/w curr. nodes.
        }
        cover/=2;															// As each edge is visited twice, divide by 2.
        return res+cover;													// Return the overall visited nodes.
    }
};