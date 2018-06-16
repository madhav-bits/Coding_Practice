/*
*
//**************************************************************133. Clone Graph.*****************************************************

Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


// Test cases aren't allowed for this question.



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is DFS based. We start traversal from the root, at each step, we check whether adj. nodes are created/visited(present in HashMap).
// If present in HashMap, get it's address directly. If not call fn. to get the adj. node created and get it's adj. node list udpated, upon 
// returning from the recursion call, we update the curr. Node's adj. node list. At the end we get a Clone Graph.



// BFS is slightly faster than DFS.





/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    
    UndirectedGraphNode* createDup(UndirectedGraphNode* node, unordered_map<int, UndirectedGraphNode*> &visited){
        UndirectedGraphNode* curr= new UndirectedGraphNode(node->label);	// Creating the curr. Node's Dup.
        visited[node->label]=curr;											// Marking the curr. Node as visited.
        for(int i=0;i<node->neighbors.size();i++){							// Iterating through all adj. nodes.
            if(visited.count(node->neighbors[i]->label)==0)					// If adj. node not created, then call. fn. to get it created.
                createDup(node->neighbors[i], visited);
            curr->neighbors.push_back(visited[node->neighbors[i]->label]);	// Update the curr. Node's adj. nodes list.
        }
        
        return curr;
        
    }
    
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node==NULL) return NULL;											// If NULL it provided, return NULL.
        unordered_map<int,UndirectedGraphNode*> visited;					// Stores created/visited Nodes.
        return createDup(node, visited);									// Call fn. to Clone Graph.
             
    }
};












//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is BFS based. At each step, we check whether curr. Node's neighbors are created or not? If not created, we create them and push
// them into Queue. If a neighbor is already created(then it must have been already once pushed into Queue), so, need not push once again into
// Queue. We get the neighbor's address and append it to the curr. Node's vector. At the end, we get a clone Graph.







/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node==NULL) return NULL;
        unordered_map<int,UndirectedGraphNode*> visited;					// Stores Labels, whose nodes had been created.
        queue<UndirectedGraphNode*>q;										// Stores Nodes, which are yet to be visited.
        UndirectedGraphNode* root= new UndirectedGraphNode(node->label);
        visited[node->label]=root;											// Starting traversal from root.
        q.push(node);                                                       // Stores Created and to be visited nodes.
        while(!q.empty()){
            UndirectedGraphNode* currOld=q.front();	
            q.pop();
            for(int i=0;i<currOld->neighbors.size();i++){					// Iterate through all neighbors of curr. Node.
                if(visited.count(currOld->neighbors[i]->label)==0 ){		// If adj. node doens't exist earlier.
                    UndirectedGraphNode* nextNode= new UndirectedGraphNode(currOld->neighbors[i]->label);
                    visited[currOld->neighbors[i]->label]=nextNode;			// Updating the visited HashMap.
                    visited[currOld->label]->neighbors.push_back(nextNode);	// Updating the curr. Node's adj. node list.
                    q.push(currOld->neighbors[i]);							// Pushing the unvisited node into Queue.
                }
                else{														// Updating the curr. Node's adj. node list.
                    visited[currOld->label]->neighbors.push_back(visited[currOld->neighbors[i]->label]);
                }
                    
            }
        }
        
        return root;    													// Returning the root of the Clone Graph. 
    }
};