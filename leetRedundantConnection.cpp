/*
*
//**********************************************************684. Redundant Connection.***************************************************

In this problem, a tree is an undirected graph that is connected and has no cycles.

The given input is a graph that started as a tree with N nodes (with distinct values 1, 2, ..., N), with one additional edge added. The added 
edge has two different vertices chosen from 1 to N, and was not an edge that already existed.

The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] with u < v, that represents an undirected edge 
connecting nodes u and v.

Return an edge that can be removed so that the resulting graph is a tree of N nodes. If there are multiple answers, return the answer that 
occurs last in the given 2D-array. The answer edge [u, v] should be in the same format, with u < v.

Example 1:
Input: [[1,2], [1,3], [2,3]]
Output: [2,3]
Explanation: The given undirected graph will be like this:
  1
 / \
2 - 3
Example 2:
Input: [[1,2], [2,3], [3,4], [1,4], [1,5]]
Output: [1,4]
Explanation: The given undirected graph will be like this:
5 - 1 - 2
    |   |
    4 - 3
Note:
The size of the input 2D-array will be between 3 and 1000.
Every integer represented in the 2D-array will be between 1 and N, where N is the size of the input array.

Update (2017-09-26):
We have overhauled the problem description + test cases and specified clearly the graph is an undirected graph. For the directed graph follow 
up please see Redundant Connection II). We apologize for any inconvenience caused.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[1,2], [2,3], [3,4], [1,4], [1,5]]

[[9,10],[5,8],[2,6],[1,5],[3,8],[6,8],[7,9],[8,10],[4,9],[4,10]]



// Time Complexity: O(n*n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*n).
// Space Complexity: O(n).	
// This algorithm is Union and Find based. We initially set the parents of all nodes to itself. while going through edges, if both edge's parent
// is the same, then store that index, as both of edges belong to same union. If not, we make the parent of one node the parent of other node's
// parent.








class Solution {
public:
    
    vector<int> parent;
    
    void setParent(int node1, int node2){                       // Setting the parent of left node as parent of parent of right node.
        parent[node2]=parent[node1];
        return ;
    }
    
    int findParent(int node1){									// Finding the parent of the node.
        while(parent[node1]!=node1) node1=parent[node1];
        return node1;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        parent=vector<int>(1001);
        // cout<<"Parent size: "<<parent.size()<<endl;
        for(int i=0;i<parent.size();i++) parent[i]=i;           // Setting parent to itself for all the nodes.
        int index=-1;											// Index of the answer.
        for(int i=0;i<edges.size();i++){
            // cout<<"Curr. index: "<<i<<" with parentNum: "<<findParent(edges[i][0])<<" and: "<<findParent(edges[i][1])<<endl;
            int p0=findParent(edges[i][0]), p1=findParent(edges[i][1]);	// Finding parents of both the nodes.
            if(p0==p1) index=i;									// If both the node's parents are same, save the index.
            else{
                setParent(edges[i][0], p1);						// Else,setting the parent of one node to be parent of other node's parent.
            }
        }
        //cout<<"The result index is: "<<index<<endl;
        return edges[index];									// Returning the redundant connection.
    }
};
