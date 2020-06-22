/*
*
//*********************************************1377. Frog Position After T Seconds.***********************************************

https://leetcode.com/problems/frog-position-after-t-seconds/description/


*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


7
[[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]]
2
4


7
[[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]]
1
7


7
[[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]]
20
6

8
[[2,1],[3,2],[4,1],[5,1],[6,4],[7,1],[8,7]]
7
7


// Time Complexity: O(n).  													// n- #nodes in the graph.
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// n- #nodes in the graph.
// Space Complexity: O(n).	
// This algorithm is BFS based. Here, we iter. over entire graph/tree, we start by assigning prob of 1 to root. In the process, we split
// a node's prob. equally into all it's child, if there are no child, it holds all the prob. 








class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        unordered_map<int,unordered_set<int>>graph;							// Stores the tree's edges relationships.
        for(int i=0;i<edges.size();i++){									// Forming graph from bidirectional edges.
            int node1=edges[i][0], node2=edges[i][1];
            graph[node1].insert(node2);
            graph[node2].insert(node1);
        }
        queue<int>q;														// Holds nodes to be visited in the BFS.
        q.push(1);
        vector<double>prob(n+1,0);											// Stores the prob. that frog stays in that node.
        prob[1]=1.0;
        while(t!=0 && !q.empty()){											// Runs for t steps/all nodes are visited, which is quicker.
            t--;
            int len=q.size();
            for(int i=0;i<len;i++){											// Visiting all nodes reachable in curr. #steps.
                int node=q.front();
                q.pop();
                if(graph[node].size()==0) continue;							// If curr. node has no children, let it hold the prob.
                double neighbors=graph[node].size();
                for(auto it=graph[node].begin();it!=graph[node].end();it++){// Iter. over all child and passing prob. to them.
                    int adj=*it;
                    graph[adj].erase(node);									// Removing parent from child's children list.
                    q.push(adj);
                    prob[adj]+=prob[node]*(1.0/neighbors);
                }                
                prob[node]=0;												// As prob. is assigned to child, parent holds no prob.
                graph[node].clear();										// Delete the curr./parent node.
            }
        }
        return prob[target];												// Return the prob. that frog stays in target node.
    }
};

