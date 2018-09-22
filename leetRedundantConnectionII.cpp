/*
*
//********************************************************685. Redundant Connection II.*************************************************

In this problem, a rooted tree is a directed graph such that, there is exactly one node (the root) for which all other nodes are descendants of 
this node, plus every node has exactly one parent, except for the root node which has no parents.

The given input is a directed graph that started as a rooted tree with N nodes (with distinct values 1, 2, ..., N), with one additional directed 
edge added. The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.

The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] that represents a directed edge connecting nodes u 
and v, where u is a parent of child v.

Return an edge that can be removed so that the resulting graph is a rooted tree of N nodes. If there are multiple answers, return the answer 
that occurs last in the given 2D-array.

Example 1:
Input: [[1,2], [1,3], [2,3]]
Output: [2,3]
Explanation: The given directed graph will be like this:
  1
 / \
v   v
2-->3
Example 2:
Input: [[1,2], [2,3], [3,4], [4,1], [1,5]]
Output: [4,1]
Explanation: The given directed graph will be like this:
5 <- 1 -> 2
     ^    |
     |    v
     4 <- 3
Note:
The size of the input 2D-array will be between 3 and 1000.
Every integer represented in the 2D-array will be between 1 and N, where N is the size of the input array.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.




[[1,2],[1,3],[2,3]]


[[1,2], [2,3], [3,4], [4,1], [1,5]]



[[2,1],[3,1],[4,2],[1,4]]



[[4,2], [1,5], [5,2], [5,3], [2,4]]



[[5,3], [4,2],[1,4],[2,1], [3,1]]



// Time Complexity: O(nlogn).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
//*****************************************************THIS IS A SIMPLE YET SUPERB APPROACH.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(n).	
// This algorithm is Union-Find based. Here, there are two ways for the Tree structure to be distrubed on adding extra edge. One is it forms
// two parent for a child. There would be a parent to the root(In deg. of all nodes is 1). In the first iteration, we iterate through all edges
// look for node with two parents, then we remove one of the edges. Now, in the first iteration, if we still encounter a cycle, then the curr.
// tree is a cycle and we are missing the removed edge's node. We remove the curr. edge where we had found the cycle(repitition). If we didn't
// find any cycles, then we had removed proper node. Now, the tree is perfect. We may also get a tree where extra edge is made to root. Here,
// we don't any nodes with in-degree 2.Here, in the second iter. we can find cycle, as we have a cycle over root, we can remove any edge and
// the tree structure remains intact.


// Below link has a very good explanation for the below algorithm.
// https://leetcode.com/problems/redundant-connection-ii/discuss/108045/C++Java-Union-Find-with-explanation-O(n)






class Solution {
public:
    
    int findParent(int node, vector<int>&parent){							// Finds the core-parent of a node.
        while(node!=parent[node]) node=parent[node];
        return node;
    }
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& v) {
        int len=v.size();
        vector<int>parent(len+1,0);											// Stores the parent of a node.
        vector<int> ans1, ans2;												// Tracks the two probable edges.
        for(int i=0;i<v.size();i++){										// Iter. over edges.
            int node1=v[i][0], node2=v[i][1];
            if(parent[node2]!=0){											// If child has been already visited.
                ans1={parent[node2], node2};								// Store the earlier edge.
                ans2=v[i];													// Store the curr. edge.
                v[i][1]=0;													// Delete the curr. edge/mark so as to get not visited.
            }
            else parent[node2]=node1;										// If child visited first time, assign parent to it.
        }
        
        for(int i=1;i<=len;i++) parent[i]=i;								// Resetting the parent values.
        for(int i=0;i<v.size();i++){										// Iter. over edges.
            int node1=v[i][0], node2=v[i][1];
            if(node2==0) continue;											// If curr. edge is deleted one, skip it.
            int parL=findParent(node1, parent);								// Find core-parent of parent of this edge.
            if(parL==node2){												// If it's core parent is the child of curr. edge(Cycle detected).
                if(ans1.size()==0) return v[i];								// If a edge hadn't been deleted(Cycle on the root), del. curr edge.
                return ans1;												// Else(Cycle on non-root node), delete other edge.		
            }	
            parent[node2]=parL;												// Setting parents to nodes of visited edges.
        }
        return ans2;														// If no cycle is found, return the deleted edge(Cycle on non-root node).
        
    }
};