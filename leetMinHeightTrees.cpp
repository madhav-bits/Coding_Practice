/*
*
//********************************************************310. Minimum Height Trees.*************************************************

For a undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. Among all possible 
rooted trees, those with minimum height are called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and 
return a list of their root labels.

Format
The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges (each edge is a pair 
of labels).

You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not 
ppear together in edges.

Example 1:

Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]

        0
        |
        1
       / \
      2   3
return [1]

Example 2:

Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

     0  1  2
      \ | /
        3
        |
        4
        |
        5
return [3, 4]

Note:

(1) According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices are connected by exactly one 
path. In other words, any connected graph without simple cycles is a tree.”

(2) The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


2
[[0, 1]]

0
[]

1
[]


6
[[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]


4
[[1,0],[1,2],[1,3]]



// Time Complexity: O(Edges).
// Space Complexity: O(Edges).	Edges= Nodes-1.

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(Edges).
// Space Complexity: O(Edges).	Edges= Nodes-1.
// This algorithm is BFS BASED TOPOLOGICAL SORTING. We start form the leaves we remove edges connecting all the leaves to the tree, now
// penultimate level becomes leaves, this way we travel upto the core of the tree. We do this until we get 1 or 2 root nodes.

// The main idea is that, nodes in the middle of topological sort gives the min. height for the tree, if they were made root.


class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> leaves;
        if(n==0) return leaves;													// If no nodes are given.
        if(n==1) return vector<int>(1,0);										// If only one node is given.
        vector<map<int, int>> tree(n);
        for(int i=0;i<edges.size();i++){										// Storing all edges from a node in a map.
            tree[edges[i].first][edges[i].second]=1;
            tree[edges[i].second][edges[i].first]=1;
        }
        
        
        for(int i=0;i<tree.size();i++){											// Finding the leave nodes.
            if(tree[i].size()==1) leaves.push_back(i);
        }
        
        
        int nodes=n;
        while(nodes>2){															// Runs till we get 1 or 2 root nodes.
            vector<int> pres;
            for(int i=0;i<leaves.size();i++){									// Iterating through all leave nodes.
                auto it=tree[leaves[i]].begin();								// Finding the nodes other side of the leave's edge.
                int node=it->first;
                tree[leaves[i]].erase(node);                                    // Leave cutting the link to inner node.
                tree[node].erase(leaves[i]);                                    // Inner node cutting link to leave.
                if(tree[node].size()==1) pres.push_back(node);					// If Inner node becomes leave node,then push into new leaves list.
            }
            nodes-=leaves.size();												// Dec. the rem. active nodes in the tree.
            leaves=pres;														// Updating the leaves list.
        }
        
        
        return leaves;															// Returning the root nodes, which gives min height.
    }
};











//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS NOT LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(Edges*Edges).
// Space Complexity: O(Edges).	Edges= Nodes-1.
// This algorithm is BFS BASED solution. Here, since we need nodes, which split tree with minm. height, it's dist. when calculated
// from all leaves, maxm of them will be minm. among all the nodes present in the tree. We maintain an array which tracks maxm possible
// dist. from of that node to all leaves. For this we perform BFS from all edges, this takes O(Edges*Edges) times. That's the reason
// it fails on the last test case.







class Solution {
public:
    
    void iterateTree(int node, vector<int>&dist, vector<vector<int>>&graph){
        vector<bool>visited(dist.size(), false);							// Prevents revisiting the nodes.
        queue<int>q;
        q.push(node);
        int steps=-1;
        while(!q.empty()){
            steps++;
            int len=q.size();
            for(int i=0;i<len;i++){
                int node=q.front();
                visited[node]=true;
                dist[node]=max(dist[node], steps);							// Tracking maxm dist from each node to all leaves.
                q.pop();
                for(auto adj: graph[node]){
                    if(visited[adj]) continue;
                    q.push(adj);
                }
            }
        }
        return;
    }
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>>graph(n);
        vector<int>res;
        for(int i=0;i<edges.size();i++){
            int node1=edges[i][0], node2=edges[i][1];
            graph[node1].push_back(node2);
            graph[node2].push_back(node1);
        }
        int start=-1, node=0;
        vector<int>dist(n, 0);
        for(int i=0;i<n;i++){
            if(graph[i].size()==1) iterateTree(i, dist, graph);    // Starting BFS from all leaves.
        }
        
        // cout<<"yo"<<endl;
        int minm=n;
        for(int i=0;i<n;i++){										// Calc. minm. dist among all nodes. 
            if(dist[i]<minm) minm=dist[i];
        }
        for(int i=0;i<n;i++){
            if(dist[i]==minm) res.push_back(i);						// Collecting nodes with minm. dist.
        }
        return res;
    }
};






