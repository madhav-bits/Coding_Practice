/*
*
//*********************************************1042. Flower Planting With No Adjacent.*********************************************

https://leetcode.com/problems/flower-planting-with-no-adjacent/	




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


3
[[1,2],[2,3],[3,1]]
4
[[1,2],[3,4]]
4
[[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]
4
[[1,2],[2,3],[3,4],[2,4]]
9
[[1,2],[2,4],[1,3],[3,4],[2,3],[1,5],[5,6],[4,8],[5,7],[7,8],[8,9],[7,9]]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is iteration based. We use the observation that each node contains at max. three edges and we have 4 colors available, so  a node can always
// have a uniq. color when compared to adj. nodes even in the case three diff uniq. colors for adj. nodes. So, when we are at node 'i', we check all adj. nodes
// which are already colored and we accordingly color our node with a diff color so they won't match and we move to next index. As we check all adj. nodes 
// colors before assigning color to curr. node, we don't have to change it once again as the later indices would pick colors based on already assigned colors
// for their adj. nodes.







class Solution {
public:
    
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>>graph(n);
        for(vector<int>&v:paths) {											// Forming adjacency list for matrix.
            graph[v[0]-1].push_back(v[1]-1);
            graph[v[1]-1].push_back(v[0]-1);
        }
        vector<int>res(n,-1);
        for(int node=0;node<n;node++) {										// Iter. over all nodes.
            int adjColor=0, rep=1;
            for(int adj:graph[node]) {										// Checking all adj. nodes of curr. node.
                if(res[adj]==-1) continue;									// Skip if not colored.
                adjColor|=(1<<res[adj]);									// Storing the color of adj. nodes.
            }
            for(int i=1;i<=4;i++) {											// Iter. over all possible colors.
                if((adjColor&(1<<i))==0) {									// Assign a diff color than that of adj. nodes.
                    res[node]=i;
                    break;
                }
            }
        }
        return res;															// Returning list with colors for all the nodes.
    }
};






//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is DFS based. This is same as the above solution, except that we used DFS to iterate over all nodes in the graph.








class Solution {
public:
    
    void fillGraph(vector<vector<int>>&graph, int node, vector<int>&res) {
        int adjColor=0, rep=1;
        for(int adj:graph[node]) {
            if(res[adj]==-1) continue;
            adjColor|=(1<<res[adj]);										// Storing the color of adj. nodes.
        }
        for(int i=1;i<=4;i++) {												// Coloring curr. node.
            if((adjColor&(1<<i))==0) {										// Assign a diff color than that of adj. nodes.
                res[node]=i;
                break;
            }
        }
        for(int adj:graph[node]) {											// DFS calls to color adj. nodes after coloring curr. node.
            if(res[adj]!=-1) continue;
            fillGraph(graph, adj, res);
        }
        return ;
    }
    
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>>graph(n);
        for(vector<int>&v:paths) {
            graph[v[0]-1].push_back(v[1]-1);
            graph[v[1]-1].push_back(v[0]-1);
        }
        vector<int>res(n,-1);
        for(int i=0;i<n;i++) {												// Iter. over all nodes in the graph.
            if(res[i]!=-1) continue ;
            fillGraph(graph, i, res);										// DFS call to color curr. node and it's connected nodes.
        }
        return res;
    }
};
