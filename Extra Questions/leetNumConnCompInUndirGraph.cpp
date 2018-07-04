/*
*
//**********************************************323. Number of Connected Components in an Undirected Graph.***************************************

Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of 
connected components in an undirected graph.

Example 1:

Input: n = 5 and edges = [[0, 1], [1, 2], [3, 4]]

     0          3
     |          |
     1 --- 2    4 

Output: 2
Example 2:

Input: n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]]

     0           4
     |           |
     1 --- 2 --- 3

Output:  1
Note:
You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not 
appear together in edges.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


5
[[0,1],[0,2],[0,3],[1,4]]


5
[[0, 1], [1, 2], [2, 3], [3, 4]]


5
[[0, 1], [0, 2], [3, 4]]


4
[[2,3],[1,2],[1,3]]



// Time Complexity: O(Nodes+Edges).  
// Space Complexity: O(Nodes).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(Nodes+Enough).
// Space Complexity: O(Nodes).	
// This algorithm is BFS based. We start from a node, traverse all connected nodes it it. As, we enocunter unvisited nodes while iter. the edges
// list, we do a BFS on it. We inc. the count by one at the start of every BFS traversal. As there might be some single node after iteration, we 
// iterate through all vertices, and inc. the #groups count whenever encountered one. Return the #groups at last.








class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& v) {
        vector<vector<int>> edges(n);										// Stores edges in the graph.
        vector<int>visited(n,0);											// Stores visited nodes in the BFS iteration.
        for(int i=0;i<v.size();i++){										// Forming bidirectional edges.
            edges[v[i].first].push_back(v[i].second);
            edges[v[i].second].push_back(v[i].first);
        }
        
        int count=0;
        queue<int>q;														// Stores nodes to be visited.
        for(int i=0;i<v.size();i++){
            if(visited[v[i].first]==1) continue;							// If node is already visited, skip it.
            // cout<<"start node: "<<v[i].first<<endl;
            q.push(v[i].first);												// Push curr. node into queue.
            count++;														// Inc. count at beginning of every BFS iter.
            visited[v[i].first]=1;											// Marking curr. node as visited.
            while(!q.empty()){
                int curr=q.front();
                q.pop();
                for(auto node: edges[curr]){								// Pushing all unvisited adj. nodes of curr. node into queue.
                    if(visited[node]==0){							
                        // cout<<"Curr. pushing node: "<<node<<endl;
                        q.push(node);
                        visited[node]=1;									// Marking adj. nodes as visited.
                    }
                }
            }
        }
        
        for(int i=0;i<n;i++){												// Finding groups with single node(unvisited).
            if(visited[i]==0) count++;
        }
        return count;														// Returning the total #groups.
    }
};